#include "player.h"
#include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>
#include "bullet.h"

Player::Player()
{
    //xpos = 0;
    //ypos = 0;
    angle = 0;
    //setRotation(angle);
    //setPos(50,50);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT (move()));
    timer->start(33.33);
}

Player::~Player() {

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::SolidPattern);
    painter->drawLine(-9,12.5,9,12.5);
    painter->drawLine(-9,12.5,0,-12.5);
    painter->drawLine(9,12.5,0,-12.5);
}

void Player::move() {

   // setPos(xpos, ypos);

}

void Player::keyPressEvent(QKeyEvent *event) {
    //qDebug() << "pressed a key";

    //this can read a key from key board to move the player
    if (event->key()== Qt::Key_Left){

        setRotation(rotation() - 10);
    }
    else if (event->key()== Qt::Key_Right){
        setRotation(rotation() + 10);
    }
    else if (event->key()== Qt::Key_Up){
        setPos(x()+(qSin( 0.0174533*rotation() )),y()-(qCos( 0.0174533*rotation() )));
    }
    else if (event->key()== Qt::Key_Down){
        //setPos(x(),y()+10);
    }
    //Shoot and create the bullet
    else if (event->key()== Qt::Key_Space){
        angle = rotation();
        bullet * bull = new bullet();
        bull->setPos(x(),y());
        bull->setRotation(angle);
        scene()->addItem(bull);

        //qDebug() << "bullet is created";
    }
}

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

