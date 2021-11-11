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
    wxImage GetImage() const;
    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnZoom(wxCommandEvent& event);
    

    void Sobel();

private:
    void Render(const int canvasW, const int canvasH);

    wxImage m_image = wxNullImage;
    wxBitmap m_bitmap = wxNullBitmap;
    float m_zoom = 1.0f;
    int m_bitmapW = -1;
    int m_bitmapH = -1;
    int m_scrollUintX = 0;
    int m_scrollUintY = 0;
    int m_currentX = -1;
    int m_currentY = -1;
};

#endif