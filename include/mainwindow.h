#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ImageProcessor.h"
#include "Compressor.h"

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

private:
    Ui::MainWindow *ui;
    QString selectedFilePath;
    ImageProcessor processor;
    Compressor compressor;

    void loadImage(const QString &filePath);
};

#endif // MAINWINDOW_H
