/********************************************************************************
** Form generated from reading UI file 'pausewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEWIDGET_H
#define UI_PAUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(800, 600);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 100, 121, 31));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 40, 121, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: italic 18pt \"Monotype Corsiva\";\n"
"    border: 1px solid #ddd;         /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 5px;             /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QLabel[alignment=\"center\"] {\n"
"    text-align: center;             /* \346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"}"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "\346\201\242\345\244\215\346\270\270\346\210\217", nullptr));
        label->setText(QCoreApplication::translate("Form", "\346\270\270\346\210\217\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWIDGET_H
