#include "networkplayer.h"
 #include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>
#include <QtNetwork>

NetworkPlayer::NetworkPlayer(QGraphicsItem *parent): QGraphicsPixmapItem(parent)

{
    setPixmap(QPixmap(":/img/Ship.png")); // set player image

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(parsePackets()));
}

NetworkPlayer::~NetworkPlayer() {

}


void NetworkPlayer::parsePackets() {
    while(udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString data_str = datagram.data();
        QStringList data_arr = data_str.split(',');

        if(data_arr.at(0) == ID) {
            setPos(data_arr.at(1).toFloat(), data_arr.at(2).toFloat());
            setRotation(data_arr.at(3).toFloat());
        }
    }
}


