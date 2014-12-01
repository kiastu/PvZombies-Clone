#ifndef SNOWPEA_H
#define SNOWPEA_H
#include "plant.h"
#include <QPainter>
#include "projectile.h"

class SnowPea : public Plant
{
    Q_OBJECT
public:
    SnowPea();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
public slots:
    void shoot();
};

#endif // SNOWPEA_H
