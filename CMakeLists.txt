cmake_minimum_required(VERSION 3.28)
project(NUWA_PEN)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
set(SOURCES
        src/main.cpp
        src/Compressor.cpp
        src/ImageProcessor.cpp
)

# Add executable
add_executable(NUWA_PEN ${SOURCES})

# OpenCV
set(OpenCV_DIR /usr/local/Cellar/opencv/4.10.0_2/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(NUWA_PEN ${OpenCV_LIBS})
