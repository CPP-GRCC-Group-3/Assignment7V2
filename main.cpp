#include "mainwindow.h"
#include "gamehandler.h"
#include <QApplication>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

