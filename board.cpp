#include "board.h"
#include <QDebug>

Board::Board(const QRectF & sceneRect, QObject * parent,int rows):QGraphicsScene(sceneRect,parent){
    this->rows = rows;
    for(int i = 0;i<rows;i++){
        for(int j=0; j<10;j++){
            if(j==0){
                isOccupied[i][j]=true;//lawnmower row.
            }
            else
                isOccupied[i][j] = false;
        }
    }
    selectedPlant = NULL;

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
   // newPlant->setPosition(ORIGINX,ORIGINY);
    newPlant->setPosition(grid_x,grid_y);

    this->addItem(newPlant);


}

void Board::selectPlant(Plant *newPlant){
    //this recieves the selected plant from the MainWindow.

    selectedPlant = newPlant;

}
Board::~Board(){

}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    //mouse click recieved. Check what grid it clicked.
    int index = clickIndex(mouseEvent->scenePos());
    std::cout<<"index:"<<index<<"\n";
    if(index == -1){
        //Not in anything...
        return;
    }
    else{
        //let's parse the int.
        int row = index/10;
        int column = index%10;
        //Let's check if we have a plant selected.
        if(selectedPlant == NULL){
            //no plant is currently selected, do nothing.
            return;
        }
        else{
            //a plant is selected. Let's plant it on to the board!
            setPlant(row,column,selectedPlant);
            // the planting is done, let's deselect the plant.
        }

    }
}

int Board::clickIndex(QPointF click){
    //TODO: Handle clicking of sun.
    //oh lord this is going to be fun....
    float x = click.x();
    float y = click.y();
    std::cout<<"X value: "<<x<<"Y value: "<<y<<"\n";

    x+=WIDTH/2;//conversion to positive numbers
    y+=HEIGHT/2;

    int column = x/COLUMN;
    int row = y/ROW;
    std::cout <<"Column:"<<column<<"Row:"<<row<<"\n";
    if(column<0||column>9||row<0||row>4){
        return -1;//error, not in board.
    }
    else{
        //return the index of the clicked grid.
        return (row*10+column);
    }
}
