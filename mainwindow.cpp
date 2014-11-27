#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Board(QRectF(game->ORIGINX,game->ORIGINY,game->WIDTH,game->HEIGHT), this,5);
    ui->gameView->setScene(game);
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
        game->addLine(QLineF(p1x,p1y,p2x,p2y) ,my_pen);
    }
    //Vertical lines
    for(int i =0;i<11;i+=1){
        float p1x = game->ORIGINX + game->COLUMN*i;
        float p1y = game->ORIGINY;
        float p2x = p1x;
        float p2y = game->HEIGHT/2;
        game->addLine(QLineF(p1x,p1y,p2x,p2y) ,my_pen);
    }
}

void MainWindow::on_seed_1_clicked()
{
    PeaShooter* ps = new PeaShooter();
    this->game->selectPlant(ps);
}

void MainWindow::on_seed_2_clicked()
{

}
void MainWindow::on_seed_3_clicked(){

}

void MainWindow::on_seed_4_clicked(){

}
void MainWindow::on_seed_5_clicked(){

}
void MainWindow::on_seed_6_clicked(){

}
void MainWindow::on_seed_7_clicked(){

}
void MainWindow::on_seed_8_clicked()
{

}
