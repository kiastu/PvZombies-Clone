#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
}

void CherryBomb::shoot(){

}

void CherryBomb::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/CherryBomb.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
    setPos(x,y);
}

