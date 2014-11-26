#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>

class Plant:public QGraphicsItem{
public:
    Plant();
    virtual void shoot();
    void die();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void setPosition(float row, float column);

protected:
    int health,damage;
    float x,y,attackSpeed;
};

#endif // PLANT_H
