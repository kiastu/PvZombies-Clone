#include "board.h"
#include "QGraphicsPixmapItem"


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
    //initialize lawnmowers
    //Let's calculate where lawnmower should be
    for(int i =0;i<5;i+=1){
        LawnMower* lm = new LawnMower();
        int grid_x = ORIGINX + COLUMN/2-30;
        int grid_y = ORIGINY + ROW*i + ROW/2-25;
        lm->setPos(grid_x,grid_y);
        this->lawnmowers.append(lm);
        this->addItem(lm);
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

    //Let's calculate where this plant should be

    int grid_x = ORIGINX + COLUMN*column + COLUMN/2-30;
    int grid_y = ORIGINY + ROW*row + ROW/2-25;
    newPlant->setPosition(grid_x,grid_y);
    QObject::connect(newPlant,SIGNAL(shootProjectile(Projectile*)),this,SLOT(fireProjectile(Projectile*)));
    this->addItem(newPlant);
    emit plantPlanted();
}

void Board::selectPlant(Plant *newPlant){
    //this recieves the selected plant from the MainWindow.

    selectedPlant = newPlant;

}

void Board::loadFile(QFile file)
{

}

void Board::unleashHorde()
{
    //this handles the logic for when to send out zombies.
}

void Board::releaseZombie(int row, int type)
{
    //new zombie, use the row to calculate proper y displacement.
    Zombie* newZombie = new Zombie(row,type);
    this->addItem(newZombie);
}

/*void Board::advance(int phase)
{
    std::cout<<"Hey I'm advancing!";
    releaseZombie(0,1);
}*/
Board::~Board(){
    //cleaning up all the pointers and shiz
    for(int i = 0;i<5;i+=1){
        for(int j=0;j<10;j+=1){
            if(isOccupied[i][j])
                delete plants[i][j];
        }
    }
    delete selectedPlant;
    for(int i=0;i<zombies.size();i+=1){
        delete zombies.at(i);
    }
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
            selectedPlant=NULL;
            // the planting is done, let's deselect the plant.
        }

    }
}

void Board::fireProjectile(Projectile* bullet)
{
    projectiles.push_back(bullet);
    this->addItem(bullet);
    //trying some new stuff with timeline to make the animation smoother.
    /*QTimeLine* timer = new QTimeLine(2000);
    timer->setFrameRange(0,100);
    QGraphicsItemAnimation* animation = new QGraphicsItemAnimation();
    animation->setItem(bullet);
    animation->setTimeLine(timer);
    animation->setPosAt(0.0, QPointF(10,0));
    animation->setPosAt(0.5, QPointF(0,100));
    animation->setPosAt(1.0, QPointF(10,0));
    timer->start();*/
}

void Board::eatPlant(Zombie *attacker)
{
    std::cout<<"Nom nom nom.";
}

void Board::killMeNow(Plant *plant)
{
    //find where this plant is.
    for(int i=0;i<5;i+=1)
    {
        for(int j=1;j<10;j+=1){
            if(plants[i][j] == plant){
                delete plant;
                plants[i][j] = NULL;
                isOccupied[i][j]=false;
            }
        }
    }
}

void Board::killMeNow(Zombie *zombie)
{
    int index = this->zombies.indexOf(zombie);
    delete this->zombies.at(index);
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
