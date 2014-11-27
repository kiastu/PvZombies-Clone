#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
}

void CherryBomb::shoot(){

}

void CherryBomb::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/CherryBomb.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF CherryBomb::boundingRect()const
{
    return QRectF(0,0,50,75);
}
