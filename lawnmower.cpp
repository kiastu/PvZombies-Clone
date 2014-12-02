#include "lawnmower.h"

LawnMower::LawnMower()
{
}
void LawnMower::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QImage lm(":images/lawnmower.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(lm).scaled(60,60));
}
