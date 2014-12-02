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
    //connect LCD's
    lcds[0] = this->ui->cd_1;
    lcds[1] = this->ui->cd_2;
    lcds[2] = this->ui->cd_3;
    lcds[3] = this->ui->cd_4;
    lcds[4] = this->ui->cd_5;
    lcds[5] = this->ui->cd_6;
    lcds[6] = this->ui->cd_7;
    lcds[7] = this->ui->cd_8;

    //draw images
    QImage plant1,plant2,plant3,plant4,plant5,plant6,plant7,plant8;

    plant1.load(":/images/peashooter.png");
    QLabel* label1 = ui->seed_1_label;
    label1->setPixmap(QPixmap::fromImage(plant1).scaled(50,50));

    plant2.load(":/images/sunflower.png");
    QLabel* label2 = ui->seed_2_label;
    label2->setPixmap(QPixmap::fromImage(plant2).scaled(50,50));

    plant3.load(":/images/cherrybomb.png");
    QLabel* label3 = ui->seed_3_label;
    label3->setPixmap(QPixmap::fromImage(plant3).scaled(50,50));

    plant4.load(":/images/wallnut.png");
    QLabel* label4 = ui->seed_4_label;
    label4->setPixmap(QPixmap::fromImage(plant4).scaled(50,50));

    plant5.load(":/images/potatomine.png");
    QLabel* label5 = ui->seed_5_label;
    label5->setPixmap(QPixmap::fromImage(plant5).scaled(50,50));

    plant6.load(":/images/snowpea.png");
    QLabel* label6 = ui->seed_6_label;
    label6->setPixmap(QPixmap::fromImage(plant6).scaled(50,50));

    plant7.load(":/images/chomper.png");
    QLabel* label7 = ui->seed_7_label;
    label7->setPixmap(QPixmap::fromImage(plant7).scaled(50,50));

    plant8.load(":/images/repeater.png");
    QLabel* label8 = ui->seed_8_label;
    label8->setPixmap(QPixmap::fromImage(plant8).scaled(50,50));

    //testing zombies
    this->game->releaseZombie(1,1);

    //Planting cooldowns
    int staticCooldowns[8] = {7500,7500,50000,30000,30000,7500,7500,7500};
    for(int i=0;i<8;i+=1){
        cooldown[i]=staticCooldowns[i];
        isAvailable[i] = 0;
    }
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), game, SLOT(advance()));
    timer->setInterval(GAMESPEED);


    //handle planting countdown.
    connect(game,SIGNAL(plantPlanted()),this,SLOT(startPlantTimer()));
    connect(timer,SIGNAL(timeout()),this,SLOT(decrementAll()));
    timer->start();

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
    if(isAvailable[0]==0){
        PeaShooter* ps = new PeaShooter();
        this->game->selectPlant(ps);
        this->selected = 0;
    }
}

void MainWindow::on_seed_2_clicked()
{
    if(isAvailable[1]==0){
        SunFlower* sf = new SunFlower();
        this->game->selectPlant(sf);
        this->selected = 1;
    }
}
void MainWindow::on_seed_3_clicked(){
    if(isAvailable[2]==0){
        CherryBomb* cb = new CherryBomb();
        this->game->selectPlant(cb);
        this->selected = 2;
    }
}

void MainWindow::on_seed_4_clicked(){
    if(isAvailable[3]==0){
        WallNut* wn = new WallNut();
        this->game->selectPlant(wn);
        this->selected = 3;
    }}
void MainWindow::on_seed_5_clicked(){
    if(isAvailable[4]==0){
        PotatoMine* pm = new PotatoMine();
        this->game->selectPlant(pm);
        this->selected = 4;
    }}
void MainWindow::on_seed_6_clicked(){
    if(isAvailable[5]==0){
        SnowPea* sp = new SnowPea();
        this->game->selectPlant(sp);
        this->selected = 5;
    }}
void MainWindow::on_seed_7_clicked(){
    if(isAvailable[6]==0){
        Chomper* c = new Chomper();
        this->game->selectPlant(c);
        this->selected = 6;
    }}
void MainWindow::on_seed_8_clicked()
{if(isAvailable[7]==0){
        Repeater* r = new Repeater();
        this->game->selectPlant(r);
        this->selected = 7;
    }}
void MainWindow::startPlantTimer(){
    //assign cooldown
    isAvailable[selected] = cooldown[selected];
}
void MainWindow::decrementAll(){
    for(int i = 0;i < 8;i+=1){
        if(isAvailable[i] >0){
            isAvailable[i]-=GAMESPEED;
            this->lcds[i]->display(isAvailable[i]/1000);
        }else{
            isAvailable[i] = 0;
            this->lcds[i]->display(0);
        }
    }

}

void MainWindow::getSun()
{
    sunStore+=25;
}
