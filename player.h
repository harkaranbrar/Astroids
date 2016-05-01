#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QStyleOption>
#include <QKeyEvent>
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
    void keys();

 private:
    QMediaPlayer * bulletsound;
    QSet<Qt::Key> keysPressed;
        qreal angle = 0;
        qreal xvel  = 0;
        qreal yvel  = 0;

};

#endif // PLAYER_H
