#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QCoreApplication>
#include <exception>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Read Level Data
    //Read Level Data
    QFile file(":/pvz_levels.csv");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Error, Levels Missing!", "Error, pvz_levels missing!!");
        this->~MainWindow();
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(":");
        levels.append(fields);
    }

    file.close();
    //Read User Data
    QList<QStringList> userData;
    bool userDataIsValid = true;
    QFile file2(":/pvz_players.csv");
    if(!file2.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Warning! ", "pvz_users not found!");
        userDataIsValid = false;
    }
    if(userDataIsValid){
        QTextStream inUser(&file2);

        while(!inUser.atEnd()) {
            QString line = inUser.readLine();
            QStringList fields = line.split(":");
            userData.append(fields);
        }
    }
    file2.close();
    if(!userDataIsValid){
        file2.resize(0);
    }
    else{
        //populate combobox
        for(int i=0;i<userData.size();i+=1){
            QStringList user = userData.at(i);
            //check for incorrect savefile.
            bool *ok = new bool(true);
            int timestamp = user.at(0).toInt(ok);
            //check for non-alpha numeric characters
            QRegExp exp(QString::fromUtf8("[-`~!@#$%^&*()_—+=|:;<>«»,.?/{}\'\"\\\[\\\]\\\\]"));
            user.at(1).contains(exp);
            if(user.at(1).length()>10){//too long
                *ok =false;
            }
            if(*ok == false){
                //is not okay!
                file2.resize(0);
                QMessageBox::information(0, "Warning! ", "pvz_users data corrupted!");
                userDataIsValid = false;
                break;
            }

        }
    }
    //populate the combo box
    for(int i=0;i<userData.length();i+=1){
        this->ui->user_select->addItem(userData.at(i).at(1));
    }
    if(userDataIsValid&&userData.length()>0){
        this->ui->button_start->setEnabled(true);
        this->ui->button_restart->setEnabled(true);
        this->ui->button_quit->setEnabled(true);
    }

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

    //set sun
    sunStore = 400;
    this->ui->sun_count->display(sunStore);
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

    //zombies
    QString aString = levels.at(0).at(1);
    QStringList zombieList = aString.split(",");
    this->game->loadFile(zombieList.size());

    //Planting cooldowns
    int staticCooldowns[8] = {7500,7500,50000,30000,30000,7500,7500,7500};
    int staticCosts[8] = {100,50,150,50,25,175,150,200};
    for(int i=0;i<8;i+=1){
        cooldown[i]=staticCooldowns[i];
        isAvailable[i] = 0;
        sunCost[i]=staticCosts[i];
    }
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), game, SLOT(advance()));
    timer->setInterval(GAMESPEED);


    //handle planting countdown.
    connect(game,SIGNAL(plantPlanted()),this,SLOT(startPlantTimer()));
    connect(timer,SIGNAL(timeout()),this,SLOT(decrementAll()));


}

MainWindow::~MainWindow()
{

    for(int i=0;i<8;i+=1){
        if(lcds[i]!=NULL)
            delete lcds[i];
    }
    if(timer!=NULL)
        delete timer;
    if(game!=NULL)
        delete game;
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

void MainWindow::startLevel(int level)
{

}

void MainWindow::on_seed_1_clicked()
{
    PeaShooter* ps = new PeaShooter();
    this->buyPlant(0,ps);
}
void MainWindow::on_seed_2_clicked()
{
    SunFlower* sf = new SunFlower();
    this->buyPlant(1,sf);
}
void MainWindow::on_seed_3_clicked(){
    CherryBomb* cb = new CherryBomb();
    this->buyPlant(2,cb);
}
void MainWindow::on_seed_4_clicked(){
    WallNut* wn = new WallNut();
    this->buyPlant(3,wn);
}
void MainWindow::on_seed_5_clicked(){
    PotatoMine* pm = new PotatoMine();
    this->buyPlant(4,pm);
}
void MainWindow::on_seed_6_clicked(){
    SnowPea* sp = new SnowPea();
    this->buyPlant(5,sp);
}
void MainWindow::on_seed_7_clicked(){
    Chomper* c = new Chomper();
    this->buyPlant(6,c);
}
void MainWindow::on_seed_8_clicked(){
    Repeater* r = new Repeater();
    this->buyPlant(7,r);
}
void MainWindow::startPlantTimer(){
    //assign cooldown
    isAvailable[selected] = cooldown[selected];
    //credit the sun.
    this->sunStore-=this->sunCost[selected];
    this->ui->sun_count->display(this->sunStore);
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
    this->ui->sun_count->display(sunStore);
}

void MainWindow::buyPlant(int plantId,Plant *plant)
{
    //Has enough sun, and is available. Let' select it.
    if(sunStore>=sunCost[plantId]&&isAvailable[plantId]==0){
        //we can buy it. Select the plant.
        this->game->selectPlant(plant);
        this->selected =plantId;
    }
    else{
        //prevent leaks
        delete plant;
    }
}

void MainWindow::on_button_start_clicked()
{
    timer->start();
    this->ui->button_new->setEnabled(false);
    this->ui->button_start->setEnabled(false);
}

void MainWindow::on_button_quit_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_button_new_clicked()
{
    if(this->ui->new_user->toPlainText()!=""){
        this->ui->user_select->addItem(this->ui->new_user->toPlainText());
        this->ui->button_start->setEnabled(true);
        this->ui->button_quit->setEnabled(true);
        this->ui->button_restart->setEnabled(true);
    }
}

void MainWindow::on_button_restart_clicked()
{
    this->timer->stop();
    QMessageBox box;
    box.setText("Restart?");
    box.setInformativeText("Are you sure you want to restart?");
    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = box.exec();
    switch(ret){
    case QMessageBox::Ok:{
        //restart the game.
        delete game;
        startLevel(this->level);
        timer->start();
        break;
    }
    case QMessageBox::Cancel:{
        box.close();
        timer->start();
        break;
    }

    }

}
