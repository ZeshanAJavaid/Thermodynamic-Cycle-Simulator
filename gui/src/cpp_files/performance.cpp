#include "../headers/performance.h"
#include "ui_performance_window.h"
#include "../headers/diagram_generation.h"
#include "../headers/states_window.h"
#include "../headers/error_window.h"
#include "../headers/help_window.h"
#include "../headers/selection.h"
#include <QScreen>
#include <QApplication>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <fstream>
#include <string>




PerformanceWindow::PerformanceWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::PerformanceWindow), isHelpOpen(false)
{
    ui->setupUi(this);

    // Connect signal/slots
    connect(ui->Selection_Button, &QPushButton::clicked, this, &PerformanceWindow::goBackToSelection); 
    connect(ui->TsDiagram_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenTsDiagram);
    connect(ui->pvDiagram_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenPvDiagram);
    connect(ui->Data_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenThermoData);
    connect(ui->Help_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenHelpWindow);

    // Populate the outputs
    this->performancefileName = std::string(PROJECT_PATH) + "/output/performance.csv";
    this->statefileName = std::string(PROJECT_PATH) + "/output/cycle.csv";
    std::ifstream ifs(this->performancefileName);
    if(!ifs.is_open())
    {
        ErrorWindow* errorWindow = new ErrorWindow();

        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText("Unable to Open File");
        errorWindow->setErrorText("CSV File cannot be opened!\nPlease check the outputs directory and rerun simulation");
        errorWindow->show();
    }
    else
    {
        std::string trash, raw_line;

        std::getline(ifs,trash);
        std::getline(ifs,raw_line);

        QString line = QString::fromStdString(raw_line);

        QStringList data = line.split(",");

        ui->Efficiency_Output->setText(data.at(0));
        ui->Work_Cycle_Output->setText(data.at(1));
        ui->Work_Compression_Output->setText(data.at(2));
        ui->Work_Expansion_Output->setText(data.at(3));
        ui->Heat_In_Output->setText(data.at(4));
        ui->Heat_Out_Output->setText(data.at(5));
    }
    
}

PerformanceWindow::~PerformanceWindow()
{
    delete ui;
}

void PerformanceWindow::goBackToSelection()
{   
    // Open Selection window
    SelectionWindow* selection = new SelectionWindow();
    selection->setAttribute(Qt::WA_DeleteOnClose);

    // open window in the correct position
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = selection->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    selection->move(windowGeometry.topLeft());
    selection->show();

    // close current window
    this->close();
    this->deleteLater();
}

void PerformanceWindow::OpenThermoData()
{
    // Open states window
    StateWindow* states = new StateWindow();
    states->setAttribute(Qt::WA_DeleteOnClose);
    // Open window in the correct position
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = states->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    states->move(windowGeometry.topLeft());
    states->show();

    // Close current window
    this->close();
    this->deleteLater();
}

void PerformanceWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen) // Check if help window is open
    {
        // Open help window and set appropriate messages
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("The following attributes are shown:\n\t1. Efficiency -> W_cycle / Q_in or 1 - Q_out / Q_in\n\t2. Work of Cycle -> W_cycle = W_comp - W_expan\n\t3. Work of Compression/Compressor -> W_comp = h2 - h1\n\t4.  Work of Expansion/Turbine -> W_exp/turbine = h3 - h4\n\t5. Heat in -> Q_in = h3 - h2\n\t6. Heat out -> Q_out = h4 - h1\n\nButtons:\n\t1. Selection -> Opens the selection window\n\t2. Ts Diagram -> Currently unavailable\n\t3. pv Diagram -> Currently unavailable\n\t4. Data -> Opens a window that contains all the thermodynamic states.\n\t5.Help -> Opens this window");
        helpWindow->setTitleText("Thermodynamic Performance of Cycle");
        helpWindow->show();

        this->isHelpOpen = true;

        // Change isHelpOpen once the help window closes
        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}   

 
void PerformanceWindow::OpenTsDiagram()
{
    TsDataPoints* tsDiagram = new TsDataPoints(this->statefileName);
    tsDiagram->graphTsDiagram();
}

void PerformanceWindow::OpenPvDiagram()
{
    PvDataPoints* pvDiagram = new PvDataPoints(this->statefileName);
    pvDiagram->graphPvDiagram();
}   