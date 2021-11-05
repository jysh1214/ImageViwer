#include "Canvas.h"
#include "Config.h"

#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

// Ref: https://wxwidgets.info/getting_aquainted_with_doc_view_architecture_part_3_en/

// Ref: https://gist.github.com/PBfordev/45bee180f6cbee6c1948a1a9813a2f27

Canvas::Canvas(wxWindow* parent, const int ID, wxPoint pos, wxSize size)
	: wxScrolledCanvas(parent, ID, pos, size, wxHSCROLL | wxVSCROLL | wxRETAINED | wxFULL_REPAINT_ON_RESIZE)
{
    this->EnableScrolling(true, true);

    // Bind event.
    this->Bind(wxEVT_PAINT, &Canvas::OnPaint, this);
    this->Bind(wxEVT_SIZE, &Canvas::OnSize, this);
    this->Bind(wxEVT_SCROLLWIN_LINEUP, &Canvas::OnScroll, this);
    this->Bind(wxEVT_SCROLLWIN_LINEDOWN, &Canvas::OnScroll, this);
    this->Bind(wxEVT_SCROLLWIN_TOP, &Canvas::OnScroll, this);
    this->Bind(wxEVT_SCROLLWIN_BOTTOM, &Canvas::OnScroll, this);
}

Canvas::~Canvas() 
{
    m_image.Destroy();
}

void Canvas::SetImage(wxImage& in)
{
    m_image = in;
    m_imageW = m_image.GetWidth();
    m_imageH = m_image.GetHeight();

    // Set scroll bar.
    this->SetVirtualSize(m_imageW, m_imageH);
    this->SetScrollbars(m_imageW / 100, m_imageH / 100, 100, 100);
    m_scrollUintX = m_imageW / 100;
    m_scrollUintY = m_imageH / 100;
    this->ShowScrollbars(wxSHOW_SB_DEFAULT, wxSHOW_SB_DEFAULT);

    this->Refresh();
}

void Canvas::OnPaint(wxPaintEvent& event)
{   
    wxPaintDC dc(this);
    DoPrepareDC(dc);
    this->OnDraw(dc);
}

void Canvas::PaintNow()
{
    wxClientDC dc(this);
    DoPrepareDC(dc);
    this->OnDraw(dc);
}

void Canvas::OnDraw(wxDC& dc)
{
    int w, h;
    dc.GetSize(&w, &h);
    if (m_imageW > w && m_imageH > h) {
        this->GetViewStart(&m_currentX, &m_currentY);
        dc.SetDeviceOrigin(-m_currentX * m_scrollUintX, -m_currentY * m_scrollUintY);
        dc.DrawBitmap(wxBitmap(m_image), 0, 0, false);
    }
    else {
        int centerX = w / 2 - m_imageW / 2;
        int centerY = h / 2 - m_imageH / 2;
        dc.DrawBitmap(wxBitmap(m_image), centerX, centerY, false);
    }
}

void Canvas::OnSize(wxSizeEvent& event)
{
    this->PaintNow();
}

void Canvas::OnScroll(wxScrollWinEvent& event)
{
    this->PaintNow();
}

void Canvas::Sobel()
{

}
