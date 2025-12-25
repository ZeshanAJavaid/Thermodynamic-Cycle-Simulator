#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // Define namespace so the generated ui class doesnt conflict with our definition. 
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private slots: 

        /**
         * @brief Opens the Selection Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; closes the main window and opens the selection window
         */
        void OpenSelectionWindow();

        /**
         * @brief Opens the Help Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; opens the help window
         */
        void OpenHelpWindow();

    private:

        // Define neccessary variables
        Ui::MainWindow* ui;
        bool isHelpOpen;

    public:

        /**
         * @brief Constructor
         * @param parent Takes in the parent QWidget
         * @note the parent parameter has a defualt value of nullptr
         */
        MainWindow(QWidget *parent = nullptr);

        /**
         * @brief Deconstructor
         */
        ~MainWindow();

};