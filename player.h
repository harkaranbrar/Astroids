#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QStyleOption>
#include <QKeyEvent>
<<<<<<< HEAD
=======
#include <qlabel.h>
>>>>>>> harkaran


class Player : public QObject, public QGraphicsItem
{

Q_OBJECT
public:
    Player();
    virtual ~Player();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void keyPressEvent(QKeyEvent *event);
    QRectF boundingRect() const;
    QPainterPath shape() const;



public slots:
    void move();

 private:

        qreal angle;
        qreal speed;
        qreal xpos;
        qreal ypos;


<<<<<<< HEAD


=======
>>>>>>> harkaran
};

#endif // PLAYER_H
