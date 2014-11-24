#ifndef BOARD_H
#define BOARD_H

#include "plant.h"


class Board:public QGraphicsItem
{
public:
    Board();
    Board(int rows);
    void setRows(int rows);
private:
    int rows;//size of the board
    int grid;
};

#endif // BOARD_H
