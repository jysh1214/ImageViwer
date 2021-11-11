#include "ToolBar.h"
#include "Config.h"

ToolBar::ToolBar(wxWindow* parent, const int ID)
    : wxPanel(parent, ID, wxDefaultPosition)
{
    // Set the tool buttons.
    m_sobel = new wxButton(this, SOBEL, "Sobel", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT | wxBORDER_NONE);

    // Bind event.
    Bind(wxEVT_BUTTON, &ToolBar::Sobel, this, SOBEL);

    // Set sizer.
    m_sizer = new wxBoxSizer(wxHORIZONTAL);
    m_sizer->Add(m_sobel, 0, wxALIGN_LEFT | wxTOP, 10);

    SetSizer(m_sizer);
    m_sizer->SetSizeHints(this);

    SetAutoLayout(true);
}

ToolBar::~ToolBar() {}

void ToolBar::Sobel(wxCommandEvent& event)
{
    event.Skip();
}

void ToolBar::OnTool(wxCommandEvent& event)
{
    event.Skip();
}