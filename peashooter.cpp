#include "peashooter.h"
#include <iostream>
PeaShooter::PeaShooter()
{

}

void PeaShooter::shoot(){

}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    painter->setPen(pen);
    painter->drawRect(boundingRect());
    setPos(x,y);
}

QRectF PeaShooter::boundingRect()const
{
    std::cout<<"x:"<<x<<"y:"<<y<<"\n";
    return QRectF(0,0,20,20);
}

