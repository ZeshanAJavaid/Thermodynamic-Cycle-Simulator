/********************************************************************************
** Form generated from reading UI file 'diesel_inputs.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIESEL_INPUTS_H
#define UI_DIESEL_INPUTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DieselInputWindow
{
public:
    QWidget *centralwidget;
    QLabel *Compression_Efficiency_Label;
    QLineEdit *Pressure_Input;
    QLineEdit *Compression_Ratio_Input;
    QLabel *Diesel_Image;
    QLabel *Initial_Temperature_Label;
    QLabel *Initial_Pressure_Label;
    QLabel *Expansion_Efficiency_Label;
    QLineEdit *Expansion_eff_input;
    QLineEdit *Compression_eff_input;
    QLabel *Compression_Ratio_Label;
    QPushButton *Help_Button;
    QLabel *Title;
    QLineEdit *Temperature_Input;
    QPushButton *Begin_Button;
    QPushButton *Back_Button;

    void setupUi(QMainWindow *DieselInputWindow)
    {
        if (DieselInputWindow->objectName().isEmpty())
            DieselInputWindow->setObjectName("DieselInputWindow");
        DieselInputWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DieselInputWindow->sizePolicy().hasHeightForWidth());
        DieselInputWindow->setSizePolicy(sizePolicy);
        DieselInputWindow->setMinimumSize(QSize(1019, 633));
        DieselInputWindow->setMaximumSize(QSize(1019, 633));
        DieselInputWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);"));
        centralwidget = new QWidget(DieselInputWindow);
        centralwidget->setObjectName("centralwidget");
        Compression_Efficiency_Label = new QLabel(centralwidget);
        Compression_Efficiency_Label->setObjectName("Compression_Efficiency_Label");
        Compression_Efficiency_Label->setGeometry(QRect(540, 350, 471, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font.setPointSize(11);
        font.setBold(true);
        Compression_Efficiency_Label->setFont(font);
        Compression_Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(229, 87, 4)"));
        Compression_Efficiency_Label->setAlignment(Qt::AlignCenter);
        Pressure_Input = new QLineEdit(centralwidget);
        Pressure_Input->setObjectName("Pressure_Input");
        Pressure_Input->setGeometry(QRect(540, 220, 471, 31));
        Pressure_Input->setFont(font);
        Pressure_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(176, 59, 0)"));
        Pressure_Input->setMaxLength(6);
        Pressure_Input->setAlignment(Qt::AlignCenter);
        Compression_Ratio_Input = new QLineEdit(centralwidget);
        Compression_Ratio_Input->setObjectName("Compression_Ratio_Input");
        Compression_Ratio_Input->setGeometry(QRect(540, 310, 471, 31));
        Compression_Ratio_Input->setFont(font);
        Compression_Ratio_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(176, 59, 0)"));
        Compression_Ratio_Input->setMaxLength(3);
        Compression_Ratio_Input->setAlignment(Qt::AlignCenter);
        Diesel_Image = new QLabel(centralwidget);
        Diesel_Image->setObjectName("Diesel_Image");
        Diesel_Image->setGeometry(QRect(10, 80, 521, 511));
        Diesel_Image->setPixmap(QPixmap(QString::fromUtf8(":/gui/graphics/diesel_cycle.png")));
        Diesel_Image->setScaledContents(true);
        Initial_Temperature_Label = new QLabel(centralwidget);
        Initial_Temperature_Label->setObjectName("Initial_Temperature_Label");
        Initial_Temperature_Label->setGeometry(QRect(540, 80, 471, 41));
        Initial_Temperature_Label->setFont(font);
        Initial_Temperature_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(229, 87, 4)"));
        Initial_Temperature_Label->setAlignment(Qt::AlignCenter);
        Initial_Pressure_Label = new QLabel(centralwidget);
        Initial_Pressure_Label->setObjectName("Initial_Pressure_Label");
        Initial_Pressure_Label->setGeometry(QRect(540, 170, 471, 41));
        Initial_Pressure_Label->setFont(font);
        Initial_Pressure_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(229, 87, 4)"));
        Initial_Pressure_Label->setAlignment(Qt::AlignCenter);
        Expansion_Efficiency_Label = new QLabel(centralwidget);
        Expansion_Efficiency_Label->setObjectName("Expansion_Efficiency_Label");
        Expansion_Efficiency_Label->setGeometry(QRect(540, 440, 471, 41));
        Expansion_Efficiency_Label->setFont(font);
        Expansion_Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(229, 87, 4)"));
        Expansion_Efficiency_Label->setAlignment(Qt::AlignCenter);
        Expansion_eff_input = new QLineEdit(centralwidget);
        Expansion_eff_input->setObjectName("Expansion_eff_input");
        Expansion_eff_input->setGeometry(QRect(540, 490, 471, 31));
        Expansion_eff_input->setFont(font);
        Expansion_eff_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(176, 59, 0)"));
        Expansion_eff_input->setMaxLength(4);
        Expansion_eff_input->setAlignment(Qt::AlignCenter);
        Compression_eff_input = new QLineEdit(centralwidget);
        Compression_eff_input->setObjectName("Compression_eff_input");
        Compression_eff_input->setGeometry(QRect(540, 400, 471, 31));
        Compression_eff_input->setFont(font);
        Compression_eff_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(176, 59, 0)"));
        Compression_eff_input->setMaxLength(4);
        Compression_eff_input->setAlignment(Qt::AlignCenter);
        Compression_Ratio_Label = new QLabel(centralwidget);
        Compression_Ratio_Label->setObjectName("Compression_Ratio_Label");
        Compression_Ratio_Label->setGeometry(QRect(540, 260, 471, 41));
        Compression_Ratio_Label->setFont(font);
        Compression_Ratio_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(229, 87, 4)"));
        Compression_Ratio_Label->setAlignment(Qt::AlignCenter);
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(550, 540, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(16);
        font1.setBold(true);
        Help_Button->setFont(font1);
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(153, 58, 3)"));
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(10, 10, 1011, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font2.setPointSize(28);
        font2.setBold(true);
        Title->setFont(font2);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        Title->setAlignment(Qt::AlignCenter);
        Temperature_Input = new QLineEdit(centralwidget);
        Temperature_Input->setObjectName("Temperature_Input");
        Temperature_Input->setGeometry(QRect(540, 130, 471, 31));
        Temperature_Input->setFont(font);
        Temperature_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(176, 59, 0)"));
        Temperature_Input->setMaxLength(6);
        Temperature_Input->setAlignment(Qt::AlignCenter);
        Temperature_Input->setDragEnabled(false);
        Temperature_Input->setReadOnly(false);
        Temperature_Input->setClearButtonEnabled(false);
        Begin_Button = new QPushButton(centralwidget);
        Begin_Button->setObjectName("Begin_Button");
        Begin_Button->setGeometry(QRect(850, 540, 141, 51));
        Begin_Button->setFont(font1);
        Begin_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(153, 58, 3)"));
        Back_Button = new QPushButton(centralwidget);
        Back_Button->setObjectName("Back_Button");
        Back_Button->setGeometry(QRect(700, 540, 141, 51));
        Back_Button->setFont(font1);
        Back_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(153, 58, 3)"));
        DieselInputWindow->setCentralWidget(centralwidget);

        retranslateUi(DieselInputWindow);

        QMetaObject::connectSlotsByName(DieselInputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DieselInputWindow)
    {
        DieselInputWindow->setWindowTitle(QCoreApplication::translate("DieselInputWindow", "Thermodynamic Simulator", nullptr));
        Compression_Efficiency_Label->setText(QCoreApplication::translate("DieselInputWindow", "Compression Efficiency", nullptr));
        Pressure_Input->setInputMask(QString());
        Pressure_Input->setPlaceholderText(QCoreApplication::translate("DieselInputWindow", "Enter the Initial Pressure in kPa", nullptr));
        Compression_Ratio_Input->setInputMask(QString());
        Compression_Ratio_Input->setPlaceholderText(QCoreApplication::translate("DieselInputWindow", "Enter the Compression Ratio", nullptr));
        Diesel_Image->setText(QString());
        Initial_Temperature_Label->setText(QCoreApplication::translate("DieselInputWindow", "Initial Temperature (K)", nullptr));
        Initial_Pressure_Label->setText(QCoreApplication::translate("DieselInputWindow", "Initial Pressure (kPa)", nullptr));
        Expansion_Efficiency_Label->setText(QCoreApplication::translate("DieselInputWindow", "Expansion Efficiency", nullptr));
        Expansion_eff_input->setInputMask(QString());
        Expansion_eff_input->setPlaceholderText(QCoreApplication::translate("DieselInputWindow", "Enter the Expansion Efficiency", nullptr));
        Compression_eff_input->setInputMask(QString());
        Compression_eff_input->setPlaceholderText(QCoreApplication::translate("DieselInputWindow", "Enter the Compression Efficiency", nullptr));
        Compression_Ratio_Label->setText(QCoreApplication::translate("DieselInputWindow", "Compression Ratio", nullptr));
        Help_Button->setText(QCoreApplication::translate("DieselInputWindow", "Help", nullptr));
        Title->setText(QCoreApplication::translate("DieselInputWindow", "Input Diesel Cycle Properties:", nullptr));
        Temperature_Input->setInputMask(QString());
        Temperature_Input->setText(QString());
        Temperature_Input->setPlaceholderText(QCoreApplication::translate("DieselInputWindow", "Enter the Initial Temperature in Kelvins", nullptr));
        Begin_Button->setText(QCoreApplication::translate("DieselInputWindow", "Begin", nullptr));
        Back_Button->setText(QCoreApplication::translate("DieselInputWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DieselInputWindow: public Ui_DieselInputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIESEL_INPUTS_H
