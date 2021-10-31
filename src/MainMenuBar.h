#ifndef MAIN_MENU_BAR_H
#define MAIN_MENU_BAR_H

#include <wx/menu.h>

class MainMenuBar: public wxMenuBar
{
public:
	MainMenuBar();
	virtual ~MainMenuBar();
private:
	wxMenu* m_fileMenu = nullptr;
	DECLARE_EVENT_TABLE()
};

#endif