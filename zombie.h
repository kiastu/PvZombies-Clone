#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QPainter>
#include "Board.h"

class Zombie : public QGraphicsItem
{
public:
    Zombie(int life = 10,int attack = 1);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void attack();
protected:
    void advance(int phase);
private :
    float x,y,speed,currentLife,maxLife;
};

#endif // ZOMBIE_H
