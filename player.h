#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QStyleOption>
#include <QKeyEvent>
#include <Qset>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
//#include <qlabel.h>


class Player : public QObject, public QGraphicsPixmapItem
{

Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    virtual ~Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);




public slots:
    void move();
    //void spawn();
    void keys();

 private:

        qreal angle;
        qreal speed;
        qreal xvel;
        qreal yvel;
        QMediaPlayer * bulletsound;
        QSet<Qt::Key> keysPressed;
        QTimer fireRate;
        // Handles key presses.
       // void keys();
};

#endif // PLAYER_H
