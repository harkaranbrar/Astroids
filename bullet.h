#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>


class bullet: public QObject, public QGraphicsPixmapItem
{
    //to receive a signals macro
    Q_OBJECT
public:
    bullet(QGraphicsItem * parent=0);
public slots:
    void move();

};

#endif // BULLET_H
