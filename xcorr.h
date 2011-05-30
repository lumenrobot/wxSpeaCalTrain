#ifndef XCORR_H
#define XCORR_H

#include <complex.h>
#include <fftw3.h>
#include "wxSpeaCalTrainMain.h"

#ifdef __cplusplus
extern "C" {
#endif

    void *xcorr_thread(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
