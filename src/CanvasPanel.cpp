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
    //m_bitmap = wxBitmap(in);
    m_image = in;
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
    int w, h;
    dc.GetSize(&w, &h);
    int centerX = w / 2 - m_image.GetWidth() / 2;
    int centerY = h / 2 - m_image.GetHeight() / 2;
    dc.DrawBitmap(m_image, centerX, centerY, false);
}

void CanvasPanel::OnSize(wxSizeEvent& event)
{
    this->PaintNow();
}

void CanvasPanel::Sobel()
{

}