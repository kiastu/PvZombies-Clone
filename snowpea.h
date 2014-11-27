#ifndef SNOWPEA_H
#define SNOWPEA_H
#include "plant.h"
#include <QPainter>

class SnowPea : public Plant
{
public:
    SnowPea();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void shoot();
};

#endif // SNOWPEA_H
