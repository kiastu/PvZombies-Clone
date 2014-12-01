#ifndef POTATOMINE_H
#define POTATOMINE_H

#include <QPainter>
#include "plant.h"
class PotatoMine : public Plant
{
public:
    PotatoMine();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
public slots:
    void shoot();
};

#endif // POTATOMINE_H
