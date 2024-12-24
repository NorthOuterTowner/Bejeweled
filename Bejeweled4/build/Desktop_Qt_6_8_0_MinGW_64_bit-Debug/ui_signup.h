/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QLabel *label_image;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_username;
    QLabel *label_4;
    QLineEdit *lineEdit_passwd;
    QLabel *label_5;
    QLineEdit *lineEdit_surepasswd;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QPushButton *btn_return;

    void setupUi(QWidget *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(745, 486);
        Signup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_image = new QLabel(Signup);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(50, 0, 261, 481));
        label = new QLabel(Signup);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 40, 161, 31));
        label->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";"));
        label_2 = new QLabel(Signup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 70, 301, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";"));
        layoutWidget = new QWidget(Signup);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(370, 140, 291, 309));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(label_3);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(lineEdit_username);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(label_4);

        lineEdit_passwd = new QLineEdit(layoutWidget);
        lineEdit_passwd->setObjectName("lineEdit_passwd");
        lineEdit_passwd->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(lineEdit_passwd);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(label_5);

        lineEdit_surepasswd = new QLineEdit(layoutWidget);
        lineEdit_surepasswd->setObjectName("lineEdit_surepasswd");
        lineEdit_surepasswd->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(lineEdit_surepasswd);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));

        verticalLayout_2->addWidget(pushButton_2);

        btn_return = new QPushButton(layoutWidget);
        btn_return->setObjectName("btn_return");
        btn_return->setMinimumSize(QSize(0, 40));
        btn_return->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));

        verticalLayout_2->addWidget(btn_return);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QWidget *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Form", nullptr));
        label_image->setText(QCoreApplication::translate("Signup", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Signup", "Hello", nullptr));
        label_2->setText(QCoreApplication::translate("Signup", "Welcome to us!", nullptr));
        label_3->setText(QCoreApplication::translate("Signup", "Username", nullptr));
        label_4->setText(QCoreApplication::translate("Signup", "Password", nullptr));
        label_5->setText(QCoreApplication::translate("Signup", "Ensure your password\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Signup", "Sure", nullptr));
        btn_return->setText(QCoreApplication::translate("Signup", "Return login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
