#include "game.h"
#include "qevent.h"
#include "ui_game.h"
#include "stonelabel.h"
#include "globalvalue.h"
#include "mainwindow.h"
#include "pause.h"
#include "ui_pause.h"
#include "end.h"
#include <QLabel>
#include <random>
#include <cmath>
#include <vector>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QVector>
#include <QProgressDialog>
#include <QProgressBar>
#include <QMessageBox>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QSoundEffect>
#include <QParallelAnimationGroup>
#include "ShopWidget.h"  // 引入 ShopWidget


/*Space between Window and Labels*/
#define upSpacer 80
#define leftSpacer 100
/*The Widget of game district*/
QGridLayout* mainWidget;
StoneLabel* waitLabel;
Game* Game::gameInstance = nullptr;
int Game::jewelNum=8;
/**
 * @brief generate random digit from 1 to 10
 * @return random digit
 */
int genRandom(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, difficulty);
    return dis(gen);
}
/**
 * @brief Update the window by vector<vector<StoneLabel*>> stones
 */
void Game::update(){
    for (int i = 0; i < Game::jewelNum; i++) {
        for (int j = 0; j < Game::jewelNum; j++) {
            StoneLabel* pic = stones.at(i).at(j);
            pic->resize(48,48);
            std::string pixStr=":/"+StoneLabel::stoneMode+std::to_string(pic->getIndex())+".png";
            pic->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(48,48));
            pic->setAlignment(Qt::AlignCenter);
            mainWidget->addWidget(pic, i, j);
        }
    }
}

Game::Game(QWidget *parent,Game::GameMode mode,Client* c)
    : QWidget(parent)
    , ui(new Ui::Game)
    , gameMode(mode)
    , client(c)
{
    // gameItems = new GameItems();  // 初始化 GameItems
    ui->setupUi(this);
    // 循环播放背景音乐
    sound = new QSoundEffect(this);
    sound->setSource(QUrl("qrc:/music/background/music-2.wav"));  // 使用 qrc 路径
    sound->setLoopCount(QSoundEffect::Infinite);
    sound->setVolume(1.0f);  // 最大音量
    sound->play();


    Game::jewelNum=8;
    this->parent=parent;
    this->score=0;
    //this->ui->lcdNumber->set
    connect(this, &Game::eliminateAgainSignal, this, &Game::onEliminateAgain);
    connect(this, &Game::initEndSignal, this, &Game::initEnd);
    gameTimer = new GameTimer(this);
    connect(this, &Game::startGameTimer, this, &Game::onStartGameTimer);
    connect(gameTimer, &GameTimer::timeUpdated, this, &Game::updateTimerDisplay);
    connect(gameTimer, &GameTimer::timeExpired, this, &Game::onTimeExpired);
    init();
    initing=true;
    progressDialog = new QProgressDialog("正在初始化中，请稍后...", "取消", 0, 0, this);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setValue(0);
    progressDialog->show();
    this->swapReturn=std::vector<int>(4,0);
    if (checkFormatches()) {
        eliminateMatches();
    }else{
        progressDialog->setValue(100);
        progressDialog->hide();
        emit startGameTimer();
    }

    //经典模式下相关显示与逻辑特殊处理
    ui->passScoreLabel->hide();
    ui->textBrowser->hide();
    ui->levelNumLabel->hide();


}


Game::Game(QWidget *parent,int levelNumber,Game::GameMode mode,Client* c)
    : QWidget(parent)
    , ui(new Ui::Game)
    , gameMode(mode)
    , levelNumber(levelNumber)
    , client(c)
{
    ui->setupUi(this);
    Game::jewelNum=8;
    this->parent=parent;
    this->score=0;
    //this->ui->lcdNumber->set
    connect(this, &Game::eliminateAgainSignal, this, &Game::onEliminateAgain);
    connect(this, &Game::initEndSignal, this, &Game::initEnd);
    gameTimer = new GameTimer(this);
    connect(this, &Game::startGameTimer, this, &Game::onStartGameTimer);
    connect(gameTimer, &GameTimer::timeUpdated, this, &Game::updateTimerDisplay);
    connect(gameTimer, &GameTimer::timeExpired, this, &Game::onTimeExpired);
    init();
    initing=true;
    progressDialog = new QProgressDialog("正在初始化中，请稍后...", "取消", 0, 0, this);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setValue(0);
    progressDialog->show();
    this->swapReturn=std::vector<int>(4,0);
    if (checkFormatches()) {
        eliminateMatches();
    }else{
        progressDialog->setValue(100);
        progressDialog->hide();
        emit startGameTimer();
    }

    //冒险模式下相关显示与逻辑特殊处理
    setWinScore(levelNumber);
    QString levelInfo=QString::fromStdString("关卡:"+std::to_string(levelNumber/8+1)+"-"+std::to_string((levelNumber-1)%8+1));
    ui->levelNumLabel->setText(levelInfo);

}

Game::~Game()
{
    delete ui;
    delete end;
}
Game* Game::instance(QWidget *parent, Game::GameMode mode, int levelNum,Client* c) {
    if (gameInstance == nullptr) {
        if (levelNum == -1) {
            gameInstance = new Game(parent, mode,c);
        }
        else {
            gameInstance = new Game(parent, levelNum, mode,c);
        }
    }
    return gameInstance;
}
/**
 * @brief init labels on the ui
 */
void Game::init(){
    /**
     * Test code*/
    QWidget* centralWidget = new QWidget(this);
    mainWidget = new QGridLayout();
    mainWidget->setSpacing(0);
    mainWidget->setContentsMargins(0, 0, 0, 0);
    centralWidget->setLayout(mainWidget);
    centralWidget->setGeometry(leftSpacer,upSpacer,384,384);
    centralWidget->setParent(this);


    // 更新炸弹道具数量标签
    ui->bombLabel->setText(QString("炸弹: %1").arg(ShopWidget::bombCount));

    // 更新横向消除道具数量标签
    ui->horizonLabel->setText(QString("横向消除: %1").arg(ShopWidget::horizonCount));

    // 更新竖向消除道具数量标签
    ui->verticalLabel->setText(QString("竖向消除: %1").arg(ShopWidget::verticalCount));


    updateHintCountDisplay();  // 显示初始提示次数
    for (int row = 0; row < Game::jewelNum; row++) {
        for (int col = 0; col < Game::jewelNum; col++) {
            StoneLabel* imgLabel = new StoneLabel(this);

            imgLabel->isFrozen = false;
            imgLabel->setrow(row);
            imgLabel->setcol(col);
            imgLabel->resize(48,48);
            imgLabel->setIndex(genRandom());
            std::string pixStr=":/"+StoneLabel::stoneMode+std::to_string(imgLabel->getIndex())+".png";
            imgLabel->setpix(pixStr);
            imgLabel->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(48,48));
            // 根据冰冻状态设置初始外观样式
            if (imgLabel->isFrozen) {
                imgLabel->setStyleSheetForFrozen();
            }
            stones[row][col]=imgLabel;
            mainWidget->addWidget(imgLabel, row, col); // 使用addWidget()来将QLabel添加到布局中
        }
    }
    change=false;
    waitLabel=nullptr;
    pause = nullptr;

    connect(ui->pauseButton, &QPushButton::clicked, this, &Game::on_pushButton_3_clicked);
}
/**
 * @brief Game::mousePressEvent
 * @param event
 */
bool Game::arePositionsAdjacent(int row1, int col1, int row2, int col2) {
    return std::abs(row1 - row2) + std::abs(col1 - col2) == 1;
}

void Game::mousePressEvent(QMouseEvent *event) {
    QPoint clickPoint = event->pos();
    int x = clickPoint.x(), y = clickPoint.y();
    if (x <= leftSpacer || y <= upSpacer || x >= leftSpacer + 8 * 48 || y >= upSpacer + 8 * 48)
        return;

    int col = (x - leftSpacer) / 48, row = (y - upSpacer) / 48;
    /*左上*/
    if(row>=1 && row<=4){
        if(col>=1 && col<=4){
            clickDistrict[0]++;
        }
    }
    /*右上*/
    if(row>=1 && row<=4){
        if(col>=4 && col<=8){
            clickDistrict[1]++;
        }
    }
    /*左下*/
    if(row>=4 && row<=8){
        if(col>=1 && col<=4){
            clickDistrict[2]++;
        }
    }
    /*右下*/
    if(row>=4 && row<=8){
        if(col>=4 && col<=8){
            clickDistrict[3]++;
        }
    }
    StoneLabel* curLabel = stones[row][col];
    if (curLabel->isFrozen) {  // 如果当前点击的棋子处于冰冻状态，直接返回，不做任何操作
        return;
    }
    if (isBombMode) {
        // 如果当前处于炸弹模式，触发炸弹效果
        triggerBomb(row, col);
        return;
    }
    if (!change) {
        //isComboing = true;
        waitLabel = curLabel;
        waitLabel->setStyle(1);
        change = true;
    } else {
        int row1 = waitLabel->getrow(), col1 = waitLabel->getcol();
        int row2 = curLabel->getrow(), col2 = curLabel->getcol();

        if (!arePositionsAdjacent(row1, col1, row2, col2)) {// 判断两次点击的位置是否相邻,若不则跟随移动
            // 如果不相邻，忽视第一次点击，将此次点击视为第一次点击
            waitLabel->setStyle();
            //isComboing = true;
            waitLabel = stones[row][col];
            waitLabel->setStyle(1);
            change = true;
            return;
        }

        // 创建动画
        QPropertyAnimation *animation1 = new QPropertyAnimation(stones[row1][col1], "pos");
        QPropertyAnimation *animation2 = new QPropertyAnimation(stones[row2][col2], "pos");

        // 设置动画时长和目标位置
        animation1->setDuration(300); // 动画持续时间300ms
        animation2->setDuration(300);

        // 计算目标位置
        QPoint targetPos1 = stones[row2][col2]->pos();
        QPoint targetPos2 = stones[row1][col1]->pos();

        animation1->setEndValue(targetPos1);
        animation2->setEndValue(targetPos2);

        // 启动动画
        animation1->start(QAbstractAnimation::DeleteWhenStopped);
        animation2->start(QAbstractAnimation::DeleteWhenStopped);

        // 动画结束后交换
        connect(animation1, &QPropertyAnimation::finished, [=]() {
            // 交换数据
            waitLabel->setStyle();
            std::swap(stones[row1][col1], stones[row2][col2]);
            stones[row1][col1]->setrow(row1);
            stones[row1][col1]->setcol(col1);
            stones[row2][col2]->setrow(row2);
            stones[row2][col2]->setcol(col2);

            update();

            if (!hasStartedScoring)  // 如果还未开始计分，在这里标记为开始计分
            {
                hasStartedScoring = true;
            }

            if (checkFormatches()) {
                // 标记被选中且发生消除的棋子
                stones[row1][col1]->setSelectedAndEliminated(true);
                stones[row2][col2]->setSelectedAndEliminated(true);
                eliminateMatches();
            } else {
                //Animation Shaked
                QPoint originalPos = stones[row2][col2]->pos();
                QPropertyAnimation *animationShake = new QPropertyAnimation(stones[row2][col2], "pos");
                animationShake->setDuration(300);
                QList<QPair<double, QVariant>> keyframes;

                keyframes.append(qMakePair(0.0, QVariant::fromValue(originalPos + QPoint(8, 0))));  // 向右移动
                keyframes.append(qMakePair(0.1, QVariant::fromValue(originalPos - QPoint(8, 0))));  // 向左移动
                keyframes.append(qMakePair(0.2, QVariant::fromValue(originalPos + QPoint(8, 0))));  // 向右移动
                keyframes.append(qMakePair(0.3, QVariant::fromValue(originalPos - QPoint(8, 0))));  // 向左移动
                keyframes.append(qMakePair(0.4, QVariant::fromValue(originalPos)));                  // 恢复原位置

                // 设置关键帧
                animationShake->setKeyValues(keyframes);
                animationShake->start(QAbstractAnimation::DeleteWhenStopped);
                //Animation Shaked2
                QPoint originalPos2 = stones[row1][col1]->pos();
                QPropertyAnimation *animationShake2 = new QPropertyAnimation(stones[row1][col1], "pos");
                animationShake2->setDuration(300);
                QList<QPair<double, QVariant>> keyframes2;

                keyframes2.append(qMakePair(0.0, QVariant::fromValue(originalPos2 + QPoint(8, 0))));  // 向右移动
                keyframes2.append(qMakePair(0.1, QVariant::fromValue(originalPos2 - QPoint(8, 0))));  // 向左移动
                keyframes2.append(qMakePair(0.2, QVariant::fromValue(originalPos2 + QPoint(8, 0))));  // 向右移动
                keyframes2.append(qMakePair(0.3, QVariant::fromValue(originalPos2 - QPoint(8, 0))));  // 向左移动
                keyframes2.append(qMakePair(0.4, QVariant::fromValue(originalPos2)));                  // 恢复原位置

                // 设置关键帧
                animationShake2->setKeyValues(keyframes2);
                animationShake2->start(QAbstractAnimation::DeleteWhenStopped);

                connect(animationShake, &QPropertyAnimation::finished, [=](){

                QPropertyAnimation *reverseAnim1 = new QPropertyAnimation(stones[row1][col1], "pos");
                QPropertyAnimation *reverseAnim2 = new QPropertyAnimation(stones[row2][col2], "pos");

                reverseAnim1->setDuration(200);
                reverseAnim2->setDuration(200);

                // 计算回退的目标位置
                reverseAnim1->setEndValue(targetPos1); // 原位置
                reverseAnim2->setEndValue(targetPos2); // 原位置

                reverseAnim1->start(QAbstractAnimation::DeleteWhenStopped);
                reverseAnim2->start(QAbstractAnimation::DeleteWhenStopped);

                // 动画完成后恢复交换
                connect(reverseAnim1, &QPropertyAnimation::finished, [=]() {
                    // 换回去
                    std::swap(stones[row1][col1], stones[row2][col2]);
                    stones[row1][col1]->setrow(row1);
                    stones[row1][col1]->setcol(col1);
                    stones[row2][col2]->setrow(row2);
                    stones[row2][col2]->setcol(col2);

                    update();
                });
                });
            }

            change = false;
        });
    }
    if(horizon){//横劈道具
        curLabel->setStyle(0);
        horizondelete(row);
        horizon=false;
        change=false;
    }
    if(vertical){//竖劈道具
        curLabel->setStyle(1);
        verticaldelete(col);
        vertical=false;
        change=false;
    }
}

//判断
bool Game::checkFormatches(){
    bool hasMatch = false;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 6; ++col) {  // 检查每行的前6列
            if (stones[row][col]->getIndex() == stones[row][col + 1]->getIndex() &&
                stones[row][col]->getIndex() == stones[row][col + 2]->getIndex()) {
                hasMatch = true;

                // 标记这些棋子为待消除
                stones[row][col]->setMatched(true);
                stones[row][col + 1]->setMatched(true);
                stones[row][col + 2]->setMatched(true);
            }
        }
    }

    // 纵向检查
    for (int col = 0; col < 8; ++col) {
        for (int row = 0; row < 6; ++row) {  // 检查每列的前6行
            if (stones[row][col]->getIndex() == stones[row + 1][col]->getIndex() &&
                stones[row][col]->getIndex() == stones[row + 2][col]->getIndex()) {
                hasMatch = true;

                // 标记这些棋子为待消除
                stones[row][col]->setMatched(true);
                stones[row + 1][col]->setMatched(true);
                stones[row + 2][col]->setMatched(true);
            }
        }
    }

    for (int col = 0; col < 8; ++col) {

        for (int row = 0; row < 8; ++row) {
            // 更新匹配数
            stones[row][col]->setColMatchNum(colCheckMatch(row, col));
            stones[row][col]->setRowMatchNum(rowCheckMatch(row, col));
            stones[row][col]->setMatchNum(checkMatch(stones[row][col]->rowMatchNum,stones[row][col]->colMatchNum));
            // 更新样式状态
            stones[row][col]->setOriginalStyleSheet(stones[row][col]->styleSheet());
        }
    }

    return hasMatch;
}

void Game::eliminateMatches() {
    int eliminatedCount = 0;  // 用于记录本次消除的棋子个数
    int iceKilledNum = 0;   // 用于记录本次消除的冰块个数

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (stones[row][col] != nullptr && stones[row][col]->isMatched() && !stones[row][col]->isFrozen) {//未冰冻的棋子，直接消除即可
                if(stones[row][col]->isSelectedAndEliminated && stones[row][col]->matchNum == 4){//鼠标点击了一次4消
                    if(stones[row][col]->colMatchNum == 4){//四个纵的合成横劈
                        stones[row][col]->setLineKiller(1);
                        stones[row][col]->setMatched(false);
                        stones[row][col]->setStyleSheetForRowKiller();
                    }else if(stones[row][col]->rowMatchNum == 4){//四个横的合成竖劈
                        stones[row][col]->setLineKiller(2);
                        stones[row][col]->setMatched(false);
                        stones[row][col]->setStyleSheetForColKiller();
                    }
                }
                else {//非鼠标直接消除 或 鼠标点击了普通三消 直接删除即可
                    if(stones[row][col]->lineKiller == 0){//如果是普通棋子
                        //删除棋子
                        delete stones[row][col];
                        stones[row][col] = nullptr;  // 清空位置
                    }
                    else if(stones[row][col]->lineKiller == 1){//如果是横劈
                        //使用掉lineKiller效果
                        stones[row][col]->lineKiller = 0;
                        stones[row][col]->setStyleSheetForNormal();
                        // 执行横劈逻辑，消除整行
                        for (int temp_col = 0; temp_col < 8; ++temp_col) {
                            if (stones[row][temp_col]!= nullptr) {
                                delete stones[row][temp_col];
                                stones[row][temp_col] = nullptr;
                                eliminatedCount++;  // 统计消除的棋子个数
                            }
                        }
                    }
                    else if(stones[row][col]->lineKiller == 2){//如果是竖劈
                        //使用掉lineKiller效果
                        stones[row][col]->lineKiller == 0;
                        stones[row][col]->setStyleSheetForNormal();
                        // 执行竖劈逻辑，消除整列
                        for (int temp_row = 0; temp_row < 8; ++temp_row) {
                            if (stones[temp_row][col]!= nullptr) {
                                delete stones[temp_row][col];
                                stones[temp_row][col] = nullptr;
                                eliminatedCount++;
                            }
                        }
                    }
                }

                eliminatedCount++;  // 统计消除的棋子个数
            }
            else if (stones[row][col] != nullptr && stones[row][col]->isMatched() && stones[row][col]->isFrozen) { // 如果是冰冻棋子，清除匹配标记并恢复正常外观
                stones[row][col]->setMatched(false);
                stones[row][col]->isFrozen = false;
                stones[row][col]->setStyleSheetForNormal();
                std::string pixStr = ":/" + StoneLabel::stoneMode + std::to_string(stones[row][col]->getIndex()) + ".png";
                stones[row][col]->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(48, 48));
                iceKilledNum++;
            }
        }
    }

    if (hasStartedScoring)  // 根据计分标记判断是否计分
    {
        // 根据消除的棋子个数计算得分，计分规则见calGainScore()
        score += calGainScore(eliminatedCount,iceKilledNum); // 将本次得分累加到总积分中
    }

    // 更新积分显示
    ui->lcdNumber->display(score);

    if (!progressDialog->isVisible()) {
        QSoundEffect* soundEffect;
        switch(eliminatedCount){
        case 3:{
            soundEffect = new QSoundEffect(this);
            soundEffect->setSource(QUrl::fromLocalFile(":/music/eliminate/triple.wav"));
            soundEffect->setLoopCount(1);  // 只播放一次
            soundEffect->setVolume(volume);
            break;
        }
        case 4:{
            soundEffect = new QSoundEffect(this);
            soundEffect->setSource(QUrl::fromLocalFile(":/music/eliminate/quadruple.wav"));
            soundEffect->setLoopCount(1);  // 只播放一次
            soundEffect->setVolume(volume);
            break;
        }
        default:{
            soundEffect = new QSoundEffect(this);
            soundEffect->setSource(QUrl::fromLocalFile(":/music/eliminate/penta.wav"));
            soundEffect->setLoopCount(1);  // 只播放一次
            soundEffect->setVolume(volume);
            break;
        }
        }
        soundEffect->play();//播放消除音效
    }
    dropStones();// 执行棋子下落逻辑，用于填补因消除产生的空位
    resetMatchedFlags();// 重置所有棋子的匹配标记，为下一轮检测做准备
}
//生成新子
//生成一个新子
void Game::generateNewStone(int row, int col){
    // 初始化
    StoneLabel* imgLabel = new StoneLabel(this);
    imgLabel->setrow(row);
    imgLabel->setcol(col);
    imgLabel->resize(48, 48);
    imgLabel->setIndex(genRandom());
    std::string pixStr = ":/" + StoneLabel::stoneMode + std::to_string(imgLabel->getIndex()) + ".png";
    imgLabel->setPixmap(QPixmap(QString::fromStdString(pixStr)).scaled(48, 48));
    imgLabel->setpix(pixStr);

    // 显示添加
   // mainWidget->addWidget(imgLabel, row, col);

    if (genRandom() < 3) {
        imgLabel->isFrozen = true;
        imgLabel->setStyleSheetForFrozen();  // 设置为白色填充样式，代表冰冻状态
    } else {
        imgLabel->isFrozen = false;
    }

    // 逻辑添加
    stones[row][col] = imgLabel;
}

void Game::onEliminateAgain(){
    {
        if(checkFormatches()){
            isComboing = true;
            eliminateMatches();
        }else{
            isComboing = false;
            int row1=swapReturn[0],col1=swapReturn[1],row2=swapReturn[2],col2=swapReturn[3];
            std::cout<<"row1:"<<row1<<",row2:"<<row2<<",col1:"<<col1<<",col2:"<<col2<<std::endl;
            std::swap(stones[row1][col1], stones[row2][col2]);
            stones[row1][col1]->setrow(row1);
            stones[row1][col1]->setcol(col1);
            stones[row2][col2]->setrow(row2);
            stones[row2][col2]->setcol(col2);
            if(gameMode == GameMode::ADVENTURE_MODE){//冒险模式
                if (checkAdventureWin() && !isComboing) {//胜利
                    // 显示结束界面并提示闯关成功
                    end = new End(this,client);
                    connect(end, &End::nextButtonClicked, this, &Game::onNextButtonClicked);
                    end->showAdventureWinUI();

                    // 停止游戏相关的定时器等操作
                    resetGameState();
                    return;
                }
            }
            emit initEndSignal();
        }
    }
}

void Game::initEnd(){
    std::cout<<"initEnd"<<std::endl;
    this->progressDialog->setValue(100);
    this->progressDialog->hide();
    emit startGameTimer();
}

//遍历空白位置，生成全部新子
void Game::creatstones(){
    int sum=0;
    int tmpRow=-1;
    for(int row=7;row>=0;--row){// 行从下到上
        for(int col=7;col>=0;--col){//列从下到上

            if(stones[row][col]==nullptr && tmpRow!=row){
                sum++;
                tmpRow=row;
            }
        }
    }
    for(int row=7;row>=0;--row){// 行从下到上
        for(int col=7;col>=0;--col){//列从下到上
            if(stones[row][col]==nullptr){
                generateNewStone(row,col);
                int time=sum*200;
                dropLabel(stones[row][col],col*48,(row-sum)*48,col*48,row*48,time);
            }
        }
    }
    update();
    emit eliminateAgainSignal();
}

//棋子下落动画
//duration should set to x/v
void Game::dropLabel(StoneLabel* stoneLabel, int startX,int startY,int targetX, int targetY, int duration) {
    this->initing=true;
    duration=1000*(targetY-startY)/192;
    QPropertyAnimation* animation = new QPropertyAnimation(stoneLabel, "pos");
    animation->setStartValue(QPoint(startX,startY));// 起始位置NO
    animation->setEndValue(QPoint(targetX, targetY)); // 目标位置
    animation->setDuration(duration); // 持续时间
    // 连接动画完成的信号
    connect(animation, &QPropertyAnimation::finished, this, &Game::onDropAnimationFinished);
    // 启动动画
    animation->start(QAbstractAnimation::DeleteWhenStopped);  // 动画完成后自动删除
}
//下落并生成新子
void Game::dropStones() {
    animationsLeft = 0;  // 重置动画计数器
    bool drop=false;

    // 让上面的棋子填补下方空位
    for (int col = 0; col < 8; ++col) {
        // 从底部开始检查每一列
        for (int row = 7; row >= 0; --row) {
            if (stones[row][col] == nullptr) {  // 如果当前这个位置为空
                // 查找上面第一个非空的位置
                int emptyRow = row;//空位置
                for (int checkRow = row - 1; checkRow >= 0; --checkRow) {
                    if (stones[checkRow][col] != nullptr) {
                        // 这个位置有棋子，交换
                        // 计算目标位置的坐标
                        int targetX = col * 48;
                        int targetY = emptyRow * 48;
                        stones[checkRow][col]->targetX=targetX;
                        stones[checkRow][col]->targetY=targetY;
                        dropLabel(stones[checkRow][col],col*48,checkRow*48,targetX,targetY,1000);//下落动画
                        drop=true;

                        stones[emptyRow][col] = stones[checkRow][col];//逻辑交换
                        stones[emptyRow][col]->setrow(emptyRow);
                        stones[emptyRow][col]->setcol(col);
                        stones[checkRow][col] = nullptr;  // 清空原位置

                        // 更新动画计数器
                        animationsLeft++;
                        break;
                    }
                }
            }
        }
    }
   // 若无子下落，遍历前三行，找到空位生成新子
    if(!drop){
        creatstones();
    }

    resetMatchedFlags();
}

void Game::resetMatchedFlags(){
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (stones[row][col] != nullptr) {
                stones[row][col]->setMatched(false);
                stones[row][col]->isSelectedAndEliminated = false;  // 重置标记
            }
        }
    }
}

// 设置游戏模式的函数实现
void Game::setGameMode(GameMode mode)
{
    gameMode = mode;
}

void Game::onStartGameTimer(){
    gameTimer->startCountdown(initTime);
    ui->progressBar->setRange(0, gameTimer->getRemainingSeconds());  // 设置进度条范围与倒计时初始时间一致
    ui->progressBar->setValue(gameTimer->getRemainingSeconds());  // 设置初始值为总时间
    ui->progressBar->setTextVisible(false);
    ui->timerLabel->setText("--");

    disconnect(this, &Game::startGameTimer, this, &Game::onStartGameTimer);
}

int Game::calGainScore(int eliminatedCount,int iceKilledNum){
    // k是对数调节系数，offset是偏移量，用于保证积分值在合理范围且为正整数等
    // 例如设置k = 20，offset = 5
    int k = 10;
    int offset = 8;
    // n为破冰数线性系数
    int n = 15;
    int scoreGain = static_cast<int>(std::log(eliminatedCount + 1) * k + offset + iceKilledNum * n);
    return scoreGain;
}

void Game::onTimeExpired()
{
    // 在这里可以添加游戏结束相关的逻辑，比如提示游戏结束、禁用操作等
    ui->timerLabel->setText(QString::number(0) + "s");
    ui->progressBar->setValue(0);  // 更新进度条当前值
    isTimeExpired = true;

    if(gameMode == Game::GameMode::ADVENTURE_MODE){
        if (isTimeExpired && !isComboing && !checkAdventureWin()){
            // 显示结束界面并提示闯关失败
            end = new End(this,client);
            connect(end, &End::nextButtonClicked, this, &Game::onNextButtonClicked);
            connect(end, &End::retryGame, this, &Game::onRetryGame);
            end->showAdventureLoseUI();
            // 停止游戏相关的定时器等操作
            resetGameState();
            emit adventureLostBackToMain();// 发射信号通知 MainWindow 进行 levelNum 自减一操作
        }
    }else{
        end = new End(this,client);
        connect(end, &End::nextButtonClicked, this, &Game::onNextButtonClicked);
        end->showEndUI();
        // 停止游戏相关的定时器等操作
        resetGameState();
    }
}

void Game::updateTimerDisplay()
{
    int remainingSeconds = gameTimer->getRemainingSeconds();
    ui->timerLabel->setText(QString::number(remainingSeconds+1) + "s");
    ui->progressBar->setValue(remainingSeconds+1);  // 更新进度条当前值
}

//暂停
void Game::on_pushButton_3_clicked()
{
    if (!pause) {
        pause = new Pause(this);
        connect(pause, &Pause::resumeGame, this, &Game::resume);
        connect(pause, &Pause::returnToMainMenu, this, &Game::on_returnFromPauseToMainMenu);
        connect(pause, &Pause::renewGame, this, &Game::onRetryGame);
        if(gameMode == Game::GameMode::ADVENTURE_MODE){
            QString levelInfo=QString::fromStdString("关卡:"+std::to_string(levelNumber/8+1)+"-"+std::to_string((levelNumber-1)%8+1));
            pause->ui->levelInfo->setText(levelInfo);
        }else{
            pause->ui->levelInfo->hide();
        }
    }
    pause->show();

    // 暂停游戏逻辑，停止计时器并设置暂停状态为true
    gameTimer->stop();
    isPaused = true;
}

void Game::resume()
{
    if (isPaused) {
        gameTimer->start();  // 恢复计时器运行
        isPaused = false;
    }
}

void Game::resetGameState()
{
    if (gameTimer) {
        gameTimer->stop();
        delete gameTimer;
        gameTimer = nullptr;
    }
    score = 0;
    if (end) {
        end = nullptr;
    }
    if (pause) {
        pause = nullptr;
    }
    // 这里可以进一步添加对其他游戏相关变量的重置逻辑，比如：
    // 重置棋子相关状态等，可根据实际需求完善
}

void Game::on_returnFromPauseToMainMenu()
{
    resetGameState();
    emit adventureLostBackToMain();
    //sound->stop();
    emit returnMainwindow();
}

//重新排布按键
void Game::on_pushButton_5_clicked()
{
    shuffleStones();
}
//重新排布逻辑方法
void Game::shuffleStones() {
    // 创建一个随机顺序的数组
    std::vector<StoneLabel*> shuffledStones;
    for (int row = 0; row < Game::jewelNum; row++) {
        for (int col = 0; col < Game::jewelNum; col++) {
            shuffledStones.push_back(stones[row][col]);
        }
    }

    // 打乱数组中的元素
    std::random_shuffle(shuffledStones.begin(), shuffledStones.end());

    // 目标位置：屏幕中心
    int targetRow = Game::jewelNum / 2;
    int targetCol = Game::jewelNum / 2;

    // 创建一个动画组来管理所有动画（并行动画组）
    QParallelAnimationGroup* parallelGroup = new QParallelAnimationGroup(this);

    // 将所有棋子同时聚集到目标位置
    for (StoneLabel* stone : shuffledStones) {
        int targetX = targetCol * stone->width();  // 目标位置的X坐标
        int targetY = targetRow * stone->height(); // 目标位置的Y坐标

        // 创建动画：让每个棋子同时移动到目标位置
        QPropertyAnimation* animation = new QPropertyAnimation(stone, "pos");
        animation->setDuration(500);  // 动画时长
        animation->setStartValue(stone->pos());  // 起始位置
        animation->setEndValue(QPoint(targetX, targetY));  // 目标位置

        // 将每个动画添加到并行动画组中
        parallelGroup->addAnimation(animation);
    }

    // 启动所有棋子的聚集动画
    parallelGroup->start();

    // 当聚集动画完成后，逐个移动每个棋子到其最终位置
    connect(parallelGroup, &QParallelAnimationGroup::finished, this, [this, shuffledStones]() {
        QSequentialAnimationGroup* finalAnimationGroup = new QSequentialAnimationGroup(this);

        int index = 0;
        for (int row = 0; row < Game::jewelNum; row++) {
            for (int col = 0; col < Game::jewelNum; col++) {
                StoneLabel* stone = shuffledStones[index];
                stones[row][col]=shuffledStones[index];
                stones[row][col]->setrow(row);
                stones[row][col]->setcol(col);
                stones[row][col]->resize(48,48);
                stones[row][col]->setIndex(shuffledStones[index]->getIndex());
                //stones[row][col]->setPixmap(QPixmap(QString::fromStdString(shuffledStones[index]->getpix())).scaled(48,48));
                // 创建新的目标位置
                int targetX = col * stone->width();
                int targetY = row * stone->height();

                // 创建新的动画
                QPropertyAnimation* finalAnimation = new QPropertyAnimation(stone, "pos");
                finalAnimation->setDuration(80);  // 新位置动画时长
                finalAnimation->setStartValue(stone->pos());  // 起始位置（聚集位置）
                finalAnimation->setEndValue(QPoint(targetX, targetY));  // 目标位置（新的随机位置）

                // 将每个动画按顺序添加到最终动画组
                finalAnimationGroup->addAnimation(finalAnimation);

                index++;
                 //mainWidget->addWidget(stones[row][col],row,col);
            }
        }

        // 启动第二阶段动画（棋子从聚集点逐个移动到新位置）
        finalAnimationGroup->start();
        connect(finalAnimationGroup, &QSequentialAnimationGroup::finished, this, [this]() {
            update();
        });
    });
}

void Game::onNextButtonClicked()
{
    difficulty+=1;
    if(difficulty>10){
        QMessageBox::information(this, "游戏结束", "恭喜你通过了全部关卡！");
        emit returnMainwindow();
        return;
    }
    emit directToNextLevel();
}

void Game::onRetryGame(){
    close();
    resetGameState();
    if(gameMode == Game::GameMode::ADVENTURE_MODE){
        emit retryAdventure();
    }else{
        emit retryClassic();
    }
}

int Game::getScore(){
    return score;
}

void Game::setWinScore(int levelNum){
    winScore = 200+(levelNum-1)*50;
    ui->textBrowser->setText(QString::number(winScore));
}

void Game::on_bombButton_clicked() {


    if(ShopWidget::bombCount > 0){
        ShopWidget::bombCount--;  // 减少炸弹数量
        // 激活炸弹模式
        isBombMode = true;
        this->updateItemCountLabels();
    }
    else{
        QMessageBox::information(nullptr, "没有炸弹", "您没有炸弹道具了！");
    }

}

bool Game::checkAdventureWin() const
{
    if (score >= winScore) {
        return true;
    }
    return false;
}
void Game::triggerBomb(int row, int col) {
    if (!isBombMode) {
        return;  // 如果不处于炸弹模式，则不处理
    }

    // 触发炸弹效果，消除选中位置周围3x3区域的宝石
    for (int r = row - 1; r <= row + 1; ++r) {
        for (int c = col - 1; c <= col + 1; ++c) {
            if (r >= 0 && r < Game::jewelNum && c >= 0 && c < Game::jewelNum) {
                // 如果位置有效，消除该宝石
                StoneLabel* targetStone = stones[r][c];
                if (targetStone != nullptr) {
                    targetStone->setMatched(true);  // 标记为待消除
                    score+=4;
                }
            }
        }
    }

    eliminateMatches();  // 执行消除操作

    // 结束炸弹模式
    isBombMode = false;
    // statusBar()->clearMessage();  // 清除提示信息
}
//横向删除按钮
void Game::on_horizon_clicked()
{
    if(ShopWidget::horizonCount > 0){
        ShopWidget::horizonCount--;  // 减少炸弹数量
        horizon=true;
        this->updateItemCountLabels();
    }
    else{
        QMessageBox::information(nullptr, "没有horizon", "您没有horizon道具了！");
    }

}
void Game::horizondelete(int row){
    for (int col = 0; col < 8; ++col) {
            if (stones[row][col] != nullptr ) {
            score+=4;
            stones[row][col]->setMatched(true);
            }
        }
    eliminateMatches();


    qDebug()<<"horizon"<<row;
}

//竖向消除
void Game::on_vertical_clicked()
{
    if(ShopWidget::verticalCount > 0){
        ShopWidget::verticalCount--;  // 减少炸弹数量
        vertical=true;
        this->updateItemCountLabels();
    }
    else{
         QMessageBox::information(nullptr, "没有vertical", "您没有vertical道具了！");
    }

}

void Game::onAnimationFinished(){
    dropStones();

}
void Game::verticaldelete(int col){
    for(int row=0;row<8;++row){
        if(stones[row][col]!=nullptr){
            score+=4;
            stones[row][col]->setMatched(true);
        }
    }
    eliminateMatches();
}

QList<QPair<int, int>> Game::findHint() {
    QList<QPair<int, int>> hints;

    // 遍历所有棋盘位置
    for (int row = 0; row < Game::jewelNum; ++row) {
        for (int col = 0; col < Game::jewelNum; ++col) {
            if (canMatch(row, col)) {
                hints.append(qMakePair(row, col));
                return hints;  // 只返回第一个可以匹配的宝石
            }
        }
    }

    if (hints.isEmpty()) {
        qDebug() << "没有找到匹配的宝石!";
    }

    return hints;
}

// 检查给定位置的宝石是否可以与相邻宝石交换形成匹配
bool Game::canMatch(int row, int col) {
    // 上下左右相邻的方向
    const QVector<QPair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 遍历四个方向，检查交换后的匹配情况
    for (const auto& dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        if (newRow >= 0 && newRow < Game::jewelNum && newCol >= 0 && newCol < Game::jewelNum) {
            // 交换位置，检查是否形成匹配
            if (canSwapAndMatch(row, col, newRow, newCol)) {
                return true;
            }
        }
    }
    return false;
}

// 检查交换后是否能形成匹配
bool Game::canSwapAndMatch(int row1, int col1, int row2, int col2) {
    // 交换两宝石
    StoneLabel* temp = stones[row1][col1];
    stones[row1][col1] = stones[row2][col2];
    stones[row2][col2] = temp;

    // 检查是否形成匹配
    bool isMatch = checkMatch(rowCheckMatch(row1, col1),colCheckMatch(row1, col1)) >= 3 || checkMatch(rowCheckMatch(row2, col2),colCheckMatch(row2, col2)) >= 3;

    // 交换回原位置
    stones[row2][col2] = stones[row1][col1];
    stones[row1][col1] = temp;

    return isMatch;
}


void Game::highlightHints(const QList<QPair<int, int>>& hints) {
    if (hints.isEmpty()) {
        return;
    }

    // 获取第一个提示的宝石位置
    int row = hints.first().first;
    int col = hints.first().second;

    StoneLabel* label = stones[row][col];  // 获取当前宝石的标签

    // 检查是否已经有效果，避免重复添加
    if (label->graphicsEffect() == nullptr) {
        // 设置高亮效果
        label->setStyleSheet("background-color: red; border: 3px solid yellow;");

        // 设置定时器，在指定时间后移除高亮效果
        QTimer::singleShot(1500, [label]() {
            label->setStyleSheet("");  // 清除背景和边框
        });

        // 显示箭头图标
        QLabel* hintArrowLabel = new QLabel(this);
        hintArrowLabel->setPixmap(QPixmap(":/arrow.png"));  // 设置箭头图片
        hintArrowLabel->setFixedSize(40, 40);  // 设置箭头图片的大小

        // 获取宝石标签的位置
        QRect labelRect = label->geometry();

        // 箭头的水平位置为宝石标签的水平居中
        int arrowX = labelRect.left() + (labelRect.width() - hintArrowLabel->width()) / 2 + 112;

        // 箭头的垂直位置为宝石标签底部
        int arrowY = labelRect.bottom() + 80;  // 箭头位于宝石下方

        hintArrowLabel->move(arrowX, arrowY);  // 设置箭头位置
        hintArrowLabel->show();

        // 创建上下震动的动画
        QPropertyAnimation* anim = new QPropertyAnimation(hintArrowLabel, "geometry");
        anim->setDuration(600);  // 增加动画时长，使得上下运动更加平滑
        anim->setStartValue(QRect(arrowX, arrowY, hintArrowLabel->width(), hintArrowLabel->height()));  // 起始位置
        anim->setEndValue(QRect(arrowX, arrowY + 10, hintArrowLabel->width(), hintArrowLabel->height()));  // 向下移动10px
        anim->setEasingCurve(QEasingCurve::InOutQuad);  // 使用平滑的缓动曲线
        anim->setLoopCount(-1);  // 无限循环动画，使箭头持续上下震动
        anim->start();



        // 动画结束后删除箭头图标
        QTimer::singleShot(1500, hintArrowLabel, [hintArrowLabel]() {
            hintArrowLabel->deleteLater();  // 删除箭头图标
        });
    }
}

//最大匹配数
int Game::checkMatch(int countRow, int countCol) {
    return countRow>countCol ? countRow : countCol;
}

// 检查某个位置的宝石是否和相邻的宝石匹配
int Game::rowCheckMatch(int row, int col) {
    // 检查横向是否匹配
    int countRow = 1;  // 当前宝石本身算一个
    // 向右检查
    for (int i = col + 1; i < Game::jewelNum && stones[row][i]->getIndex() == stones[row][col]->getIndex(); ++i) {
        ++countRow;
    }
    // 向左检查
    for (int i = col - 1; i >= 0 && stones[row][i]->getIndex() == stones[row][col]->getIndex(); --i) {
        ++countRow;
    }
    stones[row][col]->setRowMatchNum(countRow);
    return countRow;
}

int Game::colCheckMatch(int row, int col) {
    // 检查纵向是否匹配
    int countCol = 1;
    // 向下检查
    for (int i = row + 1; i < Game::jewelNum && stones[i][col]->getIndex() == stones[row][col]->getIndex(); ++i) {
        ++countCol;
    }
    // 向上检查
    for (int i = row - 1; i >= 0 && stones[i][col]->getIndex() == stones[row][col]->getIndex(); --i) {
        ++countCol;
    }
    stones[row][col]->setColMatchNum(countCol);
    return countCol;
}


void Game::on_Tips_clicked()
{
    if (hintCount > 0) {
        QList<QPair<int, int>> hints = findHint();  // 查找可以匹配的宝石
        if (!hints.isEmpty()) {
            highlightHints(hints);  // 高亮显示提示的宝石
            --hintCount;  // 减少提示次数
            updateHintCountDisplay();  // 更新提示次数显示
        } else {
            QMessageBox::information(this, "没有更多匹配", "当前没有可以匹配的宝石!");
        }
    } else {
        QMessageBox::warning(this, "提示已用尽", "您已用尽所有提示!");
    }
}

void Game::updateHintCountDisplay() {
    ui->hintRemain->setText(QString("剩余提示次数: %1").arg(hintCount));
    ui->hintRemain->setStyleSheet("color: black; font-size: 9px;");  // 可选：设置文本样式
}



void Game::on_Shop_clicked()
{
    gameTimer->stop();
    isPaused = true;
    // 创建 ShopWidget 窗口实例
    ShopWidget *shopWindow = new ShopWidget;
    // 显示 ShopWidget 窗口
    shopWindow->show();    // this 表示父窗口是当前游戏窗口
    // 更新UI显示炸弹数量
    ui->bombLabel->setText(QString("炸弹: %1").arg(ShopWidget::bombCount));

    ui->horizonLabel->setText(QString("横向消除: %1").arg(ShopWidget::horizonCount));


}

void Game::setScore(int newScore) {
    score = newScore;
    // 更新积分显示
    ui->lcdNumber->display(score);
}

// 获取炸弹数量
int Game::getBombCount() const {
    return ShopWidget::bombCount;  // 直接访问 ShopWidget 中的静态变量
}

// 获取横向消除数量
int Game::getHorizonCount() const {
    return ShopWidget::horizonCount;  // 直接访问 ShopWidget 中的静态变量
}

// 获取竖向消除数量
int Game::getVerticalCount() const {
    return ShopWidget::verticalCount;  // 直接访问 ShopWidget 中的静态变量
}

// Game.cpp
void Game::updateItemCountLabels() {
    // 更新炸弹道具数量标签
    ui->bombLabel->setText(QString("炸弹: %1").arg(ShopWidget::bombCount));

    // 更新横向消除道具数量标签
    ui->horizonLabel->setText(QString("横向消除: %1").arg(ShopWidget::horizonCount));

    // 更新竖向消除道具数量标签
    ui->verticalLabel->setText(QString("竖向消除: %1").arg(ShopWidget::verticalCount));
}
