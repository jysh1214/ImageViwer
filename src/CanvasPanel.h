#ifndef CANVAS_PANEL_H
#define CANVAS_PANEL_H

#include <wx/panel.h>
#include <wx/image.h>
#include <wx/bitmap.h>

class CanvasPanel: public wxPanel
{
public:
	CanvasPanel(wxWindow* parent, const int ID, wxPoint pos, wxSize size);
	virtual ~CanvasPanel();

	void SetImage(wxImage& in);
	void OnPaint(wxPaintEvent& event);
	void PaintNow();
	void Render(wxDC& dc);
	void OnSize(wxSizeEvent& event);

private:
	wxBitmap m_bitmap;
};

#endif