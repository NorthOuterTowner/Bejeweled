#include "game.h"
#include "qevent.h"
#include "ui_game.h"
#include "stonelabel.h"
#include "globalvalue.h"
#include <QLabel>
#include <random>
#include <vector>
<<<<<<< HEAD
#include <iostream>
#include "gridwidget.h"
=======
>>>>>>> parent of c78b449 (update the delete method)
/*Space between Window and Labels*/
#define upSpacer 80
#define leftSpacer 100

/**
 * @brief generate random digit from 1 to 10
 * @return random digit
 */
GridWidget* gameWidget;
int genRandom(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}
Game::Game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    init();
}

Game::~Game()
{
    delete ui;
}
/**
 * @brief init labels on the ui
 */
void Game::init(){
    for(int row=0;row<8;row++){
        for(int line=0;line<8;line++){
            //Need change to StoneLabel
            StoneLabel *imgLabel = new StoneLabel(this);
            stones[row][line]=imgLabel;
<<<<<<< HEAD
=======
            imgLabel->resize(48,48);
            imgLabel->move(row*48+leftSpacer,line*48+upSpacer);
            std::string pixStr=":/"+imgLabel->getMode()+std::to_string(genRandom())+".png";
            imgLabel->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(48,48));
>>>>>>> parent of c78b449 (update the delete method)
        }
    }
    gameWidget=new GridWidget(this);
    gameWidget->move(leftSpacer,upSpacer);
    waitforchage=false;
    firstLabel=nullptr;
    secondLabel=nullptr;

}

std::pair<int,int> Game::delStone(){
    std::pair<int,int> ret;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            std::cout<<"del";
        }
    }
    return ret;
}
//Mouse Click
void Game::mousePressEvent(QMouseEvent *event){
<<<<<<< HEAD
    delStone();
    std::cout<<"DELETE Success"<<std::endl;
    gameWidget->updateData();
=======

>>>>>>> parent of c78b449 (update the delete method)
    QWidget* clickedWidget=this->childAt(event->pos());
    StoneLabel* label=qobject_cast<StoneLabel*>(clickedWidget);
        if(clickedWidget&&clickedWidget->inherits("QLabel")){
        if(!waitforchage&&firstLabel==nullptr){
            firstLabel = qobject_cast<StoneLabel*>(clickedWidget);
            firstLabel->setStyleSheet("background-color: lightblue;");
            waitforchage = true;

        }else if(waitforchage&&secondLabel==nullptr){
            //满足消除条件可交换？
            secondLabel = qobject_cast<StoneLabel*>(clickedWidget);
            secondLabel->setStyleSheet("background-color: lightblue;");

            // 交换位置
            QPoint temp = firstLabel->pos();
            firstLabel->move(secondLabel->pos());
            secondLabel->move(temp);

            //高亮消除
            firstLabel->setStyleSheet("");
            secondLabel->setStyleSheet("");

            // 清空指针
            firstLabel = nullptr;
            secondLabel = nullptr;
            waitforchage = false;
        }
    }
}

