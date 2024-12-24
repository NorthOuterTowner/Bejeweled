#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow {
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    void onSendData(QString);         // 发送
    QString onReadyRead();        // 接收服务器消息
    void onDisconnected();     // 服务器断开

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    QTcpSocket *tcpSocket;
private:
    Ui::Client *ui;
    QString username;
};

#endif // CLIENT_H
