#include "plant.h"

Plant::Plant()
{

}

void Plant::shoot(){

}

void Plant::die(){

}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

}

void Plant::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}
float Plant::getAttackSpeed() const
{
    return attackSpeed;
}

void Plant::setAttackSpeed(float value)
{
    attackSpeed = value;
}
QRectF Plant::boundingRect()const
{
    return QRectF(0,0,60,60);
}



