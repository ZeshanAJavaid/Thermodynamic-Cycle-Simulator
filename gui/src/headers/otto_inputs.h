#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class OttoInputWindow; }
QT_END_NAMESPACE

class OttoInputWindow : public QMainWindow
{
    Q_OBJECT

    private slots: 
        void OpenPerformanceWindow();
        void OpenHelpWindow();
        void OpenSelectionWindow();

    private:

        Ui::OttoInputWindow* ui;
        bool isHelpOpen;
        bool isErrorOpen;

    public:

        OttoInputWindow(QWidget *parent = nullptr);
        ~OttoInputWindow();

};