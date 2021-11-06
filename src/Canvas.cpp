#include "Canvas.h"
#include "Config.h"

#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

// Ref: https://gist.github.com/PBfordev/45bee180f6cbee6c1948a1a9813a2f27

Canvas::Canvas(wxWindow* parent, const int ID, wxPoint pos, wxSize size)
	: wxScrolledCanvas(parent, ID, pos, size, wxHSCROLL | wxVSCROLL | wxRETAINED | wxFULL_REPAINT_ON_RESIZE)
{
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);

    // Bind event.
    this->Bind(wxEVT_PAINT, &Canvas::OnPaint, this);
    this->Bind(wxEVT_SIZE, &Canvas::OnSize, this);
}

Canvas::~Canvas() 
{

}

bool Canvas::SetImage(wxImage& in)
{
    m_bitmap = wxBitmap(in);

    if (!m_bitmap.IsOk()) {
        return false;
    }

    m_bitmapW = m_bitmap.GetWidth();
    m_bitmapH = m_bitmap.GetHeight();

    // Set scroll bar.
    this->SetVirtualSize(m_bitmapW, m_bitmapH);
    this->SetScrollbars(m_bitmapW / 100, m_bitmapH / 100, 100, 100);
    m_scrollUintX = m_bitmapW / 100;
    m_scrollUintY = m_bitmapH / 100;
    this->ShowScrollbars(wxSHOW_SB_DEFAULT, wxSHOW_SB_DEFAULT);
    this->EnableScrolling(true, true);

    this->Refresh();
    this->Update();

    return true;
}

void Canvas::OnPaint(wxPaintEvent& event)
{   
    wxClientDC client(this);
    int canvasW, canvasH;
    client.GetSize(&canvasW, &canvasH);

    Render(canvasW, canvasH);
}

void Canvas::OnSize(wxSizeEvent& event)
{
    wxClientDC client(this);
    int canvasW, canvasH;
    client.GetSize(&canvasW, &canvasH);

    Render(canvasW, canvasH);
}

void Canvas::Render(const int canvasW, const int canvasH)
{
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    if (m_bitmapW > canvasW && m_bitmapH > canvasH) {
        wxRect bitmapVisibleRect;
        wxBitmap visibleBitmap;
        this->GetViewStart(&m_currentX, &m_currentY);
        bitmapVisibleRect.SetTopLeft(wxPoint(m_currentX * m_scrollUintX, m_currentY * m_scrollUintY));
        bitmapVisibleRect.SetWidth(canvasW);
        bitmapVisibleRect.SetHeight(canvasH);
        visibleBitmap = m_bitmap.GetSubBitmap(bitmapVisibleRect);

        dc.DrawBitmap(visibleBitmap, 0, 0, true);
    }
    else {
        int centerX = canvasW / 2 - m_bitmapW / 2;
        int centerY = canvasH / 2 - m_bitmapH / 2;
        dc.DrawBitmap(m_bitmap, centerX, centerY, false);
    }
}

void Canvas::Sobel()
{

}
