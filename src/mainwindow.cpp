#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <chrono>
#include <fstream>
#include <QDir>
#include <QDebug>

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

    // Çalışma dizinini ayarlayın
    QDir::setCurrent("/Users/dilaratuzuner/Desktop/NUWA_PEN/");
    qDebug() << "Current working directory: " << QDir::currentPath();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage(const QString &filePath, QLabel *label)
{
    QPixmap pixmap(filePath);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image: " << filePath;
    }
    label->setPixmap(pixmap);
}

void MainWindow::clearResults()
{
    ui->binaryImageLabel->clear();
    ui->decompressedImageLabel->clear();
    ui->outputTextEdit->clear();
}

void MainWindow::on_selectImageButton1_clicked()
{
    selectedImagePath = "images/Assignment1_1.jpg";
    loadImage(selectedImagePath, ui->originalImageLabel);
    clearResults(); // Eski sonuçları temizle
}

void MainWindow::on_selectImageButton2_clicked()
{
    selectedImagePath = "images/Assignment1_2.jpg";
    loadImage(selectedImagePath, ui->originalImageLabel);
    clearResults(); // Eski sonuçları temizle
}

void MainWindow::on_selectImageButton3_clicked()
{
    selectedImagePath = "images/Assignment1_3.jpg";
    loadImage(selectedImagePath, ui->originalImageLabel);
    clearResults(); // Eski sonuçları temizle
}

void MainWindow::on_selectImageButton4_clicked()
{
    selectedImagePath = "images/Assignment1_4.jpg";
    loadImage(selectedImagePath, ui->originalImageLabel);
    clearResults(); // Eski sonuçları temizle
}

void MainWindow::on_processButton_clicked()
{
    if (selectedImagePath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select an image first.");
        return;
    }
    processImage();
}

void MainWindow::processImage()
{
    ui->loadingLabel->setVisible(true);
    QCoreApplication::processEvents();

    cv::Mat image = cv::imread(selectedImagePath.toStdString());

    if (image.empty()) {
        QMessageBox::critical(this, "Error", "Could not open or find the image.");
        ui->loadingLabel->setVisible(false);
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    cv::Mat binaryImage = imageProcessor.binarize(image);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    ui->outputTextEdit->append("Binarization time: " + QString::number(duration.count()) + " seconds");

    start = std::chrono::high_resolution_clock::now();
    std::vector<uint8_t> compressedData = compressor.compress(binaryImage);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    ui->outputTextEdit->append("Compression time: " + QString::number(duration.count()) + " seconds");

    QString compressedFilePath = "outputs/compressed.bin";
    std::ofstream outFile(compressedFilePath.toStdString(), std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size());
    outFile.close();

    start = std::chrono::high_resolution_clock::now();
    cv::Mat decompressedImage = compressor.decompress(compressedData, binaryImage.rows, binaryImage.cols);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    ui->outputTextEdit->append("Decompression time: " + QString::number(duration.count()) + " seconds");

    QString binaryImagePath = "outputs/binary_image.png";
    QString decompressedImagePath = "outputs/decompressed_image.png";
    cv::imwrite(binaryImagePath.toStdString(), binaryImage);
    cv::imwrite(decompressedImagePath.toStdString(), decompressedImage);

    // Mean Squared Error Hesaplama
    cv::Mat diff;
    cv::absdiff(binaryImage, decompressedImage, diff);
    diff.convertTo(diff, CV_32F);
    diff = diff.mul(diff);
    double mse = cv::sum(diff)[0] / (binaryImage.total());
    ui->outputTextEdit->append("Mean Squared Error: " + QString::number(mse));

    loadImage(binaryImagePath, ui->binaryImageLabel);
    loadImage(decompressedImagePath, ui->decompressedImageLabel);

    ui->loadingLabel->setVisible(false);
}
