
# Image Binarization and Compression

## Overview

This project binarizes and compresses images using OpenCV. It converts grayscale images to binary and compresses them to reduce file size. The codec can also decompress images and calculate the Mean Squared Error (MSE) between original and decompressed images.

## Features

- **Binarization**: Converts grayscale images to binary using Otsu's thresholding.
- **Compression**: Compresses binary images.
- **Decompression**: Reconstructs binary images from compressed data.
- **MSE Calculation**: Evaluates error between original and decompressed images.

## Technologies Used

- **C++**
- **OpenCV**
- **stb_image**

## How to Compile and Run

### Prerequisites

- **C++ Compiler** (e.g., g++, clang)
- **OpenCV**
- **CMake**

### Compilation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/dilaratznr/nuwa_pen_interview.git
    cd nuwa_pen_interview
    git checkout binarization_and_compression
    ```

2. **Build with CMake**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

### Running the Program

1. **Execute**:
    ```sh
    ./NUWA_PEN <path_to_image>
    ```

## File Descriptions

- **ImageProcessor.h / .cpp**: Handles image binarization and MSE calculation.
- **Compressor.h / .cpp**: Manages image compression and decompression.
- **main.cpp**: Main executable logic.
- **mainwindow.h / .cpp / .ui**: GUI component.

## Output
<img width="1277" alt="Ekran Resmi 2024-08-05 13 28 21" src="https://github.com/user-attachments/assets/c69dd7e2-4c18-44df-a6f0-b2985cb847fd">

<img width="1277" alt="Ekran Resmi 2024-08-05 13 28 53" src="https://github.com/user-attachments/assets/ceb67b52-a5fa-4f44-94c4-699d7c362fd6">


