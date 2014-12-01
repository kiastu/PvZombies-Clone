#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QPainter>

class Zombie : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    Zombie (int row, int type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    int attack();
    void die();
protected:
    void advance(int phase);
private:
    float x,y;
    float speed,life,attackSpeed;
    int row,type;
};

#endif // ZOMBIE_H
