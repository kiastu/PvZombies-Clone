#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include "plant.h"
#include <QPainter>

class CherryBomb : public Plant
{
public:
    CherryBomb();
    void shoot();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;

};

#endif // CHERRYBOMB_H
