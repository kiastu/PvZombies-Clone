#include "projectile.h"
#include "board.h"

Projectile::Projectile(int xorigin, int yorigin,QString type):
    x(xorigin+50),y(yorigin+5),type(type),speed(7){
}
void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*){
    QString path = ":images/"+type+".png";
    QImage* bullet= new QImage (path);
    setPos(this->x,this->y);
    setPixmap(QPixmap::fromImage(*bullet).scaled(15,15));
    setTransformationMode(Qt::SmoothTransformation);
    painter->drawPixmap(0,0,this->pixmap());
}
void Projectile::advance(int phase){
    if(!phase) return;
    //calculations on speed.
    float oldX = this->x;
    float pixelSpeed = Board::getColumn()/speed;
    float newX = oldX + pixelSpeed*1;
    this->x = newX;
    setPos(this->x,this->y);
}

//QRectF Projectile::boundingRect()const
//{
//    return QRectF(0,0,15,15);
//}

void Projectile::hit()
{
    this->scene()->removeItem(this);
    this->~Projectile();
}
float Projectile::getDamage() const
{
    return damage;
}

void Projectile::setDamage(float value)
{
    damage = value;
}
float Projectile::getX() const
{
    return x;
}

void Projectile::setX(float value)
{
    x = value;
}
float Projectile::getY() const
{
    return y;
}

void Projectile::setY(float value)
{
    y = value;
}



