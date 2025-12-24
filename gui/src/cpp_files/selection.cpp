#include "../headers/selection.h"
#include "ui_selector_window.h"
#include "../headers/brayton_inputs.h"
#include "../headers/otto_inputs.h"
#include "../headers/diesel_inputs.h"
#include "../headers/help_window.h"
#include <QScreen>


SelectionWindow::SelectionWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::SelectionWindow), isHelpOpen(false)
{
    ui->setupUi(this);

    connect(ui->Brayton_Button,&QPushButton::clicked,this,&SelectionWindow::OpenBraytonInputs);
    connect(ui->Otto_Button,&QPushButton::clicked,this,&SelectionWindow::OpenOttoInputs);
    connect(ui->Diesel_Button,&QPushButton::clicked,this,&SelectionWindow::OpenDieselInputs);
    connect(ui->Help_Button,&QPushButton::clicked,this,&SelectionWindow::OpenHelpWindow);
}

SelectionWindow::~SelectionWindow()
{
    delete ui;
}

void SelectionWindow::OpenBraytonInputs()
{
    BraytonInputWindow* brayton = new BraytonInputWindow();
    brayton->setAttribute(Qt::WA_DeleteOnClose);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = brayton->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    brayton->move(windowGeometry.topLeft());

    brayton->show();

    this->close();
    this->deleteLater();
}

void SelectionWindow::OpenOttoInputs()
{
    OttoInputWindow* otto = new OttoInputWindow();
    otto->setAttribute(Qt::WA_DeleteOnClose);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = otto->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    otto->move(windowGeometry.topLeft());
    otto->show();

    this->close();
    this->deleteLater();
}

void SelectionWindow::OpenDieselInputs()
{
    DieselInputWindow* diesel = new DieselInputWindow();
    diesel->setAttribute(Qt::WA_DeleteOnClose);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = diesel->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    diesel->move(windowGeometry.topLeft());
    diesel->show();

    this->close();
    this->deleteLater();
}

void SelectionWindow::OpenHelpWindow()
{
    if(!this->isHelpOpen)
    {
        HelpWindow* helpWindow = new HelpWindow();
        helpWindow->setAttribute(Qt::WA_DeleteOnClose);
        helpWindow->setHelpText("There are three possible cycles to choose from:\n\t1. Brayton Cycle\n\t2. Otto Cycle\n\t3. Diesel Cycle\n\n");
        helpWindow->setTitleText("Selection Window");
        helpWindow->show();

        this->isHelpOpen = true;

        connect(helpWindow, &QObject::destroyed, this, [this](){
            this->isHelpOpen = false;
        });
    }
}
