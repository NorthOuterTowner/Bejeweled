/********************************************************************************
** Form generated from reading UI file 'rankdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKDIALOG_H
#define UI_RANKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_RankDialog
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *RankDialog)
    {
        if (RankDialog->objectName().isEmpty())
            RankDialog->setObjectName("RankDialog");
        RankDialog->resize(850, 593);
        pushButton = new QPushButton(RankDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(660, 510, 121, 61));
        tableWidget = new QTableWidget(RankDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 80, 741, 371));

        retranslateUi(RankDialog);

        QMetaObject::connectSlotsByName(RankDialog);
    } // setupUi

    void retranslateUi(QDialog *RankDialog)
    {
        RankDialog->setWindowTitle(QCoreApplication::translate("RankDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("RankDialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankDialog: public Ui_RankDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKDIALOG_H
