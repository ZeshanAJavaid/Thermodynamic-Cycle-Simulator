#include "../headers/error_window.h"
#include "ui_error_window.h"

ErrorWindow::ErrorWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);

    // Connect signal/slots
    connect(ui->Close_Button,&QPushButton::clicked,this,&ErrorWindow::closeWindow);
}

void ErrorWindow::closeWindow()
{
    // Closes this window 
    this->close();
    this->deleteLater();
}

void ErrorWindow::setErrorText(const QString &text)
{  
    // Sets the Error label
    this->ui->Error_Label->setText(text);
}

void ErrorWindow::setTitleText(const QString &text)
{  
    // Sets the title label
    this->ui->Title_Label->setText(text);
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}