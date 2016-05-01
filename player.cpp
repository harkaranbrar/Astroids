#include "player.h"
#include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>
#include "bullet.h"
#include "rocks.h"

//================================== Player Constructor =========================================//

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    xvel = 0;
    yvel = 0;
    angle = 0;
    //setRotation(angle);
    //setPos(50,50);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT (move()));
    timer->start(33.33);

    setPixmap(QPixmap(":/img/Ship.png"));

}

//==============================================================================================//

//================================== Player destructor =========================================//

Player::~Player() {

}

//==============================================================================================//



//================================ Player Move Function ==================================//

void Player::move() {

        if(xvel <= -5.0) { xvel = -5.0; }
        if(xvel >= 5.0) { xvel = 5.0; }
        if(yvel <= -5.0) { yvel = -5.0; }
        if(yvel >= 5.0) { yvel = 5.0; }
        setPos(x()+xvel, y()+yvel);

 //================= For looping Around =====================//

         if(x() > 800)
           setPos(x() -800,y());
         else if(x()<0)
           setPos(x() + 800,y());

        if (y() > 600)
           setPos(x() ,y()-600);
        else if(y()<0)
           setPos(x(),y()+600);
}

//================================== Key press Event funtion ========================================//
//=========================Read a key from key board to move the player======================//

void Player::keys() {

    foreach(Qt::Key k, keysPressed)
    {
       switch(k)
       {
       case Qt::Key_Up:
       //case Qt::Key_W:
       {
           xvel += 0.05*(qSin( 0.0174533*rotation() ));
           yvel += -0.05*(qCos( 0.0174533*rotation() ));
           //qDebug() << "key up";
           break;
       }



       case Qt::Key_Left:
     //  case Qt::Key_A:
       {
            setRotation(rotation() - 0.09);
            break;
       }

       case Qt::Key_Right:
      // case Qt::Key_D:
       {
           setRotation(rotation() +0.09);
           break;
       }


       case Qt::Key_Space:
       {
           // create a bullet
           angle = rotation();
           bullet * bull = new bullet(); // create a new bullet
           bull->setPos(x()+20,y()+20); // position of bullet
           bull->QGraphicsItem::setTransformOriginPoint(10,10);
           bull->setRotation(angle); //set angle of bullet
           scene()->addItem(bull); //added to scene
           fireRate.start(333, this);
           qDebug() << "bullet is created";

           break;
           }
        default:
       {
           // prevents 430 warnings
           break;
       }
       }
    }
}




void Player::keyPressEvent(QKeyEvent *event)
{
    keysPressed += (Qt::Key)event->key();
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(keys()));

    timer->start(50);

}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    keysPressed -= (Qt::Key)event->key();
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(keys()));
    timer->start(50);
}
