#include "../headers/states_window.h"
#include "ui_States_window.h"
// #include "../headers/TsDiagram.h"
// #include "../headers/PvDiagram.h"
#include "../headers/performance.h"
#include "../headers/help_window.h"
#include "../headers/error_window.h"
#include <string>
#include <QScreen>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>



StateWindow::StateWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::StateWindow), isHelpOpen(false), csvModel(new QStandardItemModel(this))
{
    ui->setupUi(this);



    connect(ui->Quit_Button, &QPushButton::clicked, this, &StateWindow::quit); 
    // connect();
    // connect();
    connect(ui->Performance_Button, &QPushButton::clicked, this, &StateWindow::OpenThermoData);
    connect(ui->Help_Button, &QPushButton::clicked, this, &StateWindow::OpenHelpWindow);

    loadCsvData(std::string(PROJECT_PATH) +"/output/cycle.csv");

    ui->States->setModel(csvModel);
    ui->States->resizeColumnsToContents();
}

void StateWindow::loadCsvData(const QString &filePath)
{

    // 2. Open the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ErrorWindow* errorWindow = new ErrorWindow();

        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText("Unable to Open File");
        errorWindow->setErrorText("CSV File cannot be opened!\nPlease check the outputs directory and rerun simulation");
        errorWindow->show();
        
        this->close();
        this->deleteLater();
    }

    QTextStream in(&file);

    if (!in.atEnd()) {
        QString headerLine = in.readLine();
        
        QStringList headers = headerLine.split(','); 
        
        csvModel->setHorizontalHeaderLabels(headers);
    }

    while (!in.atEnd()) {
        QString line = in.readLine();
        
        if (line.trimmed().isEmpty()) continue;

        QStringList fields = line.split(',');
        QList<QStandardItem *> rowItems;

        for (const QString &field : fields) {
            rowItems.append(new QStandardItem(field));
        }

        csvModel->appendRow(rowItems);
    }

    file.close();
}

StateWindow::~StateWindow()
{
    delete ui;
    delete csvModel;
}

void StateWindow::quit()
{
    QApplication::quit();
}

void StateWindow::OpenThermoData()
{
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

void StateWindow::OpenHelpWindow()
{
     if(!this->isHelpOpen)
    {
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("Following Proccess:\n\t1. State 1 -> State 2: Compression \n\t2. State 2 -> State3: Heat Addition\n\t3. State 3 -> State 4: Expansion\n\t5. State 4 -> State 1: Heat Rejection");
        helpWindow->setTitleText("Thermodynamic States of Cycle");
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