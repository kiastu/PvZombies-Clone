#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gs = new GameScene(QRectF(game->ORIGINX,game->ORIGINY,game->WIDTH,game->HEIGHT), this);
    game  = new Board(gs);
    ui->gameView->setScene(gs);
    drawBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawBoard(){
    QPen my_pen = QPen(Qt::green);        // Draw lines with a green;
    //horizontal lines
    for(int i =0;i<6;i+=1){
        float p1x = game->ORIGINX;
        float p1y = game->ORIGINY + game->ROW*i;
        float p2x = game->WIDTH/2;
        float p2y = p1y;
        gs->addLine(QLineF(p1x,p1y,p2x,p2y) ,my_pen);
    }
    //Vertical lines
    for(int i =0;i<11;i+=1){
        float p1x = game->ORIGINX + game->COLUMN*i;
        float p1y = game->ORIGINY;
        float p2x = p1x;
        float p2y = game->HEIGHT/2;
        gs->addLine(QLineF(p1x,p1y,p2x,p2y) ,my_pen);
    }
}

void MainWindow::on_seed_1_clicked()
{
    PeaShooter* ps = new PeaShooter();
    this->game->setPlant(0,1,ps);


}
