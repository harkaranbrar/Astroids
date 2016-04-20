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


rocks::rocks():QObject()
{

//=================Random number for x ========================//

    int random_number = rand () % 700;

//================= set Random Position =======================//

    setPos(random_number,0);

//================== Draw the Rocks ===========================//

    setRect(0,0,50,50);

//============= Create a timer or Connect the rocks============//

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

//================================== Move Function of Rocks =========================================//

void rocks::move()
{

//================== Set the position of rocks===========================//

    setPos(x(), y()+5);

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
                      //this->split();
                      scene()->removeItem(this);

               //========== Bullet and rocks removed from memory ============//

                      delete colliding_items[i];
                      delete this;
                      //qDebug() << "bullet stikes and rocks destroyed ";
                      return;
          }


  }
}

//================================== Spawn and create a rocks=========================================//

void rocks::spawn(){
    rocks * rock = new rocks();//create a rock
    scene()->addItem(rock);//added to scene
}
