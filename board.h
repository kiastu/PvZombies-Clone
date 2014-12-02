#ifndef BOARD_H
#define BOARD_H

#include "plant.h"
#include <vector>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QFile>
#include "zombie.h"
#include "projectile.h"
#include <QObject>
#include "lawnmower.h"


class Board :public QGraphicsScene{

Q_OBJECT

public:
    Board(const QRectF & sceneRect, QObject * parent = 0,int rows=5);
    void setRows(int rows);
    Plant& getPlant(int row, int column);
    void setPlant(int row, int column, Plant *newPlant);
    void selectPlant(Plant *newPlant);
    void loadFile(int size);
    void unleashHorde();
    void releaseZombie(int row,int type);
    ~Board();
    //Mouse Events
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    enum{
        WIDTH = 800,
        HEIGHT = 500,
        ORIGINX = -WIDTH/2,
        ORIGINY = -HEIGHT/2,
        COLUMN = WIDTH/10,
        ROW = HEIGHT/5
    };
    static int getWidth(){return WIDTH;}
    static int getHeight(){return HEIGHT;}
    static int getColumn(){return COLUMN;}
    static int getRow(){return ROW;}
    static int getOriginX(){return ORIGINX;}
    static int getOriginY(){return ORIGINY;}
signals:
    void plantPlanted();
public slots:
    void fireProjectile(Projectile* bullet);
    void eatPlant(Zombie* attacker);
    void killMeNow(Plant* plant);
    void killMeNow(Zombie* zombie);
    void dropSun();

private:
    int clickIndex(QPointF click);
    int rows;//size of the board
    Plant* plants[5][10];
    QList<Projectile*> projectiles;
    bool isOccupied[5][10];
    Plant* selectedPlant;
    QList<Zombie*> zombies;
    QList<LawnMower*> lawnmowers;
};

#endif // BOARD_H
