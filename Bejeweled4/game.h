#ifndef GAME_H
#define GAME_H

// 前置声明End类，告知编译器有这样一个类存在，但暂不给出其具体定义
class End;

#include "globalvalue.h"
#include "stonelabel.h"
#include "gametimer.h"
#include "client.h"
#include "pause.h"
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <iostream>
#include <QProgressDialog>
#include <QProgressBar>

#include <QSoundEffect>

// 使用前向声明 GameItems 类，而不是包含完整的头文件
class GameItems;

QT_BEGIN_NAMESPACE
namespace Ui {
class Game;
}
QT_END_NAMESPACE
class Game : public QWidget
{
    Q_OBJECT

public:
    ~Game();
    // 新增枚举类型表示游戏模式
    enum class GameMode {
        CLASSIC_MODE,  // 经典模式
        ADVENTURE_MODE  // 冒险模式
    };
    static Game* instance(QWidget* parent = nullptr,Game::GameMode mode = Game::GameMode::ADVENTURE_MODE,int levelNum = -1,Client* client=nullptr);

    void init();
    void update();
    void handleStoneSwap(int row, int col, StoneLabel* curLabel);
    static void delInstance(){
        gameInstance=nullptr;
    }
    bool isPaused=false;
    static int jewelNum;
    QWidget* parent;

    void horizondelete(int row);
    void verticaldelete(int col);
    void onAnimationFinished();
    // 设置游戏模式的函数
    void setGameMode(GameMode mode);
    GameMode getGameMode() const;
    bool canMatch(int row, int col);
    //提示部分函数
    QList<QPair<int, int>> findHint();
    void highlightHints(const QList<QPair<int, int>>& hints);
    void updateHintCountDisplay();
    bool canSwapAndMatch(int row1, int col1, int row2, int col2);

    int checkMatch(int countRow, int countCol);//匹配(数)检测函数
    int rowCheckMatch(int row, int col);
    int colCheckMatch(int row, int col);

    void resume();//处理继续游戏信号

    int getScore();  //获取当前积分值
    int getScoreToShop() const { return score; }  // 提供获取当前分数的函数，在商店中同步积分
    // 设置分数
    void setScore(int newScore);
    //道具商店数据
    int bombCount;
    int horizonCount;
    int verticalCount;

    // 获取当前炸弹数量
    int getBombCount() const;
    void setBombCount(int count);

    // 获取当前横向消除道具数量
    int getHorizonCount() const;
    void setHorizonCount(int count);

    // 获取当前竖向消除道具数量
    int getVerticalCount() const;
    void setVerticalCount(int count);
    void updateItemCountLabels();  // 更新道具数量标签的函数

    Ui::Game *ui;
signals:
    void eliminateAgainSignal();
    void returnMainwindow();
    void directToNextLevel();
    void initEndSignal();
    void adventureLostBackToMain();
    void retryAdventure();
    void retryClassic();
    void startGameTimer();
private slots:
    void initEnd();
    void onDropAnimationFinished() {
        // 每完成一个动画，减小计数器
        animationsLeft--;

        // 所有动画完成后，执行 creatstones
        if (animationsLeft == 0) {
            qDebug()<<"OK";
            creatstones();
            this->initing=false;
        }
    }
    void onEliminateAgain();//判断新落下的棋子是否造成“连消”
    void on_pushButton_3_clicked();//暂停
    void onStartGameTimer();//开始计时
    void on_returnFromPauseToMainMenu();  //处理从暂停界面返回主菜单的信号
    void onNextButtonClicked();//下一关
    void onRetryGame();//重新挑战
    void on_pushButton_5_clicked();
    void onTimeExpired();//倒计时结束时的处理


    void on_bombButton_clicked();
    //  void on_rainbowGemButton_clicked();
    //void on_freezeTimeButton_clicked();

    void on_horizon_clicked();

    void on_vertical_clicked();

    void on_Tips_clicked();

    void on_Shop_clicked();

private:
    explicit Game(QWidget *parent = nullptr,Game::GameMode mode = Game::GameMode::CLASSIC_MODE,Client* client=nullptr);//经典模式构造器
    explicit Game(QWidget *parent = nullptr,int LevelNum = -1,Game::GameMode mode = Game::GameMode::ADVENTURE_MODE,Client* client=nullptr);//冒险模式构造器
    static Game* gameInstance;
    bool arePositionsAdjacent(int row1, int col1, int row2, int col2);//判断两次鼠标点击位置是否相邻
    void mousePressEvent(QMouseEvent *event) override;
    bool checkFormatches();//判断哪些棋子将要被消去
    void eliminateMatches() ;//消除
    void dropStones();//棋子下落，创建新子
    void dropLabel(StoneLabel* stoneLabel, int startX,int startY,int targetX, int targetY, int duration) ;//棋子下落动画
    void resetMatchedFlags();//重置所有棋子为不可消除
    void generateNewStone(int row, int col);//创建一个新子
    void creatstones();//创建所有需要的子
    void shuffleStones();//重排布
    int calGainScore(int scoreGain = 0,int iceKilledNum = 0);//计分规则
    int initTime = 20;//初始时间20s
    GameTimer *gameTimer = nullptr;//计时器
    bool isTimeExpired = false;//判断时间是否结束
    QProgressBar *progressBar = nullptr;  //计时进度条
    void updateTimerDisplay();//更新界面上显示倒计时的QLabel的文本内容
    int animationsLeft = 0;  // 重置动画计数器
    Pause *pause = nullptr;  // 暂停界面指针
    void resetGameState();//用于重置游戏状态
    End *end = nullptr;//结束界面指针
    GameMode gameMode;//游戏模式
    bool change=false;
    bool eliminateAgain=true;
    std::vector<int> swapReturn;
    QProgressDialog *progressDialog;
    bool initing;


    //Ui::Game *ui;
    bool isComboing = false; // 判断此时是否处于连击combo状态
    void setWinScore(int levelNum);//根据关卡数设置通关分数
    bool checkAdventureWin() const;//判断是否过关
    int score=0;  //记录游戏当前积分
    bool hasStartedScoring=false;  //标记是否可以开始计分，初始化为false，表示未开始计分
    int levelNumber = -1;//关卡难度
    int winScore;//目标分数
    bool horizon=false;//是否要横向消除
    bool vertical=false;//是否竖向消除
    void triggerBomb(int row, int col);
    bool isBombMode = false;  // 标记是否处于炸弹模式
    QSoundEffect* sound;  // 背景音乐
    int hintCount = 5;//提示的初始次数
    Client* client;

};

#endif // GAME_H
