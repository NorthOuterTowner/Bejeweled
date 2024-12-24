#include "ShopWidget.h"
#include <QPainter>
#include <QPixmap>
#include<QKeyEvent>
#include <QLabel>  // 引入 QLabel 用于显示图片和文本
#include<globalvalue.h>
// 定义静态成员变量
int ShopWidget::bombCount = 1;    // 炸弹数量
int ShopWidget::horizonCount = 1; // 横向消除道具数量
int ShopWidget::verticalCount = 1; // 竖向消除道具数量



ShopWidget::ShopWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopWidget),
    game(Game::instance(parent))  // 获取游戏实例（单例模式）

{
    ui->setupUi(this);

    connect(this, &ShopWidget::resumeGame, game, &Game::resume);
    // 初始化当前选择道具为 NONE
    currentItemType = ItemType::NONE;
    //去窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint | this->windowFlags());
    //把窗口背景设置为透明
    this->setAttribute(Qt::WA_TranslucentBackground);



    // 更新UI显示炸弹数量
    ui->bombLabel->setText(QString("炸弹: %1").arg(bombCount));
    // 更新显示当前积分
    ui->score->setText(QString("当前积分: %1").arg(game->getScoreToShop()));

    // 更新UI显示横向数量
    ui->horizonLabel->setText(QString("横向: %1").arg(horizonCount));
    // 更新显示当前积分


    ui->verticalLabel->setText(QString("竖向: %1").arg(verticalCount));




}

ShopWidget::~ShopWidget()
{
    delete ui;
}

void ShopWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap(":/button/Level_back.png");

    // 拉伸图片以适应整个窗口
    painter.drawPixmap(0, 0, width(), height(), pixmap);
}

// 处理按键事件
void ShopWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        // 按下 Esc 键时，关闭窗口或执行其他返回操作
        this->close();  // 关闭当前窗口
        emit resumeGame();
    } else {
        // 其他键处理，可以调用父类的 keyPressEvent 进行默认处理
        QWidget::keyPressEvent(event);
    }
}



#include<QMessageBox>
void ShopWidget::on_Buy_clicked()
{
    // 检查是否没有选择任何道具
    if (currentItemType == ItemType::NONE) {
        // 如果没有选择道具，弹出提示框
        QMessageBox::information(this, "选择道具", "请先选择购买的道具！");
        return;  // 退出函数，避免继续执行购买逻辑
    }

    int itemPrice = 0;

    // 根据选中的道具确定价格
    switch (currentItemType) {
    case ItemType::BOMB:
        itemPrice = 20;  // 炸弹价格
        break;
    case ItemType::HORIZON:
    case ItemType::VERTICAL:
        itemPrice = 30;  // 横向和竖向消除的价格
        break;
    }

    // 获取当前游戏分数
    int currentScore = game->getScoreToShop();

    if (currentScore >= itemPrice) {
        // 如果分数足够购买道具
        game->setScore(currentScore - itemPrice);  // 扣除积分

        // 根据道具类型更新购买数量
        switch (currentItemType) {
        case ItemType::BOMB:
            bombCount++;
            // 更新 Game 中的炸弹数量
            ui->bombLabel->setText(QString("炸弹: %1").arg(bombCount));
              break;
        case ItemType::HORIZON:
            horizonCount++;
            // 更新 Game 中的横向消除数量
            ui->horizonLabel->setText(QString("横向消除: %1").arg(horizonCount));
            break;
        case ItemType::VERTICAL:
            verticalCount++;
           // 更新 Game 中的竖向消除数量
            ui->verticalLabel->setText(QString("竖向消除: %1").arg(verticalCount));
            break;
        }

        // 更新游戏界面中的道具数量标签
        game->updateItemCountLabels();
        // 更新显示当前积分
        ui->score->setText(QString("当前积分: %1").arg(game->getScoreToShop()));

        // 购买成功提示
        QMessageBox::information(this, "购买成功", "道具购买成功！");
    } else {
        // 如果积分不足，弹出提示框
        QMessageBox::information(this, "购买失败", "积分不足，无法购买道具！");
    }
}





void ShopWidget::on_bomb_clicked()
{
    currentItemType = ItemType::BOMB;  // 设置为炸弹道具

    // 显示炸弹的图片和描述
    ui->picture->setPixmap(QPixmap(":/button/bomb_image.png"));
    ui->introduction->setText("炸弹道具：用于消除选定区域的宝石\n价格：20积分");
    ui->picture->show();
    ui->introduction->show();
}

void ShopWidget::on_horizon_clicked()
{
    currentItemType = ItemType::HORIZON;  // 设置为横向消除道具

    // 显示横向消除的图片和描述
    ui->picture->setPixmap(QPixmap(":/button/horizon_image.png"));
    ui->introduction->setText("横向消除道具：消除一整行的宝石\n价格：30积分");
    ui->picture->show();
    ui->introduction->show();
}

void ShopWidget::on_vertical_clicked()
{
    currentItemType = ItemType::VERTICAL;  // 设置为竖向消除道具

    // 显示竖向消除的图片和描述
    ui->picture->setPixmap(QPixmap(":/button/vertical_image.png"));
    ui->introduction->setText("竖向消除道具：消除一整列的宝石\n价格：30积分");
    ui->picture->show();
    ui->introduction->show();
}

// 重置道具数量
void ShopWidget::resetItemCounts() {
    bombCount = 1;   // 重置炸弹数量
    horizonCount = 1; // 重置横向消除道具数量
    verticalCount = 1; // 重置竖向消除道具数量

    // 更新 UI 显示
    ui->bombLabel->setText(QString("炸弹: %1").arg(bombCount));
    ui->horizonLabel->setText(QString("横向: %1").arg(horizonCount));
    ui->verticalLabel->setText(QString("竖向: %1").arg(verticalCount));
}
