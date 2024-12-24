#include "client.h"
#include "login.h"
#include "ui_client.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
Client::Client(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Client) {
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);

    /*
    // 网络通信的槽函数
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::onDisconnected);
*/
}

Client::~Client() {

    delete ui;
}


void Client::onSendData(QString data) {
    tcpSocket->write(data.toUtf8());
}//发送信息


QString Client::onReadyRead() {
    QByteArray data = tcpSocket->readAll();
    return QString::fromUtf8(data);
}//接受信息

void Client::onDisconnected() {

}

/*void QMainWindow::closeEvent(QCloseEvent *event){

}*/
void Client::on_pushButton_clicked()
{
    QString host = ui->hostEdit->text();
    quint16 port = ui->portEdit->text().toUInt();

    tcpSocket->connectToHost(host, port);
    connect(tcpSocket,&QTcpSocket::connected,[this]()
    {
        QMessageBox::information(this,"服务器连接成功","连接服务器成功");
        Login *w=new Login(this);
        w->show();
        this->close();
    });
    /*
    if (tcpSocket->waitForConnected(3000)) {
        QMessageBox::information(this, "服务器连接失败", "进入离线模式");
        Login *w=new Login(nullptr);
        w->show();
        this->close();
    } else {
        QString data = "a "+username;
        tcpSocket->write(data.toUtf8());
        QMessageBox::information(this, "服务器连接成功", "进入在线模式");
        Login *w=new Login(tcpSocket);
        w->show();
        this->close();
    }
*/
}//尝试连接服务器


void Client::on_pushButton_2_clicked()
{
    MainWindow *w=new MainWindow();
    w->show();
    this->close();
}//进行离线游戏

