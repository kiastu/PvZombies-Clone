#include "sunflower.h"

SunFlower::SunFlower()
{
}

void SunFlower::shoot(){

}

void SunFlower::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/sunflower.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF SunFlower::boundingRect()const
{
    return QRectF(0,0,50,75);
}
