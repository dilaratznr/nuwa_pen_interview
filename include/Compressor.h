#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <vector>
#include <opencv2/opencv.hpp>

class Compressor {
public:
    std::vector<uint8_t> compress(const cv::Mat& binaryImage);
    cv::Mat decompress(const std::vector<uint8_t>& compressedData, int rows, int cols);
};

#endif // COMPRESSOR_H
