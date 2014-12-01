#include "wallnut.h"

WallNut::WallNut()
{
}

void WallNut::shoot(){

}

void WallNut::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    setPos(x,y);
    QImage plant("images/WallNut.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
}

