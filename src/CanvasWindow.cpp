#include "CanvasWindow.h"
#include "Config.h"

#include <wx/sizer.h>

CanvasWindow::CanvasWindow(wxWindow* parent, const int ID, wxSize size)
    : wxScrolledWindow(parent, ID, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL)
{
    int canvasW, canvasH;
    this->GetSize(&canvasW, &canvasH);

    m_canvasPanel = new CanvasPanel(this, CANVAS_PANEL, wxDefaultPosition, wxSize(canvasW, canvasH));

    // Set sizer.
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_canvasPanel, 1, wxEXPAND);
    this->SetSizer(sizer);
}

CanvasWindow::~CanvasWindow() {}

void CanvasWindow::SetImage(wxImage& in)
{
    m_canvasPanel->SetImage(in);
}

void CanvasWindow::Sobel()
{
    this->m_canvasPanel->Sobel();
}