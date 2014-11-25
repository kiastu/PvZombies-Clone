#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>

class Plant: public QGraphicsItem{
public:
    Plant();
    virtual void shoot();
    void die();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;

private:
    int health,damage,x,y;
    float attackSpeed;
};

#endif // PLANT_H
