#include "../headers/performance.h"
#include "ui_Performance_window.h"
// #include "../headers/TsDiagram.h"
// #include "../headers/PvDiagram.h"
#include "../headers/states_window.h"
#include "../headers/error_window.h"
#include "../headers/help_window.h"
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

    connect(ui->Quit_Button, &QPushButton::clicked, this, &PerformanceWindow::quit); 
    // connect();
    // connect();
    connect(ui->Data_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenThermoData);
    connect(ui->Help_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenHelpWindow);

    std::ifstream ifs(std::string(PROJECT_PATH) +"/output/performance.csv");
    if(!ifs.is_open())
    {
        ErrorWindow* errorWindow = new ErrorWindow();

        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText("Unable to Open File");
        errorWindow->setErrorText("CSV File cannot be opened!\nPlease check the outputs directory and rerun simulation");
        errorWindow->show();
        
        this->close();
        this->deleteLater();
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

void PerformanceWindow::quit()
{
    QApplication::quit();
}

void PerformanceWindow::OpenThermoData()
{
    StateWindow* states = new StateWindow();
    states->setAttribute(Qt::WA_DeleteOnClose);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = states->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    states->move(windowGeometry.topLeft());
    states->show();

    this->close();
    this->deleteLater();
}

void PerformanceWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen)
    {
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("The following attributes are shown:\n\t1. Efficiency -> W_cycle / Q_in or 1 - Q_out / Q_in\n\t2. Work of Cycle -> W_cycle = W_comp - W_expan\n\t3. Work of Compression/Compressor -> W_comp = h2 - h1\n\t4.  Work of Expansion/Turbine -> W_exp/turbine = h3 - h4\n\t5. Heat in -> Q_in = h3 - h2\n\t6. Heat out -> Q_out = h4 - h1");
        helpWindow->setTitleText("Thermodynamic Performance of Cycle");
        helpWindow->show();

        this->isHelpOpen = true;

        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}   

// void PerformanceWindow::OpenTsDiagram()
// {
    
// }

// void PerformanceWindow::OpenPvDiagram()
// {
    
// }