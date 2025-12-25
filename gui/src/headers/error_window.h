#pragma once
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class ErrorWindow; } // Define namespace so the generated ui class doesnt conflict with our definition. 
QT_END_NAMESPACE

class ErrorWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    /**
     * @brief Closes the Error Window
     * @param none It needs a signal from a QPushButton to execute.
     */
    void closeWindow();

private:

    // Define neccessary variables
    Ui::ErrorWindow* ui;

public:

    /**
     * @brief Constructor
     * @param parent Takes in the parent QWidget
     * @note the parent parameter has a defualt value of nullptr
     */
    ErrorWindow(QWidget *parent = nullptr);

    /**
     * @brief Deconstructor
     */
    ~ErrorWindow();

    /**
     * @brief Sets the Title Text QLabel 
     * @param text Takes in the desired text
     * @return none; changes the QLabel to text
     */
    void setTitleText(const QString &text);

    /**
     * @brief Sets the Error Text QLabel 
     * @param text Takes in the desired text
     * @return none; changes the QLabel to text
     */
    void setErrorText(const QString &text);

};