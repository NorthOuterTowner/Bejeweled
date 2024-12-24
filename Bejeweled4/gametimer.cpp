#include "gametimer.h"

GameTimer::GameTimer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this); //创建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));  //关联槽函数
    timer->start(1000);  //1000毫秒
}

// 实现用于初始化倒计时的函数
void GameTimer::startCountdown(int seconds)
{
    remainingSeconds = seconds;
    // 也可以在这里添加一些额外的初始化相关逻辑（如果有的话）
}

void GameTimer::stop()
{
    if (timer->isActive()) {  // 先判断定时器是否正在运行
        timer->stop();
    }
}

void GameTimer::start()
{
    if (!timer->isActive()) {  // 判断定时器当前是否未运行，避免重复启动
        timer->start();
    }
}

int GameTimer::getRemainingSeconds()
{
    return remainingSeconds;
}

void GameTimer::updateTime()
{
    if (timer->isActive() && remainingSeconds > 0) {  // 判断游戏是否暂停，只有未暂停且剩余时间大于0时才进行倒计时
        remainingSeconds--;
        emit timeUpdated(remainingSeconds);
    } else if (remainingSeconds == 0) {
        timer->stop();
        emit timeExpired();
    }
}
