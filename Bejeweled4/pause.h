#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>

namespace Ui {
class Pause;
}

class Pause : public QWidget
{
    Q_OBJECT
public:
    explicit Pause(QWidget *parent = nullptr);
    ~Pause();
    Ui::Pause *ui;

signals:
    void resumeGame();  // 新增的信号，用于通知恢复游戏
    void returnToMainMenu();  // 新增的信号，用于通知返回主菜单
    void renewGame();   // 新增的信号，用于重新开始
private slots:
    void on_resumeButton_clicked();  // 新增的槽函数，对应恢复游戏按钮点击事件
    void on_returnButton_clicked();  // 新增的槽函数，对应返回主菜单按钮点击事件
    void on_background_clicked();   //实现锁屏效果的空槽函数
    void on_renewButton_clicked();  //新增的槽函数，对应重新挑战按钮点击事件
private:

};

#endif // PAUSE_H
