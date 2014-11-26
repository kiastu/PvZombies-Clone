#ifndef BOARD_H
#define BOARD_H

#include "plant.h"
#include <vector>
#include <iostream>
#include <QGraphicsScene>

class Board :public QGraphicsScene{
public:
    Board(const QRectF & sceneRect, QObject * parent = 0,int rows=5);
    void setRows(int rows);
    Plant& getPlant(int row, int column);
    void setPlant(int row, int column, Plant *newPlant);
    ~Board();
    enum{
        WIDTH = 800,
        HEIGHT = 500,
        ORIGINX = -WIDTH/2,
        ORIGINY = -HEIGHT/2,
        COLUMN = WIDTH/10,
        ROW = HEIGHT/5
    };

private:
    int rows;//size of the board
    Plant* plants[5][10];
    bool isOccupied[5][10];
};

#endif // BOARD_H
