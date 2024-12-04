#ifndef GAME_H
#define GAME_H

#include "stonelabel.h"
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

namespace Ui {
class Game;
}

class Game : public QWidget
{

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    void init();
    static std::vector<std::pair<int,int>> delStone();

private:
    void mousePressEvent(QMouseEvent *event) override;
    bool waitforchage=false;//棋子交换-等待第二次点击
    StoneLabel *firstLabel=nullptr;
    StoneLabel *secondLabel=nullptr;
    Ui::Game *ui;
};

#endif // GAME_H
