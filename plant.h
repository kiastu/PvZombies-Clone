#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsObject>
#include <QPainter>
#include "Projectile.h"
#include <QTimer>

class Plant: public QObject, public QGraphicsItem{

    Q_OBJECT

public:
    Plant();
    void die();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    void setPosition(float row, float column);
    float getAttackSpeed() const;
    void setAttackSpeed(float value);
    QRectF boundingRect()const;
signals:
    void shootProjectile(Projectile* bullet);
public slots:
    virtual void shoot();
protected:
    QTimer* timer;
    int health,damage;
    float x,y,attackSpeed;
};

#endif // PLANT_H
