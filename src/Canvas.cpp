#include "Canvas.h"
#include "Config.h"

#include <algorithm>
#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/menu.h>

// Ref: https://gist.github.com/PBfordev/45bee180f6cbee6c1948a1a9813a2f27
// Ref: https://github.com/habisoft/ImageViewer

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
    m_image.Destroy();
}

bool Canvas::SetImage(wxImage& in)
{
    m_image = in;
    m_bitmap = wxBitmap(in);

    if (!m_bitmap.IsOk()) {
        return false;
    }

    m_bitmapW = m_bitmap.GetWidth();
    m_bitmapH = m_bitmap.GetHeight();

    m_zoom = 1.f;

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
    if (!m_image.IsOk()) return;

    wxClientDC client(this);
    int canvasW, canvasH;
    client.GetSize(&canvasW, &canvasH);

    Render(canvasW, canvasH);
}

void Canvas::Render(int canvasW, int canvasH)
{
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();
    dc.SetUserScale((double)m_zoom, (double)m_zoom);

    // Adjust client size.
    canvasW = dc.DeviceToLogicalX(canvasW);
    canvasH = dc.DeviceToLogicalY(canvasH);

    this->GetViewStart(&m_currentX, &m_currentY);
    wxRect roi;
    wxPoint currentPosition(
        dc.DeviceToLogicalX(m_currentX * m_scrollUintX), 
        dc.DeviceToLogicalY(m_currentY * m_scrollUintY)
    );
    roi.SetTopLeft(currentPosition);
    roi.SetWidth(std::min(canvasW, static_cast<int>(dc.DeviceToLogicalX(m_bitmapW * m_zoom))));
    roi.SetHeight(std::min(canvasH, static_cast<int>(dc.DeviceToLogicalY(m_bitmapH * m_zoom))));
    wxBitmap visibleBitmap;
    visibleBitmap = m_bitmap.GetSubBitmap(roi);

    int centerX = std::max(0, canvasW / 2 - dc.DeviceToLogicalX(m_bitmapW * m_zoom) / 2);
    int centerY = std::max(0, canvasH / 2 - dc.DeviceToLogicalY(m_bitmapH * m_zoom) / 2);
    
    dc.DrawBitmap(visibleBitmap, centerX, centerY, true);

    this->Refresh();
}

void Canvas::OnZoom(wxCommandEvent& event)
{
    if (!m_image.IsOk()) return;

    if (event.GetId() == wxID_ZOOM_IN) {
        m_zoom = (m_zoom + 0.1f > 10.0f) ? 10.0f : (m_zoom + 0.1f);
    }
    else if (event.GetId() == wxID_ZOOM_OUT) {
        m_zoom = (m_zoom - 0.1f < 0.1f) ? 0.1f : (m_zoom - 0.1f);
    }

    wxClientDC client(this);
    int canvasW, canvasH;
    client.GetSize(&canvasW, &canvasH);

    int virtualX = static_cast<int>(floorf(m_bitmapW * m_zoom) - ceil(2 * m_scrollUintX * m_zoom));
    int virtualY = static_cast<int>(floorf(m_bitmapH * m_zoom) - ceil(2 * m_scrollUintY * m_zoom));

    // Reset scroll rate.
    this->SetVirtualSize(virtualX, virtualY);
    
    Render(canvasW, canvasH);
    //this->Refresh();
    //this->Update();
}

void Canvas::Sobel()
{
    
}
