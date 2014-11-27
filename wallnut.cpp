#include "wallnut.h"

WallNut::WallNut()
{
}

void WallNut::shoot(){

}

void WallNut::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/WallNut.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF WallNut::boundingRect()const
{
    return QRectF(0,0,50,75);
}
