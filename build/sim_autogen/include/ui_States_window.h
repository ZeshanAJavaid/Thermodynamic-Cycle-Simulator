/********************************************************************************
** Form generated from reading UI file 'States_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATES_WINDOW_H
#define UI_STATES_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title;
    QTableView *States;
    QPushButton *Quit_Button;
    QPushButton *pvDiagram_Button;
    QPushButton *TsDiagram_Button;
    QPushButton *Performance_Button;
    QPushButton *Help_Button;

    void setupUi(QMainWindow *StateWindow)
    {
        if (StateWindow->objectName().isEmpty())
            StateWindow->setObjectName("StateWindow");
        StateWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StateWindow->sizePolicy().hasHeightForWidth());
        StateWindow->setSizePolicy(sizePolicy);
        StateWindow->setMinimumSize(QSize(1019, 633));
        StateWindow->setMaximumSize(QSize(1019, 633));
        StateWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);\n"
""));
        centralwidget = new QWidget(StateWindow);
        centralwidget->setObjectName("centralwidget");
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(0, 10, 1011, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font.setPointSize(28);
        font.setBold(true);
        Title->setFont(font);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        Title->setAlignment(Qt::AlignCenter);
        States = new QTableView(centralwidget);
        States->setObjectName("States");
        States->setGeometry(QRect(50, 160, 941, 271));
        Quit_Button = new QPushButton(centralwidget);
        Quit_Button->setObjectName("Quit_Button");
        Quit_Button->setGeometry(QRect(30, 550, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(16);
        font1.setBold(true);
        Quit_Button->setFont(font1);
        Quit_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        pvDiagram_Button = new QPushButton(centralwidget);
        pvDiagram_Button->setObjectName("pvDiagram_Button");
        pvDiagram_Button->setGeometry(QRect(430, 550, 141, 51));
        pvDiagram_Button->setFont(font1);
        pvDiagram_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        TsDiagram_Button = new QPushButton(centralwidget);
        TsDiagram_Button->setObjectName("TsDiagram_Button");
        TsDiagram_Button->setGeometry(QRect(230, 550, 141, 51));
        TsDiagram_Button->setFont(font1);
        TsDiagram_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Performance_Button = new QPushButton(centralwidget);
        Performance_Button->setObjectName("Performance_Button");
        Performance_Button->setGeometry(QRect(640, 550, 151, 51));
        Performance_Button->setFont(font1);
        Performance_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(850, 550, 141, 51));
        Help_Button->setFont(font1);
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        StateWindow->setCentralWidget(centralwidget);

        retranslateUi(StateWindow);

        QMetaObject::connectSlotsByName(StateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StateWindow)
    {
        StateWindow->setWindowTitle(QCoreApplication::translate("StateWindow", "Thermodynamic Simulator", nullptr));
        Title->setText(QCoreApplication::translate("StateWindow", "Thermodynamic States of Cycle", nullptr));
        Quit_Button->setText(QCoreApplication::translate("StateWindow", "Quit", nullptr));
        pvDiagram_Button->setText(QCoreApplication::translate("StateWindow", "pv Diagram", nullptr));
        TsDiagram_Button->setText(QCoreApplication::translate("StateWindow", "Ts Diagram", nullptr));
        Performance_Button->setText(QCoreApplication::translate("StateWindow", "Performance", nullptr));
        Help_Button->setText(QCoreApplication::translate("StateWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StateWindow: public Ui_StateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATES_WINDOW_H
