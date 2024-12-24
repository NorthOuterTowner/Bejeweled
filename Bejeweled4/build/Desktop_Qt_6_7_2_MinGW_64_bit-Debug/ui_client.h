/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *hostEdit;
    QLineEdit *portEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(172, 123);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 0, 111, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 20, 54, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 40, 54, 16));
        hostEdit = new QLineEdit(centralwidget);
        hostEdit->setObjectName("hostEdit");
        hostEdit->setGeometry(QRect(40, 20, 113, 20));
        portEdit = new QLineEdit(centralwidget);
        portEdit->setObjectName("portEdit");
        portEdit->setGeometry(QRect(40, 40, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 60, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 60, 75, 24));
        Client->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Client);
        statusbar->setObjectName("statusbar");
        Client->setStatusBar(statusbar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Client", "\345\256\235\347\237\263\350\277\267\351\230\265\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245", nullptr));
        label_2->setText(QCoreApplication::translate("Client", "\344\270\273\346\234\272\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Client", "\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Client", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Client", "\347\246\273\347\272\277\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
