#ifndef CANVAS_WINDOW_H
#define CANVAS_WINDOW_H

#include <wx/vscroll.h>
#include <wx/image.h>

#include "CanvasPanel.h"

// Ref: https://github.com/wxWidgets/wxWidgets/blob/master/samples/image/image.cpp

class CanvasWindow: public wxScrolledWindow
{
public:
	CanvasWindow(wxWindow* parent, const int ID);
	virtual ~CanvasWindow();

	void SetImage(wxImage in);
	void PaintEvent(wxPaintEvent& event);

private:
	CanvasPanel* m_canvasPanel = nullptr;
};

#endif