#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include "ImageProcessor.h"
#include "Compressor.h"

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image_directory>" << std::endl;
        return -1;
    }

    std::string imageDirectory = argv[1];
    std::string outputDirectory = "../outputs";  // Ensure this path is relative to your build directory

    // Check if the output directory exists, if not, create it
    if (!fs::exists(outputDirectory)) {
        fs::create_directory(outputDirectory);
    }

    std::cout << "Processing images in directory: " << imageDirectory << std::endl;

    ImageProcessor processor;
    Compressor compressor;

    int imageIndex = 1;

    for (const auto& entry : fs::directory_iterator(imageDirectory)) {
        std::string imagePath = entry.path().string();
        std::cout << "Processing image: " << imagePath << std::endl;
        cv::Mat image = cv::imread(imagePath);

        if (image.empty()) {
            std::cerr << "Could not open or find the image: " << imagePath << std::endl;
            continue;
        }

        auto start = std::chrono::high_resolution_clock::now();
        cv::Mat binaryImage = processor.binarize(image);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Binarization time for " << imagePath << ": " << duration.count() << " seconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        std::vector<uint8_t> compressedData = compressor.compress(binaryImage);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Compression time for " << imagePath << ": " << duration.count() << " seconds" << std::endl;

        std::string compressedFilePath = outputDirectory + "/compressed_" + std::to_string(imageIndex) + ".bin";
        std::ofstream outFile(compressedFilePath, std::ios::binary);
        outFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size());
        outFile.close();

        start = std::chrono::high_resolution_clock::now();
        cv::Mat decompressedImage = compressor.decompress(compressedData, binaryImage.rows, binaryImage.cols);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Decompression time for " << imagePath << ": " << duration.count() << " seconds" << std::endl;

        std::string binaryImagePath = outputDirectory + "/binary_image_" + std::to_string(imageIndex) + ".png";
        std::string decompressedImagePath = outputDirectory + "/decompressed_image_" + std::to_string(imageIndex) + ".png";
        cv::imwrite(binaryImagePath, binaryImage);
        cv::imwrite(decompressedImagePath, decompressedImage);

        double mse = cv::norm(binaryImage, decompressedImage, cv::NORM_L2);
        mse = mse * mse / (binaryImage.total());
        std::cout << "Mean Squared Error for " << imagePath << ": " << mse << std::endl;

        imageIndex++;
    }

    return 0;
}
