/***************************************************************
 * Name:      wxSpeaCalTrainApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aditya Arie Nugraha (arie@aanugraha.web.id)
 * Created:   2011-04-30
 * Copyright: Aditya Arie Nugraha (http://blog.aanugraha.web.id)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSpeaCalTrainApp.h"

//(*AppHeaders
#include "wxSpeaCalTrainMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxSpeaCalTrainApp);

bool wxSpeaCalTrainApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxSpeaCalTrainFrame* Frame = new wxSpeaCalTrainFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
