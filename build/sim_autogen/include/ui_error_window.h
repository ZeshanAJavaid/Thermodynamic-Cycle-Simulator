/********************************************************************************
** Form generated from reading UI file 'error_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_WINDOW_H
#define UI_ERROR_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Close_Button;
    QLabel *Title_Label;
    QLabel *Error_Label;

    void setupUi(QMainWindow *ErrorWindow)
    {
        if (ErrorWindow->objectName().isEmpty())
            ErrorWindow->setObjectName("ErrorWindow");
        ErrorWindow->resize(602, 402);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ErrorWindow->sizePolicy().hasHeightForWidth());
        ErrorWindow->setSizePolicy(sizePolicy);
        ErrorWindow->setMinimumSize(QSize(602, 402));
        ErrorWindow->setMaximumSize(QSize(602, 402));
        ErrorWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);\n"
""));
        centralwidget = new QWidget(ErrorWindow);
        centralwidget->setObjectName("centralwidget");
        Close_Button = new QPushButton(centralwidget);
        Close_Button->setObjectName("Close_Button");
        Close_Button->setGeometry(QRect(250, 320, 141, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font.setPointSize(12);
        font.setBold(true);
        Close_Button->setFont(font);
        Close_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 38, 0);"));
        Title_Label = new QLabel(centralwidget);
        Title_Label->setObjectName("Title_Label");
        Title_Label->setGeometry(QRect(0, 20, 601, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(16);
        font1.setBold(true);
        Title_Label->setFont(font1);
        Title_Label->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 0, 69);"));
        Title_Label->setAlignment(Qt::AlignCenter);
        Title_Label->setWordWrap(true);
        Error_Label = new QLabel(centralwidget);
        Error_Label->setObjectName("Error_Label");
        Error_Label->setGeometry(QRect(0, 100, 601, 181));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code Retina")});
        font2.setPointSize(12);
        font2.setBold(false);
        Error_Label->setFont(font2);
        Error_Label->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 0, 0);"));
        Error_Label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Error_Label->setWordWrap(true);
        ErrorWindow->setCentralWidget(centralwidget);

        retranslateUi(ErrorWindow);

        QMetaObject::connectSlotsByName(ErrorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ErrorWindow)
    {
        ErrorWindow->setWindowTitle(QCoreApplication::translate("ErrorWindow", "Thermodynamic Simulator", nullptr));
        Close_Button->setText(QCoreApplication::translate("ErrorWindow", "Close", nullptr));
        Title_Label->setText(QCoreApplication::translate("ErrorWindow", "TextLabel", nullptr));
        Error_Label->setText(QCoreApplication::translate("ErrorWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorWindow: public Ui_ErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_WINDOW_H
