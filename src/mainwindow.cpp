#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <chrono>
#include <fstream>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->selectImageButton1, &QPushButton::clicked, this, &MainWindow::on_selectImageButton1_clicked);
    connect(ui->selectImageButton2, &QPushButton::clicked, this, &MainWindow::on_selectImageButton2_clicked);
    connect(ui->selectImageButton3, &QPushButton::clicked, this, &MainWindow::on_selectImageButton3_clicked);
    connect(ui->selectImageButton4, &QPushButton::clicked, this, &MainWindow::on_selectImageButton4_clicked);
    connect(ui->processButton, &QPushButton::clicked, this, &MainWindow::on_processButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage(const QString &filePath)
{
    QPixmap pixmap(filePath);
    ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
    selectedFilePath = filePath;
}

void MainWindow::on_selectImageButton1_clicked()
{
    loadImage("../images/Assignment1_1.jpg");
}

void MainWindow::on_selectImageButton2_clicked()
{
    loadImage("../images/Assignment1_2.jpg");
}

void MainWindow::on_selectImageButton3_clicked()
{
    loadImage("../images/Assignment1_3.jpg");
}

void MainWindow::on_selectImageButton4_clicked()
{
    loadImage("../images/Assignment1_4.jpg");
}

void MainWindow::on_processButton_clicked()
{
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a file first.");
        return;
    }

    cv::Mat image = cv::imread(selectedFilePath.toStdString());

    if (image.empty()) {
        QMessageBox::critical(this, "Error", "Could not open or find the image.");
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    cv::Mat binaryImage = processor.binarize(image);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    ui->outputTextEdit->append("Binarization time: " + QString::number(duration.count()) + " seconds");

    start = std::chrono::high_resolution_clock::now();
    std::vector<uint8_t> compressedData = compressor.compress(binaryImage);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    ui->outputTextEdit->append("Compression time: " + QString::number(duration.count()) + " seconds");

    std::string compressedFilePath = "compressed.bin";
    std::ofstream outFile(compressedFilePath, std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size());
    outFile.close();

    start = std::chrono::high_resolution_clock::now();
    cv::Mat decompressedImage = compressor.decompress(compressedData, binaryImage.rows, binaryImage.cols);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    ui->outputTextEdit->append("Decompression time: " + QString::number(duration.count()) + " seconds");

    std::string binaryImagePath = "binary_image.png";
    std::string decompressedImagePath = "decompressed_image.png";
    cv::imwrite(binaryImagePath, binaryImage);
    cv::imwrite(decompressedImagePath, decompressedImage);

    double mse = cv::norm(binaryImage, decompressedImage, cv::NORM_L2);
    mse = mse * mse / (binaryImage.total());
    ui->outputTextEdit->append("Mean Squared Error: " + QString::number(mse));
}
