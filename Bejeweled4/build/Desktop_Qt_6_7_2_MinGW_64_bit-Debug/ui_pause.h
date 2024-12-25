/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_H
#define UI_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pause
{
public:
    QPushButton *background;
    QLabel *label;
    QLabel *levelInfo;
    QPushButton *resumeButton;
    QPushButton *renewButton;
    QPushButton *returnButton;

    void setupUi(QWidget *Pause)
    {
        if (Pause->objectName().isEmpty())
            Pause->setObjectName("Pause");
        Pause->resize(800, 600);
        Pause->setStyleSheet(QString::fromUtf8(""));
        background = new QPushButton(Pause);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 800, 600));
        background->setStyleSheet(QString::fromUtf8(""));
        background->setFlat(true);
        label = new QLabel(Pause);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 90, 181, 51));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 1px solid #ddd;         /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;             /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"}"));
        levelInfo = new QLabel(Pause);
        levelInfo->setObjectName("levelInfo");
        levelInfo->setGeometry(QRect(190, 170, 81, 31));
        levelInfo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(255, 170, 0);                    /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    font-size: 11px;                /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    border: 1px solid #ddd;         /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;             /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"   \n"
"}\n"
"\n"
"QLabel[alignment=\"center\"] {\n"
"    text-align: center;             /* \346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"}\n"
""));
        resumeButton = new QPushButton(Pause);
        resumeButton->setObjectName("resumeButton");
        resumeButton->setGeometry(QRect(280, 220, 121, 31));
        resumeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 170, 0);             /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #2980b9; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;       /* \345\234\206\350\247\222 */\n"
"    font-size:12px;          /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(170, 170, 127)/* \346\202\254\345\201\234\346\227\266\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        renewButton = new QPushButton(Pause);
        renewButton->setObjectName("renewButton");
        renewButton->setGeometry(QRect(280, 280, 121, 31));
        renewButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 170, 0);             /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #2980b9; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;       /* \345\234\206\350\247\222 */\n"
"    font-size:12px;          /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(170, 170, 127)/* \346\202\254\345\201\234\346\227\266\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        returnButton = new QPushButton(Pause);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(280, 340, 121, 31));
        returnButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 170, 0);             /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #2980b9; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;       /* \345\234\206\350\247\222 */\n"
"    font-size:12px;          /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(170, 170, 127)/* \346\202\254\345\201\234\346\227\266\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));

        retranslateUi(Pause);

        QMetaObject::connectSlotsByName(Pause);
    } // setupUi

    void retranslateUi(QWidget *Pause)
    {
        Pause->setWindowTitle(QCoreApplication::translate("Pause", "Form", nullptr));
        background->setText(QString());
        label->setText(QString());
        levelInfo->setText(QString());
        resumeButton->setText(QCoreApplication::translate("Pause", "\346\201\242\345\244\215\346\270\270\346\210\217", nullptr));
        renewButton->setText(QCoreApplication::translate("Pause", "\345\206\215\346\254\241\346\214\221\346\210\230", nullptr));
        returnButton->setText(QCoreApplication::translate("Pause", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pause: public Ui_Pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
