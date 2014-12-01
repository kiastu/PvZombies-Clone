#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>

class Projectile : public QGraphicsItem
{
public:
    Projectile(int xorigin, int yorigin, QString type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;

    float getDamage() const;
    void setDamage(float value);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

protected:
    void advance(int phase);
private:
    float x,y;
    int damage,speed;
    QString type;
};

#endif // PROJECTILE_H
