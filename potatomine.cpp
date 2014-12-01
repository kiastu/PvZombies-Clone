#include "potatomine.h"

PotatoMine::PotatoMine()
{
}

void PotatoMine::shoot(){

}

void PotatoMine::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/PotatoMine.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
    setPos(x,y);
}

