#include "pa_playback.h"

typedef struct
{
    int     frameIndex;
    int     maxFrameIndex;
    SAMPLE  *recordedSamples;
}
paTestData;

static int playCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags, void *userData)
{
    SAMPLE          *output = (SAMPLE *) outputBuffer;
    SAMPLE          *data_buffer = (SAMPLE *) userData;
    unsigned int    i;

    (void) inputBuffer;
    (void) timeInfo;
    (void) statusFlags;

    for(i=0; i<framesPerBuffer; i++)
    {
        *output++ = *data_buffer++;
        if(NUM_CHANNELS == 2)
            *output++ = *data_buffer++;
    }

    return paComplete;
}

void *pa_play_thread(void *ptr)
{
    PAThreadData        *pPAThreadData = (PAThreadData *) ptr;
    PaStreamParameters  outputParameters;
    PaStream            *stream;
    PaError             err = paNoError;
    int                 FramesPerBuffer;
    FILE                *fid;

    fid = fopen(pPAThreadData->filename, "rb");
    if(fid == NULL)
    {
        fprintf(stderr, "Could not read buffer or buffer doesn't exist.");
    }
    else
    {
        intPubAttrCheck(6, (wxSpeaCalTrainFrame *) pPAThreadData->mainThread, FramesPerBuffer);

        SAMPLE  data_buffer[FramesPerBuffer];

        fread(data_buffer, NUM_CHANNELS * sizeof(SAMPLE), FramesPerBuffer, fid);
        fclose(fid);

        //int i;
        //for(i=0; i<FramesPerBuffer; i++)
        //    fprintf(stdout, "%d: %d\n", i, data_buffer[i]);

        outputParameters.device = Pa_GetDefaultOutputDevice();
        if (outputParameters.device == paNoDevice)
        {
            fprintf(stderr,"Error: Specified output device unavailable.\n");
            goto done;
        }
        else
        {
            outputParameters.channelCount = NUM_CHANNELS;
            outputParameters.sampleFormat = PA_SAMPLE_TYPE;
            outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
            outputParameters.hostApiSpecificStreamInfo = NULL;
        }

        err = Pa_OpenStream(&stream,
                            NULL,
                            &outputParameters,
                            SAMPLE_RATE,
                            FramesPerBuffer,
                            paNoFlag,
                            playCallback,
                            (void *) &data_buffer);
        if(err != paNoError) goto done;

        err = Pa_StartStream(stream);
        if(err != paNoError) goto done;

        while((err = Pa_IsStreamActive(stream)) == 1)
            Pa_Sleep(100);
        if(err < 0) goto done;

        err = Pa_CloseStream(stream);
        if(err != paNoError) goto done;

done:
        if(err != paNoError)
        {
            fprintf(stderr, "An error occured while using the portaudio stream in thread\n");
            fprintf(stderr, "Error number: %d\n", err);
            fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
        }
    }
    return (void *) err;
}
