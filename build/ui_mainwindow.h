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
    QPushButton *selectImageButton1;
    QPushButton *selectImageButton2;
    QPushButton *selectImageButton3;
    QPushButton *selectImageButton4;
    QPushButton *processButton;
    QLabel *imageLabel;
    QTextEdit *outputTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        selectImageButton1 = new QPushButton(centralwidget);
        selectImageButton1->setObjectName("selectImageButton1");
        selectImageButton1->setGeometry(QRect(20, 20, 100, 50));
        selectImageButton2 = new QPushButton(centralwidget);
        selectImageButton2->setObjectName("selectImageButton2");
        selectImageButton2->setGeometry(QRect(20, 80, 100, 50));
        selectImageButton3 = new QPushButton(centralwidget);
        selectImageButton3->setObjectName("selectImageButton3");
        selectImageButton3->setGeometry(QRect(20, 140, 100, 50));
        selectImageButton4 = new QPushButton(centralwidget);
        selectImageButton4->setObjectName("selectImageButton4");
        selectImageButton4->setGeometry(QRect(20, 200, 100, 50));
        processButton = new QPushButton(centralwidget);
        processButton->setObjectName("processButton");
        processButton->setGeometry(QRect(20, 260, 100, 50));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(150, 20, 600, 400));
        outputTextEdit = new QTextEdit(centralwidget);
        outputTextEdit->setObjectName("outputTextEdit");
        outputTextEdit->setGeometry(QRect(150, 440, 600, 100));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        selectImageButton1->setText(QCoreApplication::translate("MainWindow", "Select Image 1", nullptr));
        selectImageButton2->setText(QCoreApplication::translate("MainWindow", "Select Image 2", nullptr));
        selectImageButton3->setText(QCoreApplication::translate("MainWindow", "Select Image 3", nullptr));
        selectImageButton4->setText(QCoreApplication::translate("MainWindow", "Select Image 4", nullptr));
        processButton->setText(QCoreApplication::translate("MainWindow", "Process", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
