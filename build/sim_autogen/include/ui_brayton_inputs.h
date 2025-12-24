/********************************************************************************
** Form generated from reading UI file 'brayton_inputs.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAYTON_INPUTS_H
#define UI_BRAYTON_INPUTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BraytonInputWindow
{
public:
    QWidget *centralwidget;
    QLabel *Brayton_Image;
    QLabel *Title;
    QLabel *Initial_Temperature_Label;
    QLineEdit *Temperature_Input;
    QLabel *Initial_Pressure_Label;
    QLineEdit *Pressure_Input;
    QLabel *Pressure_Ratio_Label;
    QLineEdit *Pressure_Ratio_Input;
    QLabel *Compressor_Efficiency_Label;
    QLineEdit *Compressor_eff_input;
    QLabel *Turbine_Efficiency_Label;
    QLineEdit *Turbine_eff_input;
    QPushButton *Help_Button;
    QPushButton *Begin_Button;
    QPushButton *Back_Button;

    void setupUi(QMainWindow *BraytonInputWindow)
    {
        if (BraytonInputWindow->objectName().isEmpty())
            BraytonInputWindow->setObjectName("BraytonInputWindow");
        BraytonInputWindow->setEnabled(true);
        BraytonInputWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BraytonInputWindow->sizePolicy().hasHeightForWidth());
        BraytonInputWindow->setSizePolicy(sizePolicy);
        BraytonInputWindow->setMinimumSize(QSize(1019, 633));
        BraytonInputWindow->setMaximumSize(QSize(1019, 633));
        BraytonInputWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);\n"
""));
        centralwidget = new QWidget(BraytonInputWindow);
        centralwidget->setObjectName("centralwidget");
        Brayton_Image = new QLabel(centralwidget);
        Brayton_Image->setObjectName("Brayton_Image");
        Brayton_Image->setGeometry(QRect(10, 80, 521, 511));
        Brayton_Image->setPixmap(QPixmap(QString::fromUtf8("../graphics/brayton_cycle.png")));
        Brayton_Image->setScaledContents(true);
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
        Initial_Temperature_Label = new QLabel(centralwidget);
        Initial_Temperature_Label->setObjectName("Initial_Temperature_Label");
        Initial_Temperature_Label->setGeometry(QRect(540, 80, 471, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(11);
        font1.setBold(true);
        Initial_Temperature_Label->setFont(font1);
        Initial_Temperature_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(140, 0, 0)"));
        Initial_Temperature_Label->setAlignment(Qt::AlignCenter);
        Temperature_Input = new QLineEdit(centralwidget);
        Temperature_Input->setObjectName("Temperature_Input");
        Temperature_Input->setGeometry(QRect(540, 130, 471, 31));
        Temperature_Input->setFont(font1);
        Temperature_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Temperature_Input->setMaxLength(6);
        Temperature_Input->setAlignment(Qt::AlignCenter);
        Initial_Pressure_Label = new QLabel(centralwidget);
        Initial_Pressure_Label->setObjectName("Initial_Pressure_Label");
        Initial_Pressure_Label->setGeometry(QRect(540, 170, 471, 41));
        Initial_Pressure_Label->setFont(font1);
        Initial_Pressure_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(140, 0, 0)"));
        Initial_Pressure_Label->setAlignment(Qt::AlignCenter);
        Pressure_Input = new QLineEdit(centralwidget);
        Pressure_Input->setObjectName("Pressure_Input");
        Pressure_Input->setGeometry(QRect(540, 220, 471, 31));
        Pressure_Input->setFont(font1);
        Pressure_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Pressure_Input->setMaxLength(6);
        Pressure_Input->setAlignment(Qt::AlignCenter);
        Pressure_Ratio_Label = new QLabel(centralwidget);
        Pressure_Ratio_Label->setObjectName("Pressure_Ratio_Label");
        Pressure_Ratio_Label->setGeometry(QRect(540, 260, 471, 41));
        Pressure_Ratio_Label->setFont(font1);
        Pressure_Ratio_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(140, 0, 0)"));
        Pressure_Ratio_Label->setAlignment(Qt::AlignCenter);
        Pressure_Ratio_Input = new QLineEdit(centralwidget);
        Pressure_Ratio_Input->setObjectName("Pressure_Ratio_Input");
        Pressure_Ratio_Input->setGeometry(QRect(540, 310, 471, 31));
        Pressure_Ratio_Input->setFont(font1);
        Pressure_Ratio_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Pressure_Ratio_Input->setMaxLength(3);
        Pressure_Ratio_Input->setAlignment(Qt::AlignCenter);
        Compressor_Efficiency_Label = new QLabel(centralwidget);
        Compressor_Efficiency_Label->setObjectName("Compressor_Efficiency_Label");
        Compressor_Efficiency_Label->setGeometry(QRect(540, 350, 471, 41));
        Compressor_Efficiency_Label->setFont(font1);
        Compressor_Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(140, 0, 0)"));
        Compressor_Efficiency_Label->setAlignment(Qt::AlignCenter);
        Compressor_eff_input = new QLineEdit(centralwidget);
        Compressor_eff_input->setObjectName("Compressor_eff_input");
        Compressor_eff_input->setGeometry(QRect(540, 400, 471, 31));
        Compressor_eff_input->setFont(font1);
        Compressor_eff_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Compressor_eff_input->setMaxLength(4);
        Compressor_eff_input->setAlignment(Qt::AlignCenter);
        Turbine_Efficiency_Label = new QLabel(centralwidget);
        Turbine_Efficiency_Label->setObjectName("Turbine_Efficiency_Label");
        Turbine_Efficiency_Label->setGeometry(QRect(540, 440, 471, 41));
        Turbine_Efficiency_Label->setFont(font1);
        Turbine_Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(140, 0, 0)"));
        Turbine_Efficiency_Label->setAlignment(Qt::AlignCenter);
        Turbine_eff_input = new QLineEdit(centralwidget);
        Turbine_eff_input->setObjectName("Turbine_eff_input");
        Turbine_eff_input->setGeometry(QRect(540, 490, 471, 31));
        Turbine_eff_input->setFont(font1);
        Turbine_eff_input->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255); background-color: rgb(95, 16, 3)\n"
""));
        Turbine_eff_input->setMaxLength(4);
        Turbine_eff_input->setAlignment(Qt::AlignCenter);
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(550, 540, 141, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font2.setPointSize(16);
        font2.setBold(true);
        Help_Button->setFont(font2);
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Begin_Button = new QPushButton(centralwidget);
        Begin_Button->setObjectName("Begin_Button");
        Begin_Button->setGeometry(QRect(850, 540, 141, 51));
        Begin_Button->setFont(font2);
        Begin_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        Back_Button = new QPushButton(centralwidget);
        Back_Button->setObjectName("Back_Button");
        Back_Button->setGeometry(QRect(700, 540, 141, 51));
        Back_Button->setFont(font2);
        Back_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(95, 16, 3)"));
        BraytonInputWindow->setCentralWidget(centralwidget);

        retranslateUi(BraytonInputWindow);

        QMetaObject::connectSlotsByName(BraytonInputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BraytonInputWindow)
    {
        BraytonInputWindow->setWindowTitle(QCoreApplication::translate("BraytonInputWindow", "Thermodynamic Simulator", nullptr));
        Brayton_Image->setText(QString());
        Title->setText(QCoreApplication::translate("BraytonInputWindow", "Input Brayton Cycle Properties:", nullptr));
        Initial_Temperature_Label->setText(QCoreApplication::translate("BraytonInputWindow", "Initial Temperature (K)", nullptr));
        Temperature_Input->setInputMask(QString());
        Temperature_Input->setText(QString());
        Temperature_Input->setPlaceholderText(QCoreApplication::translate("BraytonInputWindow", "Enter the Initial Temperature in Kelvins", nullptr));
        Initial_Pressure_Label->setText(QCoreApplication::translate("BraytonInputWindow", "Initial Pressure (kPa)", nullptr));
        Pressure_Input->setInputMask(QString());
        Pressure_Input->setPlaceholderText(QCoreApplication::translate("BraytonInputWindow", "Enter the Initial Pressure in kPa", nullptr));
        Pressure_Ratio_Label->setText(QCoreApplication::translate("BraytonInputWindow", "Pressure Ratio", nullptr));
        Pressure_Ratio_Input->setInputMask(QString());
        Pressure_Ratio_Input->setPlaceholderText(QCoreApplication::translate("BraytonInputWindow", "Enter the Pressure Ratio of the Compressor", nullptr));
        Compressor_Efficiency_Label->setText(QCoreApplication::translate("BraytonInputWindow", "Compressor Efficiency", nullptr));
        Compressor_eff_input->setInputMask(QString());
        Compressor_eff_input->setPlaceholderText(QCoreApplication::translate("BraytonInputWindow", "Enter the Compressor Efficiency", nullptr));
        Turbine_Efficiency_Label->setText(QCoreApplication::translate("BraytonInputWindow", "Turbine Efficiency", nullptr));
        Turbine_eff_input->setInputMask(QString());
        Turbine_eff_input->setPlaceholderText(QCoreApplication::translate("BraytonInputWindow", "Enter the Turbine Efficiency", nullptr));
        Help_Button->setText(QCoreApplication::translate("BraytonInputWindow", "Help", nullptr));
        Begin_Button->setText(QCoreApplication::translate("BraytonInputWindow", "Begin", nullptr));
        Back_Button->setText(QCoreApplication::translate("BraytonInputWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BraytonInputWindow: public Ui_BraytonInputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAYTON_INPUTS_H
