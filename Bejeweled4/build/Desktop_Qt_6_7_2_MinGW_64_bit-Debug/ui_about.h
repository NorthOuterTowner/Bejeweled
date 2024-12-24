/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(400, 300);
        About->setStyleSheet(QString::fromUtf8("background-color: #f5f5f5; /* \346\265\205\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"color: #333333; /* \346\267\261\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"font-family: \"Segoe UI\", Arial, sans-serif; /* \350\256\276\347\275\256\345\255\227\344\275\223 */\n"
"font-size: 14px; /* \351\273\230\350\256\244\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
""));
        buttonBox = new QDialogButtonBox(About);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(About);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 131, 71));
        label->setStyleSheet(QString::fromUtf8(" QLabel{font-size: 24px; /* \346\233\264\345\244\247\345\255\227\344\275\223 */\n"
"    font-weight: bold; /* \345\212\240\347\262\227 */\n"
"    color: #2980b9; /* \350\223\235\350\211\262\346\226\207\345\255\227 */\n"
"    border-bottom: 2px solid #2980b9; /* \345\272\225\351\203\250\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    padding-bottom: 10px; /* \345\242\236\345\212\240\345\272\225\351\203\250\347\251\272\351\227\264 */\n"
"    margin-bottom: 15px; /* \344\270\216\344\270\213\351\235\242\345\206\205\345\256\271\347\232\204\350\267\235\347\246\273 */\n"
"}\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QLabel:hover {\n"
"    color: #16a085; /* \347\273\277\350\211\262\346\226\207\345\255\227 */\n"
"    text-decoration: underline; /* \346\267\273\345\212\240\344\270\213\345\210\222\347\272\277 */\n"
"}\n"
""));
        horizontalLayoutWidget_2 = new QWidget(About);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(60, 140, 239, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: #2c3e50; /* \346\267\261\350\223\235\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 16px; /* \345\255\227\344\275\223\347\250\215\345\244\247 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    padding: 5px; /* \345\206\205\351\227\264\350\267\235 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	font: 18pt \"\351\232\266\344\271\246\";\n"
"}"));

        horizontalLayout_2->addWidget(label_5);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: #2c3e50; /* \346\267\261\350\223\235\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 16px; /* \345\255\227\344\275\223\347\250\215\345\244\247 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    padding: 5px; /* \345\206\205\351\227\264\350\267\235 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	font: 18pt \"\351\232\266\344\271\246\";\n"
"}"));

        horizontalLayout_2->addWidget(label_4);

        label_2 = new QLabel(About);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 115, 78));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: #2c3e50; /* \346\267\261\350\223\235\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 16px; /* \345\255\227\344\275\223\347\250\215\345\244\247 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    padding: 5px; /* \345\206\205\351\227\264\350\267\235 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	font: 18pt \"\351\232\266\344\271\246\";\n"
"}"));
        label_6 = new QLabel(About);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(130, 70, 161, 78));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: #2c3e50; /* \346\267\261\350\223\235\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 16px; /* \345\255\227\344\275\223\347\250\215\345\244\247 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    padding: 5px; /* \345\206\205\351\227\264\350\267\235 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	font: 18pt \"\351\232\266\344\271\246\";\n"
"}"));
        label_3 = new QLabel(About);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 70, 329, 78));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: #2c3e50; /* \346\267\261\350\223\235\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 16px; /* \345\255\227\344\275\223\347\250\215\345\244\247 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    padding: 5px; /* \345\206\205\351\227\264\350\267\235 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	font: 18pt \"\351\232\266\344\271\246\";\n"
"}"));

        retranslateUi(About);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, About, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, About, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("About", "\345\260\217\347\273\204\346\210\220\345\221\230\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("About", "\345\274\240\346\227\255\346\227\270", nullptr));
        label_4->setText(QCoreApplication::translate("About", "\345\221\250\351\224\246\346\263\275", nullptr));
        label_2->setText(QCoreApplication::translate("About", "\351\251\254\350\276\260\345\256\207", nullptr));
        label_6->setText(QCoreApplication::translate("About", "\346\235\216\347\221\236\346\263\275", nullptr));
        label_3->setText(QCoreApplication::translate("About", "\345\274\240\347\220\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
