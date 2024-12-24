/********************************************************************************
** Form generated from reading UI file 'heatmap.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEATMAP_H
#define UI_HEATMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeatMap
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *HeatMap)
    {
        if (HeatMap->objectName().isEmpty())
            HeatMap->setObjectName("HeatMap");
        HeatMap->resize(400, 300);
        buttonBox = new QDialogButtonBox(HeatMap);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        verticalLayoutWidget = new QWidget(HeatMap);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, 9, 401, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(HeatMap);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HeatMap, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HeatMap, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HeatMap);
    } // setupUi

    void retranslateUi(QDialog *HeatMap)
    {
        HeatMap->setWindowTitle(QCoreApplication::translate("HeatMap", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeatMap: public Ui_HeatMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEATMAP_H
