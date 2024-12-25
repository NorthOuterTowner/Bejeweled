/********************************************************************************
** Form generated from reading UI file 'end.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_END_H
#define UI_END_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_End
{
public:
    QLabel *scoreLabel;
    QPushButton *returnButton;
    QPushButton *nextButton;
    QPushButton *retryButton;
    QPushButton *background;

    void setupUi(QWidget *End)
    {
        if (End->objectName().isEmpty())
            End->setObjectName("End");
        End->resize(800, 600);
        scoreLabel = new QLabel(End);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(240, 90, 241, 51));
        returnButton = new QPushButton(End);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(320, 210, 71, 31));
        returnButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 170, 0);             /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"	font: 700 9pt \"Microsoft YaHei UI\";\n"
"    border: 2px solid #2980b9; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;       /* \345\234\206\350\247\222 */\n"
"    font-size: 12px;          /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}"));
        nextButton = new QPushButton(End);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(320, 160, 71, 31));
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 170, 0);             /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"	font: 700 9pt \"Microsoft YaHei UI\";\n"
"    border: 2px solid #2980b9; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;       /* \345\234\206\350\247\222 */\n"
"    font-size: 12px;          /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}"));
        retryButton = new QPushButton(End);
        retryButton->setObjectName("retryButton");
        retryButton->setGeometry(QRect(320, 160, 71, 31));
        retryButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 170, 0);             /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"	font: 700 9pt \"Microsoft YaHei UI\";\n"
"    border: 2px solid #2980b9; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;       /* \345\234\206\350\247\222 */\n"
"    font-size: 12px;          /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}"));
        background = new QPushButton(End);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 800, 600));
        background->setFlat(true);
        background->raise();
        scoreLabel->raise();
        returnButton->raise();
        nextButton->raise();
        retryButton->raise();

        retranslateUi(End);

        QMetaObject::connectSlotsByName(End);
    } // setupUi

    void retranslateUi(QWidget *End)
    {
        End->setWindowTitle(QCoreApplication::translate("End", "Form", nullptr));
        scoreLabel->setText(QCoreApplication::translate("End", "\346\270\270\346\210\217\347\273\223\346\235\237", nullptr));
        returnButton->setText(QCoreApplication::translate("End", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        nextButton->setText(QCoreApplication::translate("End", "\344\270\213\344\270\200\345\205\263", nullptr));
        retryButton->setText(QCoreApplication::translate("End", "\351\207\215\346\226\260\346\214\221\346\210\230", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class End: public Ui_End {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_END_H
