#ifndef IMAGE_VIWER_H
#define IMAGE_VIWER_H

#include <wx/wx.h>

class ImageViwer: public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
    virtual int OnExit() wxOVERRIDE;
   
private:
};

#endif
