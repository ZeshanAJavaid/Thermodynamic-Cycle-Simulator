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
    bool toDouble;

    temperature = ui->initial_temperature_input->text();
    pressure = ui->Initial_pressure_input->text();
    compression_ratio = ui->Ratio_Input->text();
    compression_eff = ui->Compression_eff_input->text();
    expansion_eff = ui->Expansion_eff_input->text();


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
    dCompression_ratio = compression_ratio.QString::toDouble(&toDouble);
    if(!toDouble)
    {
        if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Compression Ratio! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        } 
    }
    dCompression_eff = compression_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
       if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Compression Efficiency! Please enter a number!");
            errorWindow->show();

            this->isErrorOpen = true;

            connect(errorWindow, &QObject::destroyed, this, [this](){
                this->isErrorOpen = false;
            });

            return;
        } 
    }
    dExpansion_eff = expansion_eff.QString::toDouble(&toDouble);
    if(!toDouble)
    {
       if(!this->isErrorOpen)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("Incorrect Input Type");
            errorWindow->setErrorText("Incorrect Input for Expansion Efficiency! Please enter a number!");
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
        Computation* otto = new Computation(Cycles(1),dPressure,dTemperature,dCompression_ratio,dCompression_eff,dExpansion_eff);
        otto->compute();
        delete otto;
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

void OttoInputWindow::OpenSelectionWindow()
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

void OttoInputWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen)
    {
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("Input Parameters:\n\t1. Temperature (Kelvins)\n\t2. Pressure (Kilo-Pascals)\n\t3. Compression Ratio (V1 / V2)\n\t4. Compression Isentropic Efficiency (%)\n\t5. Expansion Isentropic Efficiency (%)");
        helpWindow->setTitleText("Otto Cycle Inputs");
        helpWindow->show();

        this->isHelpOpen = true;

        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}

