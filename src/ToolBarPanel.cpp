#include "ToolBarPanel.h"
#include "Config.h"

ToolBarPanel::ToolBarPanel(wxWindow* parent, const int ID)
    : wxPanel(parent, ID, wxDefaultPosition)
{
    // Set the tool buttons.
    m_sobel = new wxButton(this, TOOL_SOBEL, "Sobel", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);

    // Set sizer.
    m_sizer = new wxBoxSizer(wxHORIZONTAL);
    m_sizer->Add(m_sobel, 0, wxALIGN_LEFT | wxTOP, 10);

    this->SetSizer(m_sizer);
    m_sizer->SetSizeHints(this);

    this->SetAutoLayout(true);
}

ToolBarPanel::~ToolBarPanel()
{

}