#pragma once
#include <QMainWindow>

namespace Ui { class DieselInputWindow; }
QT_END_NAMESPACE

class DieselInputWindow : public QMainWindow
{
    Q_OBJECT

    private slots: 
        void OpenPerformanceWindow();
        void OpenHelpWindow();
        void OpenSelectionWindow();

    private:

        Ui::DieselInputWindow* ui;
        bool isHelpOpen;
        bool isErrorOpen;

    public:

        DieselInputWindow(QWidget *parent = nullptr);
        ~DieselInputWindow();

};