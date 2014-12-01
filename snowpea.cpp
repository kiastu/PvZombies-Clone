#include "snowpea.h"


SnowPea::SnowPea()
{
    this->attackSpeed = 10;
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->setInterval(500*attackSpeed);
    timer->start();
}

void SnowPea::shoot(){
    Projectile* frozenPea = new Projectile(this->x,this->y,"frozenpea");
    emit shootProjectile(frozenPea);
}

void SnowPea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QImage plant("images/SnowPea.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
    setPos(x,y);
}

