#include "Canvas.h"
#include "Config.h"

#include <wx/event.h>
#include <wx/dcclient.h>

// Ref: https://wxwidgets.info/getting_aquainted_with_doc_view_architecture_part_3_en/

Canvas::Canvas(wxWindow* parent, const int ID, wxPoint pos, wxSize size)
	: wxScrolledCanvas(parent, ID, pos, size, wxHSCROLL | wxVSCROLL | wxSUNKEN_BORDER | wxFULL_REPAINT_ON_RESIZE)
{
    this->EnableScrolling(true, true);

    // Bind event.
    this->Bind(wxEVT_PAINT, &Canvas::OnPaint, this);
    this->Bind(wxEVT_SIZE, &Canvas::OnSize, this);
    // wxEVT_SCROLLBAR is deprecated
    this->Bind(wxEVT_SCROLLWIN_THUMBRELEASE, &Canvas::OnScroll, this);
    this->Bind(wxEVT_SCROLLWIN_THUMBRELEASE, &Canvas::OnScroll, this);
    this->Bind(wxEVT_SCROLLWIN_LINEUP, &Canvas::OnScroll, this);
    this->Bind(wxEVT_SCROLLWIN_LINEDOWN, &Canvas::OnScroll, this);
}

Canvas::~Canvas() {}

void Canvas::SetImage(wxImage& in)
{
    // Set scroll bar.
    this->SetVirtualSize(in.GetWidth(), in.GetHeight());
    this->SetScrollbars(10, 10, in.GetWidth() / 10, in.GetHeight() / 10);
    this->ShowScrollbars(wxSHOW_SB_DEFAULT, wxSHOW_SB_DEFAULT);

    m_image = in;
    this->Refresh();
}

void Canvas::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    //wxBufferedPaintDC  dc(this);
    this->Render(dc);
}

void Canvas::PaintNow()
{
    wxClientDC dc(this);
    this->Render(dc);
}

void Canvas::Render(wxDC& dc)
{
    dc.Clear();
    int w, h;
    dc.GetSize(&w, &h);
    if (m_image.GetWidth() > w && m_image.GetHeight() > h) {
        dc.DrawBitmap(m_image, 0, 0, false);
    }
    else {
        int centerX = w / 2 - m_image.GetWidth() / 2;
        int centerY = h / 2 - m_image.GetHeight() / 2;
        dc.DrawBitmap(m_image, centerX, centerY, false);
    }
}

void Canvas::OnSize(wxSizeEvent& event)
{
    this->PaintNow();
}

void Canvas::OnScroll(wxScrollWinEvent& event)
{
    this->AdjustVirtualSize();
    event.Skip();
}

void Canvas::Sobel()
{

}

