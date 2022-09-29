#include "window.hpp"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWin mainWindow;
    mainWindow.show();

    app.exec();
}