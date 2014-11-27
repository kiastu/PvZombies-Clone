#include "snowpea.h"


SnowPea::SnowPea()
{
}

void SnowPea::shoot(){

}

void SnowPea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/SnowPea.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(50,50));
    setPos(x,y);
}

QRectF SnowPea::boundingRect()const
{
    return QRectF(0,0,50,75);
}
