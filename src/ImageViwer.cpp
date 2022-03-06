#include <wx/app.h>

#include "Config.h"
#include "ImageViwer.h"

wxIMPLEMENT_APP(ImageViwer);

bool ImageViwer::OnInit()
{
    if (!wxApp::OnInit()) {
        return false;
    }

    wxInitAllImageHandlers();

    MainFrame* frame = new MainFrame("FUCK", MAIN_FRAME);
    frame->Maximize();
    frame->Show(true);
    SetTopWindow(frame);

    return true;
}

int ImageViwer::OnExit()
{
    return 0;
}
