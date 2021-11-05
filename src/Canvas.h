#ifndef CANVAS_PANEL_H
#define CANVAS_PANEL_H

#include <wx/scrolwin.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

class Canvas: public wxScrolledCanvas
{
public:
	Canvas(wxWindow* parent, const int ID, wxPoint pos, wxSize size);
	virtual ~Canvas();

	void SetImage(wxImage& in);
	void OnPaint(wxPaintEvent& event);
	void PaintNow();
	void OnDraw(wxDC& dc);
	void OnSize(wxSizeEvent& event);
	void OnScroll(wxScrollWinEvent& event);

	void Sobel();

private:
	wxImage m_image;
	int m_imageW;
	int m_imageH;
	int m_scrollUintX;
	int m_scrollUintY;
	int m_currentX;
	int m_currentY;
};

#endif