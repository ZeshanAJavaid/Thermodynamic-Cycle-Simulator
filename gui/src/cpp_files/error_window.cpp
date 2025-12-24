#include "../headers/error_window.h"
#include "ui_incorrect_input_window.h"

ErrorWindow::ErrorWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);

    connect(ui->Close_Button,&QPushButton::clicked,this,&ErrorWindow::closeWindow);
}

void ErrorWindow::closeWindow()
{
    this->close();
}

void ErrorWindow::setErrorText(const QString &text)
{
    this->ui->Error_Label->setText(text);
}

void ErrorWindow::setTitleText(const QString &text)
{
    this->ui->Title_Label->setText(text);
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}