#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>

class bullet: public QObject, public QGraphicsRectItem
{
    //to receive a signals macro
    Q_OBJECT
public:
    bullet();
public slots:
    void move();



};

#endif // BULLET_H
