#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "plant.h"

class PeaShooter:public Plant
{
public:
    PeaShooter();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void shoot();
};
#endif // PEASHOOTER_H
