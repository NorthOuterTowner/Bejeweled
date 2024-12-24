#include "mainwindow.h"
#include "rankdialog.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "hoverbutton.h"  // 引入 HoverButton 类
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSoundEffect>
#include <QCoreApplication>
#include <QDebug>
#include <QCursor>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "rankdialog.h"
#include "ui_rankdialog.h"
#include<settingwidget.h>
#include"shopwidget.h"
#include<QMessageBox.h>
#include "about.h"
#include "help.h"
#include "heatmap.h"


MainWindow::MainWindow(Client* c,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    client=c;
    // 初始化其他成员
    ui->setupUi(this);
    StoneLabel::stoneMode = "gemstone";
    // 设置背景并启动动画
    QPropertyAnimation *backgroundAnimation = ShowBackground();
    backgroundAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    // 启动标题动画
    QPropertyAnimation *titleAnimation = ShowTitle();
    titleAnimation->start(QAbstractAnimation::DeleteWhenStopped);  // 启动标题动画
    // 循环播放背景音乐
    sound = new QSoundEffect(this);
    sound->setSource(QUrl("qrc:/music/background/music-1.wav"));  // 使用 qrc 路径
    sound->setLoopCount(QSoundEffect::Infinite);
    sound->setVolume(1.0f);  // 最大音量
    sound->play();

    // 设置鼠标-普通
    setCursor(QCursor(QPixmap(":/mouse1.png")));

    HoverButton *AboutButton = new HoverButton(this);
    AboutButton->setImage(":/icons/start_normal.png", ":/icons/start_hover.png", 100, 25);
    AboutButton->setLabel("关于", 10);
    AboutButton->adjustSize();  // 自动调整按钮大小
    AboutButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    AboutButton->move(ui->About->pos());  // 将新按钮放置在原按钮的位置
    connect(AboutButton, &QPushButton::clicked, this, []{
        About* dlg=new About();
        dlg->show();
    });

    // 隐藏原始的 QPushButton
    ui->About->hide();

    HoverButton *HelpButton = new HoverButton(this);
    HelpButton->setImage(":/icons/start_normal.png", ":/icons/start_hover.png", 100, 25);
    HelpButton->setLabel("帮助", 10);
    HelpButton->adjustSize();  // 自动调整按钮大小
    HelpButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    HelpButton->move(ui->Help->pos());  // 将新按钮放置在原按钮的位置
    connect(HelpButton, &QPushButton::clicked, this, []{
        Help* dlg=new Help();
        dlg->show();
    });

    // 隐藏原始的 QPushButton
    ui->About->hide();

    HoverButton *HeatButton = new HoverButton(this);
    HeatButton->setImage(":/icons/start_normal.png", ":/icons/start_hover.png", 100, 25);
    HeatButton->setLabel("热力图", 10);
    HeatButton->adjustSize();  // 自动调整按钮大小
    HeatButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    HeatButton->move(ui->Heat->pos());  // 将新按钮放置在原按钮的位置
    connect(HeatButton, &QPushButton::clicked, this, []{
        HeatMap heatmapDialog;
        //std::vector<int> clickDistrict = {10, 20, 15, 5};
        heatmapDialog.setClickData(clickDistrict);
        heatmapDialog.exec();
    });

    // 隐藏原始的 QPushButton
    ui->About->hide();

    // 使用 HoverButton 替换原有按钮
    HoverButton *startButton = new HoverButton(this);
    startButton->setImage(":/icons/start_normal.png", ":/icons/start_hover.png", 100, 25);
    startButton->setLabel("开始游戏", 13);
    startButton->adjustSize();  // 自动调整按钮大小
    startButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    startButton->move(ui->pushButton->pos());  // 将新按钮放置在原按钮的位置
    connect(startButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

    // 隐藏原始的 QPushButton
    ui->pushButton->hide();

    HoverButton *settingButton = new HoverButton(this);
    settingButton->setImage(":/icons/settings_normal.png", ":/icons/settings_hover.png", 100, 50);
    settingButton->setLabel("设置", 13);
    settingButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    settingButton->move(ui->pushButton_10->pos());  // 设置位置与原按钮相同
    connect(settingButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    ui->pushButton_10->hide();  // 隐藏原按钮

    //排行榜按钮
    HoverButton *rankButton=new HoverButton(this);
    rankButton->setImage(":/icons/rank_normal.png", ":/icons/rank_hover.png", 100, 50);
    rankButton->setLabel("排行榜",13);
    rankButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    rankButton->move(ui->ranking->pos());
    connect(rankButton, &QPushButton::clicked, this, &MainWindow::on_ranking_clicked);
       ui->ranking->hide();

   /* // 创建其他 HoverButton 按钮
    HoverButton *easyButton = new HoverButton(this);
    easyButton->setImage(":/icons/easy_normal.png", ":/icons/easy_hover.png", 100, 45);
    easyButton->setLabel("Easy", 13);

    easyButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    easyButton->move(ui->pushButton_2->pos());  // 设置位置与原按钮相同
    connect(easyButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    ui->pushButton_2->hide();  // 隐藏原按钮

    HoverButton *mediumButton = new HoverButton(this);
    mediumButton->setImage(":/icons/medium_normal.png", ":/icons/medium_hover.png", 150, 50);
    mediumButton->setLabel("Medium", 13);
    mediumButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    mediumButton->move(ui->pushButton_3->pos());
    connect(mediumButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    ui->pushButton_3->hide();

    HoverButton *hardButton = new HoverButton(this);
    hardButton->setImage(":/icons/hard_normal.png", ":/icons/hard_hover.png", 150, 50);
    hardButton->setLabel("Hard", 13);
    hardButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    hardButton->move(ui->pushButton_4->pos());
    connect(hardButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
    ui->pushButton_4->hide();

    HoverButton *jewelButton = new HoverButton(this);
    jewelButton->setImage(":/icons/hard_normal.png", ":/icons/hard_hover.png", 150, 50);
    jewelButton->setLabel("jewel", 13);
    jewelButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    jewelButton->move(ui->pushButton_5->pos());
    connect(jewelButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_5_clicked);
    ui->pushButton_5->hide();

    HoverButton *fruitButton = new HoverButton(this);
    fruitButton->setImage(":/icons/fruit_normal.png", ":/icons/fruit_hover.png", 150, 50);
    fruitButton->setLabel("Fruit Mode", 13);
    fruitButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    fruitButton->move(ui->pushButton_7->pos());
    connect(fruitButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);
    ui->pushButton_7->hide();

    HoverButton *vegetableButton = new HoverButton(this);
    vegetableButton->setImage(":/icons/vegetable_normal.png", ":/icons/vegetable_hover.png", 150, 50);
    vegetableButton->setLabel("Vegetable Mode", 13);
    vegetableButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    vegetableButton->move(ui->pushButton_6->pos());
    connect(vegetableButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
    ui->pushButton_6->hide();

    HoverButton *veryHardButton = new HoverButton(this);
    veryHardButton->setImage(":/icons/veryhard_normal.png", ":/icons/veryhard_hover.png", 150, 50);
    veryHardButton->setLabel("Very Hard", 13);
    veryHardButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    veryHardButton->move(ui->pushButton_8->pos());
    connect(veryHardButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);
    ui->pushButton_8->hide();*/

    // 在构造函数中添加以下代码，类似其他按钮的创建方式
    nextLevelButton = new HoverButton(this);
    nextLevelButton->setImage(":/icons/next_normal.png", ":/icons/next_hover.png", 150, 50);
    QString nextLevel=QString::fromStdString("下一关:"+std::to_string(levelNum/8+1)+"-"+std::to_string(levelNum%8+1));
    nextLevelButton->setLabel(nextLevel, 13);
    nextLevelButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    nextLevelButton->move(ui->pushButton_9->pos());
    connect(nextLevelButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_9_clicked);
    ui->pushButton_9->hide(); // 隐藏原始按钮

    //连接接受信息与登录页面
    if(client){
        connect(client->tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::onDataReceived);
    }
}

void setBkImg(const char * str, QLabel * label);

QPropertyAnimation* MainWindow::ShowBackground() {
    QLabel *background = new QLabel(this);
    QPropertyAnimation *bkAnim = new QPropertyAnimation(background, "geometry", this);

    // 设置背景图片backdrop00.jpg
    setBkImg(":/StartPage/background.png", background);
    background->show();

    // 设置动画属性
    bkAnim->setDuration(2000);  // 动画持续时间
    bkAnim->setStartValue(QRect(background->x(), background->y(), background->width(), background->height()));
    bkAnim->setEndValue(QRect(background->x(), this->height() - background->height(), background->width(), background->height()));
    bkAnim->setEasingCurve(QEasingCurve::InOutCubic);  // 设置缓动效果

    return bkAnim;
}
QPropertyAnimation * MainWindow ::ShowTitle(){
    QPixmap pix;
    QLabel *title = new QLabel(this); // 创建一个 QLabel 来显示标题
    title->setGeometry(this->width()/2-500/2,-title->height(),500,100); // 设置标题的初始位置，使其位于屏幕外
    setAdaptedImg(":/title.png", title); // 设置标题图像作为 QLabel 的内容
    title->show(); // 显示标题标签

    // 创建标题的动画
    QPropertyAnimation *animation = new QPropertyAnimation(title, "geometry",this);
    animation->setDuration(2000); // 动画持续时间为 2000 毫秒 (2秒)
    animation->setStartValue(QRect(title->x(), title->y(), title->width(), title->height())); // 设置动画起始位置
    animation->setEndValue(QRect(title->x(), 100, title->width(), title->height())); // 设置动画结束位置，将标题移至 y = 100 处
    animation->setEasingCurve(QEasingCurve::OutExpo); // 使用 OutExpo 缓动效果（平滑动画）
    return animation; // 返回动画对象    // 新增枚举类型表示游戏模式
    enum class GameMode {
        CLASSIC_MODE,  // 经典模式
        ADVENTURE_MODE  // 冒险模式
    };
}
//将path的图片放置到label上，自适应label大小
void MainWindow ::setAdaptedImg(QString path,QLabel *label)
{
    QImage image(path);
    QSize size=label->size();
    QImage image2=image.scaled(size,Qt::IgnoreAspectRatio);//重新调整图像大小以适应label
    label->setPixmap(QPixmap::fromImage(image2));//显示
}


void MainWindow::setBkImg(QString path, QLabel *label) {
    QImage image = QImage(path);
    if(image.isNull()) {
        qDebug() << "背景图片未找到。";
    }

    double ratio = (double)image.height() / (double)image.width();
    QImage resizedImage = image.scaled(this->width(), ratio * this->width(), Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(resizedImage));
    label->setGeometry(0, 0, this->width(), ratio * this->width());  // 调整标签的几何位置
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(gameDlg){
        Game::delInstance();
    }

    sound->stop();  // 暂停背景音乐
    gameDlg = Game::instance(nullptr, Game::GameMode::CLASSIC_MODE,-1,client); // 创建游戏，设置游戏模式为经典模式
    connect(gameDlg, &Game::returnMainwindow, this, &MainWindow::onReturnMainwindow);
    connect(gameDlg, &Game::retryClassic, this, &MainWindow::onRetryClassic);
    shopWidget = new ShopWidget();
    shopWidget->resetItemCounts();
    // 更新游戏界面中的道具数量标签
    gameDlg->updateItemCountLabels();
    gameDlg->show();
    this->hide();
}

void MainWindow::onReturnMainwindow()
{
    QString nextLevel=QString::fromStdString("下一关:"+std::to_string(levelNum/8+1)+"-"+std::to_string(levelNum%8+1));
    nextLevelButton->setLabel(nextLevel, 13);
    Game::instance()->hide();
    this->show();
    sound->play();  // 恢复背景音乐
}

void MainWindow::onDirectToNextLevel(){
    onReturnMainwindow();
    on_pushButton_9_clicked();
    QDialog dialog(this);
    dialog.setWindowTitle("获得新宝石");
    QVBoxLayout layout;
    QLabel gemLabel;
    QString pixStr=QString::fromStdString(":/"+StoneLabel::stoneMode+std::to_string(difficulty)+".png");
    QPixmap gemPixmap(pixStr); // 替换为实际的宝石图片路径
    gemLabel.setPixmap(gemPixmap);
    gemLabel.setAlignment(Qt::AlignCenter);
    gemLabel.setFixedSize(48, 48); // 设置 QLabel 大小
    gemLabel.setScaledContents(true); // 使图片适应 QLabel 大小
    layout.addWidget(&gemLabel);
    QLabel textLabel("恭喜！你获得了一颗新的宝石。");
    textLabel.setAlignment(Qt::AlignCenter);
    layout.addWidget(&textLabel);
    dialog.setLayout(&layout);
    dialog.exec();
}
/*
void MainWindow::on_pushButton_2_clicked()
{
    difficulty = 4;  // Easy difficulty
}

void MainWindow::on_pushButton_3_clicked()
{
    difficulty = 6;  // Medium difficulty
}

void MainWindow::on_pushButton_4_clicked()
{
    difficulty = 8;  // Hard difficulty
}

void MainWindow::on_pushButton_7_clicked()
{
    StoneLabel::stoneMode = "Fruit";  // Set stone mode to Fruit
}

void MainWindow::on_pushButton_6_clicked()
{
    StoneLabel::stoneMode = "Vegetable";  // Set stone mode to Vegetable
}

void MainWindow::on_pushButton_8_clicked()
{
    difficulty = 10;  // Very Hard difficulty
}void MainWindow::on_pushButton_5_clicked()
{

}*/

void MainWindow::onAdventureLostBackToMain(){
    --levelNum;
}

/*冒险模式*/
void MainWindow::on_pushButton_9_clicked()
{
    if(levelNum%8==0){
        difficulty=4;
    }
    levelNum++;
    QString nextLevel=QString::fromStdString("下一关:"+std::to_string(levelNum/8+1)+"-"+std::to_string(levelNum%8+1));
    nextLevelButton->setLabel(nextLevel, 13);
    if(gameDlg){
        Game::delInstance();
    }
    gameDlg = Game::instance(nullptr, Game::GameMode::ADVENTURE_MODE,levelNum,client); // 创建游戏，设置游戏模式为冒险模式
    connect(gameDlg, &Game::returnMainwindow, this, &MainWindow::onReturnMainwindow);
    connect(gameDlg, &Game::directToNextLevel, this, &MainWindow::onDirectToNextLevel);
    connect(gameDlg, &Game::retryAdventure, this, &MainWindow::onRetryAdventure);
    connect(gameDlg, &Game::adventureLostBackToMain, this, &MainWindow::onAdventureLostBackToMain);
    shopWidget = new ShopWidget();
    gameDlg->show();
    this->hide();
}

void MainWindow::on_pushButton_10_clicked()
{
    // 创建并显示 Setting 对话框
    settingwidget settingDlg(sound,this);  // 创建 settingwidget 对象
    if (settingDlg.exec() == QDialog::Accepted) {  // 判断对话框是否被接受
        // 获取设置后的难度和模式
        int selectedDifficulty = settingDlg.getDifficulty();
        std::string selectedMode = settingDlg.getMode();



        // 在 MainWindow 中更新难度和模式
        difficulty = selectedDifficulty;
        StoneLabel::stoneMode = selectedMode;
    }
}

void MainWindow::on_ranking_clicked()
{
    if(client==nullptr){
        QMessageBox::information(this, "排名", "离线模式无法查看排名");
    }else{
        client->onSendData("d");
    }
}//获取排行榜数据

void MainWindow::onDataReceived(){
    QString buffer;
    buffer.append(client->tcpSocket->readAll()); // 将接收到的数据追加到缓冲区

    // 按分隔符（如换行符）处理
    QStringList messages = buffer.split(' ');
    int index=2;
    int num=messages[1].toInt();

    RankDialog rank(this);

    rank.resize(850,650);
    QTableWidget* tableWidget = rank.ui->tableWidget;

    // 设置行数和列数
    tableWidget->setRowCount(num);
    tableWidget->setColumnCount(2);

    // 设置列头
    tableWidget->setHorizontalHeaderLabels(QStringList() << "用户名" << "得分");

    //逻辑添加真实数据
    // 模拟
    QVector<QPair<QString, int>> usersScores;
    for(int i = 0; i < num; ++i){
        usersScores.append({messages[index],messages[index+1].toInt()});
        index+=2;
    }//将数据输入数组
    std::sort(usersScores.begin(), usersScores.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second; // 比较第二项，从大到小排序
              });//按大小排序
    // 填充表格数据
    for (int i = 0; i < usersScores.size(); ++i) {
        // 设置每一行的用户名和得分
        tableWidget->setItem(i, 0, new QTableWidgetItem(usersScores[i].first));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(usersScores[i].second)));
    }

    // 设置字体大小
    QFont font = tableWidget->font();
    font.setPointSize(12);
    tableWidget->setFont(font);
    tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // 列标题的自动扩展
    tableWidget->horizontalHeader()->setStretchLastSection(true);



    rank.exec();

}//显示排行榜

void MainWindow::onRetryAdventure(){
    levelNum--;
    on_pushButton_9_clicked();
}

void MainWindow::onRetryClassic(){
    on_pushButton_clicked();
}

