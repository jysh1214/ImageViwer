#include <wx/app.h>

#include "ImageViwer.h"
#include "Main.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(ImageViwer);

bool ImageViwer::OnInit()
{
    if (!wxApp::OnInit()) {
        return false;
    }

    MainFrame* frame = new MainFrame(wxT("FUCK"), MAIN_FRAME_ID);
    frame->Show(true);
    SetTopWindow(frame);

    return true;
}

int ImageViwer::OnExit()
{
    return 0;
}
