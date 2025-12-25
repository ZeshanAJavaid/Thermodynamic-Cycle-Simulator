#include "../headers/states_window.h"
#include "ui_states_window.h"
// #include "../headers/TsDiagram.h"
// #include "../headers/PvDiagram.h"
#include "../headers/performance.h"
#include "../headers/help_window.h"
#include "../headers/error_window.h"
#include "../headers/selection.h"
#include <string>
#include <QScreen>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>



StateWindow::StateWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::StateWindow), isHelpOpen(false), csvModel(new QStandardItemModel(this))
{
    ui->setupUi(this);


    // Setup signals/slots
    connect(ui->Selection_Button, &QPushButton::clicked, this, &StateWindow::goBackToSelection); 
    // connect(ui->TsDiagram_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenTsDiagram);
    // connect(ui->pvDiagram_Button, &QPushButton::clicked, this, &PerformanceWindow::OpenPvDiagram);
    connect(ui->Performance_Button, &QPushButton::clicked, this, &StateWindow::OpenThermoData);
    connect(ui->Help_Button, &QPushButton::clicked, this, &StateWindow::OpenHelpWindow);

    // Loads the csv data into the QTableView
    loadCsvData(QString::fromStdString(std::string(PROJECT_PATH) + "/output/cycle.csv"));
    ui->States->setModel(csvModel);
    ui->States->resizeColumnsToContents();
}

void StateWindow::loadCsvData(const QString &filePath)
{

    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Check if file opened properly
        // Open Error Window 
        ErrorWindow* errorWindow = new ErrorWindow();
        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText("Unable to Open File");
        errorWindow->setErrorText("CSV File cannot be opened!\nPlease check the outputs directory and rerun simulation");
        errorWindow->show();
    }

    QTextStream in(&file);

    if (!in.atEnd()) { // Read the headers
        QString headerLine = in.readLine();
        
        QStringList headers = headerLine.split(',');
        
        csvModel->setHorizontalHeaderLabels(headers);
    }

    while (!in.atEnd()) { // Read the rest of the data
        QString line = in.readLine();
        
        if (line.trimmed().isEmpty()) {continue;}

        QStringList fields = line.split(','); 
        QList<QStandardItem *> rowItems;

        for (const QString &field : fields) {
            rowItems.append(new QStandardItem(field));
        }

        csvModel->appendRow(rowItems); // Add row to the QTableView 
    }

    file.close(); // Close file
}

StateWindow::~StateWindow()
{
    delete ui;
    delete csvModel;
}

void StateWindow::goBackToSelection()
{
    // Open Selection Window
    SelectionWindow* selection = new SelectionWindow();
    selection->setAttribute(Qt::WA_DeleteOnClose);

    // Open window in the correct position
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = selection->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    selection->move(windowGeometry.topLeft());
    selection->show();

    // Close current window
    this->close();
    this->deleteLater();
}

void StateWindow::OpenThermoData()
{
    // Open Performance Window 
    PerformanceWindow* performanceWindow = new PerformanceWindow();
    performanceWindow->setAttribute(Qt::WA_DeleteOnClose);

    // Open window in the correct position
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = performanceWindow->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    performanceWindow->move(windowGeometry.topLeft());
    performanceWindow->show();

    // Close the current window
    this->close();
    this->deleteLater();
}

void StateWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen) // Check if help window is already open
    {
        // Opens help window and sets the appropriate messages
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("Following Proccess:\n\t1. State 1 -> State 2: Compression \n\t2. State 2 -> State3: Heat Addition\n\t3. State 3 -> State 4: Expansion\n\t5. State 4 -> State 1: Heat Rejection");
        helpWindow->setTitleText("Thermodynamic States of Cycle");
        helpWindow->show();

        this->isHelpOpen = true;

        // Changes isHelpOpen once the help window is closed
        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}   

/**
 * @todo Implement the Ts and Pv diagram functions 
 * 
void PerformanceWindow::OpenTsDiagram()
{
    
}

void PerformanceWindow::OpenPvDiagram()
{
    
}
 */
