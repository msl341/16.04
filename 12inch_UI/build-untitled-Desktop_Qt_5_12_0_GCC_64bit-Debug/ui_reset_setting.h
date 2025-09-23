/********************************************************************************
** Form generated from reading UI file 'reset_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESET_SETTING_H
#define UI_RESET_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "reset_setting.h"

QT_BEGIN_NAMESPACE

class Ui_reset_setting
{
public:
    Label_yes_reset *label_yes;
    QLabel *label_backdrop;
    Label_no_reset *label_no;
    QLabel *label;
    QLabel *label_num;

    void setupUi(QWidget *reset_setting)
    {
        if (reset_setting->objectName().isEmpty())
            reset_setting->setObjectName(QString::fromUtf8("reset_setting"));
        reset_setting->resize(1280, 800);
        label_yes = new Label_yes_reset(reset_setting);
        label_yes->setObjectName(QString::fromUtf8("label_yes"));
        label_yes->setGeometry(QRect(410, 490, 100, 60));
        label_backdrop = new QLabel(reset_setting);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"color: rgb(255, 255, 255);"));
        label_no = new Label_no_reset(reset_setting);
        label_no->setObjectName(QString::fromUtf8("label_no"));
        label_no->setGeometry(QRect(790, 490, 100, 60));
        label = new QLabel(reset_setting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_num = new QLabel(reset_setting);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 330, 720, 40));
        label_backdrop->raise();
        label->raise();
        label_yes->raise();
        label_no->raise();
        label_num->raise();

        retranslateUi(reset_setting);

        QMetaObject::connectSlotsByName(reset_setting);
    } // setupUi

    void retranslateUi(QWidget *reset_setting)
    {
        reset_setting->setWindowTitle(QApplication::translate("reset_setting", "Form", nullptr));
        label_yes->setText(QApplication::translate("reset_setting", "\346\230\257", nullptr));
        label_backdrop->setText(QString());
        label_no->setText(QApplication::translate("reset_setting", "\345\220\246", nullptr));
        label->setText(QString());
        label_num->setText(QApplication::translate("reset_setting", "\346\230\257\345\220\246\351\207\215\347\275\256\350\256\276\345\256\232\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reset_setting: public Ui_reset_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESET_SETTING_H
