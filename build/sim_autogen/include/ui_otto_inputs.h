/********************************************************************************
** Form generated from reading UI file 'otto_inputs.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTTO_INPUTS_H
#define UI_OTTO_INPUTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OttoInputWindow
{
public:
    QWidget *centralwidget;
    QLabel *Compression_Ratio_Label;
    QLabel *Expansion_Efficiency_Label;
    QLabel *Initial_Temperature_Label;
    QLabel *Compression_Efficiency_Label;
    QLabel *Initial_Pressure_Label;
    QLineEdit *Expansion_eff_input;
    QLabel *Otto_Image;
    QLabel *Title;
    QLineEdit *Compression_eff_input;
    QLineEdit *Ratio_Input;
    QLineEdit *Initial_pressure_input;
    QLineEdit *initial_temperature_input;
    QPushButton *Help_Button;
    QPushButton *Begin_Button;
    QPushButton *Back_Button;

    void setupUi(QMainWindow *OttoInputWindow)
    {
        if (OttoInputWindow->objectName().isEmpty())
            OttoInputWindow->setObjectName("OttoInputWindow");
        OttoInputWindow->resize(1019, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OttoInputWindow->sizePolicy().hasHeightForWidth());
        OttoInputWindow->setSizePolicy(sizePolicy);
        OttoInputWindow->setMinimumSize(QSize(1019, 633));
        OttoInputWindow->setMaximumSize(QSize(1019, 633));
        OttoInputWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 29, 11);\n"
"color: rgb(255,255,255);\n"
"\n"
""));
        centralwidget = new QWidget(OttoInputWindow);
        centralwidget->setObjectName("centralwidget");
        Compression_Ratio_Label = new QLabel(centralwidget);
        Compression_Ratio_Label->setObjectName("Compression_Ratio_Label");
        Compression_Ratio_Label->setGeometry(QRect(540, 260, 471, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font.setPointSize(11);
        font.setBold(true);
        Compression_Ratio_Label->setFont(font);
        Compression_Ratio_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(252, 140, 3)"));
        Compression_Ratio_Label->setAlignment(Qt::AlignCenter);
        Expansion_Efficiency_Label = new QLabel(centralwidget);
        Expansion_Efficiency_Label->setObjectName("Expansion_Efficiency_Label");
        Expansion_Efficiency_Label->setGeometry(QRect(540, 440, 471, 41));
        Expansion_Efficiency_Label->setFont(font);
        Expansion_Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(252, 140, 3)"));
        Expansion_Efficiency_Label->setAlignment(Qt::AlignCenter);
        Initial_Temperature_Label = new QLabel(centralwidget);
        Initial_Temperature_Label->setObjectName("Initial_Temperature_Label");
        Initial_Temperature_Label->setGeometry(QRect(540, 80, 471, 41));
        Initial_Temperature_Label->setFont(font);
        Initial_Temperature_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(252, 140, 3)"));
        Initial_Temperature_Label->setAlignment(Qt::AlignCenter);
        Compression_Efficiency_Label = new QLabel(centralwidget);
        Compression_Efficiency_Label->setObjectName("Compression_Efficiency_Label");
        Compression_Efficiency_Label->setGeometry(QRect(540, 350, 471, 41));
        Compression_Efficiency_Label->setFont(font);
        Compression_Efficiency_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(252, 140, 3)"));
        Compression_Efficiency_Label->setAlignment(Qt::AlignCenter);
        Initial_Pressure_Label = new QLabel(centralwidget);
        Initial_Pressure_Label->setObjectName("Initial_Pressure_Label");
        Initial_Pressure_Label->setGeometry(QRect(540, 170, 471, 41));
        Initial_Pressure_Label->setFont(font);
        Initial_Pressure_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(252, 140, 3)"));
        Initial_Pressure_Label->setAlignment(Qt::AlignCenter);
        Expansion_eff_input = new QLineEdit(centralwidget);
        Expansion_eff_input->setObjectName("Expansion_eff_input");
        Expansion_eff_input->setGeometry(QRect(540, 490, 471, 31));
        Expansion_eff_input->setFont(font);
        Expansion_eff_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(206, 88, 4)"));
        Expansion_eff_input->setMaxLength(4);
        Expansion_eff_input->setAlignment(Qt::AlignCenter);
        Otto_Image = new QLabel(centralwidget);
        Otto_Image->setObjectName("Otto_Image");
        Otto_Image->setGeometry(QRect(0, 80, 521, 511));
        Otto_Image->setPixmap(QPixmap(QString::fromUtf8(":/gui/graphics/otto_cycle.png")));
        Otto_Image->setScaledContents(true);
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(0, 10, 1011, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font1.setPointSize(28);
        font1.setBold(true);
        Title->setFont(font1);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        Title->setAlignment(Qt::AlignCenter);
        Compression_eff_input = new QLineEdit(centralwidget);
        Compression_eff_input->setObjectName("Compression_eff_input");
        Compression_eff_input->setGeometry(QRect(540, 400, 471, 31));
        Compression_eff_input->setFont(font);
        Compression_eff_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(206, 88, 4)"));
        Compression_eff_input->setMaxLength(4);
        Compression_eff_input->setAlignment(Qt::AlignCenter);
        Ratio_Input = new QLineEdit(centralwidget);
        Ratio_Input->setObjectName("Ratio_Input");
        Ratio_Input->setGeometry(QRect(540, 310, 471, 31));
        Ratio_Input->setFont(font);
        Ratio_Input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(206, 88, 4)"));
        Ratio_Input->setMaxLength(3);
        Ratio_Input->setAlignment(Qt::AlignCenter);
        Initial_pressure_input = new QLineEdit(centralwidget);
        Initial_pressure_input->setObjectName("Initial_pressure_input");
        Initial_pressure_input->setGeometry(QRect(540, 220, 471, 31));
        Initial_pressure_input->setFont(font);
        Initial_pressure_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(206, 88, 4)"));
        Initial_pressure_input->setMaxLength(6);
        Initial_pressure_input->setAlignment(Qt::AlignCenter);
        initial_temperature_input = new QLineEdit(centralwidget);
        initial_temperature_input->setObjectName("initial_temperature_input");
        initial_temperature_input->setGeometry(QRect(540, 130, 471, 31));
        initial_temperature_input->setFont(font);
        initial_temperature_input->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(206, 88, 4)"));
        initial_temperature_input->setMaxLength(6);
        initial_temperature_input->setAlignment(Qt::AlignCenter);
        Help_Button = new QPushButton(centralwidget);
        Help_Button->setObjectName("Help_Button");
        Help_Button->setGeometry(QRect(540, 540, 141, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fira Code SemiBold")});
        font2.setPointSize(16);
        font2.setBold(true);
        Help_Button->setFont(font2);
        Help_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(152, 51, 0)"));
        Begin_Button = new QPushButton(centralwidget);
        Begin_Button->setObjectName("Begin_Button");
        Begin_Button->setGeometry(QRect(860, 540, 141, 51));
        Begin_Button->setFont(font2);
        Begin_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(152, 51, 0)"));
        Back_Button = new QPushButton(centralwidget);
        Back_Button->setObjectName("Back_Button");
        Back_Button->setGeometry(QRect(700, 540, 141, 51));
        Back_Button->setFont(font2);
        Back_Button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color: rgb(152, 51, 0)"));
        OttoInputWindow->setCentralWidget(centralwidget);

        retranslateUi(OttoInputWindow);

        QMetaObject::connectSlotsByName(OttoInputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OttoInputWindow)
    {
        OttoInputWindow->setWindowTitle(QCoreApplication::translate("OttoInputWindow", "Thermodynamic Simulator", nullptr));
        Compression_Ratio_Label->setText(QCoreApplication::translate("OttoInputWindow", "Compression Ratio", nullptr));
        Expansion_Efficiency_Label->setText(QCoreApplication::translate("OttoInputWindow", "Expansion Efficiency", nullptr));
        Initial_Temperature_Label->setText(QCoreApplication::translate("OttoInputWindow", "Initial Temperature (K)", nullptr));
        Compression_Efficiency_Label->setText(QCoreApplication::translate("OttoInputWindow", "Compression Efficiency", nullptr));
        Initial_Pressure_Label->setText(QCoreApplication::translate("OttoInputWindow", "Initial Pressure (kPa)", nullptr));
        Expansion_eff_input->setInputMask(QString());
        Expansion_eff_input->setPlaceholderText(QCoreApplication::translate("OttoInputWindow", "Enter the Expansion Efficiency", nullptr));
        Otto_Image->setText(QString());
        Title->setText(QCoreApplication::translate("OttoInputWindow", "Input Otto Cycle Properties:", nullptr));
        Compression_eff_input->setInputMask(QString());
        Compression_eff_input->setPlaceholderText(QCoreApplication::translate("OttoInputWindow", "Enter the Compression Efficiency", nullptr));
        Ratio_Input->setInputMask(QString());
        Ratio_Input->setPlaceholderText(QCoreApplication::translate("OttoInputWindow", "Enter the Compression Ratio", nullptr));
        Initial_pressure_input->setInputMask(QString());
        Initial_pressure_input->setPlaceholderText(QCoreApplication::translate("OttoInputWindow", "Enter the Initial Pressure in kPa", nullptr));
        initial_temperature_input->setInputMask(QString());
        initial_temperature_input->setPlaceholderText(QCoreApplication::translate("OttoInputWindow", "Enter the Initial Temperature in Kelvins", nullptr));
        Help_Button->setText(QCoreApplication::translate("OttoInputWindow", "Help", nullptr));
        Begin_Button->setText(QCoreApplication::translate("OttoInputWindow", "Begin", nullptr));
        Back_Button->setText(QCoreApplication::translate("OttoInputWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OttoInputWindow: public Ui_OttoInputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTTO_INPUTS_H
