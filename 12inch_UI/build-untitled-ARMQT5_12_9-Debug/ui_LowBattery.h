/********************************************************************************
** Form generated from reading UI file 'LowBattery.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOWBATTERY_H
#define UI_LOWBATTERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LowBattery
{
public:
    QLabel *bkg;
    QPushButton *closeBtn;

    void setupUi(QDialog *LowBattery)
    {
        if (LowBattery->objectName().isEmpty())
            LowBattery->setObjectName(QString::fromUtf8("LowBattery"));
        LowBattery->resize(400, 250);
        bkg = new QLabel(LowBattery);
        bkg->setObjectName(QString::fromUtf8("bkg"));
        bkg->setGeometry(QRect(0, 0, 400, 250));
        QFont font;
        font.setPointSize(18);
        bkg->setFont(font);
        bkg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:45px;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);"));
        bkg->setAlignment(Qt::AlignCenter);
        closeBtn = new QPushButton(LowBattery);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(270, 204, 101, 31));
        QFont font1;
        font1.setPointSize(14);
        closeBtn->setFont(font1);
        closeBtn->setFocusPolicy(Qt::NoFocus);
        closeBtn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: none;\n"
"border:none;"));

        retranslateUi(LowBattery);

        QMetaObject::connectSlotsByName(LowBattery);
    } // setupUi

    void retranslateUi(QDialog *LowBattery)
    {
        LowBattery->setWindowTitle(QApplication::translate("LowBattery", "Dialog", nullptr));
        bkg->setText(QApplication::translate("LowBattery", "Low Battery, please charge", nullptr));
        closeBtn->setText(QApplication::translate("LowBattery", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LowBattery: public Ui_LowBattery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOWBATTERY_H
