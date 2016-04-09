#include "bullet.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

bullet::bullet()
{

    //Draw the bullet
        setRect (0,0,2,10);
        //connect the bullet
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
}
void bullet::move(){
    //move bullet up
    setPos(x()+(10*qSin( 0.0174533*rotation() )),y()-(10*qCos( 0.0174533*rotation() )));
    //to delete the bullet from scene
    if (pos().y() +rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
