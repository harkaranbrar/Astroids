#include "rocks.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
rocks::rocks():QObject()
{
    int random_number = rand () % 700;
    //set random position
    setPos(random_number,0);
 //draw the rocks
    setRect(0,0,50,50);
    //connect the square rocks

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

void rocks::move()
{
    setPos(x(), y()+5);
    //to delete the bullet from scene
//    if (pos().y() +rect().height() < 0){
//        scene()->removeItem(this);
//        delete this;
//        qDebug() << "bullet deleted upwards";
//    }
}
void rocks::spawn(){
    //create a rock
    rocks * rock = new rocks();
    scene()->addItem(rock);
}
