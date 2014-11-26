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

QRectF Plant::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void Plant::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}
