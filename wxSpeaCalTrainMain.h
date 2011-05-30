/***************************************************************
 * Name:      wxSpeaCalTrainMain.h
 * Purpose:   Defines Application Frame
 * Author:    Aditya Arie Nugraha (arie@aanugraha.web.id)
 * Created:   2011-04-30
 * Copyright: Aditya Arie Nugraha (http://blog.aanugraha.web.id)
 * License:
 **************************************************************/

#ifndef WXSPEACALTRAINMAIN_H
#define WXSPEACALTRAINMAIN_H

/********************************************************************************/
/** HEADERS *********************************************************************/
/********************************************************************************/

//(*Headers(wxSpeaCalTrainFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <pthread.h>
#include <signal.h>
#include "portaudio.h"
#include <complex.h>
#include <fftw3.h>
#include "xcorr.h"
#include "pa_record.h"
#include "pa_playback.h"
#include <sys/time.h>
#include "floatfann.h"

/********************************************************************************/


/********************************************************************************/
/** CONSTANTS *******************************************************************/
/********************************************************************************/

#define DEBUG_MODE          0

/**  Cek bagian ini dulu!  **/
#define FIRST_MIC_ID        2
#define RECORD_THREADS      4
#define NUM_TDOA            6  // = (RECORD_THREADS)C2 = RECORD_THREADS!/((RECORD_THREADS-2)! * 2!)
#define SAMPLE_RATE         24000
/****************************/

#define COMPUTE_XCORR       1
#define N_SEC_XCORR_WINDOW  1 // sec
#define N_SEC_BETWEEN_REC   1000 * N_SEC_XCORR_WINDOW // msec
//#define N_SEC_BETWEEN_REC   0 // msec

//#define FRAMES_PER_BUFFER   SAMPLE_RATE * N_SEC_XCORR_WINDOW
#define NUM_CHANNELS        1
#define DITHER_FLAG         0
#define WRITE_TO_FILE       0
#define INF_LOOP            0

#define USE_BPF             1
/** Biquad Band-Pass Filter (Fs=24KHz, Fc=1800Hz, Butterworth **/
#define BPF_COEFF_A0        0.24301081704614158
#define BPF_COEFF_A1        0
#define BPF_COEFF_A2        -0.24301081704614158
#define BPF_COEFF_B1        -1.34896460150382
#define BPF_COEFF_B2        0.5139783659077168
/***************************************************************/

#define ANN_INPUT_NUM       12
#define ANN_OUTPUT_NUM      3

#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"

//#define PA_SAMPLE_TYPE      paInt16
//typedef short SAMPLE;
//#define SAMPLE_SILENCE      (0)
//#define PRINTF_S_FORMAT     "%d"

/********************************************************************************/

typedef struct
{
    void                *mainThread;
    PaStreamParameters  *inputParameters;
    char                filename[1024];
}
PAThreadData;


#ifdef __cplusplus

class wxSpeaCalTrainFrame: public wxFrame
{
    public:

        wxSpeaCalTrainFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxSpeaCalTrainFrame();

        int             TimevalDiff(struct timeval*, struct timeval*, struct timeval*);

        short int       pubXcorrReadyFlag[2];       // 0000 0000 0000 0000
        short int       pubBufFileID;
        short int       pubXcorrFileID;
        int             pubMenuNormTDOA;
        int             pubPAStreamRun;
        int             pubFramesPerBuffer;
        double          pubDevXcorrReadyTime[RECORD_THREADS];
        double          pubDevRecordStartTime[RECORD_THREADS];
        double          pubTDOAValue[NUM_TDOA];     // [0] time (xcorr finished) [1...n] TDOAValue
        double          pubNormTDOAValue[NUM_TDOA]; // [0] time (xcorr finished) [1...n] TDOAValue
        double          pubElapsedTime;
        double          pubPeakAmplitude[RECORD_THREADS];
        double          pubRMSAmplitudeRatio[NUM_TDOA];
        double          pubNormRMSAmplitudeRatio[NUM_TDOA];
        double          pubPeakAmplitudeRatio[NUM_TDOA];
        double          pubNormPeakAmplitudeRatio[NUM_TDOA];
        struct timeval  pubStartTime;

    private:

        //(*Handlers(wxSpeaCalTrainFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnCreateNewTrainingSetFile(wxCommandEvent& event);
        void OnRecordButtonClick(wxCommandEvent& event);
        void OnInsertDataButtonClick(wxCommandEvent& event);
        void OnMenuNormTDOASelected(wxCommandEvent& event);
        void OnOpenTrainingSetFile(wxCommandEvent& event);
        void OnCreateNeuralNetButtonClick(wxCommandEvent& event);
        void OnPlayBuf1ButtonClick(wxCommandEvent& event);
        void OnPlayBuf2ButtonClick(wxCommandEvent& event);
        void OnPlayBuf3ButtonClick(wxCommandEvent& event);
        void OnPlayBuf4ButtonClick(wxCommandEvent& event);
        void OnSuperTrainingButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxSpeaCalTrainFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT11;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT20;
        static const long ID_STATICLINE2;
        static const long ID_TEXTCTRL11;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT14;
        static const long ID_BUTTON3;
        static const long ID_STATICLINE1;
        static const long ID_TEXTCTRL12;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long idMenuNewTrainingSetFile;
        static const long idMenuOpenTrainingSetFile;
        static const long idMenuQuit;
        static const long idMenuNormTDOA;
        static const long idMenuDelRecOnQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxSpeaCalTrainFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText9;
        wxStaticText* StaticText20;
        wxTextCtrl* wxTDOA3Value;
        wxTextCtrl* wxTDOA5Value;
        wxTextCtrl* wxPosYValue;
        wxStaticText* StaticText13;
        wxStaticText* StaticText2;
        wxButton* wxRecordButton;
        wxStaticText* StaticText14;
        wxMenu* Menu3;
        wxStaticText* StaticText6;
        wxMenuItem* MenuItem4;
        wxTextCtrl* wxPosZValue;
        wxButton* wxPlayBuf1Button;
        wxStaticText* StaticText19;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxStaticText* StaticText18;
        wxPanel* Panel1;
        wxTextCtrl* wxTDOA6Value;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxTextCtrl* wxTDOA2Value;
        wxStaticLine* StaticLine2;
        wxTextCtrl* wxTDOA4Value;
        wxButton* wxInsertDataButton;
        wxTextCtrl* wxRecDuration;
        wxMenuItem* MenuItem3;
        wxTextCtrl* wxPosXValue;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxStaticLine* StaticLine1;
        wxMenuItem* MenuNormTDOA;
        wxStaticText* StaticText15;
        wxButton* wxPlayBuf4Button;
        wxStaticText* StaticText12;
        wxButton* wxCreateNeuralNetButton;
        wxTextCtrl* wxTDOA1Value;
        wxTextCtrl* wxNeuralNetFile;
        wxStaticText* StaticText4;
        wxStaticText* StaticText17;
        wxTextCtrl* wxTrainingSetFile;
        wxButton* wxPlayBuf2Button;
        wxStaticText* StaticText16;
        wxMenuItem* MenuDelRecOnQuit;
        wxButton* wxPlayBuf3Button;
        //*)

        void OnIdle(wxIdleEvent&);
        void OnPAError(void);
        void OnRecord(void);
        void StopRunningThread(void);
        void OnPlayBuffer(const char*);
        void OnInsertData(void);

        pthread_t           recordThread[RECORD_THREADS];
        pthread_t           tdoaComputeThread;
        pthread_t           playbackThread;

        PAThreadData        pPARecThreadData[RECORD_THREADS];
        PAThreadData        pPAPlayThreadData;
        PaError             err;
        int                 i;
        int                 speakerPosValue[3];
        double              recDuration;

        wxString            wxstrTrainingSetFile;
        wxString            wxstrNeuralNetFile;
        char                chTrainingSetFile[1024];
        char                chNormTrainingSetFile[1024];

        DECLARE_EVENT_TABLE()
};

#else

typedef struct wxSpeaCalFrame wxSpeaCalFrame;

#endif

#ifdef __cplusplus
extern "C" {
#endif

    wxSpeaCalTrainFrame*         TimevalDiff(struct timeval*, struct timeval*,
                                        struct timeval*, wxSpeaCalTrainFrame*);
    wxSpeaCalTrainFrame*         shintPubAttrCheck(int, int, wxSpeaCalTrainFrame*, short int&);
    wxSpeaCalTrainFrame*         shintPubAttrBitToggle(int, int, wxSpeaCalTrainFrame*, int);
    wxSpeaCalTrainFrame*         intPubAttrCheck(int, wxSpeaCalTrainFrame*, int&);
    wxSpeaCalTrainFrame*         doublePubAttrCheck(int, int, wxSpeaCalTrainFrame*, double&);
    wxSpeaCalTrainFrame*         doublePubAttrAssign(int, int, wxSpeaCalTrainFrame*, double);
    wxSpeaCalTrainFrame*         timevalPubStartTimeCheck(wxSpeaCalTrainFrame*, struct timeval&);

#ifdef __cplusplus
}
#endif

#endif // WXSPEACALTRAINMAIN_H
