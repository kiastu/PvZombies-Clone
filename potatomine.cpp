#include "potatomine.h"
#include "Zombie.h"
#include <QGraphicsScene>

PotatoMine::PotatoMine()
{
}

void PotatoMine::shoot(){

}

void PotatoMine::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    //if we collide with a zombie...
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
    bool collision = !collidingItems.isEmpty();
    if(collision){
        //check if zombie
        for(int i =0;i<collidingItems.size();i++){
            Zombie* testZombie = dynamic_cast<Zombie*>(collidingItems.at(i));
            if(testZombie!=NULL){//is a zombie
                testZombie->getHit(9999);
                painter->drawText(0,0,"Boom!");
                emit killMeNow(this);
            }

        }
    }
    QImage plant(":images/potatomine.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(plant).scaled(60,60));
    setPos(x,y);
}

