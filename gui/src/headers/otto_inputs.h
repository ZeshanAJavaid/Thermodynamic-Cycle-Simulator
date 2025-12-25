#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class OttoInputWindow; } // Define namespace so the generated ui class doesnt conflict with our definition. 
QT_END_NAMESPACE

class OttoInputWindow : public QMainWindow
{
    Q_OBJECT

    private slots: // Define the functions that each button do
        /**
         * @brief Opens the next window that display the results of the user's inputs
         * @param none It needs a signal from a QPushButton to execute.
         * @return it closes the current window and opens the performance window.
         */
        void OpenPerformanceWindow();

        /**
         * @brief Opens a window that contains information regarding the current window.
         * @param none It needs a signal from a QPushButton to execute.
         * @return it opens the help window.
         */
        void OpenHelpWindow();

        /**
         * @brief Opens the previous window that enables the user to rechoose their cycle type.
         * @param none It needs a signal from a QPushButton to execute.
         * @return it closes the current window and opens the selection window.
         */
        void OpenSelectionWindow();

    private:

        // Define Neccessary Variables
        Ui::OttoInputWindow* ui;
        bool isHelpOpen;
        bool isErrorOpen;

    public:

        /**
         * @brief Constructor
         * @param parent Takes in the parent QWidget
         * @note the parent parameter has a defualt value of nullptr
         */
        OttoInputWindow(QWidget *parent = nullptr);

        /**
         * @brief Deconstructor
         */
        ~OttoInputWindow();

};