#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>

#include "MainMenuBar.h"
#include "ToolBarPanel.h"
#include "CanvasWindow.h"

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString title, const int ID);
    virtual ~MainFrame();

    void OnOpenFile(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

    void SetImage(wxImage& in);
    void Sobel(wxCommandEvent& event);

private:
    MainMenuBar* m_menuBar = nullptr;
    ToolBarPanel* m_toolBar = nullptr;
    CanvasWindow* m_canvasWindow = nullptr;
};

#endif
