#include "bullet.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include "rocks.h"
//#include <iostream>
//using namespace std;

bullet::bullet() :QObject()
{

    //Draw the bullet
        setRect (0,0,2,10);
        //connect the bullet
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
}
void bullet::move(){


    //bullet stikes and rocks destroyed
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid (rocks))
        {

            //bullet and rocks removed from scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //bullet and rocks deleted from memory
            delete colliding_items[i];
            delete this;
            qDebug() << "bullet stikes and rocks destroyed ";
            return;


}

    }




    //move bullet in all direction left right up down
    setPos(x()+(10*qSin( 0.0174533*rotation() )),y()-(10*qCos( 0.0174533*rotation() )));
    //to delete the bullet from scene
    if (pos().y() +rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted upwards";
    }
    else if (pos().y() +rect().height() >650)  {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted downwards";
    }
    else if (pos().x() +rect().height() < 0)  {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted left";
    }
    else if (pos().x() +rect().height() >850)  {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted right";
    }
}
