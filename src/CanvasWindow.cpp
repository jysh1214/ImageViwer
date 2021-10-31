#include "CanvasWindow.h"
#include "Config.h"

#include <wx/sizer.h>

CanvasWindow::CanvasWindow(wxWindow* parent, const int ID)
    : wxScrolledWindow(parent, ID, wxDefaultPosition, wxDefaultSize)
{
    int canvasW, camvasH;
    this->GetSize(&canvasW, &camvasH);
    m_canvasPanel = new CanvasPanel(this, CANVAS_PANEL, wxDefaultPosition, wxSize(canvasW, camvasH));

    // Set sizer.
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_canvasPanel, 1, wxEXPAND);
    this->SetSizer(sizer);
}

CanvasWindow::~CanvasWindow() {}

void CanvasWindow::SetImage(wxImage in)
{
    m_canvasPanel->SetImage(in);
}