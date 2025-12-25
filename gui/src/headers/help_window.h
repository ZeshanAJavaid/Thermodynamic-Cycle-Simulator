#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class HelpWindow; } // Define namespace so the generated ui class doesnt conflict with our definition. 
QT_END_NAMESPACE

class HelpWindow : public QMainWindow
{
    Q_OBJECT


private slots:

    /**
     * @brief Closes the Help Window
     * @param none It needs a signal from a QPushButton to execute.
     */
    void closeWindow();

private:

    // Define neccessary variables
    Ui::HelpWindow* ui;

public:

    /**
     * @brief Constructor
     * @param parent Takes in the parent QWidget
     * @note the parent parameter has a defualt value of nullptr
     */
    HelpWindow(QWidget *parent = nullptr);

    /**
     * @brief Deconstructor
     */
    ~HelpWindow();
    
    /**
     * @brief Sets the Title Text QLabel 
     * @param text Takes in the desired text
     * @return none; changes the QLabel to text
     */
    void setTitleText(const QString &text);

    /**
     * @brief Sets the Help Text QLabel 
     * @param text Takes in the desired text
     * @return none; changes the QLabel to text
     */
    void setHelpText(const QString &text);

};