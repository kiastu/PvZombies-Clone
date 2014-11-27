#include "chomper.h"

Chomper::Chomper()
{
}

void Chomper::shoot(){

}

void Chomper::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/Chomper.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF Chomper::boundingRect()const
{
    return QRectF(0,0,50,75);
}
