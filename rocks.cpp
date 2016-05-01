#include "rocks.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <typeinfo>
#include "bullet.h"
#include "player.h"
#include "mainwindow.h"


extern MainWindow * game; // Global object

//================================== Rocks Constructor =========================================//


rocks::rocks(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

//=================Random number for x ========================//

    int random_number = qrand () % 700;

//================= set Random Position =======================//

    int pos_x = rand () %2;
    if(pos_x == 0)
        xvel = qrand () % 5;
    else
        xvel = (qrand () % 5)* (-1);
    int pos_y = rand () %2;
    if (pos_y == 0)
        yvel = qrand () % 5;
    else
        yvel = (qrand() %5)*(-1);

    if (pos_x == 0)
        setPos(x() + random_number, y() - 60);
    else
        setPos(x() - 20, y() - random_number);

//================== Draw the Rocks ===========================//

    size = 3;
    setPixmap(QPixmap(":/img/Rock.png"));

//============= Create a timer or Connect the rocks============//

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

rocks::rocks(int size)
{
    int pos_x = rand () %2;
    if(pos_x == 0)
        xvel = qrand () % 5+1;
    else
        xvel = (qrand () % 5+1)* (-1);
    int pos_y = rand () %2;
    if (pos_y == 0)
        yvel = qrand () % 5+1;
    else
        yvel = (qrand() %5+1)*(-1);
    switch (size)
    {
    case 3:
        //qDebug () << "sent to size";
       setPixmap(QPixmap(":/img/Rock1.png"));
        this->size = 2;
        break;
    case 2:
        //qDebug () << "sent to size";
       setPixmap(QPixmap(":/img/Rock2.png"));
        break;
    }
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

//================================== Move Function of Rocks =========================================//

void rocks::move()
{
//===================Screen Looping for rocks=========================//

    if(x() > 800)
      setPos(x() -800,y()-60);
    else if(x()<0)
      setPos(x() + 800,y()-60);

   if (y() > 650)
      setPos(x() ,y()-650);
   else if(y()<0)
      setPos(x(),y()+650);

//================== Set the position of rocks===========================//

    int xdir = xvel;
    int ydir = yvel;
    setPos(x()+xdir, y()+ydir);

//================== Rocks collides with ship and remove ==========================//

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid (Player))
        {
            //==========================Decrease the Health =======================//
            game->health->decrease(); // player health decrease
            scene()->removeItem(this); //remove from the scene
             delete this;              //delete the rocks
             return;

    }
    }

//================== Rocks collides with bullet and remove ==========================//
  for (int i = 0, n = colliding_items.size(); i<n; i++){
      if (typeid(*(colliding_items[i])) == typeid (bullet))
      {
        //==========================Increase the Score =======================//

                 game->score->Score::increase();

             //========== Bullet and rocks removed from scene==============//

                      scene()->removeItem(colliding_items[i]);
                      this->split();
                      scene()->removeItem(this);

               //========== Bullet and rocks removed from memory ============//

                      delete colliding_items[i];
                      delete this;
                      //qDebug() << "bullet stikes and rocks destroyed ";
                      return;
          }


  }
  /*
  //=======Delete the asteroid from upwards=====//
  if (pos().y() +rect().height() < 0){
      scene()->removeItem(this);
      delete this;
     //qDebug() << "asteroid deleted upwards";
  }

  //=====Delete the asteroid from downwards=====//

  else if (pos().y() +rect().height() >650)  {
      scene()->removeItem(this);
      delete this;
      //qDebug() << "asteroid deleted downwards";
  }

  //=====Delete the asteroid from left=====//

  else if (pos().x() +rect().height() < 0)  {
      scene()->removeItem(this);
      delete this;
      //qDebug() << "asteroid deleted left";
  }

  //=====Delete the asteroid from right=====//

  else if (pos().x() +rect().height() >850)  {
      scene()->removeItem(this);
      delete this;
      //qDebug() << "asteroid deleted right";
  }
  */
}

//================================== Spawn and create a rocks=========================================//

void rocks::spawn(){
    rocks * rock = new rocks();//create a rock
    scene()->addItem(rock);//added to scene
    qDebug() << "spawned";
}

void rocks::split()
{
    //qDebug() << "split";
    switch (size)
    {
        case 3:
    {
            rocks * rocks1 = new rocks(3);
            rocks * rocks2 = new rocks(3);
            rocks1 -> setPos(x(), y());
            rocks2 -> setPos(x(), y());

            scene()->addItem(rocks1);
            scene()->addItem(rocks2);
            break;
    }

        case 2:
    {
            rocks * rocks1 = new rocks(2);
            rocks * rocks2 = new rocks(2);
            rocks1 -> setPos(x(), y());
            rocks2 -> setPos(x(), y());

            scene()->addItem(rocks1);
            scene()->addItem(rocks2);
        break;
    }
    }
}
