#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
#include <random>
#include <iostream>
#include "game.h"
#include "globalvalue.h"

#define upSpacer 80
#define leftSpacer 100

class GridWidget : public QWidget
{
    Q_OBJECT

public:
    int genRandom(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10);
        return dis(gen);
    }
    explicit GridWidget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        gridLayout = new QGridLayout(this);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labels=stones;
        initData();
    }
    void initData(){
        std::cout<<"Init"<<std::endl;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                StoneLabel* label=labels[i][j];
                gridLayout->addWidget(label, i, j);
                label->resize(48,48);
                //label->move(i*48+leftSpacer,j*48+upSpacer);
                int type=genRandom();
                label->setType(type);
                std::string pixStr=":/"+label->getMode()+std::to_string(type)+".png";
                label->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(48,48));
            }
        }
    }
    void clearLayout(QGridLayout *layout) {
        if (!layout) return;
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            std::cout<<"Sucing"<<std::endl;
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        std::cout<<"Suc"<<std::endl;
    }
    void updateData(){
        for (const auto& pos : Game::delStone()) {
            StoneLabel* label = stones[pos.first][pos.second];
            delete label;
            stones[pos.first][pos.second] = nullptr;
        }
    }

private:
    QGridLayout *gridLayout;  // 网格布局
    std::vector<std::vector<StoneLabel*>>  labels;     // 用于存放8x8的QLabel
};
