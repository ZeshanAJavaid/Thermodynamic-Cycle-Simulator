#pragma once
#include <QMainWindow>

namespace Ui { class BraytonInputWindow; }
QT_END_NAMESPACE

class BraytonInputWindow : public QMainWindow
{
    Q_OBJECT

    private slots: 
        void OpenPerformanceWindow();
        void OpenHelpWindow();
        void OpenSelectionWindow();

    private:
 
        Ui::BraytonInputWindow* ui;
        bool isHelpOpen;
        bool isErrorOpen;

    public:

        BraytonInputWindow(QWidget *parent = nullptr);
        ~BraytonInputWindow();

};