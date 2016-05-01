#include "Health.h"
#include <QFont>
//======================== Health Constructor  =======================//

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

   //============= set default value for health ==============//

    health = 3;

    //======================== Draw the Health =======================//

    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::blue);//set color blue
    setFont(QFont("times",16)); //text style
}

//==========================Decrease funtion of health =======================//

void Health::decrease(){

    health--;//decrease

    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

//========================= Getter function of health =======================//

int Health::getHealth(){

    return health;
}
