#ifndef MAIN_MENU_BAR_H
#define MAIN_MENU_BAR_H

#include <wx/menu.h>
#include <wx/event.h>

#include "Config.h"

class MainMenuBar: public wxMenuBar
{
public:
	MainMenuBar();
	virtual ~MainMenuBar();

	void OnOpenFile(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);

private:
	wxMenu* m_fileMenu = nullptr;
};

#endif