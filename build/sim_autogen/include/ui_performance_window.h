/********************************************************************************
** Form generated from reading UI file 'performance_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFORMANCE_WINDOW_H
#define UI_PERFORMANCE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PerformanceWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title;
    QPushButton *Selection_Button;
    QPushButton *TsDiagram_Button;
    QPushButton *pvDiagram_Button;
    QPushButton *Data_Button;
    QPushButton *Help_Button;
    QLabel *Efficiency_Label;
    QLabel *Efficiency_Output;
    QLabel *Work_Cycle_Output;
    QLabel *Work_Cycle_Label;
    QLabel *Work_Compression_Output;
    QLabel *Work_Compression_Label;
    QLabel *Work_Expansion_Output;
    QLabel *Work_Expansion;
    QLabel *Heat_In_Output;
    QLabel *Heat_In_Label;
    QLabel *Heat_Out_Label;
    QLabel *Heat_Out_Output;

    void setupUi(QMainWindow *PerformanceWindow)
    {
        if (PerformanceWindow->objectName().isEmpty())
            PerformanceWindow->setObjectName("PerformanceWindow");
        PerformanceWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PerformanceWindow->sizePolicy().hasHeightForWidth());
        PerformanceWindow->setSizePolicy(sizePolicy);
        PerformanceWindow->setMinimumSize(QSize(1019, 633));
        PerformanceWindow->setMaximumSize(QSize(1019, 633));
        PerformanceWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);\n"
""));
        centralwidget = new QWidget(PerformanceWindow);
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
        Selection_Button = new QPushButton(centralwidget);
        Selection_Button->setObjectName("Selection_Button");
        Selection_Button->setGeometry(QRect(20, 560, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(16);
        font1.setBold(true);
        Selection_Button->setFont(font1);
        Selection_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        TsDiagram_Button = new QPushButton(centralwidget);
        TsDiagram_Button->setObjectName("TsDiagram_Button");
        TsDiagram_Button->setGeometry(QRect(220, 560, 141, 51));
        TsDiagram_Button->setFont(font1);
        TsDiagram_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        pvDiagram_Button = new QPushButton(centralwidget);
        pvDiagram_Button->setObjectName("pvDiagram_Button");
        pvDiagram_Button->setGeometry(QRect(420, 560, 141, 51));
        pvDiagram_Button->setFont(font1);
        pvDiagram_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Data_Button = new QPushButton(centralwidget);
        Data_Button->setObjectName("Data_Button");
        Data_Button->setGeometry(QRect(630, 560, 141, 51));
        Data_Button->setFont(font1);
        Data_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(840, 560, 141, 51));
        Help_Button->setFont(font1);
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Efficiency_Label = new QLabel(centralwidget);
        Efficiency_Label->setObjectName("Efficiency_Label");
        Efficiency_Label->setGeometry(QRect(10, 80, 501, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font2.setPointSize(18);
        font2.setBold(true);
        Efficiency_Label->setFont(font2);
        Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255); \n"
"background-color: rgb(165, 83, 0);"));
        Efficiency_Label->setAlignment(Qt::AlignCenter);
        Efficiency_Output = new QLabel(centralwidget);
        Efficiency_Output->setObjectName("Efficiency_Output");
        Efficiency_Output->setGeometry(QRect(520, 80, 501, 61));
        Efficiency_Output->setFont(font2);
        Efficiency_Output->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255); \n"
"background-color: rgb(165, 83, 0);"));
        Efficiency_Output->setAlignment(Qt::AlignCenter);
        Work_Cycle_Output = new QLabel(centralwidget);
        Work_Cycle_Output->setObjectName("Work_Cycle_Output");
        Work_Cycle_Output->setGeometry(QRect(520, 160, 501, 61));
        Work_Cycle_Output->setFont(font2);
        Work_Cycle_Output->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(122, 0, 0);"));
        Work_Cycle_Output->setAlignment(Qt::AlignCenter);
        Work_Cycle_Label = new QLabel(centralwidget);
        Work_Cycle_Label->setObjectName("Work_Cycle_Label");
        Work_Cycle_Label->setGeometry(QRect(10, 160, 501, 61));
        Work_Cycle_Label->setFont(font2);
        Work_Cycle_Label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(122, 0, 0);"));
        Work_Cycle_Label->setAlignment(Qt::AlignCenter);
        Work_Compression_Output = new QLabel(centralwidget);
        Work_Compression_Output->setObjectName("Work_Compression_Output");
        Work_Compression_Output->setGeometry(QRect(520, 240, 501, 61));
        Work_Compression_Output->setFont(font2);
        Work_Compression_Output->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(112, 0, 56)"));
        Work_Compression_Output->setAlignment(Qt::AlignCenter);
        Work_Compression_Label = new QLabel(centralwidget);
        Work_Compression_Label->setObjectName("Work_Compression_Label");
        Work_Compression_Label->setGeometry(QRect(10, 240, 501, 61));
        Work_Compression_Label->setFont(font2);
        Work_Compression_Label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(112, 0, 56)"));
        Work_Compression_Label->setAlignment(Qt::AlignCenter);
        Work_Expansion_Output = new QLabel(centralwidget);
        Work_Expansion_Output->setObjectName("Work_Expansion_Output");
        Work_Expansion_Output->setGeometry(QRect(520, 320, 501, 61));
        Work_Expansion_Output->setFont(font2);
        Work_Expansion_Output->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(86, 0, 86)"));
        Work_Expansion_Output->setAlignment(Qt::AlignCenter);
        Work_Expansion = new QLabel(centralwidget);
        Work_Expansion->setObjectName("Work_Expansion");
        Work_Expansion->setGeometry(QRect(10, 320, 501, 61));
        Work_Expansion->setFont(font2);
        Work_Expansion->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(86, 0, 86)"));
        Work_Expansion->setAlignment(Qt::AlignCenter);
        Heat_In_Output = new QLabel(centralwidget);
        Heat_In_Output->setObjectName("Heat_In_Output");
        Heat_In_Output->setGeometry(QRect(520, 400, 501, 61));
        Heat_In_Output->setFont(font2);
        Heat_In_Output->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(118, 79, 118)"));
        Heat_In_Output->setAlignment(Qt::AlignCenter);
        Heat_In_Label = new QLabel(centralwidget);
        Heat_In_Label->setObjectName("Heat_In_Label");
        Heat_In_Label->setGeometry(QRect(10, 400, 501, 61));
        Heat_In_Label->setFont(font2);
        Heat_In_Label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(118, 79, 118)"));
        Heat_In_Label->setAlignment(Qt::AlignCenter);
        Heat_Out_Label = new QLabel(centralwidget);
        Heat_Out_Label->setObjectName("Heat_Out_Label");
        Heat_Out_Label->setGeometry(QRect(10, 480, 501, 61));
        Heat_Out_Label->setFont(font2);
        Heat_Out_Label->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(99, 99, 149);"));
        Heat_Out_Label->setAlignment(Qt::AlignCenter);
        Heat_Out_Output = new QLabel(centralwidget);
        Heat_Out_Output->setObjectName("Heat_Out_Output");
        Heat_Out_Output->setGeometry(QRect(520, 480, 501, 61));
        Heat_Out_Output->setFont(font2);
        Heat_Out_Output->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(99, 99, 149);"));
        Heat_Out_Output->setAlignment(Qt::AlignCenter);
        PerformanceWindow->setCentralWidget(centralwidget);

        retranslateUi(PerformanceWindow);

        QMetaObject::connectSlotsByName(PerformanceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PerformanceWindow)
    {
        PerformanceWindow->setWindowTitle(QCoreApplication::translate("PerformanceWindow", "Thermodynamic Simulator", nullptr));
        Title->setText(QCoreApplication::translate("PerformanceWindow", "Performance of Cycle:", nullptr));
        Selection_Button->setText(QCoreApplication::translate("PerformanceWindow", "Selection", nullptr));
        TsDiagram_Button->setText(QCoreApplication::translate("PerformanceWindow", "Ts Diagram", nullptr));
        pvDiagram_Button->setText(QCoreApplication::translate("PerformanceWindow", "pv Diagram", nullptr));
        Data_Button->setText(QCoreApplication::translate("PerformanceWindow", "Data", nullptr));
        Help_Button->setText(QCoreApplication::translate("PerformanceWindow", "Help", nullptr));
        Efficiency_Label->setText(QCoreApplication::translate("PerformanceWindow", "Efficiency (%):", nullptr));
        Efficiency_Output->setText(QString());
        Work_Cycle_Output->setText(QString());
        Work_Cycle_Label->setText(QCoreApplication::translate("PerformanceWindow", "Work of Cycle (kJ / kg):", nullptr));
        Work_Compression_Output->setText(QString());
        Work_Compression_Label->setText(QCoreApplication::translate("PerformanceWindow", "Work of Compression (kJ / kg):", nullptr));
        Work_Expansion_Output->setText(QString());
        Work_Expansion->setText(QCoreApplication::translate("PerformanceWindow", "Work of Expansion (kJ / kg):", nullptr));
        Heat_In_Output->setText(QString());
        Heat_In_Label->setText(QCoreApplication::translate("PerformanceWindow", "Heat In (kJ / kg):", nullptr));
        Heat_Out_Label->setText(QCoreApplication::translate("PerformanceWindow", "Heat Out (kJ / kg):", nullptr));
        Heat_Out_Output->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PerformanceWindow: public Ui_PerformanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFORMANCE_WINDOW_H
