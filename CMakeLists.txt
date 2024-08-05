cmake_minimum_required(VERSION 3.28)
project(NUWA_PEN)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include ${CMAKE_BINARY_DIR})

# Qt
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.7.0_1/lib/cmake")
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Qt wrapping
qt6_wrap_cpp(MOC_FILES include/mainwindow.h)
qt6_wrap_ui(UI_FILES src/mainwindow.ui)

# Source files
set(SOURCES
        src/main.cpp
        src/Compressor.cpp
        src/ImageProcessor.cpp
        src/mainwindow.cpp
        ${MOC_FILES}
        ${UI_FILES}
)

# Add executable
add_executable(NUWA_PEN ${SOURCES})

# Link libraries
target_link_libraries(NUWA_PEN Qt6::Widgets ${OpenCV_LIBS})

# OpenCV
set(OpenCV_DIR /usr/local/Cellar/opencv/4.10.0_2/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(NUWA_PEN ${OpenCV_LIBS})
