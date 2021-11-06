#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>

#include "MainMenuBar.h"
#include "ToolBarPanel.h"
#include "Canvas.h"

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString title, const int ID);
    virtual ~MainFrame();

    void OnOpenFile(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

    void Sobel(wxCommandEvent& event);

private:
    MainMenuBar* m_menuBar = nullptr;
    ToolBarPanel* m_toolBar = nullptr;
    Canvas* m_canvas = nullptr;
};

#endif
