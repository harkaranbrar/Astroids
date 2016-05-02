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
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <qmovie.h>

//==========================Constructor to Create the window==============================//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);//fixed the size of window
     ui->setupUi(this); // setup by UI FORM
}
//==========================Destructor to delete the window==============================//
MainWindow::~MainWindow()
{
    delete ui;
}

//========================== Mouse press events ==============================//
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    ply->setFocus(); // give focus to the player
    return;
}

//==========================Key Press events==============================//

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//==============Player gets a focus by key press ========================//
            ply->setFocus(); // give focus to the player
            return;
}

//==========================Start a new game=============================================//
void MainWindow::StartGame(bool m) {
    QString name;
    if(m) {

        QInputDialog msgBox;
                msgBox.setLabelText("Enter your name: ");
                int ret = msgBox.exec();
                name = msgBox.textValue();
    }

   //==========================Create a Scene========================//
    scene = new QGraphicsScene(); // create a scene
    scene->setBackgroundBrush(QBrush(QImage(":/img/backg.jpg"))); // set background image

 //============Create a Player and make it Focusable and added to scene==================//
    ply = new Player();
    if(m) {
        ply->multiplayer=m;
        ply->playerName = name;
    }

    ply->setFlag(QGraphicsItem::ItemIsFocusable); // make player focusable
    ply->QGraphicsItem::setFocus(); // set focus
    scene->addItem(ply); // add player to scene
    //===================================================================================//

//============Create a Score ,Health and added to scene==================//
        score = new Score(); // create a score
        scene->addItem(score); // add score to scene
        health = new Health(); // create a health
        health->setPos(health->x(),health->y()+25); //set the positon of the health text
        scene->addItem(health); // add health to scene

//===================== Create a View and Set up its size ===============================//
    view = new QGraphicsView(scene); // create a view
    //=============to remove the scrol bar=============================//
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // horizontal bars off
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // vertical bars off
    //==================================================================//
    view->setFixedSize(800,600); // fixed the size of view
    setCentralWidget(view); // set view in central widget
    view->setFocus(); // give focus to view
    view->show(); // show the view

 //================fixes the size of the Scene window==================//

    scene->setSceneRect(0,0,800,600); //  fixes the size of scene

 //==============================================================//

 //=================player get center in window to get its position==================//

    ply->setPos(view->width()/2,view->height()/2); //set the position of player in center
    ply->QGraphicsItem::setTransformOriginPoint(30,30); //set origin of player default is (0,0)
    ply->setTransformationMode(Qt::SmoothTransformation); // for smooth transformation of player

 //==================================================================================//


 //===========================Create a Rock add to scene===========================//
        rock = new rocks; // create a rock
        scene->addItem(rock); // rock added to scene
        QTimer * timers = new QTimer(); // create a timer
        QObject::connect(timers,SIGNAL(timeout()),rock,SLOT(spawn())); // connect the timer to spawn
        timers->start(5000); // timer start

        rock1 = new rocks; // create a second rock
        scene->addItem(rock1); // rock added to scene
        QTimer * timer = new QTimer(); //create a timer
        QObject::connect(timer,SIGNAL(timeout()),rock1,SLOT(spawn())); // connect to the timer to spawn
        timer->start(5000); // start timer


//================================================================================//

                                    music = new QMediaPlayer(); // create a media player
                                    music->setMedia(QUrl("qrc:/sounds/Music.mp3")); // set sound from resoure file

                                    //if else statement to check and play music with position setting
                                    if (music->state() == QMediaPlayer::PlayingState){
                                        music->setPosition(0);
                                    }
                                    else if (music->state() == QMediaPlayer::StoppedState){
                                        music->play();
                                    }

}
// ======================= to reset the game ====================================//
void MainWindow::reset()
{
     music->stop(); // stop music
     StartGame(false); // calls start game
}


// ======================= to remove the items ====================================//
void MainWindow::removeItem()
{
    scene->removeItem(ply); // remove player
}

void MainWindow::animation()
{
    qDebug() << " animation" ;
}





// =======================Button to Start the game ====================================//
void MainWindow::on_PlayButton_clicked()
{
    StartGame(false); //calls start game
}
//==========================Button menu to Quit a new game=============================//
void MainWindow::on_QuitButton_clicked()
{
    close(); // close
}
//==========================File menu to Start a new game==============================//
void MainWindow::on_New_triggered()
{
    reset(); // calls reset button
}
//==========================File menu to Close a new game==============================//
void MainWindow::on_Close_triggered()
{
    close(); //close
}
//=====================================================================================//



void MainWindow::on_multiplayerButton_clicked()
{
    StartGame(true);
}
