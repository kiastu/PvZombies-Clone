#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include "plant.h"
#include <QPainter>

class CherryBomb : public Plant
{
public:
    CherryBomb();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
public slots:
    void shoot();

};

#endif // CHERRYBOMB_H
