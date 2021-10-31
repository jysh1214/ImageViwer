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
    void OnExit(wxCommandEvent& event);

private:
    MainMenuBar* m_menuBar = nullptr;
    CanvasWindow* m_canvas = nullptr;
};

#endif
