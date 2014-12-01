#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "plant.h"
#include "projectile.h"

class PeaShooter:public Plant
{
    Q_OBJECT

public:
    PeaShooter();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
public slots:
    void shoot();

};
#endif // PEASHOOTER_H
