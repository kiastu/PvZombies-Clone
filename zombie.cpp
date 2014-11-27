#include "zombie.h"

Zombie::Zombie()
{
}

void Zombie::attack(){

}

void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage zombie("images/Zombie.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(zombie).scaled(50,50));
    setPos(x,y);
}

QRectF Zombie::boundingRect()const
{
    return QRectF(0,0,50,75);
}
void Zombie::advance(int phase){
    if(!phase) return;
    //calculations on speed.
    float oldX = this->x;
    float newX =
    setPos(this->x,this->y);
}

