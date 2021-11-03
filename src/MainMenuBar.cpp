#include "MainMenuBar.h"

#include <iostream>

MainMenuBar::MainMenuBar(): wxMenuBar()
{
	// File
	m_fileMenu = new wxMenu();
	m_fileMenu->Append(OPEN_FILE, "Open file", "Open file");
	m_fileMenu->Connect(OPEN_FILE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MainMenuBar::OnOpenFile));
	m_fileMenu->Append(EXIT, "Exit", "Exit");
	m_fileMenu->Connect(EXIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MainMenuBar::OnExit));

	// Append to main menu.
	this->Append(m_fileMenu, "File");
}

MainMenuBar::~MainMenuBar() {}

void MainMenuBar::OnOpenFile(wxCommandEvent& event)
{
	event.Skip();
}

void MainMenuBar::OnExit(wxCommandEvent& event)
{
	event.Skip();
}