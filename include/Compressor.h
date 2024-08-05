#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <opencv2/opencv.hpp>
#include <vector>

class Compressor
{
public:
    std::vector<uint8_t> compress(const cv::Mat &image);
    cv::Mat decompress(const std::vector<uint8_t> &data, int rows, int cols);
};

#endif // COMPRESSOR_H
