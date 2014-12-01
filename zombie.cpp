#include "zombie.h"
#include "board.h"


Zombie::Zombie(int row, int type){
    this->row = row;
    this->type = type;
    this->x = Board::WIDTH/2-10;
    this->y = Board::ORIGINY+row*Board::COLUMN;
    this->speed = 10;
}
int Zombie::attack(){
    return 1;
}
void Zombie::die(){
    //fade animation
}

void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QPen pen(Qt::green,2);
    QImage zombie(":/images/zombie.png");
    painter->drawPixmap(0,0,QPixmap::fromImage(zombie).scaled(75,100));
    setPos(x,y);
}

QRectF Zombie::boundingRect()const{
    return QRectF(0,0,75,100);
}
void Zombie::advance(int phase){
    if(!phase) return;
    //calculations on speed.
    float oldX = this->x;
    float pixelsPerSecond = Board::getColumn()/speed;
    float newX = oldX - pixelsPerSecond;
    this->x = newX;
    setPos(this->x,this->y);
}

