#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"
#include <QPainter>

class SunFlower : public Plant
{
public:
    SunFlower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void shoot();
};

#endif // SUNFLOWER_H
