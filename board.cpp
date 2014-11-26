#include "board.h"

Board::Board(QGraphicsScene *newGrid){
    //default is 5 rows.
    this->rows = 5;
    for(int i = 0;i<rows;i++){
        for(int j=0; j<10;j++){
            isOccupied[i][j] = false;
        }
    }
    grid = newGrid;
}

Board::Board(QGraphicsScene *newGrid,int rows){
    this->rows = rows;
    for(int i = 0;i<rows;i++){
        for(int j=0; j<10;j++){
            isOccupied[i][j] = false;
        }
    }
}

Plant& Board::getPlant(int row, int column){
    return *plants[row][column];
}

void Board::setPlant(int row, int column, Plant *newPlant){
    if(isOccupied[row][column]){
        std::cout<<"Error, already a plant there!";
        return;
    }
    isOccupied[row][column] = true; //there's a plant now!
    plants[row][column] = newPlant;

    //Let's calculate where this plant should be!
    int grid_width = WIDTH / 10;
    int grid_height = HEIGHT /5;
    int grid_x = ORIGINX + grid_width*column + grid_width/2;
    int grid_y = ORIGINY + grid_height*row + grid_height/2;
    std::cout<<"Grid x:"<<grid_x<<"Grid y:"<<grid_y<<"\n";
   // newPlant->setPosition(ORIGINX,ORIGINY);
    newPlant->setPosition(grid_x,grid_y);

    this->grid->addItem(newPlant);


}
Board::~Board(){

}
