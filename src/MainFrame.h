#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>

#include "MainMenuBar.h"
#include "CanvasWindow.h"

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString title, const int ID);
    virtual ~MainFrame();

    void OnOpenFile(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);

private:
    MainMenuBar* m_menuBar = nullptr;
    CanvasWindow* m_canvasWindow = nullptr;
};

#endif
