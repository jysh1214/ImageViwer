#ifndef IMAGE_TYPE_H
#define IMAGE_TYPE_H

#include <cstdint>
#include <memory>

#include <wx/image.h>
#include <wx/bitmap.h>
#include <opencv2/core.hpp>

cv::Mat wxImg2cvMat(const wxImage& src, const int channel)
{
    //cv::Mat dst(cv::Size(src.GetWidth(), src.GetHeight()), CV_8UC3, src.GetData());
    //cv::cvtColor(dst, dst, cv::COLOR_RGB2BGR);



    return dst;
}

wxImage cvMat2wxImg(const cv::Mat& src)
{
    //void* mdata = malloc((size_t)(src.dataend - src.datastart));
    //std::memcpy(mdata, src.data, (size_t)(src.dataend - src.datastart));

    uint8_t* data = (uint8_t*)malloc(src.dataend - src.datastart);
    std::memcpy(data, src.data, src.dataend - src.datastart);

    return wxImage(src.cols, src.rows, data, false);
}

#endif