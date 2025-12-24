#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class SelectionWindow; }
QT_END_NAMESPACE

class SelectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    SelectionWindow(QWidget *parent = nullptr);
    ~SelectionWindow();
    void OpenBraytonInputs();
    void OpenOttoInputs();
    void OpenDieselInputs();
    void OpenHelpWindow();

private:

    Ui::SelectionWindow* ui;
    bool isHelpOpen;
};