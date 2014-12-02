#include "repeater.h"

Repeater::Repeater()
{
    this->attackSpeed = 3;
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->setInterval(1000*attackSpeed);
    timer->start();
}

void Repeater::shoot(){
    Projectile* pea = new Projectile(this->x+20,this->y,"pea");
    Projectile* pea2 = new Projectile(this->x,this->y,"pea");
    emit shootProjectile(pea);
    emit shootProjectile(pea2);
}

void Repeater::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage plant("images/Repeater.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
    setPos(x,y);
}

