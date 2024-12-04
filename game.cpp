#include "game.h"
#include "qevent.h"
#include "ui_game.h"
#include "stonelabel.h"
#include "globalvalue.h"
#include <QLabel>
#include <random>
#include <vector>
#include <iostream>
#include "gridwidget.h"
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
        }
    }
    gameWidget=new GridWidget(this);
    gameWidget->move(leftSpacer,upSpacer);
    waitforchage=false;
    firstLabel=nullptr;
    secondLabel=nullptr;

}

/*Decide that which StoneLabel should be delete*/
std::vector<std::pair<int,int>> Game::delStone(){
    std::vector<std::pair<int,int>> deleteContent;
    for (int i = 0; i < 8; ++i) {
        int count = 1;
        for (int j = 1; j < 8; ++j) {
            if (stones[i][j] && stones[i][j]->getType() == stones[i][j - 1]->getType()) {
                ++count;
            } else {
                if (count >= 3) {
                    for (int k = j - count; k < j; ++k) {
                        deleteContent.push_back({i, k});
                    }
                }
                count = 1;
            }
        }
        if (count >= 3) {
            for (int k = 8 - count; k < 8; ++k) {
                deleteContent.push_back({i, k});
            }
        }
    }
    for (int j = 0; j < 8; ++j) {
        int count = 1;
        for (int i = 1; i < 8; ++i) {
            if (stones[i][j] && stones[i][j]->getType() == stones[i - 1][j]->getType()) {
                ++count;
            } else {
                if (count >= 3) {
                    for (int k = i - count; k < i; ++k) {
                        deleteContent.push_back({k, j});
                    }
                }
                count = 1;
            }
        }
        if (count >= 3) {
            for (int k = 8 - count; k < 8; ++k) {
                deleteContent.push_back({k, j});
            }
        }
    }
    /*Here need to be repaint*/
    for(int i=0;i<deleteContent.size();i++){
        stones[deleteContent[i].first][deleteContent[i].second]=nullptr;
    }
    return deleteContent;
}

//Mouse Click
void Game::mousePressEvent(QMouseEvent *event){
    delStone();
    std::cout<<"DELETE Success"<<std::endl;
    gameWidget->updateData();
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

