/********************************************************************************
** Form generated from reading UI file 'help_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_WINDOW_H
#define UI_HELP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title_Label;
    QPushButton *Close_Button;
    QLabel *Help_Label;

    void setupUi(QMainWindow *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName("HelpWindow");
        HelpWindow->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HelpWindow->sizePolicy().hasHeightForWidth());
        HelpWindow->setSizePolicy(sizePolicy);
        HelpWindow->setMinimumSize(QSize(602, 402));
        HelpWindow->setMaximumSize(QSize(700, 500));
        HelpWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);\n"
""));
        centralwidget = new QWidget(HelpWindow);
        centralwidget->setObjectName("centralwidget");
        Title_Label = new QLabel(centralwidget);
        Title_Label->setObjectName("Title_Label");
        Title_Label->setGeometry(QRect(10, 10, 681, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font.setPointSize(16);
        font.setBold(true);
        Title_Label->setFont(font);
        Title_Label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Title_Label->setWordWrap(true);
        Close_Button = new QPushButton(centralwidget);
        Close_Button->setObjectName("Close_Button");
        Close_Button->setGeometry(QRect(280, 430, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(12);
        font1.setBold(true);
        Close_Button->setFont(font1);
        Help_Label = new QLabel(centralwidget);
        Help_Label->setObjectName("Help_Label");
        Help_Label->setGeometry(QRect(10, 80, 681, 331));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code Retina")});
        font2.setPointSize(12);
        font2.setBold(false);
        Help_Label->setFont(font2);
        Help_Label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Help_Label->setWordWrap(true);
        HelpWindow->setCentralWidget(centralwidget);

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HelpWindow)
    {
        HelpWindow->setWindowTitle(QCoreApplication::translate("HelpWindow", "Thermodynamic Simulator", nullptr));
        Title_Label->setText(QCoreApplication::translate("HelpWindow", "TextLabel", nullptr));
        Close_Button->setText(QCoreApplication::translate("HelpWindow", "Close", nullptr));
        Help_Label->setText(QCoreApplication::translate("HelpWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_WINDOW_H
