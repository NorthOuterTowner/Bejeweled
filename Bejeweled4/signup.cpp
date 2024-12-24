// 在 Signup.cpp 文件开头加上这个声明
void sqlite_Init();  // 在这里声明 sqlite_Init()

#include "signup.h"
#include "ui_signup.h"
#include "Login.h"
#include "utils.h"
#include <QDebug>

// 以下代码不变
Signup::Signup(Client* c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup),
    client(c)
{
    ui->setupUi(this);
    QPixmap *pix = new QPixmap(":/girl1.png");
    QSize sz = ui->label_image->size();
    ui->label_image->setPixmap(pix->scaled(sz));
    connect(client->tcpSocket, &QTcpSocket::readyRead, this, &Signup::onDataReceived);
}

Signup::~Signup()
{
    delete ui;
}

// 返回登录按钮
void Signup::on_btn_return_clicked()
{
    Login *w = new Login;
    w->show();
    this->close();
}

// 注册按钮
void Signup::on_pushButton_2_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = utils::hashPassword(ui->lineEdit_passwd->text());
    QString surepass = utils::hashPassword(ui->lineEdit_surepasswd->text());

    if(password == surepass)
    {
        QString out="b "+username+" "+password;
        client->onSendData(out);
    } else {
        QMessageBox::information(this,"注册认证","两次密码输入不一致");
    }
}

void Signup::onDataReceived(){
    QString buffer;
    buffer.append(client->tcpSocket->readAll()); // 将接收到的数据追加到缓冲区

    // 按分隔符（如换行符）处理
    QStringList messages = buffer.split(' ');
    if(messages[1]=="1"){
        qDebug()<<"insert into success";
        QMessageBox::information(this,"注册认证","插入成功！");
        Login *w = new Login(client);
        w->show();
        disconnect(client->tcpSocket, &QTcpSocket::readyRead, this, &Signup::onDataReceived);
        this->close();
    }else if(messages[1]=="0"){
        qDebug()<<"insert into error";
        QMessageBox::information(this,"注册认证","插入失败！");
    }
}//判断是否注册成功
