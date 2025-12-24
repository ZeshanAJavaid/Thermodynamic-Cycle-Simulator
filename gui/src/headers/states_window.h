#pragma once
#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class StateWindow; }
QT_END_NAMESPACE


class StateWindow : public QMainWindow 
{

    private slots:

        void quit();
        void OpenThermoData();
        void OpenHelpWindow();
        void OpenTsDiagram(); // @todo 
        void OpenPvDiagram(); // @todo


    private:

        Ui::StateWindow* ui;
        QStandardItemModel* csvModel;
        bool isHelpOpen;
    public: 

        StateWindow(QWidget *parent = nullptr);
        ~StateWindow();

        void loadCsvData(const QString &filepath);

};