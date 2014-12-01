#include "sunflower.h"

SunFlower::SunFlower()
{
}

void SunFlower::spawnSun(){

}

void SunFlower::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    setPos(x,y);
    QImage plant("images/sunflower.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
}
