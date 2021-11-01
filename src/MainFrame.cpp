#include <wx/wx.h>
#include <wx/event.h>
#include <wx/filedlg.h>
#include <wx/image.h>
#include <string>

#include "MainFrame.h"

// Ref: https://zetcode.com/gui/wxwidgets/layoutmanagement/

namespace
{
    static wxString supportImageRegex = "Image files.(*.bmp,*.jpg,*.png)|*.bmp;*.jpg;*.png";
}

MainFrame::MainFrame(const wxString title, const int ID)
    : wxFrame((wxFrame*)nullptr, ID, title, wxDefaultPosition, wxDefaultSize)
{
    // Make a menubar.
    m_menuBar = new MainMenuBar();
    SetMenuBar(m_menuBar);

    // Menu event.
    this->Connect(OPEN_FILE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MainFrame::OnOpenFile));
    this->Connect(EXIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)(&MainFrame::OnExit));

    // Canvas
    int frameW, frameH;
    this->GetSize(&frameW, &frameH);
    m_canvas = new CanvasWindow(this, CANVAS_WINDOW, wxSize(frameW, frameH));
    m_canvas->Show(true);

    // Set sizer.
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(m_canvas, 1, wxEXPAND);
    this->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);
}

MainFrame::~MainFrame() {}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, "Open file", wxEmptyString, wxEmptyString, supportImageRegex, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() != wxID_OK) {
        return;
    }

    wxImage in(openFileDialog.GetPath());
    m_canvas->SetImage(in);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}