#include "MenuBar.h"

#include <iostream>

MenuBar::MenuBar(): wxMenuBar()
{
    // File
    m_fileMenu = new wxMenu();
    m_fileMenu->Append(OPEN_FILE, "Open &file\tCtrl-O");
    m_fileMenu->Append(SAVE_FILE, "Save &file\tCtrl-S");
    m_fileMenu->Append(EXIT, "Exit\tCtrl-Q");
    m_fileMenu->Connect(OPEN_FILE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MenuBar::OnOpenFile));
    m_fileMenu->Connect(SAVE_FILE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MenuBar::OnSaveFile));
    m_fileMenu->Connect(EXIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MenuBar::OnQuit));

    // View
    m_viewMenu = new wxMenu();
    m_viewMenu->Append(wxID_ZOOM_IN, "Zoom &in\tCtrl-+");
    m_viewMenu->Append(wxID_ZOOM_OUT, "Zoom &out\tCtrl--");
    m_viewMenu->Connect(wxID_ZOOM_IN, wxEVT_MENU, (wxObjectEventFunction)(&MenuBar::OnZoom));
    m_viewMenu->Connect(wxID_ZOOM_OUT, wxEVT_MENU, (wxObjectEventFunction)(&MenuBar::OnZoom));

    // Append to main menu.
    Append(m_fileMenu, "File");
    Append(m_viewMenu, "View");
}

MenuBar::~MenuBar() {}

void MenuBar::OnOpenFile(wxCommandEvent& event)
{
    event.Skip();
}

void MenuBar::OnSaveFile(wxCommandEvent& event)
{
    event.Skip();
}

void MenuBar::OnQuit(wxCommandEvent& event)
{
    event.Skip();
}

void MenuBar::OnZoom(wxCommandEvent& event)
{
    event.Skip();
}
