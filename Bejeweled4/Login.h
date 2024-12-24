#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSqlDatabase> // 数据驱动
#include <QSqlQuery>    // 数据库执行语句
#include <QMessageBox>  // 消息盒子
#include <QDebug>       // 调试信息
#include<QPropertyAnimation>
#include <QTcpSocket>
#include "client.h"
void sqlite_Init();
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }  // 修改为 Login
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:

    QPropertyAnimation *  ShowBackground();
    QPropertyAnimation * ShowTitle();
    void setAdaptedImg(QString path,QLabel *label);
    void setBkImg(QString path,QLabel *label);
 QPropertyAnimation *bkAnim;
    Login(Client *client=nullptr,QWidget *parent = nullptr);  // 构造函数
    ~Login();  // 析构函数

private slots:
    void on_btn_signin_clicked();  // 登录按钮点击槽
    void on_btn_signup_clicked();  // 注册按钮点击槽
    void onDataReceived();//处理传输数据

private:
    Ui::Login *ui;  // 修改为 Login
    Client *client;
    // 将 sqlite_Init() 函数声明为 Login 类的成员函数

};

#endif // LOGIN_H
