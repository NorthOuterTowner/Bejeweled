#include "pause.h"
#include "ui_pause.h"

Pause::Pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    // 使用样式表设置背景图片
    this->setStyleSheet("background-image: url(:/StartPage/background.png); background-repeat: no-repeat; background-position: center; background-size: cover;");

    ui->label->setPixmap(QPixmap(":/pause.png"));
    ui->label->setScaledContents(true);// 让图片自适应QLabel大小

    // 连接恢复游戏按钮的点击信号到对应的槽函数
    connect(ui->resumeButton, &QPushButton::clicked, this, &Pause::on_resumeButton_clicked);
    // 连接返回主菜单按钮的点击信号到对应的槽函数
    //connect(ui->returnButton, &QPushButton::clicked, this, &Pause::on_returnButton_clicked);
}

Pause::~Pause()
{
    delete ui;

}

void Pause::on_resumeButton_clicked()
{
    close();
    emit resumeGame();
}

void Pause::on_returnButton_clicked()
{

    emit returnToMainMenu();  // 点击返回主菜单按钮后，发射信号通知游戏主界面进行相应操作
    close();
}

void Pause::on_background_clicked(){}

void Pause::on_renewButton_clicked(){
    close();
    emit renewGame();
}


