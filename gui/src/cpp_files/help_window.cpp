#include "../headers/help_window.h"
#include "ui_help_window.h"

HelpWindow::HelpWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    
    // Connect signal/slots
    connect(ui->Close_Button,&QPushButton::clicked,this,&HelpWindow::closeWindow);
}

void HelpWindow::closeWindow()
{
    // Close help window
    this->close();
    this->deleteLater();
}

void HelpWindow::setHelpText(const QString &text)
{
    // Set the Help Text
    this->ui->Help_Label->setText(text);
}

void HelpWindow::setTitleText(const QString &text)
{
    // Set the Title text
    this->ui->Title_Label->setText(text);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}