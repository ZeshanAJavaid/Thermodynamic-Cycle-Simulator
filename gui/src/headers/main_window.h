#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private slots: 
        void OpenSelectionWindow();
        void OpenHelpWindow();

    private:

        Ui::MainWindow* ui;
        bool isHelpOpen;

    public:

        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

};