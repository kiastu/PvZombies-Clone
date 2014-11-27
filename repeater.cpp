#include "repeater.h"

Repeater::Repeater()
{
}

void Repeater::shoot(){

}

void Repeater::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/Repeater.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF Repeater::boundingRect()const
{
    return QRectF(0,0,50,75);
}
