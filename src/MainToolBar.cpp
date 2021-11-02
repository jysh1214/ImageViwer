#include "MainToolBar.h"
#include "Config.h"

#include <wx/wx.h>
#include <wx/artprov.h>

MainToolBar::MainToolBar(wxWindow* parent, const int ID)
	: wxToolBar(parent, ID, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL)
{
	// Set tool options.
	this->AddTool(TOOL_SOBEL, "Sobel", wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR));
	this->Realize();
}

MainToolBar::~MainToolBar()
{

}
