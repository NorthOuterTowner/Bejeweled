#include "game.h"
#include "ui_game.h"
#include "stonelabel.h"
#include <QLabel>
#include <random>
/**
 * @brief generate random digit from 1 to 10
 * @return random digit
 */
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
            /*Need change to StoneLabel*/
            QLabel *imgLabel = new QLabel(this);
            imgLabel->resize(64,64);
            imgLabel->move(row*64,line*64);
            std::string pixStr=":/gemstone"+std::to_string(genRandom())+".png";
            imgLabel->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(64,64));
        }
    }
}
