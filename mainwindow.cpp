#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QCoreApplication>
#include <QDebug>
#include <rocks.h>
//==========================Constructor to Create the window==============================//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


//    QMenu* fileMenu = menuBar()->addMenu("&File");
//    fileMenu->addAction("&New",this,SLOT(StartGame()));
//    fileMenu->addAction("&Close",this,SLOT(close()));
      ui->setupUi(this);

}
//==========================Destructor to delete the window==============================//
MainWindow::~MainWindow()
{
    delete ui;
}
//==========================Start a new game=============================================//
void MainWindow::StartGame() {
   //==========================Create a Player and added to Scene========================//
    QGraphicsScene* scene = new QGraphicsScene();
    Player *ply = new Player;
    scene->addItem(ply);
    QGraphicsView* view = new QGraphicsView(scene);

    //==================to make a player focusable in scene==============================//
    ply->setFlag(QGraphicsItem::ItemIsFocusable);
    ply->setFocus();
    //===================================================================================//


    //=============to remove the scrol bar=============================//
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //==================================================================//

    //view.setRenderHint(QPainter::Antialiasing);
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Asteroids"));
    view->resize(1024, 768);
    setCentralWidget(view);
    view->show();

    //================fixes the size of the window==================//
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    //==============================================================//

    //=================player get center in window to get its position==================//
    ply->setPos(view->width()/2,view->height() - ply->boundingRect().height());
    //==================================================================================//


        //===========================Create a Rock add to scene===========================//
        rocks *rock = new rocks;
        scene->addItem(rock);
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),rock,SLOT(spawn()));
        timer->start(2000);
        //================================================================================//

}




// =======================Button to Start the game ====================================//
void MainWindow::on_PlayButton_clicked()
{
    StartGame();
}
//==========================Button menu to Quit a new game=============================//
void MainWindow::on_QuitButton_clicked()
{
    close();
}
//==========================File menu to Start a new game==============================//
void MainWindow::on_New_triggered()
{
    StartGame();
}
//==========================File menu to Close a new game==============================//
void MainWindow::on_Close_triggered()
{
    close();
}
//=====================================================================================//


