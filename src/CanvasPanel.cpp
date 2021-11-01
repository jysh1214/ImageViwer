#include "CanvasPanel.h"
#include "Config.h"

#include <wx/event.h>
#include <wx/dcclient.h>

CanvasPanel::CanvasPanel(wxWindow* parent, const int ID, wxPoint pos, wxSize size)
	: wxPanel(parent, ID, pos, size)
{
    // Bind event.
    this->Bind(wxEVT_PAINT, &CanvasPanel::OnPaint, this);
    this->Bind(wxEVT_SIZE, &CanvasPanel::OnSize, this);
}

CanvasPanel::~CanvasPanel() {}

void CanvasPanel::SetImage(wxImage& in)
{
    m_bitmap = wxBitmap(in);
    this->Refresh();
}

void CanvasPanel::OnPaint(wxPaintEvent& event)
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
    dc.Clear();
    //this->SetBackgroundColour(wxColour(*wxWHITE));
    int newW, newH;
    dc.GetSize(&newW, &newH);
    int centerX = newW / 2 - m_bitmap.GetWidth() / 2;
    int centerY = newH / 2 - m_bitmap.GetHeight() / 2;

    dc.DrawBitmap(m_bitmap, centerX, centerY, false);
}

void CanvasPanel::OnSize(wxSizeEvent& event)
{
    PaintNow();
}