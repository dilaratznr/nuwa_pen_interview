/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QPushButton *selectImageButton1;
    QPushButton *selectImageButton2;
    QPushButton *selectImageButton3;
    QPushButton *selectImageButton4;
    QLabel *originalImageLabelTitle;
    QLabel *originalImageLabel;
    QLabel *binaryImageLabelTitle;
    QLabel *binaryImageLabel;
    QLabel *decompressedImageLabelTitle;
    QLabel *decompressedImageLabel;
    QPushButton *processButton;
    QLabel *loadingLabel;
    QTextEdit *outputTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 0, 1300, 50));
        titleLabel->setAlignment(Qt::AlignCenter);
        selectImageButton1 = new QPushButton(centralwidget);
        selectImageButton1->setObjectName("selectImageButton1");
        selectImageButton1->setGeometry(QRect(20, 70, 200, 40));
        selectImageButton2 = new QPushButton(centralwidget);
        selectImageButton2->setObjectName("selectImageButton2");
        selectImageButton2->setGeometry(QRect(20, 120, 200, 40));
        selectImageButton3 = new QPushButton(centralwidget);
        selectImageButton3->setObjectName("selectImageButton3");
        selectImageButton3->setGeometry(QRect(20, 170, 200, 40));
        selectImageButton4 = new QPushButton(centralwidget);
        selectImageButton4->setObjectName("selectImageButton4");
        selectImageButton4->setGeometry(QRect(20, 220, 200, 40));
        originalImageLabelTitle = new QLabel(centralwidget);
        originalImageLabelTitle->setObjectName("originalImageLabelTitle");
        originalImageLabelTitle->setGeometry(QRect(250, 60, 350, 30));
        originalImageLabelTitle->setAlignment(Qt::AlignCenter);
        originalImageLabel = new QLabel(centralwidget);
        originalImageLabel->setObjectName("originalImageLabel");
        originalImageLabel->setGeometry(QRect(250, 90, 350, 300));
        originalImageLabel->setFrameShape(QFrame::Box);
        originalImageLabel->setScaledContents(true);
        binaryImageLabelTitle = new QLabel(centralwidget);
        binaryImageLabelTitle->setObjectName("binaryImageLabelTitle");
        binaryImageLabelTitle->setGeometry(QRect(630, 60, 350, 30));
        binaryImageLabelTitle->setAlignment(Qt::AlignCenter);
        binaryImageLabel = new QLabel(centralwidget);
        binaryImageLabel->setObjectName("binaryImageLabel");
        binaryImageLabel->setGeometry(QRect(630, 90, 350, 300));
        binaryImageLabel->setFrameShape(QFrame::Box);
        binaryImageLabel->setScaledContents(true);
        decompressedImageLabelTitle = new QLabel(centralwidget);
        decompressedImageLabelTitle->setObjectName("decompressedImageLabelTitle");
        decompressedImageLabelTitle->setGeometry(QRect(1010, 60, 350, 30));
        decompressedImageLabelTitle->setAlignment(Qt::AlignCenter);
        decompressedImageLabel = new QLabel(centralwidget);
        decompressedImageLabel->setObjectName("decompressedImageLabel");
        decompressedImageLabel->setGeometry(QRect(1010, 90, 350, 300));
        decompressedImageLabel->setFrameShape(QFrame::Box);
        decompressedImageLabel->setScaledContents(true);
        processButton = new QPushButton(centralwidget);
        processButton->setObjectName("processButton");
        processButton->setGeometry(QRect(600, 410, 200, 40));
        loadingLabel = new QLabel(centralwidget);
        loadingLabel->setObjectName("loadingLabel");
        loadingLabel->setGeometry(QRect(600, 460, 200, 40));
        loadingLabel->setAlignment(Qt::AlignCenter);
        loadingLabel->setVisible(false);
        outputTextEdit = new QTextEdit(centralwidget);
        outputTextEdit->setObjectName("outputTextEdit");
        outputTextEdit->setGeometry(QRect(20, 520, 1260, 350));
        outputTextEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Nuwa Pen Interview - Dilara T\303\274z\303\274ner", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Nuwa Pen Interview - Dilara T\303\274z\303\274ner", nullptr));
        titleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QLabel {\n"
"                        font-weight: bold;\n"
"                        font-size: 20px;\n"
"                        color: #ffffff;\n"
"                        background-color: #4CAF50;\n"
"                        padding: 10px;\n"
"                        }\n"
"                    ", nullptr));
        selectImageButton1->setText(QCoreApplication::translate("MainWindow", "Select Image 1", nullptr));
        selectImageButton1->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QPushButton {\n"
"                        background-color: #4CAF50;\n"
"                        color: white;\n"
"                        border: none;\n"
"                        font-size: 16px;\n"
"                        font-weight: bold;\n"
"                        }\n"
"                        QPushButton:hover {\n"
"                        background-color: #45a049;\n"
"                        }\n"
"                    ", nullptr));
        selectImageButton2->setText(QCoreApplication::translate("MainWindow", "Select Image 2", nullptr));
        selectImageButton2->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QPushButton {\n"
"                        background-color: #4CAF50;\n"
"                        color: white;\n"
"                        border: none;\n"
"                        font-size: 16px;\n"
"                        font-weight: bold;\n"
"                        }\n"
"                        QPushButton:hover {\n"
"                        background-color: #45a049;\n"
"                        }\n"
"                    ", nullptr));
        selectImageButton3->setText(QCoreApplication::translate("MainWindow", "Select Image 3", nullptr));
        selectImageButton3->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QPushButton {\n"
"                        background-color: #4CAF50;\n"
"                        color: white;\n"
"                        border: none;\n"
"                        font-size: 16px;\n"
"                        font-weight: bold;\n"
"                        }\n"
"                        QPushButton:hover {\n"
"                        background-color: #45a049;\n"
"                        }\n"
"                    ", nullptr));
        selectImageButton4->setText(QCoreApplication::translate("MainWindow", "Select Image 4", nullptr));
        selectImageButton4->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QPushButton {\n"
"                        background-color: #4CAF50;\n"
"                        color: white;\n"
"                        border: none;\n"
"                        font-size: 16px;\n"
"                        font-weight: bold;\n"
"                        }\n"
"                        QPushButton:hover {\n"
"                        background-color: #45a049;\n"
"                        }\n"
"                    ", nullptr));
        originalImageLabelTitle->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        originalImageLabelTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QLabel {\n"
"                        font-weight: bold;\n"
"                        font-size: 16px;\n"
"                        }\n"
"                    ", nullptr));
        binaryImageLabelTitle->setText(QCoreApplication::translate("MainWindow", "Binary Image", nullptr));
        binaryImageLabelTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QLabel {\n"
"                        font-weight: bold;\n"
"                        font-size: 16px;\n"
"                        }\n"
"                    ", nullptr));
        decompressedImageLabelTitle->setText(QCoreApplication::translate("MainWindow", "Decompressed Image", nullptr));
        decompressedImageLabelTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QLabel {\n"
"                        font-weight: bold;\n"
"                        font-size: 16px;\n"
"                        }\n"
"                    ", nullptr));
        processButton->setText(QCoreApplication::translate("MainWindow", "Process", nullptr));
        processButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QPushButton {\n"
"                        background-color: #008CBA;\n"
"                        color: white;\n"
"                        border: none;\n"
"                        font-size: 16px;\n"
"                        font-weight: bold;\n"
"                        }\n"
"                        QPushButton:hover {\n"
"                        background-color: #007B9E;\n"
"                        }\n"
"                    ", nullptr));
        loadingLabel->setText(QCoreApplication::translate("MainWindow", "Loading...", nullptr));
        loadingLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QLabel {\n"
"                        font-size: 16px;\n"
"                        color: #FF0000;\n"
"                        font-weight: bold;\n"
"                        }\n"
"                    ", nullptr));
        outputTextEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        QTextEdit {\n"
"                        font-size: 14px;\n"
"                        border: 1px solid #ddd;\n"
"                        padding: 10px;\n"
"                        }\n"
"                    ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
