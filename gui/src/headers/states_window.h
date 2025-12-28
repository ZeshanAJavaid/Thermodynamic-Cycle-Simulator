#pragma once
#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class StateWindow; } // Define namespace so the generated ui class doesnt conflict with our definition. 
QT_END_NAMESPACE


class StateWindow : public QMainWindow 
{

    private slots:

        /**
         * @brief Returns to the Selection Window for another simulation
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; closes the states window and opens the selection window
         */
        void goBackToSelection();

        /**
         * @brief Open the Performance Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; closes the states window and opens the performance window
         */
        void OpenThermoData();

        /**
         * @brief Open the Help Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; opens the help window
         */
        void OpenHelpWindow();

        /**
         * @brief Open the Ts Diagram Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; opens Ts Diagram Window
         * 
         * @todo NEEDS TO BE IMPLEMENTED
         */
        void OpenTsDiagram();

        /**
         * @brief Open the Pv Diagram Window
         * @param none It needs a signal from a QPushButton to execute.
         * @return none; opens Pv Diagram Window
         * 
         * @todo NEEDS TO BE IMPLEMENTED
         */
        void OpenPvDiagram();


    private:

        // Define neccessary variables
        Ui::StateWindow* ui;
        QStandardItemModel* csvModel;
        bool isHelpOpen, isPvDiagramOpen, isTsDiagramOpen;
        std::string fileName;

    public: 

        /**
         * @brief Constructor
         * @param parent Takes in the parent QWidget
         * @note the parent parameter has a defualt value of nullptr
         */
        StateWindow(QWidget *parent = nullptr);

        /**
         * @brief Deconstructor
         */
        ~StateWindow();

        /**
         * @brief loads the QTableView with data from a csv
         * @param filepath The filepath where the .csv file is
         * @return none; fills in the QTableView
         */
        void loadCsvData(const QString &filepath);

};