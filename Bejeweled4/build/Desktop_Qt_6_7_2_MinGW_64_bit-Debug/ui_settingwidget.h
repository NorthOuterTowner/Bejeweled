/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingwidget
{
public:
    QPushButton *Easy;
    QPushButton *Medium;
    QPushButton *Hard;
    QPushButton *Jewel;
    QPushButton *Fruit;
    QPushButton *Vegetable;
    QPushButton *hell;
    QPushButton *Volume;
    QLabel *label_3;
    QLabel *label_volume;
    QLabel *label_settings;
    QLabel *label;
    QLabel *label_volume_2;
    QLabel *label_5;
    QLabel *label_volume_3;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QWidget *settingwidget)
    {
        if (settingwidget->objectName().isEmpty())
            settingwidget->setObjectName("settingwidget");
        settingwidget->resize(1024, 768);
        Easy = new QPushButton(settingwidget);
        Easy->setObjectName("Easy");
        Easy->setGeometry(QRect(300, 340, 81, 31));
        Easy->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/Settingpage/dialogbutton.png);"));
        Medium = new QPushButton(settingwidget);
        Medium->setObjectName("Medium");
        Medium->setGeometry(QRect(430, 340, 81, 31));
        Medium->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogbutton.png);"));
        Hard = new QPushButton(settingwidget);
        Hard->setObjectName("Hard");
        Hard->setGeometry(QRect(560, 340, 81, 31));
        Hard->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogbutton.png);"));
        Jewel = new QPushButton(settingwidget);
        Jewel->setObjectName("Jewel");
        Jewel->setGeometry(QRect(340, 430, 81, 31));
        Jewel->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogbutton.png);"));
        Fruit = new QPushButton(settingwidget);
        Fruit->setObjectName("Fruit");
        Fruit->setGeometry(QRect(490, 430, 81, 31));
        Fruit->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogbutton.png);"));
        Vegetable = new QPushButton(settingwidget);
        Vegetable->setObjectName("Vegetable");
        Vegetable->setGeometry(QRect(630, 430, 81, 31));
        Vegetable->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogbutton.png);"));
        hell = new QPushButton(settingwidget);
        hell->setObjectName("hell");
        hell->setGeometry(QRect(690, 340, 81, 31));
        hell->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogbutton.png);"));
        Volume = new QPushButton(settingwidget);
        Volume->setObjectName("Volume");
        Volume->setGeometry(QRect(490, 490, 75, 24));
        label_3 = new QLabel(settingwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 491, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/slider-track-2.png);"));
        label_volume = new QLabel(settingwidget);
        label_volume->setObjectName("label_volume");
        label_volume->setGeometry(QRect(370, 490, 71, 31));
        label_volume->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_settings = new QLabel(settingwidget);
        label_settings->setObjectName("label_settings");
        label_settings->setGeometry(QRect(460, 190, 121, 51));
        label_settings->setStyleSheet(QString::fromUtf8("font: 18pt \"Broadway\";\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(settingwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 180, 271, 81));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/dialogtitle.png);"));
        label_volume_2 = new QLabel(settingwidget);
        label_volume_2->setObjectName("label_volume_2");
        label_volume_2->setGeometry(QRect(500, 380, 71, 31));
        label_volume_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_5 = new QLabel(settingwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(480, 381, 71, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/DialogButtonGlow.png);"));
        label_volume_3 = new QLabel(settingwidget);
        label_volume_3->setObjectName("label_volume_3");
        label_volume_3->setGeometry(QRect(500, 289, 71, 31));
        label_volume_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_6 = new QLabel(settingwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(480, 290, 71, 31));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/Settingpage/DialogButtonGlow.png);"));
        label_2 = new QLabel(settingwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 340, 51, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_4 = new QLabel(settingwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 340, 51, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_7 = new QLabel(settingwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(580, 340, 51, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(settingwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(710, 340, 51, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_9 = new QLabel(settingwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(360, 430, 51, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_10 = new QLabel(settingwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(500, 430, 51, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_11 = new QLabel(settingwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(640, 430, 51, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"Elephant\";\n"
"color: rgb(255, 255, 255);"));
        label_12 = new QLabel(settingwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(450, 560, 131, 31));
        label_12->setStyleSheet(QString::fromUtf8("background-image: url(:/blueBar.png);\n"
""));
        label_6->raise();
        label_volume_3->raise();
        label_5->raise();
        label_volume_2->raise();
        label->raise();
        Easy->raise();
        Medium->raise();
        Hard->raise();
        Jewel->raise();
        Fruit->raise();
        Vegetable->raise();
        hell->raise();
        Volume->raise();
        label_3->raise();
        label_volume->raise();
        label_settings->raise();
        label_2->raise();
        label_4->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();

        retranslateUi(settingwidget);

        QMetaObject::connectSlotsByName(settingwidget);
    } // setupUi

    void retranslateUi(QWidget *settingwidget)
    {
        settingwidget->setWindowTitle(QCoreApplication::translate("settingwidget", "Form", nullptr));
        Easy->setText(QString());
        Medium->setText(QString());
        Hard->setText(QString());
        Jewel->setText(QString());
        Fruit->setText(QString());
        Vegetable->setText(QString());
        hell->setText(QString());
        Volume->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        label_3->setText(QString());
        label_volume->setText(QCoreApplication::translate("settingwidget", "Volume", nullptr));
        label_settings->setText(QCoreApplication::translate("settingwidget", "Settings", nullptr));
        label->setText(QString());
        label_volume_2->setText(QCoreApplication::translate("settingwidget", "<html><head/><body><p>Mode</p></body></html>", nullptr));
        label_5->setText(QString());
        label_volume_3->setText(QCoreApplication::translate("settingwidget", "<html><head/><body><p>Level</p></body></html>", nullptr));
        label_6->setText(QString());
        label_2->setText(QCoreApplication::translate("settingwidget", "Easy", nullptr));
        label_4->setText(QCoreApplication::translate("settingwidget", "Medium", nullptr));
        label_7->setText(QCoreApplication::translate("settingwidget", "Hard", nullptr));
        label_8->setText(QCoreApplication::translate("settingwidget", "Hell", nullptr));
        label_9->setText(QCoreApplication::translate("settingwidget", "Jewel", nullptr));
        label_10->setText(QCoreApplication::translate("settingwidget", "Fruit", nullptr));
        label_11->setText(QCoreApplication::translate("settingwidget", "Vegetable", nullptr));
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settingwidget: public Ui_settingwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
