#include "mainwindow.h"
#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QProgressBar>


 MainWindow * game; // Global object

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new MainWindow();//Global object = main window
    game-> show(); // show game means show main window
    return a.exec();
}
