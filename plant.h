#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include "entity.h"

class Plant:public Entity
{
public:
    Plant();
    virtual void shoot()=0;
    void die();

private:
    int health;
    int damage;
    float attackSpeed;
};

#endif // PLANT_H
