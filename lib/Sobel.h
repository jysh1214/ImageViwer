#ifndef SOBEL_H
#define SOBEL_H

#include <wx/image.h>
#include <wx/bitmap.h>
#include <opencv2/core.hpp>

wxBitmap Sobel(const wxBitmap* bitmap)
{
	int channel = bitmap->GetDepth();
	wxImage image = bitmap->ConvertToImage();

	return wxBitmap(image);
}

#endif