#include "settingwidget.h"
#include <QPushButton>
#include <hoverbutton.h>
#include <stonelabel.h>
#include<globalvalue.h>
#include "PixmapSlider.h"

settingwidget::settingwidget(QSoundEffect* s,QWidget *parent) : QDialog(parent), difficulty(4), stoneMode("gemstone"),sound(s)
{
    ui = new Ui::settingwidget();  // 使用 new 初始化 ui 指针
    ui->setupUi(this);


    QPixmap pixmap = QPixmap(":/picture/Settingpage/dialogbox.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    //去窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint | this->windowFlags());
    //把窗口背景设置为透明
    this->setAttribute(Qt::WA_TranslucentBackground);


    //设置标签对鼠标事件穿透
    ui->label_2->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_4->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_7->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_8->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_9->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_10->setAttribute(Qt::WA_TransparentForMouseEvents);
ui->label_11->setAttribute(Qt::WA_TransparentForMouseEvents);


    ui->Easy->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Medium->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Hard->setCursor(QCursor(Qt::PointingHandCursor));
    ui->hell->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Jewel->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Fruit->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Vegetable->setCursor(QCursor(Qt::PointingHandCursor));

    ui->Easy->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->Easy, &QPushButton::pressed, [=](){
        ui->Easy->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->Easy, &QPushButton::released, [=](){
        ui->Easy->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );

    ui->Medium->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->Medium, &QPushButton::pressed, [=](){
        ui->Medium->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->Medium, &QPushButton::released, [=](){
        ui->Medium->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );

    ui->Hard->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->Hard, &QPushButton::pressed, [=](){
        ui->Hard->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->Hard, &QPushButton::released, [=](){
        ui->Hard->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );

    ui->hell->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->hell, &QPushButton::pressed, [=](){
        ui->hell->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->hell, &QPushButton::released, [=](){
        ui->hell->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );

    ui->Jewel->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->Jewel, &QPushButton::pressed, [=](){
        ui->Jewel->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->Jewel, &QPushButton::released, [=](){
        ui->Jewel->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );

    ui->Fruit->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->Fruit, &QPushButton::pressed, [=](){
        ui->Fruit->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->Fruit, &QPushButton::released, [=](){
        ui->Fruit->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );

    ui->Vegetable->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)");
    connect(ui->Vegetable, &QPushButton::pressed, [=](){
        ui->Vegetable->setStyleSheet("border-image:url(:/Settingpage/DialogButtonGlow.png)");}
            );
    connect(ui->Vegetable, &QPushButton::released, [=](){
        ui->Vegetable->setStyleSheet("border-image:url(:/Settingpage/dialogbutton.png)"); }
            );
  /*  // 创建并设置 HoverButton，直接设置位置
    HoverButton *easyButton = new HoverButton(this);
    easyButton->setImage(":/icons/easy_normal.png", ":/icons/easy_hover.png", 100, 45);
    easyButton->setLabel("Easy", 13);
    easyButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    easyButton->move(ui->Easy->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(easyButton, &QPushButton::clicked, this, &settingwidget::on_Easy_clicked);
    ui->Easy->hide();  // 隐藏原按钮

    HoverButton *mediumButton = new HoverButton(this);
    mediumButton->setImage(":/icons/medium_normal.png", ":/icons/medium_hover.png", 150, 50);
    mediumButton->setLabel("Medium", 13);
    mediumButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    mediumButton->move(ui->Medium->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(mediumButton, &QPushButton::clicked, this, &settingwidget::on_Medium_clicked);
    ui->Medium->hide();  // 隐藏原按钮

    HoverButton *hardButton = new HoverButton(this);
    hardButton->setImage(":/icons/hard_normal.png", ":/icons/hard_hover.png", 150, 50);
    hardButton->setLabel("Hard", 13);
    hardButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    hardButton->move(ui->Hard->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(hardButton, &QPushButton::clicked, this, &settingwidget::on_Hard_clicked);
    ui->Hard->hide();  // 隐藏原按钮

    HoverButton *veryHardButton = new HoverButton(this);
    veryHardButton->setImage(":/icons/veryhard_normal.png", ":/icons/veryhard_hover.png", 150, 50);
    veryHardButton->setLabel("Very Hard", 13);
    veryHardButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    veryHardButton->move(ui->hell->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(veryHardButton, &QPushButton::clicked, this, &settingwidget::on_hell_clicked);
    ui->hell->hide();  // 隐藏原按钮

    HoverButton *jewelButton = new HoverButton(this);
    jewelButton->setImage(":/icons/fruit_normal.png", ":/icons/fruit_hover.png", 150, 50);
    jewelButton->setLabel("Jewel Mode", 13);
    jewelButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    jewelButton->move(ui->Jewel->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(jewelButton, &QPushButton::clicked, this, &settingwidget::on_Jewel_clicked);
    ui->Jewel->hide();  // 隐藏原按钮

    HoverButton *fruitButton = new HoverButton(this);
    fruitButton->setImage(":/icons/fruit_normal.png", ":/icons/fruit_hover.png", 150, 50);
    fruitButton->setLabel("Fruit Mode", 13);
    fruitButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    fruitButton->move(ui->Fruit->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(fruitButton, &QPushButton::clicked, this, &settingwidget::on_Fruit_clicked);
    ui->Fruit->hide();  // 隐藏原按钮

    HoverButton *vegetableButton = new HoverButton(this);
    vegetableButton->setImage(":/icons/vegetable_normal.png", ":/icons/vegetable_hover.png", 150, 50);
    vegetableButton->setLabel("Vegetable Mode", 13);
    vegetableButton->setSound(":/music/button/button_mouseover.wav", ":/music/button/button_mouseleave.wav", ":/music/button/button_press.wav", ":/music/button/button_release.wav");
    vegetableButton->move(ui->Vegetable->geometry().topLeft()); // 使用几何矩形的位置来设置
    connect(vegetableButton, &QPushButton::clicked, this, &settingwidget::on_Vegetable_clicked);
    ui->Vegetable->hide();  // 隐藏原按钮*/

    PixmapSlider* slider1=new PixmapSlider(this);
    slider1->setVisible(true);
    slider1->move(ui->Volume->geometry().topLeft()); // 使用几何矩形的位置来设置
    slider1->SetChannelImage(":/Settingpage/slider-track-1.png","");
    slider1->SetThumbImage(":/Settingpage/thumb.png",":/picture/Settingpage/thumb.png");
    slider1->SetRange(0, 99);
    slider1->SetPos(99,false);
    QObject::connect(slider1, SIGNAL(valueChanged(int)), this, SLOT(onVolumeValueChanged(int)));
    ui->Volume->hide();
    //设置音量的滑条
}


settingwidget::~settingwidget()
{
}

void settingwidget::on_Easy_clicked()
{
    difficulty = 4;
    ::difficulty = difficulty; // 更新全局变量
    // StoneLabel::stoneMode = "Fruit"; // Easy difficulty
}

void settingwidget::on_Medium_clicked()
{
    difficulty = 6;
    ::difficulty = difficulty; // 更新全局变量
}

void settingwidget::on_Hard_clicked()
{
    difficulty = 8;
    ::difficulty = difficulty; // 更新全局变量
}

void settingwidget::on_hell_clicked()
{
    difficulty = 10;
    ::difficulty = difficulty; // 更新全局变量
}

void settingwidget::on_Jewel_clicked()
{
    StoneLabel::stoneMode = "gemstone";
}

void settingwidget::on_Fruit_clicked()
{
    StoneLabel::stoneMode = "Fruit";
}

void settingwidget::on_Vegetable_clicked()
{
    StoneLabel::stoneMode = "Vegetable";
}

void settingwidget::onVolumeValueChanged(int i)
{
    ::volume=(double)i/100;
    sound->setVolume(volume);
}//改变背景音量

void settingwidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPixmap pixmap(":/Settingpage/dialogbox.png");
    pixmap = pixmap.scaled(700, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // 计算居中位置
    int x = (this->width() - pixmap.width()) / 2;
    int y = (this->height() - pixmap.height()) / 2;

    p.drawPixmap(x, y, pixmap);
}
