#include <wx/wx.h>
#include <wx/event.h>
#include <wx/filedlg.h>
#include <wx/image.h>
#include <string>

#include "MainFrame.h"

namespace
{
    static wxString supportImageRegex = "Image files.(*.jpg;*.png;*.tga;*.bmp;*.tiff;*.gif;*.ico;*.pcx)| *.jpg;*.png;*.tga;*.bmp;*.tiff;*.gif;*.ico;*.pcx";
}

MainFrame::MainFrame(const wxString title, const int ID)
    : wxFrame((wxFrame*)nullptr, ID, title, wxDefaultPosition, wxDefaultSize)
{
    // Make a menubar.
    m_menuBar = new MainMenuBar();
    this->SetMenuBar(m_menuBar);

    // Make a toolbar.
    m_toolBar = new ToolBarPanel(this, MAIN_TOOL_BAR);

    // Make a canvas window.
    int frameW, frameH;
    this->GetSize(&frameW, &frameH);
    m_canvas = new Canvas(this, CANVAS_WINDOW, wxDefaultPosition, wxSize(frameW, frameH));
    m_canvas->Show(true);

    // Layout
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(m_toolBar, 0, wxEXPAND, 20);
    mainSizer->Add(m_canvas, 1, wxEXPAND | wxALL);
    this->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    // Bind event.
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnOpenFile, this, OPEN_FILE);
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnQuit, this, EXIT);

    this->Bind(wxEVT_BUTTON, &MainFrame::Sobel, this, SOBEL);
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

void MainFrame::OnQuit(wxCommandEvent& event)
{
    this->Close(true);
}

void MainFrame::OnClose(wxCloseEvent& event)
{
    this->Close(true);
}

void MainFrame::Sobel(wxCommandEvent& event)
{
    m_canvas->Sobel();
}