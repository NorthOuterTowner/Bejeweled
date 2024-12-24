#include "rankdialog.h"
#include "ui_rankdialog.h"

RankDialog::RankDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RankDialog)
{
    ui->setupUi(this);
    qDebug() << "Image path: :/images/rrank.png";
    setStyleSheet("RankDialog{border-image:url(:/rrank.png);}");
    ui->pushButton->setStyleSheet(R"(
        QPushButton {
            background-color: #87CEEB;  /* 设置按钮背景色 */
            color: white;                /* 设置字体颜色 */
            font-size: 16px;             /* 设置字体大小 */
            font-weight: bold;           /* 设置字体加粗 */
            border: none;                /* 去掉按钮边框 */
            border-radius: 12px;         /* 圆角按钮 */


        }

        QPushButton:hover {
            background-color:#78b8d1;  /* 悬停时背景色变深 */
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2); /* 增加阴影 */
            font-size:32px;
        }

        QPushButton:pressed {
            background-color: #388e3c;  /* 按下时背景色更深 */
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1); /* 按下时阴影减小 */

    )");
}

RankDialog::~RankDialog()
{
    delete ui;
}

void RankDialog::on_pushButton_clicked()
{
    close();
}

