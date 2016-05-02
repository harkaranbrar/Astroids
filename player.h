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
#include <QtNetwork>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include "networkplayer.h"
#include <QMap>
//#include <qlabel.h>


class Player : public QObject, public QGraphicsPixmapItem
{

Q_OBJECT
public:
    QString playerName;
    bool multiplayer;
    Player(QGraphicsItem * parent=0);
    virtual ~Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public slots:
    void move();
    void keys();
    void updateNetwork();
        void parsePackets();

 private:
    QMediaPlayer * bulletsound;
    QSet<Qt::Key> keysPressed;
    QList<QString> multiplayerList;
            QUdpSocket *writeUdpSocket;
            QUdpSocket *readUdpSocket;
        qreal angle = 0;
        qreal xvel  = 0;
        qreal yvel  = 0;

};

#endif // PLAYER_H
