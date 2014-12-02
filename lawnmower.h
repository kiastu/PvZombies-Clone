#ifndef LAWNMOWER_H
#define LAWNMOWER_H

#include <QGraphicsPixmapItem>
#include <QPainter>

class LawnMower : public QGraphicsPixmapItem
{
public:
    LawnMower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);

};

#endif // LAWNMOWER_H
