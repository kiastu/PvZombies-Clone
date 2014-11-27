#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game = new Board(QRectF(game->ORIGINX,game->ORIGINY,game->WIDTH,game->HEIGHT), this, 5);
    ui->gameView->setScene(game);
    drawBoard();
    QImage plant1,plant2,plant3,plant4,plant5,plant6,plant7,plant8;

    plant1.load("images/peashooter.png");
    QLabel* label1 = ui->seed_1_label;
    label1->setPixmap(QPixmap::fromImage(plant1).scaled(50,50));

    plant2.load("images/sunflower.png");
    QLabel* label2 = ui->seed_2_label;
    label2->setPixmap(QPixmap::fromImage(plant2).scaled(50,50));

    plant3.load("images/cherrybomb.png");
    QLabel* label3 = ui->seed_3_label;
    label3->setPixmap(QPixmap::fromImage(plant3).scaled(50,50));

    plant4.load("images/wallnut.png");
    QLabel* label4 = ui->seed_4_label;
    label4->setPixmap(QPixmap::fromImage(plant4).scaled(50,50));

    plant5.load("images/potatomine.png");
    QLabel* label5 = ui->seed_5_label;
    label5->setPixmap(QPixmap::fromImage(plant5).scaled(50,50));

    plant6.load("images/snowpea.png");
    QLabel* label6 = ui->seed_6_label;
    label6->setPixmap(QPixmap::fromImage(plant6).scaled(50,50));

    plant7.load("images/chomper.png");
    QLabel* label7 = ui->seed_7_label;
    label7->setPixmap(QPixmap::fromImage(plant7).scaled(50,50));

    plant8.load("images/repeater.png");
    QLabel* label8 = ui->seed_8_label;
    label8->setPixmap(QPixmap::fromImage(plant8).scaled(50,50));

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
