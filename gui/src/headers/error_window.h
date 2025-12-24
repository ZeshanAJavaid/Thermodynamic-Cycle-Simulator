#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class ErrorWindow; }
QT_END_NAMESPACE

class ErrorWindow : public QMainWindow
{
    Q_OBJECT


private slots:
    void closeWindow();

private:

    Ui::ErrorWindow* ui;

public:
    ErrorWindow(QWidget *parent = nullptr);
    ~ErrorWindow();

    void setTitleText(const QString &text);
    void setErrorText(const QString &text);

};