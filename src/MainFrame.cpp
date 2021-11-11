#include <wx/wx.h>
#include <wx/event.h>
#include <wx/filedlg.h>
#include <wx/image.h>
#include <string>

#include "MainFrame.h"

namespace
{
    static wxString supportImageRegex = "Image files.(*.jpg;*.png;*.tga;*.bmp;*.tiff;*.gif;*.ico;*.pcx)| *.jpg;*.png;*.tga;*.bmp;*.tiff;*.gif;*.ico;*.pcx";
    
    wxString getFormat(wxString str)
    {
        wxString format;
        for (int i = str.size(); i > 0; --i) {
            if (str[i] == '.') {
                format = str.substr(i, str.size() - i);
            }
        }

        return format;
    }
    
    static bool saveImage(const wxImage& in, wxString path)
    {
        wxString format = getFormat(path);
        if (format == ".bmp") {
            in.SaveFile(path, wxBITMAP_TYPE_BMP);
            return true;
        }
        if (format == ".jpeg") {
            in.SaveFile(path, wxBITMAP_TYPE_JPEG);
            return true;
        }
        if (format == ".png") {
            in.SaveFile(path, wxBITMAP_TYPE_PNG);
            return true;
        }
        if (format == ".pcx") {
            in.SaveFile(path, wxBITMAP_TYPE_PCX);
            return true;
        }
        if (format == ".pnm") {
            in.SaveFile(path, wxBITMAP_TYPE_PNM);
            return true;
        }
        if (format == ".tiff") {
            in.SaveFile(path, wxBITMAP_TYPE_TIFF);
            return true;
        }
        if (format == ".xpm") {
            in.SaveFile(path, wxBITMAP_TYPE_XPM);
            return true;
        }
        if (format == ".ico") {
            in.SaveFile(path, wxBITMAP_TYPE_ICO);
            return true;
        }
        if (format == ".cur") {
            in.SaveFile(path, wxBITMAP_TYPE_CUR);
            return true;
        }
        else {
            return false;
        }
    }
}

MainFrame::MainFrame(const wxString title, const int ID)
    : wxFrame((wxFrame*)nullptr, ID, title, wxDefaultPosition, wxDefaultSize)
{
    // Make a menubar.
    m_menuBar = new MenuBar();
    this->SetMenuBar(m_menuBar);

    // Make a toolbar.
    m_toolBar = new ToolBar(this, TOOL_BAR);

    // Make a canvas window.
    int frameW, frameH;
    GetSize(&frameW, &frameH);
    m_canvas = new Canvas(this, CANVAS, wxDefaultPosition, wxSize(frameW, frameH));
    m_canvas->Show(true);

    // Make a status bar.
    CreateStatusBar(1);
    SetStatusText(wxT("Copyright@2020 Alex J."), 0);

    // Layout
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(m_toolBar, 0, wxEXPAND, 20);
    mainSizer->Add(m_canvas, 1, wxEXPAND | wxALL);
    SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    // Bind event.
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnOpenFile, this, OPEN_FILE);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSaveFile, this, SAVE_FILE);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnQuit, this, EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnZoom, this, wxID_ZOOM_IN);
    Bind(wxEVT_MENU, &MainFrame::OnZoom, this, wxID_ZOOM_OUT);
}

MainFrame::~MainFrame() {}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, wxT("Open file"), wxEmptyString, wxEmptyString, supportImageRegex, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() != wxID_OK) {
        return;
    }

    wxImage in(openFileDialog.GetPath());
    m_canvas->SetImage(in);
    SetStatusText(wxT("Current Path: " + openFileDialog.GetPath()), 0);
}

void MainFrame::OnSaveFile(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, wxT("Save Image"), wxEmptyString, wxEmptyString, supportImageRegex, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() != wxID_OK) {
        return;
    }

    const wxImage image = this->GetImage();
    if (saveImage(image, saveFileDialog.GetPath())) {
        SetStatusText(wxT("Save Succeed."), 0);
    }
    else {
        wxLogMessage(wxT("Save Fail."));
    }
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
    m_canvas->Close(true);
    m_canvas->Destroy();

    this->Close(true);
    this->Destroy();
}

void MainFrame::OnZoom(wxCommandEvent& event)
{
    m_canvas->OnZoom(event);
}

void MainFrame::OnClose(wxCloseEvent& event)
{
    m_canvas->Close(true);
    m_canvas->Destroy();

    this->Close(true);
    this->Destroy();
}

void MainFrame::OnMouseWheel(wxMouseEvent& event)
{
    m_wheelRotation = event.GetWheelRotation();
}

wxImage MainFrame::GetImage() const
{
    return m_canvas->GetImage();
}

void MainFrame::Sobel(wxCommandEvent& event)
{
    m_canvas->Sobel();
}

