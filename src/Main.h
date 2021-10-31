#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>

class ImageViwer: public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
    virtual int OnExit() wxOVERRIDE;

private:
    
};

#endif
