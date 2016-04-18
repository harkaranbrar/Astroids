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
    this->setFixedSize(800,600);
     ui->setupUi(this);
}
//==========================Destructor to delete the window==============================//
MainWindow::~MainWindow()
{
    delete ui;
}

//========================== Mouse press events ==============================//
void MainWindow::mousePressEvent(QMouseEvent *event)
{
//    ply->setFocus();
//    qDebug() << "in focus";
//    return;
}

//==========================Key Press events==============================//

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//==============Player gets a focus by key press ========================//
            ply->setFocus();
            qDebug() << "in focus";
            return;
}

//==========================Start a new game=============================================//
void MainWindow::StartGame() {
   //==========================Create a Scene========================//
    scene = new QGraphicsScene();

 //============Create a Player and make it Focusable and added to scene==================//
    ply = new Player;
    ply->setFlag(QGraphicsItem::ItemIsFocusable);
    ply->QGraphicsItem::setFocus();
    scene->addItem(ply);
    //===================================================================================//

//============Create a Score ,Health and added to scene==================//
        score = new Score();
        scene->addItem(score);
        health = new Health();
        health->setPos(health->x(),health->y()+25); //set the positon of the health text
        scene->addItem(health);

//===================== Create a View and Set up its size ===============================//
    view = new QGraphicsView(scene);
    //=============to remove the scrol bar=============================//
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //==================================================================//
    view->setFixedSize(800,600);
    setCentralWidget(view);
    view->setFocus();
    view->show();

 //================fixes the size of the Scene window==================//

    scene->setSceneRect(0,0,800,600);

 //==============================================================//

 //=================player get center in window to get its position==================//

    ply->setPos(view->width()/2,view->height()/2);

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


