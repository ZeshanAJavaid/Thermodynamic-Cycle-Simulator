#include "../headers/main_window.h"
#include "ui_main_window.h"
#include "../headers/selection.h"
#include "../headers/help_window.h"
#include <QScreen>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), isHelpOpen(false)
{
    ui->setupUi(this);

    connect(ui->Begin_Button, &QPushButton::clicked, this, &MainWindow::OpenSelectionWindow);
    connect(ui->Help_Button, &QPushButton::clicked, this, &MainWindow::OpenHelpWindow);
}

void MainWindow::OpenSelectionWindow()
{

    SelectionWindow* selectionwindow = new SelectionWindow();
    selectionwindow->setAttribute(Qt::WA_DeleteOnClose);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = selectionwindow->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    selectionwindow->move(windowGeometry.topLeft());

    selectionwindow->show();
    this->hide();
}

void MainWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen)
    {
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("This program simulates three basic cycles: \n\t1.Brayton -> Airplane Propulsion Systems \n\t2.Otto -> Small applications such as lawnmowers \n\t3.Diesel -> Diesel engines that power semi-trucks \n\n1. Begin Simulations -> To begin your simulation, Click the Begin button to go to the Cycle Selection page!");
        helpWindow->setTitleText("Welcome to Thermodynamic Simulator!");
        helpWindow->show();

        this->isHelpOpen = true;

        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}