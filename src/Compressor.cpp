#include "Compressor.h"

std::vector<uint8_t> Compressor::compress(const cv::Mat& binaryImage) {
    std::vector<uint8_t> compressedData;
    for (int i = 0; i < binaryImage.rows; ++i) {
        for (int j = 0; j < binaryImage.cols; ++j) {
            compressedData.push_back(binaryImage.at<uint8_t>(i, j) ? 1 : 0);
        }
    }
    return compressedData;
}

cv::Mat Compressor::decompress(const std::vector<uint8_t>& compressedData, int rows, int cols) {
    cv::Mat binaryImage(rows, cols, CV_8UC1);
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            binaryImage.at<uint8_t>(i, j) = compressedData[index++] ? 255 : 0;
        }
    }
    return binaryImage;
}
