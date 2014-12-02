#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTimeLine>
#include <QGraphicsItemAnimation>


class Projectile : public QGraphicsPixmapItem
{
public:
    Projectile(int xorigin, int yorigin, QString type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    //QRectF boundingRect()const;
    void hit();

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
    QTimeLine* timer;
    QGraphicsItemAnimation* animation;

};

#endif // PROJECTILE_H
