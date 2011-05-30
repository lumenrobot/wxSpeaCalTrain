//------------------------------
// Original Author:
//  David E. Narváez -- dMaggot
//  david.narvaez@computer.org
// Modified By:
//  Aditya A. Nugraha
//  aa.nugraha@ieee.org
//------------------------------

#include "xcorr.h"

void xcorr(fftw_complex *signala, fftw_complex *signalb, fftw_complex *result, int N) {
    fftw_complex    *signala_ext, *signalb_ext, *out_shifted, *outa, *outb, *out;
    fftw_plan       pa, pb, px;
    int             i;

    signala_ext = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * ((N << 1) - 1));
    signalb_ext = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * ((N << 1) - 1));
    out_shifted = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * ((N << 1) - 1));
    outa = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * ((N << 1) - 1));
    outb = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * ((N << 1) - 1));
    out  = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * ((N << 1) - 1));

    pa = fftw_plan_dft_1d((N << 1) - 1, signala_ext, outa, FFTW_FORWARD, FFTW_ESTIMATE);
    pb = fftw_plan_dft_1d((N << 1) - 1, signalb_ext, outb, FFTW_FORWARD, FFTW_ESTIMATE);
    px = fftw_plan_dft_1d((N << 1) - 1, out, out_shifted, FFTW_BACKWARD, FFTW_ESTIMATE);

    for (i = 0; i < (N << 1) - 1; i++) {
        if (i < N) {
	        signala_ext[i] = signala[i];
	        signalb_ext[i] = signalb[i];
        }
        else {
	        signala_ext[i] = 0;
	        signalb_ext[i] = 0;
        }
    }

    fftw_execute(pa);
    fftw_execute(pb);

    for (i = 0; i < (N << 1) - 1; i++)
        out[i] = outa[i] * conj(outb[i]);

    fftw_execute(px);

    for (i = 0; i < (N << 1) - 1; i++)
        result[i] = out_shifted[(i + N) % ((N << 1) - 1)] / ((N << 1) - 1);

    fftw_destroy_plan(pa);
    fftw_destroy_plan(pb);
    fftw_destroy_plan(px);

    fftw_free(signala_ext);
    fftw_free(signalb_ext);
    fftw_free(out_shifted);
    fftw_free(out);
    fftw_free(outa);
    fftw_free(outb);

    fftw_cleanup();

    return;
}

int maxLag(fftw_complex *xcorr_result, int lags) {
    double  maxValue = creal(xcorr_result[0]);
    int     i, maxValueIndex = 0;
    int     centerIndex = (lags - 1) >> 1;

    for(i = 1; i <= lags; i++)
    {
        if(creal(xcorr_result[i]) > maxValue)
        {
            maxValue = creal(xcorr_result[i]);
            maxValueIndex = i;
        }
    }

    //fprintf(stdout, "maxValueIndex = %d\n", maxValueIndex);
    //fprintf(stdout, "maxValue = %f\n", maxValue);

    return maxValueIndex - centerIndex;
}

int xcorr_op(fftw_complex *first_signal, fftw_complex *second_signal, int FramesPerBuffer)
{
    fftw_complex    *xcorr_result;
    int             lag;

    xcorr_result  = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * ((FramesPerBuffer << 1) - 1));

    xcorr(first_signal, second_signal, xcorr_result, FramesPerBuffer);
    lag = maxLag(xcorr_result, ((FramesPerBuffer << 1) - 1));

    fftw_free(xcorr_result);

    return lag;
}

void *xcorr_thread(void *ptr)
{
    short int       tempFlag[NUM_TDOA];
    short int       temp1, temp2, done, go_flag = 0;;
    short int       i, j, k;
    int             l;
    int             tdoa_seq;
    double          tdoa_msec;
    struct timeval  startTime, currTime, timeDiff;
    void            *dummy = 0;
    int             NormTDOA, FramesPerBuffer;
    short int       pubXcorrFileID, pubXcorrReadyFlag;
    double          pubDevRecordStartTime1, pubDevRecordStartTime2;
    double          pubDevXcorrReadyTime1, pubDevXcorrReadyTime2;
    double          startTimeDiff, readyTimeDiff;
    int             frameDiff;
    double          meanTemp1, meanTemp2, maxTemp1, maxTemp2, minTemp1, minTemp2;
    int             maxIndex1, maxIndex2, minIndex1, minIndex2;
    double          temp;

    char            fileName[32];
    FILE            *fid;
    SAMPLE          *tempData;
    fftw_complex    *first_signal, *second_signal;
    fftw_complex    *first_xcorr_signal, *second_xcorr_signal;

    intPubAttrCheck(6, (wxSpeaCalTrainFrame *) ptr, FramesPerBuffer);
    intPubAttrCheck(0, (wxSpeaCalTrainFrame *) ptr, NormTDOA);
    timevalPubStartTimeCheck((wxSpeaCalTrainFrame *) ptr, startTime);

    SAMPLE          input_data_buffer[FramesPerBuffer];
	SAMPLE          process_data_buffer[FramesPerBuffer];

    tempData            = (SAMPLE *) malloc(sizeof(SAMPLE) * FramesPerBuffer);
    first_signal        = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * FramesPerBuffer);
    second_signal       = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * FramesPerBuffer);
    first_xcorr_signal  = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * FramesPerBuffer);
    second_xcorr_signal = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * FramesPerBuffer);

    for (i=FIRST_MIC_ID; i<FIRST_MIC_ID+RECORD_THREADS; i++)
    {
        go_flag = go_flag | 1 << i;
    }

    while (1)
    {
        usleep(200000);
        shintPubAttrCheck(2, NULL, (wxSpeaCalTrainFrame *) ptr, pubXcorrFileID);
        shintPubAttrCheck(0, pubXcorrFileID, (wxSpeaCalTrainFrame *) ptr, pubXcorrReadyFlag);
        if (pubXcorrReadyFlag == go_flag)
        {
            usleep(1000);
            shintPubAttrBitToggle(1, NULL, (wxSpeaCalTrainFrame *) ptr, 0);
            done = pubXcorrReadyFlag;
            k = 0;
            //fprintf(stdout, "xcorr_ready_flag[%d] = %d\n", xcorr_file_id, xcorr_ready_flag[xcorr_file_id]);

            for(l = 0; l < RECORD_THREADS; l++)
                doublePubAttrAssign(8, l, (wxSpeaCalTrainFrame *) ptr, 0);

            for (i=FIRST_MIC_ID; i<=FIRST_MIC_ID+RECORD_THREADS-2; i++)
            {
                temp1 = pubXcorrReadyFlag >> i;

                sprintf(fileName, "dev-%d-buf-rec-%d.raw", i, pubXcorrFileID);
                fid = fopen(fileName, "rb");
                if(fid == NULL)
                {
                    fprintf(stderr, "Could not open first file for reading the buffer.");
                    exit(1);
                }
                fread(tempData, sizeof(SAMPLE), FramesPerBuffer, fid);
                for(l = 0; l < FramesPerBuffer; l++) {
#if USE_BPF
                    input_data_buffer[l] = *(tempData+l) * 1.41;

                    if (l == 0)
                    {
                        process_data_buffer[l] = (BPF_COEFF_A0*input_data_buffer[l]);
                    }
                    else if (l == 1)
                    {
                        process_data_buffer[l] = ((BPF_COEFF_A0*input_data_buffer[l])
                                                  + (BPF_COEFF_A1*input_data_buffer[l-1])
                                                  - (BPF_COEFF_B1*process_data_buffer[l-1]));
                    }
                    else if (l > 1)
                    {
                        process_data_buffer[l] = ((BPF_COEFF_A0*input_data_buffer[l])
                                                  + (BPF_COEFF_A1*input_data_buffer[l-1])
                                                  + (BPF_COEFF_A2*input_data_buffer[l-2])
                                                  - (BPF_COEFF_B1*process_data_buffer[l-1])
                                                  - (BPF_COEFF_B2*process_data_buffer[l-2]));
                    }

                    first_signal[l] = process_data_buffer[l];
#else
                    first_signal[l]  = *(tempData+l) * 1.41;
#endif
                }
                fclose(fid);

                doublePubAttrCheck(8, i-FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr, temp);
                //fprintf(stdout, "temp[%d] = %f\n", i-FIRST_MIC_ID, temp);
                if (temp == 0)
                {
                    maxTemp1  = cabs(first_signal[0]);
                    for(l = 0; l < FramesPerBuffer; l++) {
                        if(cabs(first_signal[l]) > maxTemp1)
                        {
                            maxTemp1 = cabs(first_signal[l]);
                        }
                    }
                    doublePubAttrAssign(8, i-FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr, maxTemp1);
                    //fprintf(stdout, "cari max %d!\n", i-FIRST_MIC_ID);
                    //doublePubAttrCheck(8, i-FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr, temp);
                    //fprintf(stdout, "temp[%d] = %f\n", i-FIRST_MIC_ID, temp);
                }

                /*char    recordFileName[FILENAME_MAX];
                FILE    *buf_fid;
                sprintf(recordFileName,"filtered_first_signal.raw");
                buf_fid = fopen(recordFileName, "wb");
                if(buf_fid == NULL)
                {
                    printf("Could not open file for saving the buffer.");
                    exit(1);
                }
                else
                {
                    fwrite(process_data_buffer, NUM_CHANNELS * sizeof(SAMPLE), FramesPerBuffer, buf_fid);
                }
                fclose(buf_fid);*/

                for (j = 1; j <= FIRST_MIC_ID+RECORD_THREADS-i-1; j++)
                {
                    temp2 = temp1 >> j;

                    sprintf(fileName, "dev-%d-buf-rec-%d.raw", (i+j), pubXcorrFileID);
                    fid = fopen(fileName, "rb");
                    if(fid == NULL)
                    {
                        fprintf(stderr, "Could not open second file (%s) for reading the buffer.", fileName);
                        exit(1);
                    }
                    fread(tempData, sizeof(SAMPLE), FramesPerBuffer, fid);
                    for(l = 0; l < FramesPerBuffer; l++) {
#if USE_BPF
                        input_data_buffer[l] = *(tempData+l) * 1.41; // 3 dB

                        if (l == 0)
                        {
                            process_data_buffer[l] = (BPF_COEFF_A0*input_data_buffer[l]);
                        }
                        else if (l == 1)
                        {
                            process_data_buffer[l] = ((BPF_COEFF_A0*input_data_buffer[l])
                                                      + (BPF_COEFF_A1*input_data_buffer[l-1])
                                                      - (BPF_COEFF_B1*process_data_buffer[l-1]));
                        }
                        else if (l > 1)
                        {
                            process_data_buffer[l] = ((BPF_COEFF_A0*input_data_buffer[l])
                                                      + (BPF_COEFF_A1*input_data_buffer[l-1])
                                                      + (BPF_COEFF_A2*input_data_buffer[l-2])
                                                      - (BPF_COEFF_B1*process_data_buffer[l-1])
                                                      - (BPF_COEFF_B2*process_data_buffer[l-2]));
                        }

                        second_signal[l] = process_data_buffer[l];
#else
                        second_signal[l]  = *(tempData+l) * 1.41;
#endif
                    }
                    fclose(fid);

                    doublePubAttrCheck(8, i+j-FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr, temp);
                    //fprintf(stdout, "temp[%d] = %f\n", i+j-FIRST_MIC_ID, temp);
                    if (temp == 0)
                    {
                        maxTemp2  = cabs(second_signal[0]);
                        for(l = 0; l < FramesPerBuffer; l++) {
                            if(cabs(second_signal[l]) > maxTemp2)
                            {
                                maxTemp2 = cabs(second_signal[l]);
                            }
                        }
                        doublePubAttrAssign(8, i+j-FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr, maxTemp2);
                        //fprintf(stdout, "cari max %d!\n", i+j-FIRST_MIC_ID);
                        //doublePubAttrCheck(8, i+j-FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr, temp);
                        //fprintf(stdout, "temp[%d] = %f\n", i+j-FIRST_MIC_ID, temp);
                    }

                    if (temp1 & 1 && temp2 & 1)
                    {
                        /******************************/
                        /** BEGIN UN-Normalized TDOA **/

                        for(l = 0; l < FramesPerBuffer/2000; l++) { // = 1/2 msec
                            first_signal[l]  = 0;
                            //first_signal[FramesPerBuffer-l] = 0;
                            second_signal[l] = 0;
                            //second_signal[FramesPerBuffer-l] = 0;
                        }

                        tdoa_seq = xcorr_op(first_signal, second_signal, FramesPerBuffer);
                        tdoa_msec = (double) tdoa_seq/SAMPLE_RATE*1000;
#if DEBUG_MODE
                        gettimeofday(&currTime, NULL);
                        TimevalDiff(&timeDiff, &currTime, &startTime, (wxSpeaCalTrainFrame *) dummy);
                        fprintf(stdout, "Elapsed time: %4ld.%03ld sec  [%d]     TDOA-%d-%d = %+4d frame = %+02.3f msec\n",
                                timeDiff.tv_sec, timeDiff.tv_usec/1000, pubXcorrFileID,
                                i, i+j, tdoa_seq, tdoa_msec);
#endif

                        meanTemp1 = 0;
                        meanTemp2 = 0;
                        maxTemp1  = minTemp1 = creal(first_signal[0]);;
                        maxTemp2  = minTemp2 = creal(second_signal[0]);
                        maxIndex1 = minIndex1 = 0;
                        maxIndex2 = minIndex2 = 0;
                        for(l = 0; l < FramesPerBuffer; l++) {
                            if(creal(first_signal[l]) > maxTemp1)
                            {
                                maxTemp1 = creal(first_signal[l]);
                                maxIndex1 = l;
                            }
                            if(creal(first_signal[l]) < minTemp1)
                            {
                                minTemp1 = creal(first_signal[l]);
                                minIndex1 = l;
                            }
                            if(creal(second_signal[l]) > maxTemp2)
                            {
                                maxTemp2 = creal(second_signal[l]);
                                maxIndex2 = l;
                            }
                            if(creal(second_signal[l]) < minTemp2)
                            {
                                minTemp2 = creal(second_signal[l]);
                                minIndex2 = l;
                            }
                            meanTemp1 += pow(creal(first_signal[l]),2);
                            meanTemp2 += pow(creal(second_signal[l]),2);
                        }

                        //fprintf(stdout, "maxTemp1 = %f\n", maxTemp1);
                        //fprintf(stdout, "maxIndex1 = %d\n", maxIndex1);
                        //fprintf(stdout, "maxTemp2 = %f\n", maxTemp2);
                        //fprintf(stdout, "maxIndex2 = %d\n", maxIndex2);

                        doublePubAttrAssign(4, k, (wxSpeaCalTrainFrame *) ptr, tdoa_msec);
                        doublePubAttrAssign(9, k, (wxSpeaCalTrainFrame *) ptr,
                                            sqrt(meanTemp1/FramesPerBuffer)/sqrt(meanTemp2/FramesPerBuffer));
                        doublePubAttrAssign(12, k, (wxSpeaCalTrainFrame *) ptr,
                                            (maxTemp1-minTemp1)/(maxTemp2-minTemp2));

                        /**  END  UN-Normalized TDOA **/
                        /******************************/


                        /***************************/
                        /** BEGIN Normalized TDOA **/

                        doublePubAttrCheck(11, i - FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr,
                                               pubDevRecordStartTime1);
                        doublePubAttrCheck(11, (i+j) - FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr,
                                               pubDevRecordStartTime2);
                        doublePubAttrCheck(3, i - FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr,
                                               pubDevXcorrReadyTime1);
                        doublePubAttrCheck(3, (i+j) - FIRST_MIC_ID, (wxSpeaCalTrainFrame *) ptr,
                                               pubDevXcorrReadyTime2);

                        startTimeDiff = pubDevRecordStartTime2 - pubDevRecordStartTime1; // msec
                        readyTimeDiff = pubDevXcorrReadyTime2 - pubDevXcorrReadyTime1;   // msec
                        frameDiff = (startTimeDiff+readyTimeDiff)/2 * SAMPLE_RATE/1000;
                        /*fprintf(stdout, "startTimeDiff = %f\n", startTimeDiff);
                        fprintf(stdout, "readyTimeDiff = %f\n", readyTimeDiff);
                        fprintf(stdout, "frameDiff = %d\n", frameDiff);*/

                        for(l = 0; l < FramesPerBuffer; l++) {
                            if(l < FramesPerBuffer - abs(frameDiff))
                            {
                                if(frameDiff >= 0)
                                {
                                    first_xcorr_signal[l]  = first_signal[l+abs(frameDiff)];
                                    second_xcorr_signal[l] = second_signal[l];
                                }
                                else
                                {
                                    first_xcorr_signal[l]  = first_signal[l];
                                    second_xcorr_signal[l] = second_signal[l+abs(frameDiff)];
                                }
                            }
                            else
                            {
                                first_xcorr_signal[l]  = 0;
                                second_xcorr_signal[l] = 0;
                            }
                        }

                        for(l = 0; l < FramesPerBuffer/2000; l++) { // = 1/2 msec
                            first_xcorr_signal[l]  = 0;
                            //first_signal[FramesPerBuffer-l] = 0;
                            second_xcorr_signal[l] = 0;
                            //second_signal[FramesPerBuffer-l] = 0;
                        }

                        tdoa_seq = xcorr_op(first_xcorr_signal, second_xcorr_signal, FramesPerBuffer);
                        tdoa_msec = (double) tdoa_seq/SAMPLE_RATE*1000;
#if DEBUG_MODE
                        gettimeofday(&currTime, NULL);
                        TimevalDiff(&timeDiff, &currTime, &startTime, (wxSpeaCalTrainFrame *) dummy);
                        fprintf(stdout, "Elapsed time: %4ld.%03ld sec  [%d] NormTDOA-%d-%d = %+4d frame = %+02.3f msec\n",
                                timeDiff.tv_sec, timeDiff.tv_usec/1000, pubXcorrFileID,
                                i, i+j, tdoa_seq, tdoa_msec);
#endif

                        meanTemp1 = 0;
                        meanTemp2 = 0;
                        maxTemp1  = minTemp1 = creal(first_xcorr_signal[0]);;
                        maxTemp2  = minTemp2 = creal(second_xcorr_signal[0]);
                        maxIndex1 = minIndex1 = 0;
                        maxIndex2 = minIndex2 = 0;
                        for(l = 0; l < FramesPerBuffer; l++) {
                            if(creal(first_xcorr_signal[l]) > maxTemp1)
                            {
                                maxTemp1 = creal(first_xcorr_signal[l]);
                                maxIndex1 = l;
                            }
                            if(creal(first_xcorr_signal[l]) < minTemp1)
                            {
                                minTemp1 = creal(first_xcorr_signal[l]);
                                minIndex1 = l;
                            }
                            if(creal(second_xcorr_signal[l]) > maxTemp2)
                            {
                                maxTemp2 = creal(second_xcorr_signal[l]);
                                maxIndex2 = l;
                            }
                            if(creal(second_xcorr_signal[l]) < minTemp2)
                            {
                                minTemp2 = creal(second_xcorr_signal[l]);
                                minIndex2 = l;
                            }
                            meanTemp1 += pow(creal(first_xcorr_signal[l]),2);
                            meanTemp2 += pow(creal(second_xcorr_signal[l]),2);
                        }

                        //fprintf(stdout, "maxTemp1 = %f\n", maxTemp1);
                        //fprintf(stdout, "maxIndex1 = %d\n", maxIndex1);
                        //fprintf(stdout, "maxTemp2 = %f\n", maxTemp2);
                        //fprintf(stdout, "maxIndex2 = %d\n", maxIndex2);

                        doublePubAttrAssign(7, k, (wxSpeaCalTrainFrame *) ptr, tdoa_msec);
                        doublePubAttrAssign(10, k, (wxSpeaCalTrainFrame *) ptr,
                                            sqrt(meanTemp1/FramesPerBuffer)/sqrt(meanTemp2/FramesPerBuffer));
                        doublePubAttrAssign(13, k, (wxSpeaCalTrainFrame *) ptr,
                                            (maxTemp1-minTemp1)/(maxTemp2-minTemp2));

                        /**  END  Normalized TDOA **/
                        /***************************/


                        if (NUM_TDOA > 1)
                        {
                            tempFlag[k] = pubXcorrReadyFlag ^ 1 << i ^ 1 << (i+j);
                            k++;
                        }
                        else
                        {
                            done = pubXcorrReadyFlag ^ 1 << i ^ 1 << (i+j);
                        }
                    }
                }
            }
            if (NUM_TDOA > 1)
            {
                for (i=0; i<NUM_TDOA; i++)
                    done = done ^ tempFlag[i];
            }
            if (done == 0)
            {
                gettimeofday(&currTime, NULL);
                TimevalDiff(&timeDiff, &currTime, &startTime, (wxSpeaCalTrainFrame *) dummy);
                doublePubAttrAssign(5, 0, (wxSpeaCalTrainFrame *) ptr,
                                    timeDiff.tv_sec + (double) timeDiff.tv_usec/1000000);
                doublePubAttrAssign(0, pubXcorrFileID, (wxSpeaCalTrainFrame *) ptr, 0);
                shintPubAttrBitToggle(2, NULL, (wxSpeaCalTrainFrame *) ptr, 0);
            }
        }
    }

    fftw_free(first_xcorr_signal);
    fftw_free(second_xcorr_signal);
    fftw_free(first_signal);
    fftw_free(second_signal);
    free(tempData);
}
