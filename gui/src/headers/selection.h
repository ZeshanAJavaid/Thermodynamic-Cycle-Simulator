#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class SelectionWindow; } // Define namespace so the generated ui class doesnt conflict with our definition. 
QT_END_NAMESPACE

class SelectionWindow : public QMainWindow
{
    Q_OBJECT

    private slots:

        /**
         * @brief Opens the Brayton Input Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; it closes the selection window and opens the brayton input window 
         */
        void OpenBraytonInputs();

        /**
         * @brief Opens the Otto Input Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; it closes the selection window and opens the otto input window 
         */
        void OpenOttoInputs();

        /**
         * @brief Opens the Diesel Input Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; it closes the selection window and opens the diesel input window 
         */
        void OpenDieselInputs();

        /**
         * @brief Opens the Help Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; opens the help window 
         */
        void OpenHelpWindow();

    private:

        // Define neccessary variables
        Ui::SelectionWindow* ui;
        bool isHelpOpen;

    public:

        /**
         * @brief Constructor
         * @param parent Takes in the parent QWidget
         * @note the parent parameter has a defualt value of nullptr
         */
        SelectionWindow(QWidget *parent = nullptr);

        /**
         * @brief Deconstructor
         */
        ~SelectionWindow();

};