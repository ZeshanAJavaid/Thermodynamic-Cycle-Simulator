/********************************************************************************
** Form generated from reading UI file 'selector_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTOR_WINDOW_H
#define UI_SELECTOR_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectionWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title;
    QLabel *Brayton_Image;
    QLabel *Diesel_Image;
    QLabel *Otto_Image;
    QPushButton *Brayton_Button;
    QPushButton *Diesel_Button;
    QPushButton *Otto_Button;
    QPushButton *Help_Button;

    void setupUi(QMainWindow *SelectionWindow)
    {
        if (SelectionWindow->objectName().isEmpty())
            SelectionWindow->setObjectName("SelectionWindow");
        SelectionWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SelectionWindow->sizePolicy().hasHeightForWidth());
        SelectionWindow->setSizePolicy(sizePolicy);
        SelectionWindow->setMinimumSize(QSize(1019, 633));
        SelectionWindow->setMaximumSize(QSize(1019, 633));
        SelectionWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11)"));
        centralwidget = new QWidget(SelectionWindow);
        centralwidget->setObjectName("centralwidget");
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(10, 10, 1011, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font.setPointSize(28);
        font.setBold(true);
        Title->setFont(font);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        Title->setAlignment(Qt::AlignCenter);
        Brayton_Image = new QLabel(centralwidget);
        Brayton_Image->setObjectName("Brayton_Image");
        Brayton_Image->setGeometry(QRect(10, 80, 311, 281));
        Brayton_Image->setPixmap(QPixmap(QString::fromUtf8(":/gui/graphics/brayton_cycle.png")));
        Brayton_Image->setScaledContents(true);
        Diesel_Image = new QLabel(centralwidget);
        Diesel_Image->setObjectName("Diesel_Image");
        Diesel_Image->setGeometry(QRect(340, 80, 341, 281));
        Diesel_Image->setPixmap(QPixmap(QString::fromUtf8(":/gui/graphics/diesel_cycle.png")));
        Diesel_Image->setScaledContents(true);
        Otto_Image = new QLabel(centralwidget);
        Otto_Image->setObjectName("Otto_Image");
        Otto_Image->setGeometry(QRect(700, 80, 311, 281));
        Otto_Image->setPixmap(QPixmap(QString::fromUtf8(":/gui/graphics/otto_cycle.png")));
        Otto_Image->setScaledContents(true);
        Brayton_Button = new QPushButton(centralwidget);
        Brayton_Button->setObjectName("Brayton_Button");
        Brayton_Button->setGeometry(QRect(90, 420, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(16);
        font1.setBold(true);
        Brayton_Button->setFont(font1);
        Brayton_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Diesel_Button = new QPushButton(centralwidget);
        Diesel_Button->setObjectName("Diesel_Button");
        Diesel_Button->setGeometry(QRect(440, 420, 141, 51));
        Diesel_Button->setFont(font1);
        Diesel_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Otto_Button = new QPushButton(centralwidget);
        Otto_Button->setObjectName("Otto_Button");
        Otto_Button->setGeometry(QRect(800, 420, 141, 51));
        Otto_Button->setFont(font1);
        Otto_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(440, 550, 141, 51));
        Help_Button->setFont(font1);
        Help_Button->setCursor(QCursor(Qt::ArrowCursor));
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        SelectionWindow->setCentralWidget(centralwidget);

        retranslateUi(SelectionWindow);

        QMetaObject::connectSlotsByName(SelectionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SelectionWindow)
    {
        SelectionWindow->setWindowTitle(QCoreApplication::translate("SelectionWindow", "Thermodynamic Simulator", nullptr));
        Title->setText(QCoreApplication::translate("SelectionWindow", "Select Cycle:", nullptr));
        Brayton_Image->setText(QString());
        Diesel_Image->setText(QString());
        Otto_Image->setText(QString());
        Brayton_Button->setText(QCoreApplication::translate("SelectionWindow", "Brayton", nullptr));
        Diesel_Button->setText(QCoreApplication::translate("SelectionWindow", "Diesel", nullptr));
        Otto_Button->setText(QCoreApplication::translate("SelectionWindow", "Otto", nullptr));
        Help_Button->setText(QCoreApplication::translate("SelectionWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectionWindow: public Ui_SelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTOR_WINDOW_H
