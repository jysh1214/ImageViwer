#include "ToolBar.h"
#include "Config.h"

ToolBar::ToolBar(wxWindow* parent, const int ID)
    : wxPanel(parent, ID, wxDefaultPosition)
{
    // Set the tool buttons.
    m_sobel = new wxButton(this, SOBEL, "Sobel", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT | wxBORDER_NONE);

    // Bind event.
    this->Bind(wxEVT_BUTTON, &ToolBar::Sobel, this, SOBEL);

    // Set sizer.
    m_sizer = new wxBoxSizer(wxHORIZONTAL);
    m_sizer->Add(m_sobel, 0, wxALIGN_LEFT | wxTOP, 10);

    this->SetSizer(m_sizer);
    m_sizer->SetSizeHints(this);

    this->SetAutoLayout(true);
}

ToolBar::~ToolBar() {}

void ToolBar::Sobel(wxCommandEvent& event)
{
    event.Skip();
}