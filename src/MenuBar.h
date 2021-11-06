#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <wx/menu.h>
#include <wx/event.h>

#include "Config.h"

class MenuBar: public wxMenuBar
{
public:
    MenuBar();
    virtual ~MenuBar();

    void OnOpenFile(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);

    void OnZoom(wxCommandEvent& event);

private:
    wxMenu* m_fileMenu = nullptr;
    wxMenu* m_viewMenu = nullptr;
};

#endif