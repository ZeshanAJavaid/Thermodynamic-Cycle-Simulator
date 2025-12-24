#include "../headers/brayton_inputs.h"
#include "ui_brayton_inputs.h"
#include "../headers/selection.h"
#include "../headers/help_window.h"
#include "../headers/performance.h"
#include "../headers/error_window.h"
#include "../../../computation/computation.h"
#include <QScreen>


BraytonInputWindow::BraytonInputWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::BraytonInputWindow), isHelpOpen(false), isErrorOpen(false)
{
    ui -> setupUi(this);

    connect(ui->Begin_Button,&QPushButton::clicked,this,&BraytonInputWindow::OpenPerformanceWindow);
    connect(ui->Back_Button,&QPushButton::clicked,this,&BraytonInputWindow::OpenSelectionWindow);
    connect(ui->Help_Button,&QPushButton::clicked,this,&BraytonInputWindow::OpenHelpWindow);

}

BraytonInputWindow::~BraytonInputWindow()
{
    delete ui;
}


void BraytonInputWindow::OpenPerformanceWindow()
{
    QString temperature, pressure, pressure_ratio, compressor_eff, turbine_eff;
    double dTemperature, dPressure, dPressure_ratio, dCompressor_eff, dTurbine_eff;
    bool toDouble;

    temperature = ui->Temperature_Input->text();
    pressure = ui->Pressure_Input->text();
    pressure_ratio = ui->Pressure_Ratio_Input->text();
    compressor_eff = ui->Compressor_eff_input->text();
    turbine_eff = ui->Turbine_eff_input->text();


    dTemperature = temperature.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Temperature! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        }   
    }
    dPressure = pressure.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Pressure! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        }  
    }
    dPressure_ratio = pressure_ratio.QString::toDouble(&toDouble);
    if(!toDouble)
    {
       if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Pressure Ratio! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        } 
    }
    dCompressor_eff = compressor_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Compressor Efficiency! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        } 
    }
    dTurbine_eff = turbine_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Turbine Efficiency! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        } 
    }
    else
    {
        Computation* brayton = new Computation(Cycles(0),dPressure,dTemperature,dPressure_ratio,dCompressor_eff,dTurbine_eff);
        brayton->compute();
        delete brayton;
    }   
    

    PerformanceWindow* performanceWindow = new PerformanceWindow();
    performanceWindow->setAttribute(Qt::WA_DeleteOnClose);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = performanceWindow->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    performanceWindow->move(windowGeometry.topLeft());
    performanceWindow->show();

    this->close();
    this->deleteLater();
}

void BraytonInputWindow::OpenSelectionWindow()
{   
    SelectionWindow* selections = new SelectionWindow();
    selections->setAttribute(Qt::WA_DeleteOnClose);
    
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = selections->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    selections->move(windowGeometry.topLeft());
    selections->show();

    this->close();
    this->deleteLater();
}

void BraytonInputWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen)
    {
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("Input Parameters:\n\t1. Temperature (Kelvins)\n\t2. Pressure (Kilo-Pascals)\n\t3. Pressure Ratio (P2 / P1)\n\t4. Compressor Isentropic Efficiency (%)\n\t5. Turbine Isentropic Efficiency (%)");
        helpWindow->setTitleText("Brayton Cycle Inputs");
        helpWindow->show();

        this->isHelpOpen = true;

        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}

