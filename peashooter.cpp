#include "peashooter.h"

PeaShooter::PeaShooter()
{

}

void PeaShooter::shoot(){

}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    painter->setPen(pen);
    painter->drawRect(boundingRect());
}

QRectF PeaShooter::boundingRect()const
{
    return QRectF(0,0,20,20);
}

