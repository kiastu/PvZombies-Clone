#include "board.h"

Board::Board(){
    //default is 5 rows.
    this->rows = 5;
    for(int i = 0;i<rows;i++){
        for(int j; j<10;i++){
            plants.at(i)[j]=NULL;
        }
    }
}

Board::Board(int rows){
    this->rows = rows;
    for(int i = 0;i<rows;i++){
        for(int j; j<10;i++){
            plants.at(i)[j]=NULL;
        }
    }
}


Plant* Board::getPlant(int row, int column){
    return plants.at(row)[column];
}

void Board::setPlant(int row, int column, Plant *newPlant){
    plants.at(row)[column] = newPlant;
}
Board::~Board(){

}
