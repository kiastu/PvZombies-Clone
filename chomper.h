#ifndef CHOMPER_H
#define CHOMPER_H

#include "Plant.h"
#include <QPainter>

class Chomper : public Plant
{
public:
    Chomper();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void shoot();
};

#endif // CHOMPER_H
