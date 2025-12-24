#include "../headers/help_window.h"
#include "ui_Help_window.h"

HelpWindow::HelpWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::HelpWindow)
{
    ui->setupUi(this);

    connect(ui->Close_Button,&QPushButton::clicked,this,&HelpWindow::closeWindow);
}

void HelpWindow::closeWindow()
{
    this->close();
}

void HelpWindow::setHelpText(const QString &text)
{
    this->ui->Help_Label->setText(text);
}

void HelpWindow::setTitleText(const QString &text)
{
    this->ui->Title_Label->setText(text);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}