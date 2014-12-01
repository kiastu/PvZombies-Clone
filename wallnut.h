#ifndef WALLNUT_H
#define WALLNUT_H
#include "plant.h"
#include <QPainter>
class WallNut : public Plant
{
public:
    WallNut();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    void shoot();
};

#endif // WALLNUT_H
