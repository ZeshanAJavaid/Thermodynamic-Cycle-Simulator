/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title;
    QPushButton *Begin_Button;
    QLabel *Brayton_Image;
    QLabel *Otto_Image;
    QLabel *Diesel_Image;
    QPushButton *Help_Button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1019, 633));
        MainWindow->setMaximumSize(QSize(1019, 633));
        QFont font;
        font.setFamilies({QString::fromUtf8("DejaVu Serif")});
        font.setItalic(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(10, 10, 1011, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code Medium")});
        font1.setPointSize(36);
        font1.setItalic(false);
        Title->setFont(font1);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        Title->setAlignment(Qt::AlignCenter);
        Begin_Button = new QPushButton(centralwidget);
        Begin_Button->setObjectName("Begin_Button");
        Begin_Button->setGeometry(QRect(440, 480, 141, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font2.setPointSize(16);
        font2.setBold(true);
        Begin_Button->setFont(font2);
        Begin_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Brayton_Image = new QLabel(centralwidget);
        Brayton_Image->setObjectName("Brayton_Image");
        Brayton_Image->setGeometry(QRect(10, 90, 311, 281));
        Brayton_Image->setPixmap(QPixmap(QString::fromUtf8("../graphics/brayton_cycle.png")));
        Brayton_Image->setScaledContents(true);
        Otto_Image = new QLabel(centralwidget);
        Otto_Image->setObjectName("Otto_Image");
        Otto_Image->setGeometry(QRect(700, 90, 311, 281));
        Otto_Image->setPixmap(QPixmap(QString::fromUtf8("../graphics/otto_cycle.png")));
        Otto_Image->setScaledContents(true);
        Diesel_Image = new QLabel(centralwidget);
        Diesel_Image->setObjectName("Diesel_Image");
        Diesel_Image->setGeometry(QRect(340, 90, 341, 281));
        Diesel_Image->setPixmap(QPixmap(QString::fromUtf8("../graphics/diesel_cycle.png")));
        Diesel_Image->setScaledContents(true);
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(440, 540, 141, 51));
        Help_Button->setFont(font2);
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Thermodynamic Simulator", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Thermodynamic Simulator", nullptr));
        Begin_Button->setText(QCoreApplication::translate("MainWindow", "Begin", nullptr));
        Brayton_Image->setText(QString());
        Otto_Image->setText(QString());
        Diesel_Image->setText(QString());
        Help_Button->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
