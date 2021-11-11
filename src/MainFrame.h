#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>

#include "MenuBar.h"
#include "ToolBar.h"
#include "Canvas.h"

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString title, const int ID);
    virtual ~MainFrame();

    void OnOpenFile(wxCommandEvent& event);
    void OnSaveFile(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnZoom(wxCommandEvent& event);

    void OnMouseWheel(wxMouseEvent& event);

    wxImage GetImage() const;
    void OnTool(wxCommandEvent& event);

private:
    MenuBar* m_menuBar = nullptr;
    ToolBar* m_toolBar = nullptr;
    Canvas* m_canvas = nullptr;

    int m_wheelRotation = 0;
};

#endif
