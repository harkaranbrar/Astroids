#include "mainwindow.h"
#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QStatusBar>


//This is all you need.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    return a.exec();
}
