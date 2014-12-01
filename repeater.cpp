#include "repeater.h"

Repeater::Repeater()
{
}

void Repeater::shoot(){

}

void Repeater::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/Repeater.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
    setPos(x,y);
}

