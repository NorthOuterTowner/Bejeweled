/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
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
    QLabel *label;
    QPushButton *returnButton;
    QPushButton *resumeButton;

    void setupUi(QWidget *Pause)
    {
        if (Pause->objectName().isEmpty())
            Pause->setObjectName("Pause");
        Pause->resize(800, 600);
        label = new QLabel(Pause);
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
        returnButton = new QPushButton(Pause);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(340, 150, 121, 31));
        resumeButton = new QPushButton(Pause);
        resumeButton->setObjectName("resumeButton");
        resumeButton->setGeometry(QRect(340, 100, 121, 31));

        retranslateUi(Pause);

        QMetaObject::connectSlotsByName(Pause);
    } // setupUi

    void retranslateUi(QWidget *Pause)
    {
        Pause->setWindowTitle(QCoreApplication::translate("Pause", "Form", nullptr));
        label->setText(QCoreApplication::translate("Pause", "\346\270\270\346\210\217\346\232\202\345\201\234", nullptr));
        returnButton->setText(QCoreApplication::translate("Pause", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        resumeButton->setText(QCoreApplication::translate("Pause", "\346\201\242\345\244\215\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pause: public Ui_Pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
