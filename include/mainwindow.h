#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <opencv2/opencv.hpp>
#include <vector>
#include "Compressor.h"
#include "ImageProcessor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
        void on_selectImageButton1_clicked();
    void on_selectImageButton2_clicked();
    void on_selectImageButton3_clicked();
    void on_selectImageButton4_clicked();
    void on_processButton_clicked();
    void clearResults();

private:
    Ui::MainWindow *ui;
    Compressor compressor;
    ImageProcessor imageProcessor;
    QString selectedImagePath;

    void loadImage(const QString &filePath, QLabel *label);
    void processImage();
};

#endif // MAINWINDOW_H
