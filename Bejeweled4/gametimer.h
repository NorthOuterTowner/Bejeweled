#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <QObject>
#include <QTimer>

class GameTimer : public QObject
{
    Q_OBJECT
public:
    // 构造函数，初始化GameTimer对象
    // 参数parent是父对象指针，默认为nullptr
    explicit GameTimer(QObject *parent = nullptr);

    void stop();//停止计时函数
    void start();//开始计时函数
    void startCountdown(int seconds); //用于初始化倒计时的函数
    int getRemainingSeconds();//获取剩余秒数的函数

signals:
    // 自定义信号，当计时结束时发出
    void timeExpired();

    void timeUpdated(int remainingSeconds);

private slots:
    // 私有槽函数，用于更新剩余时间
    void updateTime();

private:
    // QTimer对象指针，用于实现计时功能
    QTimer *timer;
    int remainingSeconds = -1;//剩余时间
};

#endif // GAMETIMER_H
