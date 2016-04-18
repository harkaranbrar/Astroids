#include "player.h"
#include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>
#include "bullet.h"
#include "rocks.h"

//================================== Player Constructor =========================================//

Player::Player()
{

    xvel = 0;
    yvel = 0;
    angle = 0;
    //setRotation(angle);
    //setPos(50,50);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT (move()));
    timer->start(33.33);
}

//==============================================================================================//

//================================== Player destructor =========================================//

Player::~Player() {

}

//==============================================================================================//

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::SolidPattern);
    painter->drawLine(-9,12.5,9,12.5);
    painter->drawLine(-9,12.5,0,-12.5);
    painter->drawLine(9,12.5,0,-12.5);
}

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

void Player::keyPressEvent(QKeyEvent *event) {

//============================== player change angle to left ==============================//


    if (event->key()== Qt::Key_Left){
        setRotation(rotation() - 10);

    }

 //============================== player change angle to Right ==============================//

    else if (event->key()== Qt::Key_Right){
        setRotation(rotation() + 10);
    }

//============================== player move Forward ===================================//

    else if (event->key()== Qt::Key_Up){
        // setPos(x()+(10*qSin( 0.0174533*rotation() )),y()-(10*qCos( 0.0174533*rotation() )));
        xvel += 0.25*(qSin( 0.0174533*rotation() ));
        yvel += -0.25*(qCos( 0.0174533*rotation() ));
    }

 //============================== player move Backward ===================================//

    else if (event->key()== Qt::Key_Down){
        //setPos(x(),y()+10);
    }

// ============================== Create and shoot bullet ==================================//

    else if (event->key()== Qt::Key_Space){
        angle = rotation();
        bullet * bull = new bullet(); // create a new bullet
        bull->setPos(x(),y()); // position of bullet
        bull->setRotation(angle); //set angle of bullet
        scene()->addItem(bull); //added to scene
        //qDebug() << "bullet is created";
    }
}

//==========================================================================================//

QRectF Player::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}


