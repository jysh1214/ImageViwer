#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>

class ToolBar: public wxPanel
{
public:
	ToolBar(wxWindow* parent, const int ID);
	virtual ~ToolBar();

	void Sobel(wxCommandEvent& event);

private:
	wxBoxSizer* m_sizer = nullptr;
	wxButton* m_sobel = nullptr;
};

#endif