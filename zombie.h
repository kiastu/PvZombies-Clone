#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QPainter>
#include "plant.h"

class Zombie : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    Zombie (int row, int type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect()const;
    void die();
    void nomnomnom(Plant* plant);
    void getHit(int damage);
signals:
    void killMeNow(Zombie* zombie);
protected:
    void advance(int phase);
private:
    float x,y;
    float speed,health,attackSpeed;
    int row,type;
    bool isStopped;
};

#endif // ZOMBIE_H
