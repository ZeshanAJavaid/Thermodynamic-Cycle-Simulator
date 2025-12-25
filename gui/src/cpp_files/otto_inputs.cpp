#include "../headers/otto_inputs.h"
#include "ui_otto_inputs.h"
#include "../headers/selection.h"
#include "../headers/help_window.h"
#include "../headers/performance.h"
#include "../headers/error_window.h"
#include "../../../computation/computation.h"
#include <QScreen>


OttoInputWindow::OttoInputWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::OttoInputWindow), isHelpOpen(false)
{
    ui -> setupUi(this);

    // Connect signal/slots
    connect(ui->Begin_Button,&QPushButton::clicked,this,&OttoInputWindow::OpenPerformanceWindow);
    connect(ui->Back_Button,&QPushButton::clicked,this,&OttoInputWindow::OpenSelectionWindow);
    connect(ui->Help_Button,&QPushButton::clicked,this,&OttoInputWindow::OpenHelpWindow);

}

OttoInputWindow::~OttoInputWindow()
{
    delete ui;
}


void OttoInputWindow::OpenPerformanceWindow()
{
    QString temperature, pressure, compression_ratio, compression_eff, expansion_eff;
    double dTemperature, dPressure, dCompression_ratio, dCompression_eff, dExpansion_eff;
    bool toDouble; // check if successful conversion from QString to Double

    temperature = ui->initial_temperature_input->text();
    pressure = ui->Initial_pressure_input->text();
    compression_ratio = ui->Ratio_Input->text();
    compression_eff = ui->Compression_eff_input->text();
    expansion_eff = ui->Expansion_eff_input->text();

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
            showErrorWindow("Invalid Input!","Invalid input for Temperature! Please enter a number.");
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
            showErrorWindow("Invalid Input!","Invalid input for Pressure! Please enter a number.");
            return;
        } 
    }
    else if(dPressure > 1000.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Pressure! Please try again!");
        return;
    }
    dCompression_ratio = compression_ratio.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input!","Invalid input for Compression Ratio! Please enter a number.");
            return;
        } 
    }
    else if(dCompression_ratio > 60.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Compression Ratio! Please try again!");
        return;
    }
    dCompression_eff = compression_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input!","Invalid input for Compression Efficiency! Please enter a number.");
            return;
        }  
    }
    else if(dCompression_eff > 100.0 || dCompression_eff < 0.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Compression Efficiency! Please try again!");
        return;
    }
    dExpansion_eff = expansion_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            showErrorWindow("Invalid Input!","Invalid input for Expansion Efficiency! Please enter a number.");
            return;
        } 
    }
    else if(dExpansion_eff > 100.0 || dExpansion_eff < 0.0)
    {
        showErrorWindow("Unrealistic Input","Unrealisitc Expansion Efficiency! Please try again!");
        return;
    }
    else
    {   
        // Computation
        Computation* otto = new Computation(Cycles(1),dPressure,dTemperature,dCompression_ratio,dCompression_eff,dExpansion_eff);
        otto->compute();
        delete otto;
    }   
    
    // Open Performance window
    PerformanceWindow* performanceWindow = new PerformanceWindow();
    performanceWindow->setAttribute(Qt::WA_DeleteOnClose);

    // Open window in the correct position
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

void OttoInputWindow::OpenSelectionWindow()
{   
    // Open selection window
    SelectionWindow* selections = new SelectionWindow();
    selections->setAttribute(Qt::WA_DeleteOnClose);

    // Open window in the correct position
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

void OttoInputWindow::OpenHelpWindow()
{  
    if(!this->isHelpOpen) // Check if help window is already open
    {   
        // Open help window and set the appropriate messgaes
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("Input Parameters:\n\t1. Temperature (Kelvins)\n\t2. Pressure (Kilo-Pascals)\n\t3. Compression Ratio (V1 / V2)\n\t4. Compression Isentropic Efficiency (%)\n\t5. Expansion Isentropic Efficiency (%)\n\nButtons:\n\t1. Back -> Returns to the selection page\n\t2. Begin -> Proceeds to the performance page.\n\t3. Help -> Opens this window.");
        helpWindow->setTitleText("Otto Cycle Inputs");
        helpWindow->show();

        this->isHelpOpen = true;

        // Change isHelpOpen once the window is closed
        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}

