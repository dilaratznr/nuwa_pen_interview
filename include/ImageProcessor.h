#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
    cv::Mat binarize(const cv::Mat& image);
};

#endif // IMAGEPROCESSOR_H
