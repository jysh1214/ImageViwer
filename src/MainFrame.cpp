#include <wx/wx.h>

#include "MainFrame.h"

MainFrame::MainFrame(const wxChar* title, const int ID)
    : wxFrame((wxFrame*)nullptr, ID, title, wxDefaultPosition, wxDefaultSize)
{
    // Make a menubar.
    m_menuBar = new MainMenuBar();
    SetMenuBar(m_menuBar);
}

MainFrame::~MainFrame()
{
   
}