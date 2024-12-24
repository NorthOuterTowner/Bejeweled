/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

    void setupUi(QWidget *settingwidget)
    {
        if (settingwidget->objectName().isEmpty())
            settingwidget->setObjectName("settingwidget");
        settingwidget->resize(1024, 768);
        Easy = new QPushButton(settingwidget);
        Easy->setObjectName("Easy");
        Easy->setGeometry(QRect(120, 200, 56, 18));
        Medium = new QPushButton(settingwidget);
        Medium->setObjectName("Medium");
        Medium->setGeometry(QRect(260, 200, 56, 18));
        Hard = new QPushButton(settingwidget);
        Hard->setObjectName("Hard");
        Hard->setGeometry(QRect(390, 200, 56, 18));
        Jewel = new QPushButton(settingwidget);
        Jewel->setObjectName("Jewel");
        Jewel->setGeometry(QRect(140, 300, 56, 18));
        Fruit = new QPushButton(settingwidget);
        Fruit->setObjectName("Fruit");
        Fruit->setGeometry(QRect(330, 300, 56, 18));
        Vegetable = new QPushButton(settingwidget);
        Vegetable->setObjectName("Vegetable");
        Vegetable->setGeometry(QRect(520, 300, 56, 18));
        hell = new QPushButton(settingwidget);
        hell->setObjectName("hell");
        hell->setGeometry(QRect(520, 200, 56, 18));

        retranslateUi(settingwidget);

        QMetaObject::connectSlotsByName(settingwidget);
    } // setupUi

    void retranslateUi(QWidget *settingwidget)
    {
        settingwidget->setWindowTitle(QCoreApplication::translate("settingwidget", "Form", nullptr));
        Easy->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        Medium->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        Hard->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        Jewel->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        Fruit->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        Vegetable->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
        hell->setText(QCoreApplication::translate("settingwidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingwidget: public Ui_settingwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
