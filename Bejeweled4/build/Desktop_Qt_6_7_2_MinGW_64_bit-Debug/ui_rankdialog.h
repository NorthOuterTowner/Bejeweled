/********************************************************************************
** Form generated from reading UI file 'rankdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKDIALOG_H
#define UI_RANKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_RankDialog
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QDialog *RankDialog)
    {
        if (RankDialog->objectName().isEmpty())
            RankDialog->setObjectName("RankDialog");
        RankDialog->resize(863, 610);
        pushButton = new QPushButton(RankDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(710, 540, 121, 61));
        pushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"Microsoft YaHei UI\";"));
        tableWidget = new QTableWidget(RankDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 140, 741, 371));
        label = new QLabel(RankDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 451, 81));
        label->setStyleSheet(QString::fromUtf8("font: 50pt \"\346\245\267\344\275\223\";\n"
"color: rgb(255, 85, 0);"));

        retranslateUi(RankDialog);

        QMetaObject::connectSlotsByName(RankDialog);
    } // setupUi

    void retranslateUi(QDialog *RankDialog)
    {
        RankDialog->setWindowTitle(QCoreApplication::translate("RankDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("RankDialog", "Quit", nullptr));
        label->setText(QCoreApplication::translate("RankDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankDialog: public Ui_RankDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKDIALOG_H
