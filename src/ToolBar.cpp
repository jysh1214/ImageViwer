#include "ToolBar.h"
#include "Config.h"

ToolBar::ToolBar(wxWindow* parent, const int ID)
    : wxPanel(parent, ID, wxDefaultPosition)
{
    // Set sizer.
    m_sizer = new wxBoxSizer(wxHORIZONTAL);
    m_sizer->Add(m_sobel, 0, wxALIGN_LEFT | wxTOP, 10);

    SetSizer(m_sizer);
    m_sizer->SetSizeHints(this);

    SetAutoLayout(true);
}

ToolBar::~ToolBar() {}

void ToolBar::OnTool(wxCommandEvent& event)
{
    event.Skip();
}