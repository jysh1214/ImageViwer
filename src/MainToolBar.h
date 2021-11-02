#ifndef MAIN_TOOL_BAR_H
#define MAIN_TOOL_BAR_H

#include <wx/toolbar.h>

class MainToolBar: public wxToolBar
{
public:
	MainToolBar(wxWindow* parent, const int ID);
	virtual ~MainToolBar();

private:
};

#endif