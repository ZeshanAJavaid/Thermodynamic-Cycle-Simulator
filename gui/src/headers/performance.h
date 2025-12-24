#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PerformanceWindow; }
QT_END_NAMESPACE


class PerformanceWindow : public QMainWindow 
{

    private slots:

        void quit();
        void OpenThermoData();
        void OpenHelpWindow();
        void OpenTsDiagram(); // @todo 
        void OpenPvDiagram(); // @todo


    private:

        Ui::PerformanceWindow* ui;
        bool isHelpOpen;
    public: 

        PerformanceWindow(QWidget *parent = nullptr);
        ~PerformanceWindow();
};