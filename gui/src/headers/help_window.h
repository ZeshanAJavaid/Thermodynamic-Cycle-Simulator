#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class HelpWindow; }
QT_END_NAMESPACE

class HelpWindow : public QMainWindow
{
    Q_OBJECT


private slots:
    void closeWindow();

private:

    Ui::HelpWindow* ui;

public:
    HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

    void setHelpText(const QString &text);
    void setTitleText(const QString &text);

};