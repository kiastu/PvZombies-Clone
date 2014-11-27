#ifndef REPEATER_H
#define REPEATER_H

#include "plant.h"
#include <QPainter>

class Repeater : public Plant
{
public:
    Repeater();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void shoot();
};

#endif // REPEATER_H
