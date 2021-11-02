#ifndef TOOL_BAR_PANEL_H
#define TOOL_BAR_PANEL_H

#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>

class ToolBarPanel: public wxPanel
{
public:
	ToolBarPanel(wxWindow* parent, const int ID);
	virtual ~ToolBarPanel();

private:
	wxBoxSizer* m_sizer = nullptr;
	wxButton* m_sobel = nullptr;
};

#endif