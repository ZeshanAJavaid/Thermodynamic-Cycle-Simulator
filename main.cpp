#include "gui/src/headers/main_window.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    MainWindow* mainWin = new MainWindow();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    QRect windowGeometry = mainWin->frameGeometry();
    windowGeometry.moveCenter(screenGeometry.center());
    mainWin->move(windowGeometry.topLeft());


    mainWin->show();

    return app.exec();
}