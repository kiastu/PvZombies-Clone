#include "peashooter.h"
#include <iostream>
#include "Board.h"
PeaShooter::PeaShooter()
{
    this->attackSpeed = 1.5;
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->setInterval(1000*attackSpeed);
    timer->start();
}

void PeaShooter::shoot(){
    Projectile* pea = new Projectile(this->x,this->y,"pea");
    emit shootProjectile(pea);
}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QImage plant(":images/peashooter.png");
    setPos(x,y);
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
}

