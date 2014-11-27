#include "peashooter.h"
#include <iostream>
PeaShooter::PeaShooter()
{

}

void PeaShooter::shoot(){

}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/peashooter.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF PeaShooter::boundingRect()const
{
    return QRectF(0,0,50,75);
}

