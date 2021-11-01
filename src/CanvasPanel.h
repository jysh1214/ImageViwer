#ifndef CANVAS_PANEL_H
#define CANVAS_PANEL_H

#include <wx/panel.h>
#include <wx/image.h>

class CanvasPanel: public wxPanel
{
public:
	CanvasPanel(wxWindow* parent, const int ID, wxPoint pos, wxSize size);
	virtual ~CanvasPanel();

	void SetImage(wxImage& in);
	void PaintEvent(wxPaintEvent& event);
	void Render(wxDC& dc);

private:
	wxImage m_image;
	DECLARE_EVENT_TABLE()
};

#endif