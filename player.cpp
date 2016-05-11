#include "player.h"
#include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>
#include "bullet.h"
#include "rocks.h"

//================================== Player Constructor =========================================//

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

            bulletsound = new QMediaPlayer(); // create a media player
            bulletsound->setMedia(QUrl("qrc:/sounds/SHOOTIN3.wav")); // set sound from resource file


    setPixmap(QPixmap(":/img/Ship.png")); // set player image

    QTimer * timer = new QTimer();

        QTimer * netTimer =  new QTimer();
        writeUdpSocket = new QUdpSocket(this);
        readUdpSocket = new QUdpSocket(this);
        readUdpSocket->bind(45454, QUdpSocket::ShareAddress);
        connect(timer,SIGNAL(timeout()), this, SLOT(updateNetwork()));
        connect(readUdpSocket, SIGNAL(readyRead()), this, SLOT(parsePackets()));
        netTimer->start(50.00);

        connect(timer,SIGNAL(timeout()),this, SLOT (move()));
        timer->start(33.33);

}

//==============================================================================================//

//================================== Player destructor =========================================//

Player::~Player() {

}

//==============================================================================================//

void Player::updateNetwork() {
    if(multiplayer) {
    QByteArray datagram = playerName.toLocal8Bit() + "," + QByteArray::number(x()) + "," + QByteArray::number(y()) + "," + QByteArray::number(rotation());
    writeUdpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 45454);
    }
}

void Player::parsePackets() {
    if(multiplayer) {
    while(readUdpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(readUdpSocket->pendingDatagramSize());
        readUdpSocket->readDatagram(datagram.data(), datagram.size());

        //Convert into a string, which we will parse.
        QString data_str = QString(datagram.data());

        //Parse the string to remove the appropriate information.
        //We put it into an array of size 4, since we know the packet will contain 4 variables that we want.
        //Then we use the address of the array to place the variables where they need to go
        QStringList data_arr = data_str.split(',');

        if(!multiplayerList.contains(data_arr.at(0)) && data_arr.at(0)!=playerName && data_arr.at(0)!="BULLET_EVENT") {
            multiplayerList.insert(multiplayerList.size(), data_arr.at(0));
            NetworkPlayer *newPly = new NetworkPlayer();
            newPly->QGraphicsItem::setTransformOriginPoint(30,30); //set origin of player default is (0,0)
            newPly->setTransformationMode(Qt::SmoothTransformation); // for smooth transformation of player
            newPly->ID = data_arr.at(0);
            newPly->setPos(data_arr.at(1).toFloat(), data_arr.at(2).toFloat());
            newPly->setRotation(data_arr.at(3).toFloat());
            scene()->addItem(newPly);
        }
        if(data_arr.at(0) == "BULLET_EVENT") {
            angle = data_arr.at(3).toFloat();
            bullet * bull = new bullet(); // create a new bullet
            bull->setPos(data_arr.at(1).toFloat()+20,data_arr.at(2).toFloat()+20); // position of bullet
            bull->QGraphicsItem::setTransformOriginPoint(10,10); //set the origin of bullet
            bull->setRotation(angle); //set angle of bullet
            scene()->addItem(bull); //added to scene
        }
    }
   }


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

void Player::keys() {



    foreach(Qt::Key k, keysPressed)
    {
       switch(k)
       {
       case Qt::Key_Up:
       case Qt::Key_W:
       {
           xvel += 0.5*(qSin( 0.0174533*rotation() ));
           yvel += -0.5*(qCos( 0.0174533*rotation() ));
           //qDebug() << "key up";
           break;
       }



       case Qt::Key_Left:
       case Qt::Key_A:
       {
            setRotation(rotation() -15);
            break;
       }

       case Qt::Key_Right:
       case Qt::Key_D:
       {
           setRotation(rotation() +15);
           break;
       }


       case Qt::Key_Space:
       {
           if(multiplayer) {
               QByteArray datagram = "BULLET_EVENT," + QByteArray::number(x()) + "," + QByteArray::number(y()) + "," + QByteArray::number(rotation());
               writeUdpSocket->writeDatagram(datagram.data(), datagram.size(),
                                        QHostAddress::Broadcast, 45454);
           }\

           // create a bullet
           angle = rotation(); // set angle equal to ship's rotation
           bullet * bull = new bullet(); // create a new bullet
           bull->setPos(x()+20,y()+20); // position of bullet
           bull->QGraphicsItem::setTransformOriginPoint(10,10); //set the origin of bullet
           bull->setRotation(angle); //set angle of bullet
           scene()->addItem(bull); //added to scene
 //================================== bullet fire sound ========================================//
                if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
                }
                else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
                }
 //=============================================================================================//
           break;
           }
        default:
       {
           // prevents 430 warnings
           break;
       }
       }
    }
}


//================================== KeypressEvent funtion ========================================//

void Player::keyPressEvent(QKeyEvent *event)
{
    keysPressed += (Qt::Key)event->key();
    QTimer::singleShot(10, this, SLOT(keys())); //connect the keypress to keys

}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    keysPressed -= (Qt::Key)event->key();
    QTimer::singleShot(10, this, SLOT(keys()));//connect the keyrelease to keys
}
