#ifndef SHOPWIDGET_H
#define SHOPWIDGET_H

#include <QWidget>    // 必须包含 QWidget 基类
#include <QPainter>   // 用于绘制图形
#include <QPixmap>    // 用于处理图片
#include <ui_shopwidget.h>
#include "game.h"

namespace Ui {
class ShopWidget;
}

class ShopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShopWidget(QWidget *parent = nullptr);  // 构造函数
    ~ShopWidget();  // 析构函数
    void keyPressEvent(QKeyEvent *event);

    // 静态成员变量，所有实例共享
    static int bombCount;    // 炸弹数量
    static int horizonCount; // 横向消除道具数量
    static int verticalCount; // 竖向消除道具数量
    // 重置道具数量
    void resetItemCounts();

signals:
    void resumeGame();

protected:
    void paintEvent(QPaintEvent *event) override;  // 绘制事件

private slots:
    void on_bomb_clicked();
    void on_Buy_clicked();
    void on_horizon_clicked();
    void on_vertical_clicked();


private:
    Ui::ShopWidget *ui;  // UI 控件的指针
    Game* game;  // 游戏对象指针，用于访问分数

    enum class ItemType {
        NONE,        // 没有选择道具
        BOMB,        // 炸弹
        HORIZON,     // 横向消除
        VERTICAL     // 竖向消除
    };

 ItemType currentItemType;  // 当前选中的道具类型

};

#endif // SHOPWIDGET_H
