#include "MainMenuBar.h"

wxDEFINE_EVENT(wxEVT_WAIT_COMMAND, wxCommandEvent);

enum
{
    OPEN_FILE_MENU = 1,
};

BEGIN_EVENT_TABLE(MainMenuBar, wxMenuBar)
END_EVENT_TABLE()

MainMenuBar::MainMenuBar(): wxMenuBar()
{
	// File menu.
	m_fileMenu = new wxMenu();
	m_fileMenu->Append(wxID_OPEN, "Open file", "Open file");

	// Append to main menu.
	this->Append(m_fileMenu, "File");
}

MainMenuBar::~MainMenuBar() {}