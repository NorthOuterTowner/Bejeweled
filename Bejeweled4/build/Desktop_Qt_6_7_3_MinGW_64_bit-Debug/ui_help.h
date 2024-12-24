/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName("Help");
        Help->resize(400, 300);
        buttonBox = new QDialogButtonBox(Help);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(Help);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 361, 141));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\232\266\344\271\246\";"));

        retranslateUi(Help);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Help, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Help, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Help", "\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232\n"
"\n"
"1.\345\210\206\345\210\253\347\202\271\345\207\273\344\270\244\344\270\252\344\275\240\346\203\263\344\272\244\346\215\242\347\232\204\346\243\213\345\255\220\n"
"2.\351\201\223\345\205\267\351\234\200\350\246\201\345\234\250\345\225\206\345\237\216\350\264\255\344\271\260\n"
"3.\351\227\257\345\205\263\346\250\241\345\274\217\347\247\257\345\210\206\350\276\276\345\210\260\350\246\201\346\261\202\345\215\263\345\217\257\350\277\207\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
