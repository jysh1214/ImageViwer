#include "CanvasPanel.h"
#include "Config.h"

#include <wx/dcclient.h>

BEGIN_EVENT_TABLE(CanvasPanel, wxPanel)
    EVT_PAINT(CanvasPanel::PaintEvent)
END_EVENT_TABLE()

CanvasPanel::CanvasPanel(wxWindow* parent, const int ID, wxPoint pos, wxSize size)
	: wxPanel(parent, ID, pos, size)
{
    this->Connect(RENDER, wxEVT_PAINT, (wxObjectEventFunction)(&CanvasPanel::PaintEvent));
}

CanvasPanel::~CanvasPanel() {}

void CanvasPanel::SetImage(wxImage in)
{
    m_image = in;
    Refresh();
}

void CanvasPanel::PaintEvent(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    this->Render(dc);
}

void CanvasPanel::PaintNow()
{
    wxClientDC dc(this);
    this->Render(dc);
}

void CanvasPanel::Render(wxDC& dc)
{
    dc.DrawBitmap(wxBitmap(m_image), 0, 0, false);
}