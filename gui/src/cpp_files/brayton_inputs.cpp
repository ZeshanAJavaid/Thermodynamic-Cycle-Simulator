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

    // Define the signal/slot connections
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
    bool toDouble; // Check if each QString to Double conversion was successful

    temperature = ui->Temperature_Input->text();
    pressure = ui->Pressure_Input->text();
    pressure_ratio = ui->Pressure_Ratio_Input->text();
    compressor_eff = ui->Compressor_eff_input->text();
    turbine_eff = ui->Turbine_eff_input->text();

    // Define a lamda function that shows an error window
    auto showErrorWindow = [this](QString title, QString errorText) {
        
        ErrorWindow* errorWindow = new ErrorWindow();
        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText(title);
        errorWindow->setErrorText(errorText);
        errorWindow->show();

        this->isErrorOpen = true;

        connect(errorWindow, &QObject::destroyed, this, [this](){
            this->isErrorOpen = false;
        });
    };


    // Input Validation
    dTemperature = temperature.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input Type","Invalid Input for Temperature! Please enter a number!");
            return;
        }
    }
    else if(dTemperature > 500.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Temperature! Please try again!");
        return;
    }
    dPressure = pressure.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input Type","Invalid Input for Pressure! Please enter a number!");
            return;
        }
    }
    else if(dPressure > 1000.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Pressure! Please try again!");
        return;
    }
    dPressure_ratio = pressure_ratio.QString::toDouble(&toDouble);
    if(!toDouble)
    {
       if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input Type","Invalid Input for Pressure Ratio! Please enter a number!");
            return;
        }
    }
    else if(dPressure_ratio > 60.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Pressure Ratio! Please try again!");
        return;
    }
    dCompressor_eff = compressor_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input Type","Invalid Input for Compressor Efficiency! Please enter a number!");
            return;
        }
    }
    else if(dCompressor_eff > 100.0 || dCompressor_eff < 0.0)
    {
            showErrorWindow("Unrealistic Input","Unrealisitc Compressor Efficiency! Please try again!");
            return;
    }
    dTurbine_eff = turbine_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input Type","Invalid Input for Turbine Efficiency! Please enter a number!");
            return;
        }
    }
    else if(dTurbine_eff > 100.0 || dTurbine_eff < 0.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Turbine Efficiency! Please try again!");
        return;
    }
    else
    {
        // Computation
        Computation* brayton = new Computation(Cycles(0),dPressure,dTemperature,dPressure_ratio,dCompressor_eff,dTurbine_eff);
        brayton->compute();
        delete brayton;
    }   
    
    // Open performance window
    PerformanceWindow* performanceWindow = new PerformanceWindow();
    performanceWindow->setAttribute(Qt::WA_DeleteOnClose);

    // Open performance window in the correct posisition
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = performanceWindow->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    performanceWindow->move(windowGeometry.topLeft());
    performanceWindow->show();

    // Close current window
    this->close();
    this->deleteLater();
}

void BraytonInputWindow::OpenSelectionWindow()
{  
    // Open Selection window
    SelectionWindow* selections = new SelectionWindow();
    selections->setAttribute(Qt::WA_DeleteOnClose);

    // Open in the correct position
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = selections->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    selections->move(windowGeometry.topLeft());
    selections->show();

    // Close current window
    this->close();
    this->deleteLater();
}

void BraytonInputWindow::OpenHelpWindow()
{   
    if(!this->isHelpOpen) // check if help window is already open or not
    {   
        // Open help window and set the message
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("Input Parameters:\n\t1. Temperature (Kelvins)\n\t2. Pressure (Kilo-Pascals)\n\t3. Pressure Ratio (P2 / P1)\n\t4. Compressor Isentropic Efficiency (%)\n\t5. Turbine Isentropic Efficiency (%)\n\n Buttons:\n\t1. Back -> Returns to the selection page\n\t2. Begin -> Proceeds to the performance page.\n\t3. Help -> Opens this window.");
        helpWindow->setTitleText("Brayton Cycle Inputs");
        helpWindow->show();

        this->isHelpOpen = true;

        // change the booleon once the window is closed
        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}

