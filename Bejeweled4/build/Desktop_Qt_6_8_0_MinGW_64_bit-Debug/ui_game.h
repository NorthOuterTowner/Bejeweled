/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QPushButton *pushButton_2;
    QLabel *timerLabel;
    QProgressBar *progressBar;
    QPushButton *pushButton_3;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName("Game");
        Game->resize(800, 601);
        pushButton_2 = new QPushButton(Game);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(690, 90, 93, 28));
        timerLabel = new QLabel(Game);
        timerLabel->setObjectName("timerLabel");
        timerLabel->setGeometry(QRect(480, 490, 41, 21));
        timerLabel->setTabletTracking(false);
        timerLabel->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        timerLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: italic 18pt \"Monotype Corsiva\";\n"
"    border: 1px solid #ddd;         /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;             /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QLabel[alignment=\"center\"] {\n"
"    text-align: center;             /* \346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"}"));
        timerLabel->setScaledContents(true);
        timerLabel->setWordWrap(true);
        progressBar = new QProgressBar(Game);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(97, 490, 381, 23));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid #ccc;         /* \350\277\233\345\272\246\346\235\241\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;             /* \350\277\233\345\272\246\346\235\241\345\234\206\350\247\222 */\n"
"    background: #eee;               /* \350\277\233\345\272\246\346\235\241\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    padding: 2px;                   /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background: #3498db;            /* \350\277\233\345\272\246\346\235\241\345\241\253\345\205\205\351\242\234\350\211\262 */\n"
"    width: 20px;                    /* \345\241\253\345\205\205\345\235\227\345\256\275\345\272\246 */\n"
"    border-radius: 5px;             /* \345\241\253\345\205\205\345\235\227\345\234\206\350\247\222 */\n"
"}"));
        progressBar->setValue(24);
        pushButton_3 = new QPushButton(Game);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 80, 51, 31));
        lcdNumber = new QLCDNumber(Game);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(670, 230, 101, 41));
        label = new QLabel(Game);
        label->setObjectName("label");
        label->setGeometry(QRect(690, 200, 69, 19));
        pushButton_4 = new QPushButton(Game);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(690, 130, 93, 28));
        pushButton_5 = new QPushButton(Game);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(680, 330, 93, 28));

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "GameDlg", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Game", "\346\216\222\350\241\214\346\246\234", nullptr));
        timerLabel->setText(QCoreApplication::translate("Game", "25s", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Game", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("Game", "\345\210\206\346\225\260", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Game", "\344\270\213\344\270\200\345\205\263", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Game", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
