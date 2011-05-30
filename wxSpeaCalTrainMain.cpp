/***************************************************************
 * Name:      wxSpeaCalTrainMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Aditya Arie Nugraha (arie@aanugraha.web.id)
 * Created:   2011-04-30
 * Copyright: Aditya Arie Nugraha (http://blog.aanugraha.web.id)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSpeaCalTrainMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxSpeaCalTrainFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxSpeaCalTrainFrame)
const long wxSpeaCalTrainFrame::ID_STATICTEXT1 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL1 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT2 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON1 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON4 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON5 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON6 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON7 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT6 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL5 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT15 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT7 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL6 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT16 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT8 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL7 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT17 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT9 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL8 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT18 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT10 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL9 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT19 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT11 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL10 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT20 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICLINE2 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL11 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT3 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL2 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT12 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT4 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL3 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT13 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT5 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL4 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICTEXT14 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON3 = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATICLINE1 = wxNewId();
const long wxSpeaCalTrainFrame::ID_TEXTCTRL12 = wxNewId();
const long wxSpeaCalTrainFrame::ID_BUTTON2 = wxNewId();
const long wxSpeaCalTrainFrame::ID_PANEL1 = wxNewId();
const long wxSpeaCalTrainFrame::idMenuNewTrainingSetFile = wxNewId();
const long wxSpeaCalTrainFrame::idMenuOpenTrainingSetFile = wxNewId();
const long wxSpeaCalTrainFrame::idMenuQuit = wxNewId();
const long wxSpeaCalTrainFrame::idMenuNormTDOA = wxNewId();
const long wxSpeaCalTrainFrame::idMenuDelRecOnQuit = wxNewId();
const long wxSpeaCalTrainFrame::idMenuAbout = wxNewId();
const long wxSpeaCalTrainFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxSpeaCalTrainFrame,wxFrame)
    //(*EventTable(wxSpeaCalTrainFrame)
    //*)
END_EVENT_TABLE()

wxSpeaCalTrainFrame::wxSpeaCalTrainFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxSpeaCalTrainFrame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer5;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Recording Control"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Record Duration"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxRecDuration = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(wxRecDuration, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    wxRecordButton = new wxButton(Panel1, ID_BUTTON1, _("Record"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(wxRecordButton, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Playback Control"));
    FlexGridSizer4 = new wxFlexGridSizer(0, 4, 0, 0);
    wxPlayBuf1Button = new wxButton(Panel1, ID_BUTTON4, _("Buffer 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer4->Add(wxPlayBuf1Button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxPlayBuf2Button = new wxButton(Panel1, ID_BUTTON5, _("Buffer 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    FlexGridSizer4->Add(wxPlayBuf2Button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxPlayBuf3Button = new wxButton(Panel1, ID_BUTTON6, _("Buffer 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer4->Add(wxPlayBuf3Button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxPlayBuf4Button = new wxButton(Panel1, ID_BUTTON7, _("Buffer 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    FlexGridSizer4->Add(wxPlayBuf4Button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Time Difference of Arrival (TDOA)"));
    FlexGridSizer3 = new wxFlexGridSizer(0, 6, 0, 0);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("TDOA1"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer3->Add(StaticText6, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA1Value = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(90,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer3->Add(wxTDOA1Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel1, ID_STATICTEXT15, _("msec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer3->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("TDOA2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer3->Add(StaticText7, 1, wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 15);
    wxTDOA2Value = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(90,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer3->Add(wxTDOA2Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel1, ID_STATICTEXT16, _("msec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer3->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("TDOA3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer3->Add(StaticText8, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA3Value = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    FlexGridSizer3->Add(wxTDOA3Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel1, ID_STATICTEXT17, _("msec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer3->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("TDOA4"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer3->Add(StaticText9, 1, wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 15);
    wxTDOA4Value = new wxTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    FlexGridSizer3->Add(wxTDOA4Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText18 = new wxStaticText(Panel1, ID_STATICTEXT18, _("msec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer3->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("TDOA5"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer3->Add(StaticText10, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA5Value = new wxTextCtrl(Panel1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    FlexGridSizer3->Add(wxTDOA5Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(Panel1, ID_STATICTEXT19, _("msec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    FlexGridSizer3->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("TDOA6"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    FlexGridSizer3->Add(StaticText11, 1, wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 15);
    wxTDOA6Value = new wxTextCtrl(Panel1, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    FlexGridSizer3->Add(wxTDOA6Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(Panel1, ID_STATICTEXT20, _("msec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    FlexGridSizer3->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer2->Add(StaticLine2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Training Set File"));
    wxTrainingSetFile = new wxTextCtrl(Panel1, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    StaticBoxSizer4->Add(wxTrainingSetFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Speaker Position"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 9, 0, 0);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    wxPosXValue = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(60,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer2->Add(wxPosXValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT12, _("cm"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer2->Add(StaticText12, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText4, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    wxPosYValue = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(60,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer2->Add(wxPosYValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("cm"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer2->Add(StaticText13, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Z"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    wxPosZValue = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(60,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer2->Add(wxPosZValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(Panel1, ID_STATICTEXT14, _("cm"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer2->Add(StaticText14, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxInsertDataButton = new wxButton(Panel1, ID_BUTTON3, _("Insert Data to Training Set"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer3->Add(wxInsertDataButton, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Create Neural Network"));
    wxNeuralNetFile = new wxTextCtrl(Panel1, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    StaticBoxSizer5->Add(wxNeuralNetFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxCreateNeuralNetButton = new wxButton(Panel1, ID_BUTTON2, _("Create"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer5->Add(wxCreateNeuralNetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuNewTrainingSetFile, _("Create New Training Set File"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuOpenTrainingSetFile, _("Open Training Set File"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuNormTDOA = new wxMenuItem(Menu3, idMenuNormTDOA, _("Normalize TDOA"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuNormTDOA);
    MenuDelRecOnQuit = new wxMenuItem(Menu3, idMenuDelRecOnQuit, _("Delete Recording Buffer On Exit"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuDelRecOnQuit);
    MenuBar1->Append(Menu3, _("&Options"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnRecordButtonClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnPlayBuf1ButtonClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnPlayBuf2ButtonClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnPlayBuf3ButtonClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnPlayBuf4ButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnSuperTrainingButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnCreateNeuralNetButtonClick);
    Connect(idMenuNewTrainingSetFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnCreateNewTrainingSetFile);
    Connect(idMenuOpenTrainingSetFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnOpenTrainingSetFile);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnQuit);
    Connect(idMenuNormTDOA,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnMenuNormTDOASelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalTrainFrame::OnAbout);
    //*)

    for(i=0; i<3; i++)
    {
        speakerPosValue[i] = 0;
    }
    wxPosXValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[0]));
    wxPosYValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[1]));
    wxPosZValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[2]));

    recDuration = 1;
    wxRecDuration->ChangeValue(wxString::Format(wxT("%.1f"), recDuration));

    MenuNormTDOA->Check(TRUE);
    MenuDelRecOnQuit->Check(TRUE);

    pubPAStreamRun = 0;
    Connect(wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(wxSpeaCalTrainFrame::OnIdle));
}

wxSpeaCalTrainFrame::~wxSpeaCalTrainFrame()
{
    //(*Destroy(wxSpeaCalTrainFrame)
    //*)
}

void wxSpeaCalTrainFrame::OnQuit(wxCommandEvent& event)
{
    char    filename[32];
    int     i;

    if(MenuDelRecOnQuit->IsChecked())
    {
        for(i=FIRST_MIC_ID; i<FIRST_MIC_ID+RECORD_THREADS; i++)
        {
            sprintf(filename,"dev-%d-buf-rec-0.raw", i);
            remove(filename);
        }
    }

    Close();
}

void wxSpeaCalTrainFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("wxSpeaCal (Train)\n\nAditya Arie Nugraha\narie@aanugraha.web.id"));
    wxMessageBox(msg, _("About"));
}

void wxSpeaCalTrainFrame::OnCreateNewTrainingSetFile(wxCommandEvent& event)
{
    char    strDataBuffer[1024];

    wxFileDialog* createFileDialog =
		new wxFileDialog( this, _("Create New Training Set File"),
                   wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr,
                   wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	if (createFileDialog->ShowModal() == wxID_OK)
	{
        FILE    *pTrainingSetFile, *pNormTrainingSetFile;

        wxstrTrainingSetFile = createFileDialog->GetPath();
        wxstrNeuralNetFile = wxstrTrainingSetFile + wxT(".net");
        wxTrainingSetFile->ChangeValue(wxstrTrainingSetFile);
        wxNeuralNetFile->ChangeValue(wxstrNeuralNetFile);
        strncpy(chTrainingSetFile, (const char*) wxstrTrainingSetFile.ToUTF8(), 1023);
        strcpy(chNormTrainingSetFile, chTrainingSetFile);
        strcat(chNormTrainingSetFile, ".norm");

        pTrainingSetFile     = fopen(chTrainingSetFile, "w");
        pNormTrainingSetFile = fopen(chNormTrainingSetFile, "w");

        if(pTrainingSetFile == NULL || pNormTrainingSetFile == NULL)
        {
            wxMessageBox(wxString::Format(wxT("Could not create file(s).")));
            wxstrTrainingSetFile = wxT("");
            strcpy(chTrainingSetFile, "");
            strcpy(chNormTrainingSetFile, "");
        }
        else
        {
            sprintf(strDataBuffer, "0\t%d\t%d\n", ANN_INPUT_NUM, ANN_OUTPUT_NUM);
            fputs(strDataBuffer, pTrainingSetFile);
            sprintf(strDataBuffer, "0\t%d\t%d\n", ANN_INPUT_NUM, ANN_OUTPUT_NUM);
            fputs(strDataBuffer, pNormTrainingSetFile);
            fclose(pTrainingSetFile);
            fclose(pNormTrainingSetFile);
        }

        strcat(chTrainingSetFile, ".test");
        strcat(chNormTrainingSetFile, ".test");

        pTrainingSetFile     = fopen(chTrainingSetFile, "w");
        pNormTrainingSetFile = fopen(chNormTrainingSetFile, "w");

        if(pTrainingSetFile == NULL || pNormTrainingSetFile == NULL)
        {
            wxMessageBox(wxString::Format(wxT("Could not create file(s).")));
            wxstrTrainingSetFile = wxT("");
            strcpy(chTrainingSetFile, "");
            strcpy(chNormTrainingSetFile, "");
        }
        else
        {
            sprintf(strDataBuffer, "0\t%d\t%d\n", ANN_INPUT_NUM, ANN_OUTPUT_NUM);
            fputs(strDataBuffer, pTrainingSetFile);
            sprintf(strDataBuffer, "0\t%d\t%d\n", ANN_INPUT_NUM, ANN_OUTPUT_NUM);
            fputs(strDataBuffer, pNormTrainingSetFile);
            fclose(pTrainingSetFile);
            fclose(pNormTrainingSetFile);
        }

        strncpy(chTrainingSetFile, (const char*) wxstrTrainingSetFile.ToUTF8(), 1023);
        strcpy(chNormTrainingSetFile, chTrainingSetFile);
        strcat(chNormTrainingSetFile, ".norm");
    }
}

void wxSpeaCalTrainFrame::OnMenuNormTDOASelected(wxCommandEvent& event)
{
    pubMenuNormTDOA = MenuNormTDOA->IsChecked();
}

void wxSpeaCalTrainFrame::OnRecordButtonClick(wxCommandEvent& event)
{
    OnRecord();
}

void wxSpeaCalTrainFrame::OnRecord(void)
{
    wxRecDuration->GetValue().ToDouble(&recDuration);
    pubFramesPerBuffer = SAMPLE_RATE * recDuration;

    if (!pubPAStreamRun)
    {
        gettimeofday(&pubStartTime, NULL);

        err = paNoError;

        err = Pa_Initialize();
        if(err != paNoError) OnPAError();

        for(i=0; i<RECORD_THREADS; i++)
        {
            pPARecThreadData[i].mainThread = this;
            pPARecThreadData[i].inputParameters = (PaStreamParameters *) malloc(sizeof(PaStreamParameters));
            pPARecThreadData[i].inputParameters->device = FIRST_MIC_ID+i;
            if (pPARecThreadData[i].inputParameters->device == paNoDevice)
            {
                fprintf(stderr,"Error: Specified input device unavailable.\n");
                OnPAError();
            }
            else
            {
                printf("inputParameters[%d] device = %s\n",
                       i, Pa_GetDeviceInfo(pPARecThreadData[i].inputParameters->device)->name);
                pPARecThreadData[i].inputParameters->channelCount = NUM_CHANNELS;
                pPARecThreadData[i].inputParameters->sampleFormat = PA_SAMPLE_TYPE;
                pPARecThreadData[i].inputParameters->suggestedLatency = Pa_GetDeviceInfo(pPARecThreadData[i].inputParameters->device)->defaultLowInputLatency;
                pPARecThreadData[i].inputParameters->hostApiSpecificStreamInfo = NULL;
            }
        }

        for(i=0; i<NUM_TDOA; i++)
        {
            pubTDOAValue[i] = 0;
            pubNormTDOAValue[i] = 0;
        }
        pubElapsedTime       = 0;
        pubBufFileID         = 0;
        pubXcorrFileID       = 0;
        pubXcorrReadyFlag[0] = 0;
        pubXcorrReadyFlag[1] = 0;
        pubMenuNormTDOA      = MenuNormTDOA->IsChecked();

        pthread_create(&tdoaComputeThread, NULL, xcorr_thread, (void *) this);

        pubPAStreamRun      = 1;

        for(i=0; i<RECORD_THREADS; i++)
        {
            //pubAbsAmplitudeMean[i] = 0;
            pthread_create(&recordThread[i], NULL, pa_record_thread, (void *) &pPARecThreadData[i]);
        }

        StopRunningThread();
    }
}

void wxSpeaCalTrainFrame::OnIdle(wxIdleEvent& evt)
{
    usleep(200000); // .2 sec; 5fps

    // Update tampilan data TDOA
    //wxElapsedTime->ChangeValue(wxString::Format(wxT("%.3f"), pubElapsedTime));

    if(pubMenuNormTDOA)
    {
        wxTDOA1Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[0]));
        wxTDOA2Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[1]));
        wxTDOA3Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[2]));
        wxTDOA4Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[3]));
        wxTDOA5Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[4]));
        wxTDOA6Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[5]));
    }
    else
    {
        wxTDOA1Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[0]));
        wxTDOA2Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[1]));
        wxTDOA3Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[2]));
        wxTDOA4Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[3]));
        wxTDOA5Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[4]));
        wxTDOA6Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[5]));
    }

    evt.RequestMore(); // render continuously, not only once on idle
}

void wxSpeaCalTrainFrame::OnPAError(void)
{
    StopRunningThread();
}

void wxSpeaCalTrainFrame::StopRunningThread(void)
{
    if(pubPAStreamRun)
    {
        for(i=0; i<RECORD_THREADS; i++)
        {
            if (recordThread[i])
                pthread_join(recordThread[i], NULL);
            free(pPARecThreadData[i].inputParameters);
        }
        Pa_Terminate();
        while (!pubXcorrFileID) {}
        if (tdoaComputeThread)
            pthread_cancel(tdoaComputeThread);
        pubPAStreamRun = 0;
    }
}

int wxSpeaCalTrainFrame::TimevalDiff (struct timeval *result, struct timeval *x, struct timeval *y)
{
    // Perform the carry for the later subtraction by updating y.
    if(x->tv_usec < y->tv_usec)
    {
        int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
        y->tv_usec -= 1000000 * nsec;
        y->tv_sec += nsec;
    }
    if(x->tv_usec - y->tv_usec > 1000000)
    {
        int nsec = (x->tv_usec - y->tv_usec) / 1000000;
        y->tv_usec += 1000000 * nsec;
        y->tv_sec -= nsec;
    }

    // Compute the time remaining to wait. tv_usec is certainly positive.
    result->tv_sec = x->tv_sec - y->tv_sec;
    result->tv_usec = x->tv_usec - y->tv_usec;

    // Return 1 if result is negative.
    return x->tv_sec < y->tv_sec;
}

wxSpeaCalTrainFrame* TimevalDiff(struct timeval *result, struct timeval *x,
                            struct timeval *y, wxSpeaCalTrainFrame* wxSpeaCal)
{
    wxSpeaCal->TimevalDiff(result, x, y);

    return wxSpeaCal;
}

wxSpeaCalTrainFrame* shintPubAttrCheck(int index, int arrayIndex, wxSpeaCalTrainFrame* wxSpeaCal, short int& result)
{
    // Index:
    //  0 = pubXcorrReadyFlag
    //  1 = pubBufFileID
    //  2 = pubXcorrFileID

    switch(index)
    {
        case 0:
            result = wxSpeaCal->pubXcorrReadyFlag[arrayIndex];
            break;
        case 1:
            result = wxSpeaCal->pubBufFileID;
            break;
        case 2:
            result = wxSpeaCal->pubXcorrFileID;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalTrainFrame* shintPubAttrBitToggle(int index, int arrayIndex, wxSpeaCalTrainFrame* wxSpeaCal, int bitNum)
{
    // Index:
    //  0 = pubXcorrReadyFlag
    //  1 = pubBufFileID
    //  2 = pubXcorrFileID

    switch(index)
    {
        case 0:
            wxSpeaCal->pubXcorrReadyFlag[arrayIndex] ^= 1 << bitNum;
            break;
        case 1:
            wxSpeaCal->pubBufFileID ^= 1 << bitNum;
            break;
        case 2:
            wxSpeaCal->pubXcorrFileID ^= 1 << bitNum;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalTrainFrame* intPubAttrCheck(int index, wxSpeaCalTrainFrame* wxSpeaCal, int& result)
{
    // Index:
    //  0 = pubMenuNormTDOA
    //  1 = pubPAStreamRun
    //  6 = pubFramesPerBuffer

    switch(index)
    {
        case 0:
            result = wxSpeaCal->pubMenuNormTDOA;
            break;
        case 1:
            result = wxSpeaCal->pubPAStreamRun;
            break;
        case 6:
            result = wxSpeaCal->pubFramesPerBuffer;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalTrainFrame* doublePubAttrCheck(int index, int arrayIndex, wxSpeaCalTrainFrame* wxSpeaCal, double& result)
{
    // Index:
    //  3 = pubDevXcorrReadyTime
    // 11 = pubDevRecordStartTime

    switch(index)
    {
        case 3:
            result = wxSpeaCal->pubDevXcorrReadyTime[arrayIndex];
            break;
        case 8:
            result = wxSpeaCal->pubPeakAmplitude[arrayIndex];
            break;
        case 11:
            result = wxSpeaCal->pubDevRecordStartTime[arrayIndex];
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalTrainFrame* doublePubAttrAssign(int index, int arrayIndex, wxSpeaCalTrainFrame* wxSpeaCal, double value)
{
    // Index:
    //  0 = pubXcorrReadyFlag
    //  3 = pubDevXcorrReadyTime
    //  4 = pubTDOAValue
    //  5 = pubElapsedTime
    //  7 = pubNormTDOAValue
    //  8 = pubAbsAmplitudeMean
    //  9 = pubRMSAmplitudeRatio
    // 10 = pubNormRMSAmplitudeRatio
    // 11 = pubDevRecordStartTime
    // 12 = pubPeakAmplitudeRatio
    // 13 = pubNormPeakAmplitudeRatio

    switch(index)
    {
        case 0:
            wxSpeaCal->pubXcorrReadyFlag[arrayIndex] = (short int) value;
            break;
        case 3:
            wxSpeaCal->pubDevXcorrReadyTime[arrayIndex] = value;
            break;
        case 4:
            wxSpeaCal->pubTDOAValue[arrayIndex] = value;
            break;
        case 5:
            wxSpeaCal->pubElapsedTime = value;
            break;
        case 7:
            wxSpeaCal->pubNormTDOAValue[arrayIndex] = value;
            break;
        case 8:
            wxSpeaCal->pubPeakAmplitude[arrayIndex] = value;
            break;
        case 9:
            wxSpeaCal->pubRMSAmplitudeRatio[arrayIndex] = value;
            break;
        case 10:
            wxSpeaCal->pubNormRMSAmplitudeRatio[arrayIndex] = value;
            break;
        case 11:
            wxSpeaCal->pubDevRecordStartTime[arrayIndex] = value;
            break;
        case 12:
            wxSpeaCal->pubPeakAmplitudeRatio[arrayIndex] = value;
            break;
        case 13:
            wxSpeaCal->pubNormPeakAmplitudeRatio[arrayIndex] = value;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalTrainFrame* timevalPubStartTimeCheck(wxSpeaCalTrainFrame* wxSpeaCal, struct timeval& result)
{
    result = wxSpeaCal->pubStartTime;

    return wxSpeaCal;
}

void wxSpeaCalTrainFrame::OnInsertDataButtonClick(wxCommandEvent& event)
{
    OnInsertData();
}

void wxSpeaCalTrainFrame::OnInsertData(void)
{
    char        strDataBuffer[1024];
    char        filename[32];
    int         countLines = 1, countNormLines = 1;
    FILE        *pTrainingSetFile, *pNormTrainingSetFile;
    FILE        *pTempFile, *pNormTempFile;

    if(wxstrTrainingSetFile == wxEmptyString)
    {
        wxMessageBox(wxT("Create/open training set data first."));
    }
    else
    {
        pTrainingSetFile = fopen(chTrainingSetFile, "r");
        pNormTrainingSetFile = fopen(chNormTrainingSetFile, "r");
        if(pTrainingSetFile == NULL || pNormTrainingSetFile == NULL)
        {
            wxMessageBox(wxString::Format(wxT("Could not open file(s).")));
        }
        else
        {
            sprintf(filename, ".tmpTrainingSetFile");
            pTempFile = fopen(filename, "w+");
            sprintf(filename, ".tmpNormTrainingSetFile");
            pNormTempFile = fopen(filename, "w+");

            while((i=fgetc(pTrainingSetFile))!=EOF)
            {
                if (countLines > 1)
                    fputc(i, pTempFile);
                if (i == '\n')
                {
                    countLines++;
                }
            }
            while((i=fgetc(pNormTrainingSetFile))!=EOF)
            {
                if (countNormLines > 1)
                    fputc(i, pNormTempFile);
                if (i == '\n')
                {
                    countNormLines++;
                }
            }

            fclose(pTrainingSetFile);
            fclose(pNormTrainingSetFile);

            pTrainingSetFile = fopen(chTrainingSetFile, "w");
            pNormTrainingSetFile = fopen(chNormTrainingSetFile, "w");

            if(pTrainingSetFile == NULL || pNormTrainingSetFile == NULL)
            {
                wxMessageBox(wxString::Format(wxT("Could not open file(s).")));
            }
            else
            {
                sprintf(strDataBuffer, "%d\t%d\t%d\n", countLines/2, ANN_INPUT_NUM, ANN_OUTPUT_NUM);
                fputs(strDataBuffer, pTrainingSetFile);
                sprintf(strDataBuffer, "%d\t%d\t%d\n", countNormLines/2, ANN_INPUT_NUM, ANN_OUTPUT_NUM);
                fputs(strDataBuffer, pNormTrainingSetFile);

                rewind(pTempFile);
                rewind(pNormTempFile);
                while((i=fgetc(pTempFile))!=EOF)
                    fputc(i, pTrainingSetFile);
                while((i=fgetc(pNormTempFile))!=EOF)
                    fputc(i, pNormTrainingSetFile);

                speakerPosValue[0] = wxAtoi(wxPosXValue->GetValue());
                speakerPosValue[1] = wxAtoi(wxPosYValue->GetValue());
                speakerPosValue[2] = wxAtoi(wxPosZValue->GetValue());

                sprintf(strDataBuffer, "%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n%d\t%d\t%d\n",
                        pubTDOAValue[0], pubTDOAValue[1], pubTDOAValue[2],
                        pubTDOAValue[3], pubTDOAValue[4], pubTDOAValue[5],
                        //pubRMSAmplitudeRatio[0], pubRMSAmplitudeRatio[1],
                        //pubRMSAmplitudeRatio[2], pubRMSAmplitudeRatio[3],
                        //pubRMSAmplitudeRatio[4], pubRMSAmplitudeRatio[5],
                        20*log10(pubPeakAmplitudeRatio[0]), 20*log10(pubPeakAmplitudeRatio[1]),
                        20*log10(pubPeakAmplitudeRatio[2]), 20*log10(pubPeakAmplitudeRatio[3]),
                        20*log10(pubPeakAmplitudeRatio[4]), 20*log10(pubPeakAmplitudeRatio[5]),
                        20*log10(pubPeakAmplitude[0]), 20*log10(pubPeakAmplitude[1]),
                        20*log10(pubPeakAmplitude[2]), 20*log10(pubPeakAmplitude[3]),
                        speakerPosValue[0], speakerPosValue[1], speakerPosValue[2]);
                fputs(strDataBuffer, pTrainingSetFile);

                sprintf(strDataBuffer, "%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n%d\t%d\t%d\n",
                        pubNormTDOAValue[0], pubNormTDOAValue[1], pubNormTDOAValue[2],
                        pubNormTDOAValue[3], pubNormTDOAValue[4], pubNormTDOAValue[5],
                        //pubNormRMSAmplitudeRatio[0], pubNormRMSAmplitudeRatio[1],
                        //pubNormRMSAmplitudeRatio[2], pubNormRMSAmplitudeRatio[3],
                        //pubNormRMSAmplitudeRatio[4], pubNormRMSAmplitudeRatio[5],
                        20*log10(pubNormPeakAmplitudeRatio[0]), 20*log10(pubNormPeakAmplitudeRatio[1]),
                        20*log10(pubNormPeakAmplitudeRatio[2]), 20*log10(pubNormPeakAmplitudeRatio[3]),
                        20*log10(pubNormPeakAmplitudeRatio[4]), 20*log10(pubNormPeakAmplitudeRatio[5]),
                        20*log10(pubPeakAmplitude[0]), 20*log10(pubPeakAmplitude[1]),
                        20*log10(pubPeakAmplitude[2]), 20*log10(pubPeakAmplitude[3]),
                        speakerPosValue[0], speakerPosValue[1], speakerPosValue[2]);
                fputs(strDataBuffer, pNormTrainingSetFile);

                fclose(pNormTrainingSetFile);
                fclose(pTrainingSetFile);
            }
            fclose(pNormTempFile);
            fclose(pTempFile);

            sprintf(filename, ".tmpTrainingSetFile");
            remove(filename);
            sprintf(filename, ".tmpNormTrainingSetFile");
            remove(filename);
        }
    }
}

void wxSpeaCalTrainFrame::OnOpenTrainingSetFile(wxCommandEvent& event)
{
    wxFileDialog* createFileDialog =
		new wxFileDialog( this, _("Open Training Set File"),
                   wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr,
                   wxFD_OPEN, wxDefaultPosition);

	if (createFileDialog->ShowModal() == wxID_OK)
	{
        wxstrTrainingSetFile = createFileDialog->GetPath();
        wxstrNeuralNetFile = wxstrTrainingSetFile + wxT(".net");
        wxTrainingSetFile->ChangeValue(wxstrTrainingSetFile);
        wxNeuralNetFile->ChangeValue(wxstrNeuralNetFile);
        strncpy(chTrainingSetFile, (const char*) wxstrTrainingSetFile.ToUTF8(), 1023);
        strcpy(chNormTrainingSetFile, chTrainingSetFile);
        strcat(chNormTrainingSetFile, ".norm");
    }
}

void wxSpeaCalTrainFrame::OnCreateNeuralNetButtonClick(wxCommandEvent& event)
{
    char                    chTestSetFile[1024], chNeuralNetFile[1024], extNeuralNetFile[1024];
    const unsigned int      num_layers = 3;
    const unsigned int      num_neurons_hidden_1 = 16;
    const unsigned int      num_neurons_hidden_2 = 8;
    const float             desired_error = (const float) 0.0001;
    unsigned int            max_epochs = 100000;
    const unsigned int      epochs_between_reports = 1000;
    struct fann             *ann;
    struct fann_train_data  *train_data, *test_data;
    unsigned int            i = 0, loopCount = 0;
    float                   MSE;

    train_data = fann_read_train_from_file(chTrainingSetFile);

    do {
    ann = fann_create_standard(num_layers, train_data->num_input,
                               num_neurons_hidden_1,
                               //num_neurons_hidden_2,
                               train_data->num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_LINEAR);

    fprintf(stdout, "Training network.\n");
    fann_train_on_data(ann, train_data, max_epochs,
                       epochs_between_reports, desired_error);
    max_epochs += 10000;
    } while(fann_get_MSE(ann) > desired_error);

    printf("Testing network.\n");
    strcpy(chTestSetFile, chTrainingSetFile);
    strcat(chTestSetFile, ".test");
    fprintf(stdout, "Test Data: %s\n", chTestSetFile);
    test_data = fann_read_train_from_file(chTestSetFile);

    fann_reset_MSE(ann);
    for(i = 0; i < fann_length_train_data(test_data); i++)
    {
        fann_test(ann, test_data->input[i], test_data->output[i]);
    }
    MSE = fann_get_MSE(ann);
    printf("MSE error on test data: %f\n", MSE);

    /*strcat(chTestSetFile, ".all");
    fprintf(stdout, "Test Data: %s\n", chTestSetFile);
    test_data = fann_read_train_from_file(chTestSetFile);

    fann_reset_MSE(ann);
    for(i = 0; i < fann_length_train_data(test_data); i++)
    {
        fann_test(ann, test_data->input[i], test_data->output[i]);
    }
    MSE = fann_get_MSE(ann);
    printf("MSE error on test data: %f\n", MSE);*/

    printf("Saving network.\n");
    strncpy(chNeuralNetFile, (const char*) wxNeuralNetFile->GetValue().ToUTF8(), 1023);
    fann_save(ann, chNeuralNetFile);

    fann_print_parameters(ann);
    fann_get_train_error_function(ann);
    fann_get_train_stop_function(ann);
    fann_get_bit_fail_limit(ann);
    fann_get_quickprop_decay(ann);
    fann_get_quickprop_mu(ann);
    fann_get_rprop_increase_factor(ann);
    fann_get_rprop_decrease_factor(ann);
    fann_get_rprop_delta_min(ann);
    fann_get_rprop_delta_min(ann);
    fann_get_rprop_delta_max(ann);
    fann_get_rprop_delta_zero(ann);

    fann_destroy_train(train_data);
    fann_destroy_train(test_data);
    fann_destroy(ann);
}

void wxSpeaCalTrainFrame::OnPlayBuf1ButtonClick(wxCommandEvent& event)
{
    OnPlayBuffer("dev-2-buf-rec-0.raw");
}

void wxSpeaCalTrainFrame::OnPlayBuf2ButtonClick(wxCommandEvent& event)
{
    OnPlayBuffer("dev-3-buf-rec-0.raw");
}

void wxSpeaCalTrainFrame::OnPlayBuf3ButtonClick(wxCommandEvent& event)
{
    OnPlayBuffer("dev-4-buf-rec-0.raw");
}

void wxSpeaCalTrainFrame::OnPlayBuf4ButtonClick(wxCommandEvent& event)
{
    OnPlayBuffer("dev-5-buf-rec-0.raw");
}

void wxSpeaCalTrainFrame::OnPlayBuffer(const char* filename)
{
    err = Pa_Initialize();
    if(err != paNoError) OnPAError();

    pPAPlayThreadData.mainThread = this;
    sprintf(pPAPlayThreadData.filename, "%s", filename);

    pthread_create(&playbackThread, NULL, pa_play_thread, (void *) &pPAPlayThreadData);
    pthread_join(playbackThread, NULL);

    Pa_Terminate();
}

void wxSpeaCalTrainFrame::OnSuperTrainingButtonClick(wxCommandEvent& event)
{
    char    oldFilename[FILENAME_MAX], newFilename[FILENAME_MAX];
    char    filename[FILENAME_MAX], strDataBuffer[1024];
    char    txFilename[FILENAME_MAX];
    FILE    *fid;
    int     i, j, k;

    sprintf(txFilename, "FAW_7B");

    if(wxstrTrainingSetFile == wxEmptyString)
    {
        wxMessageBox(wxT("Create/open training set data first."));
    }
    else
    {
        speakerPosValue[0] = wxAtoi(wxPosXValue->GetValue());
        speakerPosValue[1] = wxAtoi(wxPosYValue->GetValue());
        speakerPosValue[2] = wxAtoi(wxPosZValue->GetValue());

        sprintf(filename, "%s_%+d%+d%+d.log",
                txFilename,
                (speakerPosValue[0]-10) / 60 - 1,
                (speakerPosValue[1] / 60 + 2),
                (speakerPosValue[2] / 30)
                );
        fid = fopen(filename, "w");

        for(i=0; i<8; i++)
        {
            fprintf(stdout, ">>> Training Set [%d]\n", i+1);
            OnRecord();
            OnInsertData();
            for (j = 2; j <= 5; j++)
            {
                sprintf(oldFilename, "dev-%d-buf-rec-0.raw", j);
                sprintf(newFilename, "%s_%+d%+d%+d_%d_%d.raw",
                        txFilename,
                        (speakerPosValue[0]-10) / 60 - 1,
                        (speakerPosValue[1] / 60 + 2),
                        (speakerPosValue[2] / 30),
                        i, j);
                rename(oldFilename, newFilename);
            }
            sprintf(strDataBuffer, "--- %s\n", newFilename);
            fputs(strDataBuffer, fid);
            for (j = 0; j < RECORD_THREADS; j++)
            {
                sprintf(strDataBuffer, "[%d]\t%f\t%f\n",
                        j + FIRST_MIC_ID, pubDevRecordStartTime[j], pubDevXcorrReadyTime[j]);
                fputs(strDataBuffer, fid);
            }
            //usleep(100000);
        }
        strcat(chTrainingSetFile, ".test");
        strcat(chNormTrainingSetFile, ".test");
        for(k=0; k<2; k++)
        {
            fprintf(stdout, ">>> Testing Set [%d]\n", k+1);
            OnRecord();
            OnInsertData();
            for (j = 2; j <= 5; j++)
            {
                sprintf(oldFilename, "dev-%d-buf-rec-0.raw", j);
                sprintf(newFilename, "%s_%+d%+d%+d_%d_%d.raw",
                        txFilename,
                        (speakerPosValue[0]-10) / 60 - 1,
                        (speakerPosValue[1] / 60 + 2),
                        (speakerPosValue[2] / 30),
                        i+k, j);
                rename(oldFilename, newFilename);
            }
            sprintf(strDataBuffer, "--- %s\n", newFilename);
            fputs(strDataBuffer, fid);
            for (j = 0; j < RECORD_THREADS; j++)
            {
                sprintf(strDataBuffer, "[%d]\t%f\t%f\n",
                        j + FIRST_MIC_ID, pubDevRecordStartTime[j], pubDevXcorrReadyTime[j]);
                fputs(strDataBuffer, fid);
            }
            //usleep(100000);
        }
        strncpy(chTrainingSetFile, (const char*) wxstrTrainingSetFile.ToUTF8(), 1023);
        strcpy(chNormTrainingSetFile, chTrainingSetFile);
        strcat(chNormTrainingSetFile, ".norm");

        fclose(fid);
        fprintf(stdout, "--- SuperTraining Finished!\n");
    }
}
