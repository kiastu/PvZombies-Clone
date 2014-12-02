#include "zombie.h"
#include "board.h"
#include "Plant.h"
#include <QTimer>
#include "projectile.h"

Zombie::Zombie(int row, int type):isStopped(false),health(10){
    this->row = row;
    this->type = type;
    this->x = Board::WIDTH/2-10;
    this->y = Board::ORIGINY+row*Board::ROW;
    this->speed = 10;
    nomTimer = 5;
}

void Zombie::die(){
    std::cout<<"Argh I have been slainzored";
    this->scene()->removeItem(this);
    emit killMeNow(this);
}

void Zombie::nomnomnom(Plant *plant)
{
    nomTimer++;
    if(nomTimer)
    plant->beEaten();
}

void Zombie::getHit(int damage)
{
    this->health -= damage;
    if(this->health <=0)
        this->die();
}

void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
    bool collision = !collidingItems.isEmpty();
    this->isStopped = false;
    if(collision){
        //check what object it smacked in to.
        for(int i =0;i<collidingItems.size();i++){
            Plant* testPlant = dynamic_cast<Plant*>(collidingItems.at(i));
            Projectile* testProjectile = dynamic_cast<Projectile*>(collidingItems.at(i));
            if(testPlant!=NULL){//is a plant.
                this->nomnomnom(testPlant);
                painter->drawText(0,0,"Nomnomnomnom");
                this->isStopped = true;
            }
            else if(testProjectile != NULL){
                //is a projectile
                this->getHit(1);
                testProjectile->hit();
            }else{
                //do nothing
            }
        }
    }
    else{
        this->isStopped = false;
    }
    if(type ==1){
        QImage zombie(":/images/zombienewspaper.png");
        setPos(x,y);
        painter->drawPixmap(0,0,QPixmap::fromImage(zombie).scaled(75,100));
    }
    else{
        QImage zombie(":/images/zombie.png");
        setPos(x,y);
        painter->drawPixmap(0,0,QPixmap::fromImage(zombie).scaled(75,100));
    }


}


QRectF Zombie::boundingRect()const{
    return QRectF(0,0,75,100);
}
void Zombie::advance(int phase){
    if(!phase) return;
    //stops zombie on encountering plant.
    if(!isStopped){
        //calculations on speed.
        float oldX = this->x;
        float pixelsPerSecond = 0;
        if(speed !=0){
            pixelsPerSecond = Board::getColumn()/speed;
            float newX = oldX - pixelsPerSecond;
            this->x = newX;
            setPos(this->x,this->y);
        }

    }
    else return;
}

