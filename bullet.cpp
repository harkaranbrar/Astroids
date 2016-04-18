#include "bullet.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include "rocks.h"
#include "mainwindow.h"

extern MainWindow * game; // Global

//============================================================================================//

bullet::bullet() :QObject()
{

    //==========================Draw the Bullet =======================//

        setRect (0,0,2,10);

    //================ Create a Timer and Connect the Bullet =============//

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
}

//============================ Bullet move Function ===========================================//


void bullet::move(){


    //================= Bullet Strikes and destroyed =================//

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid (rocks))
        {
    //==========================Increase the Score =======================//

         game->score->Score::increase();

    //====================================================================//


    //========== Bullet and rocks removed from scene==============//

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

     //========== Bullet and rocks removed from memory ============//

            delete colliding_items[i];
            delete this;
            //qDebug() << "bullet stikes and rocks destroyed ";
            return;
}
    }

    //=============================Movement of Bullet ================================//

    setPos(x()+(10*qSin( 0.0174533*rotation() )),y()-(10*qCos( 0.0174533*rotation() )));

   //===========================Delete the bullet from Memory=========================//

    //=====Delete the bullet from Upwards=====//

    if (pos().y() +rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet deleted upwards";
    }

    //=====Delete the bullet from downwards=====//

    else if (pos().y() +rect().height() >650)  {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet deleted downwards";
    }

    //=====Delete the bullet from left=====//

    else if (pos().x() +rect().height() < 0)  {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet deleted left";
    }

    //=====Delete the bullet from right=====//

    else if (pos().x() +rect().height() >850)  {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet deleted right";
    }
}
//============================================================================================//
