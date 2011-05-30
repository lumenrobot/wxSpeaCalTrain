#include "pa_record.h"

typedef struct
{
    short int       devNum;
    FILE            *main_fid;
    int             pubMenuNormTDOA;
    struct timeval  pubStartTime;
    void            *mainThread;
}
pDataFile;

static int recordCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags, void *dataFile)
{
	pDataFile       *userDataFile = (pDataFile *) dataFile;
	const SAMPLE    *input = (const SAMPLE*) inputBuffer;
	//SAMPLE          input_data_buffer[framesPerBuffer];
	//SAMPLE          process_data_buffer[framesPerBuffer];
	SAMPLE          output_data_buffer[framesPerBuffer];
	struct timeval  currTime, timeDiff;
	char            recordFileName[32];
	FILE            *buf_fid;
	unsigned int    i;
	void            *dummy = 0;
	short int       pubBufFileID;

	(void) outputBuffer;
    (void) timeInfo;
    (void) statusFlags;

    if(inputBuffer == NULL)
    {
        for(i=0; i<framesPerBuffer; i++)
        {
            output_data_buffer[i] = SAMPLE_SILENCE;  /* left */
            if(NUM_CHANNELS == 2)
                output_data_buffer[i] = SAMPLE_SILENCE;  /* right */
        }
    }
    else
    {
        for(i=0; i<framesPerBuffer; i++)
        {
            output_data_buffer[i] = *input++;
        }
	}

#if WRITE_TO_FILE
    fwrite(output_data_buffer, NUM_CHANNELS * sizeof(SAMPLE), framesPerBuffer, userDataFile->main_fid);
#endif

#if COMPUTE_XCORR
    shintPubAttrCheck(1, NULL, (wxSpeaCalTrainFrame *) userDataFile->mainThread, pubBufFileID);
    sprintf(recordFileName,"dev-%d-buf-rec-%d.raw", userDataFile->devNum, pubBufFileID);
    buf_fid = fopen(recordFileName, "wb");
    if(buf_fid == NULL)
    {
        printf("Could not open file for saving the buffer.");
        exit(1);
    }
    else
    {
        fwrite(output_data_buffer, NUM_CHANNELS * sizeof(SAMPLE), framesPerBuffer, buf_fid);
        shintPubAttrBitToggle(0, pubBufFileID, (wxSpeaCalTrainFrame *) userDataFile->mainThread, userDataFile->devNum);
        gettimeofday(&currTime, NULL);
        TimevalDiff(&timeDiff, &currTime, &userDataFile->pubStartTime, (wxSpeaCalTrainFrame *) dummy);
        if(userDataFile->pubMenuNormTDOA)
        {
            doublePubAttrAssign(3, userDataFile->devNum - FIRST_MIC_ID,
                                (wxSpeaCalTrainFrame *) userDataFile->mainThread,
                                timeDiff.tv_sec*1000 + (double) timeDiff.tv_usec/1000);
        }
#if DEBUG_MODE
        fprintf(stdout, "Elapsed time: %4ld.%03ld sec  [%d] Buffer XCORR's device %d READY!\n",
                timeDiff.tv_sec, timeDiff.tv_usec/1000, pubBufFileID, userDataFile->devNum);
#endif
        fclose(buf_fid);
    }
#endif

#if INF_LOOP
    Pa_Sleep(N_SEC_BETWEEN_REC);

    return paContinue;
#else
    return paComplete;
#endif
}

void *pa_record_thread(void *ptr)
{
    PAThreadData        *pPAThreadData = (PAThreadData *) ptr;
    PaStreamParameters  *inputParameters = (PaStreamParameters *) pPAThreadData->inputParameters;
    PaStream            *stream;
    PaError             err = paNoError;
    struct timeval      startTime, currTime, timeDiff;
    pDataFile           userDataFile;
    int                 PAStreamRun, FramesPerBuffer;

    timevalPubStartTimeCheck((wxSpeaCalTrainFrame *) pPAThreadData->mainThread, startTime);

    intPubAttrCheck(6, (wxSpeaCalTrainFrame *) pPAThreadData->mainThread, FramesPerBuffer);
    userDataFile.mainThread = pPAThreadData->mainThread;
    intPubAttrCheck(0, (wxSpeaCalTrainFrame *) pPAThreadData->mainThread,
                    userDataFile.pubMenuNormTDOA);
    userDataFile.pubStartTime = startTime;

#if (WRITE_TO_FILE || COMPUTE_XCORR)
    userDataFile.devNum = inputParameters->device;
#endif

#if WRITE_TO_FILE
    char                recordFileName[32];
    sprintf(recordFileName,"dev-%d-main-rec.raw", inputParameters->device);
    userDataFile.main_fid = fopen(recordFileName, "wb");
    if(userDataFile.main_fid == NULL)
    {
        printf("Could not open file.");
        goto error;
    }
#endif

    err = Pa_OpenStream(&stream,
                        inputParameters,
                        NULL,
                        SAMPLE_RATE,
                        FramesPerBuffer,
                        paNoFlag,
                        recordCallback,
#if (WRITE_TO_FILE || COMPUTE_XCORR)
                        &userDataFile
#else
                        NULL
#endif
                        );
    if(err != paNoError) goto error;

    gettimeofday(&currTime, NULL);
    TimevalDiff(&timeDiff, &currTime, &startTime,
                (wxSpeaCalTrainFrame *) pPAThreadData->mainThread);
    doublePubAttrAssign(11, inputParameters->device - FIRST_MIC_ID,
                        (wxSpeaCalTrainFrame *) pPAThreadData->mainThread,
                        timeDiff.tv_sec*1000 + (double) timeDiff.tv_usec/1000);

    err = Pa_StartStream(stream);
    if(err != paNoError) goto error;

    while((err = Pa_IsStreamActive(stream)) == 1)
    {
        Pa_Sleep(1000);
        intPubAttrCheck(1, (wxSpeaCalTrainFrame *) pPAThreadData->mainThread, PAStreamRun);
        if(!PAStreamRun)
            break;

        /*Pa_Sleep(60 * 1000);
        gettimeofday(&currTime, NULL);
        timeval_subtract(&timeDiff, &currTime, &startTime);
        if (timeDiff.tv_sec > 3600)
        {
            Pa_StopStream(stream);
        }*/
    }
    if(err < 0) goto error;

    err = Pa_CloseStream(stream);
    if(err != paNoError) goto error;

#if WRITE_TO_FILE
    fclose(userDataFile.main_fid);
#endif

error:
    if(err != paNoError)
    {
        fprintf(stderr, "An error occured while using the portaudio stream in thread\n");
        fprintf(stderr, "Error number: %d\n", err);
        fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
    }
    return (void *) err;
}
