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

	bool SetImage(wxImage& in);
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);

	void Sobel();

private:
	void Render(const int canvasW, const int canvasH);

	wxBitmap m_bitmap = wxNullBitmap;
	int m_bitmapW;
	int m_bitmapH;
	int m_scrollUintX;
	int m_scrollUintY;
	int m_currentX;
	int m_currentY;
};

#endif