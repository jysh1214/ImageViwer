#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>

#include "MainMenuBar.h"

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxChar* title, const int ID);
    virtual ~MainFrame();

private:
    MainMenuBar* m_menuBar = nullptr;
};

#endif
