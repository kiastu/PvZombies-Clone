#include "potatomine.h"

PotatoMine::PotatoMine()
{
}

void PotatoMine::shoot(){

}

void PotatoMine::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/PotatoMine.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF PotatoMine::boundingRect()const
{
    return QRectF(0,0,50,75);
}
