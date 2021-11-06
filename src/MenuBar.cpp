#include "MenuBar.h"

#include <iostream>

MenuBar::MenuBar(): wxMenuBar()
{
	// File
	m_fileMenu = new wxMenu();
	m_fileMenu->Append(OPEN_FILE, "Open file", "Open file");
	m_fileMenu->Append(EXIT, "Exit", "Exit");
	m_fileMenu->Connect(OPEN_FILE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MenuBar::OnOpenFile));
	m_fileMenu->Connect(EXIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MenuBar::OnQuit));

	// View
	m_viewMenu = new wxMenu();
	m_viewMenu->Append(wxID_ZOOM_IN, "Zoom &in\tCtrl-+");
	m_viewMenu->Append(wxID_ZOOM_OUT, "Zoom &out\tCtrl--");
	m_viewMenu->Connect(wxID_ZOOM_IN, wxEVT_MENU, (wxObjectEventFunction)(&MenuBar::OnZoom));
	m_viewMenu->Connect(wxID_ZOOM_OUT, wxEVT_MENU, (wxObjectEventFunction)(&MenuBar::OnZoom));

	// Append to main menu.
	this->Append(m_fileMenu, "File");
	this->Append(m_viewMenu, "View");
}

MenuBar::~MenuBar() {}

void MenuBar::OnOpenFile(wxCommandEvent& event)
{
	event.Skip();
}

void MenuBar::OnQuit(wxCommandEvent& event)
{
	event.Skip();
}

void MenuBar::OnZoom(wxCommandEvent& event) // wxZoomGestureEvent
{
	event.Skip();
}
