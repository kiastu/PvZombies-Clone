#ifndef BOARD_H
#define BOARD_H

#include "plant.h"
#include "entity.h"
#include <vector>
#include <iostream>

class Board:public QGraphicsItem{
public:
    Board();
    Board(int rows);
    void setRows(int rows);
    Plant* getPlant(int row, int column);
    void setPlant(int row, int column, Plant *newPlant);
    ~Board();

private:
    int rows;//size of the board
    std::vector<Plant*[10]> plants;

};

#endif // BOARD_H
