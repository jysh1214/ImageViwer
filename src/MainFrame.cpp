#include <wx/wx.h>

#include "MainFrame.h"

MainFrame::MainFrame(const wxString title, const int ID)
    : wxFrame((wxFrame*)nullptr, ID, title, wxDefaultPosition, wxDefaultSize)
{
    // Make a menubar.
    m_menuBar = new MainMenuBar();
    SetMenuBar(m_menuBar);

    this->Connect(OPEN_FILE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MainFrame::OnOpenFile));
    this->Connect(EXIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MainFrame::OnExit));
}

MainFrame::~MainFrame()
{
   
}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}