#ifndef ROCKS_H
#define ROCKS_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>


class rocks :public QObject , public QGraphicsPixmapItem
{
    //to receive a signals
    Q_OBJECT
public:
    rocks(QGraphicsItem * parent=0);
    rocks(int size);
public slots:
    void move();
    void spawn();
    void split();
    void explosion();
private:
    int size;
    qreal xvel;
    qreal yvel;
    QMediaPlayer * destroysound;
    QMediaPlayer * shiphitsound;
};

#endif // ROCKS_H
