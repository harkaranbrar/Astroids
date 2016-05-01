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

bullet::bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

                //==========================bullet from PNG =======================//

                setPixmap(QPixmap(":/img/bullet1.png"));

                //================ Create a Timer and Connect the Bullet =============//

                QTimer * timer = new QTimer();
                connect(timer,SIGNAL(timeout()),this,SLOT(move())); //connect timer to move slot

                timer->start(33.33); //start timer
                //qDebug() << "bullet is created";
}




                //============================ Bullet move Function =======================//


void bullet::move(){


//=============================Movement of Bullet ================================//

setPos(x()+(10*qSin( 0.0174533*rotation() )),y()-(10*qCos( 0.0174533*rotation() )));

//===========================Delete the bullet from Memory=========================//

                    //=====Delete the bullet from Upwards=====//

                    if (pos().y()  < 0){
                    scene()->removeItem(this);
                    delete this;
                    //qDebug() << "bullet deleted upwards";
                    }

                    //=====Delete the bullet from downwards=====//

                    else if (pos().y()  >650)  {
                    scene()->removeItem(this);
                    delete this;
                    //qDebug() << "bullet deleted downwards";
                    }

                    //=====Delete the bullet from left=====//

                    else if (pos().x()  < 0)  {
                    scene()->removeItem(this);
                    delete this;
                    //qDebug() << "bullet deleted left";
                    }

                    //=====Delete the bullet from right=====//

                    else if (pos().x()  >850)  {
                    scene()->removeItem(this);
                    delete this;
                    //qDebug() << "bullet deleted right";
                    }
}
//============================================================================================//
