#include "end.h"
#include "ui_end.h"

// 构造函数，初始化界面相关元素并设置布局
End::End(Game* game,Client* c, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::End),
    gameInfo(game),
    client(c)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/end.png); background-repeat: no-repeat; background-position: center; background-size: cover;d");
    setWindowTitle("游戏结束");

    connect(ui->returnButton, &QPushButton::clicked, this, &End::onReturnButtonClicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &End::onNextButtonClicked);
    connect(ui->retryButton, &QPushButton::clicked, this, &End::onRetryButtonClicked);
}

// 析构函数，释放相关资源（这里如果有其他资源需要释放可添加代码）
End::~End()
{
    delete ui;
}

void End::onReturnButtonClicked()
{
    emit gameInfo->returnMainwindow();
    close();
}

void End::showEndUI()
{
    ui->nextButton->hide();
    ui->retryButton->hide();
    // 获取游戏最终得分并设置到得分标签上显示
    int finalScore = gameInfo->getScore();
    if(client!=nullptr){
        client->onSendData("c "+QString::number(finalScore));
    }
    ui->scoreLabel->setText(QString("游戏结束啦，你的最终得分是: %1").arg(finalScore));

    // 显示结束界面
    show();
}

void End::showAdventureWinUI()
{
    ui->retryButton->hide();
    // 设置不同的提示信息
    int finalScore = gameInfo->getScore();
    ui->scoreLabel->setText(QString("恭喜你，闯关成功！你的最终得分是: %1").arg(finalScore));

    // 显示结束界面
    show();
}

void End::showAdventureLoseUI()
{
    ui->nextButton->hide();
    // 设置不同的提示信息
    int finalScore = gameInfo->getScore();
    ui->scoreLabel->setText(QString("很遗憾，闯关失败！你的最终得分是: %1").arg(finalScore));

    // 显示结束界面
    show();
}

void End::onNextButtonClicked(){
    close();
    emit nextButtonClicked();

}

void End::onRetryButtonClicked()
{
    close();
    emit retryGame();
}
