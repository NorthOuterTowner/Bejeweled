/********************************************************************************
** Form generated from reading UI file 'shopwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPWIDGET_H
#define UI_SHOPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopWidget
{
public:
    QPushButton *bomb;
    QPushButton *horizon;
    QPushButton *vertical;
    QPushButton *Buy;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *introduction;
    QLabel *picture;
    QLabel *score;
    QLabel *bombLabel;
    QLabel *horizonLabel;
    QLabel *verticalLabel;

    void setupUi(QWidget *ShopWidget)
    {
        if (ShopWidget->objectName().isEmpty())
            ShopWidget->setObjectName("ShopWidget");
        ShopWidget->resize(764, 666);
        bomb = new QPushButton(ShopWidget);
        bomb->setObjectName("bomb");
        bomb->setGeometry(QRect(70, 140, 61, 61));
        horizon = new QPushButton(ShopWidget);
        horizon->setObjectName("horizon");
        horizon->setGeometry(QRect(70, 230, 61, 61));
        vertical = new QPushButton(ShopWidget);
        vertical->setObjectName("vertical");
        vertical->setGeometry(QRect(70, 320, 61, 61));
        Buy = new QPushButton(ShopWidget);
        Buy->setObjectName("Buy");
        Buy->setGeometry(QRect(440, 370, 141, 51));
        label_2 = new QLabel(ShopWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 751, 51));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"\n"
"QLabel {\n"
"    background-color: #3E2723;  /* \346\267\261\345\222\226\345\225\241\350\211\262\350\203\214\346\231\257 */\n"
"    color: white;  /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 2px solid #5D4037;  /* \350\276\271\346\241\206\351\242\234\350\211\262\344\270\272\347\250\215\346\265\205\347\232\204\345\222\226\345\225\241\350\211\262 */\n"
"    border-radius: 5px;  /* \345\234\206\350\247\222\346\225\210\346\236\234 */\n"
"    padding: 10px;  /* \345\206\205\350\276\271\350\267\235 */\n"
"    text-align: center;  /* \346\226\207\345\255\227\345\261\205\344\270\255 */\n"
"    font-size: 14px;  /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"font: 18pt \"Broadway\";\n"
"}\n"
"\n"
"\n"
"QLabel:pressed {\n"
"    background-color: #5D4037;  /* \347\202\271\345\207\273\346\227\266\350\203\214\346\231\257\350\211\262\345\217\230\344\270\272\346\233\264\346\267\261\347\232\204\345\222\226\345\225\241\350\211\262 */\n"
"    border-color: #3E2723;  /* \347\202"
                        "\271\345\207\273\346\227\266\350\276\271\346\241\206\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
""));
        label_4 = new QLabel(ShopWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 40, 111, 51));
        introduction = new QLabel(ShopWidget);
        introduction->setObjectName("introduction");
        introduction->setGeometry(QRect(400, 230, 191, 91));
        picture = new QLabel(ShopWidget);
        picture->setObjectName("picture");
        picture->setGeometry(QRect(409, 131, 171, 71));
        score = new QLabel(ShopWidget);
        score->setObjectName("score");
        score->setGeometry(QRect(140, 70, 171, 31));
        bombLabel = new QLabel(ShopWidget);
        bombLabel->setObjectName("bombLabel");
        bombLabel->setGeometry(QRect(140, 150, 71, 41));
        horizonLabel = new QLabel(ShopWidget);
        horizonLabel->setObjectName("horizonLabel");
        horizonLabel->setGeometry(QRect(140, 240, 111, 41));
        verticalLabel = new QLabel(ShopWidget);
        verticalLabel->setObjectName("verticalLabel");
        verticalLabel->setGeometry(QRect(140, 330, 111, 41));

        retranslateUi(ShopWidget);

        QMetaObject::connectSlotsByName(ShopWidget);
    } // setupUi

    void retranslateUi(QWidget *ShopWidget)
    {
        ShopWidget->setWindowTitle(QCoreApplication::translate("ShopWidget", "Form", nullptr));
        bomb->setText(QCoreApplication::translate("ShopWidget", "bomb", nullptr));
        horizon->setText(QCoreApplication::translate("ShopWidget", "horizon", nullptr));
        vertical->setText(QCoreApplication::translate("ShopWidget", "vertical", nullptr));
        Buy->setText(QCoreApplication::translate("ShopWidget", "Buy", nullptr));
        label_2->setText(QCoreApplication::translate("ShopWidget", "<html><head/><body><p align=\"center\">SHOP</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ShopWidget", "\346\214\211esc\350\277\224\345\233\236\346\270\270\346\210\217", nullptr));
        introduction->setText(QCoreApplication::translate("ShopWidget", "TextLabel", nullptr));
        picture->setText(QCoreApplication::translate("ShopWidget", "TextLabel", nullptr));
        score->setText(QString());
        bombLabel->setText(QString());
        horizonLabel->setText(QString());
        verticalLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShopWidget: public Ui_ShopWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPWIDGET_H
