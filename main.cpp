//#include "MainWindow.h"
#include "Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Controller controller;

    return application.exec();
}
