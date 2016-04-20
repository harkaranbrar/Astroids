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
