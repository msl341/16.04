/********************************************************************************
** Form generated from reading UI file 'system_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_SETTING_H
#define UI_SYSTEM_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "system_setting.h"

QT_BEGIN_NAMESPACE

class Ui_system_setting
{
public:
    Label_formatting *label_formatting;
    Label_reset *label_reset;
    Label_time *label_time;
    Label_language *label_language;
    Label_return *label_return;
    Label_versions *label_versions;
    QLabel *label_b;

    void setupUi(QWidget *system_setting)
    {
        if (system_setting->objectName().isEmpty())
            system_setting->setObjectName(QString::fromUtf8("system_setting"));
        system_setting->resize(1280, 800);
        system_setting->setStyleSheet(QString::fromUtf8(""));
        label_formatting = new Label_formatting(system_setting);
        label_formatting->setObjectName(QString::fromUtf8("label_formatting"));
        label_formatting->setGeometry(QRect(100, 80, 360, 320));
        label_formatting->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/format.png);"));
        label_reset = new Label_reset(system_setting);
        label_reset->setObjectName(QString::fromUtf8("label_reset"));
        label_reset->setGeometry(QRect(460, 80, 360, 320));
        label_reset->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/reset.png);"));
        label_time = new Label_time(system_setting);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(100, 430, 360, 320));
        label_time->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/timeset.png);"));
        label_language = new Label_language(system_setting);
        label_language->setObjectName(QString::fromUtf8("label_language"));
        label_language->setGeometry(QRect(460, 430, 360, 320));
        label_language->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/languageset.png);"));
        label_return = new Label_return(system_setting);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(820, 430, 360, 320));
        label_return->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/return.png);"));
        label_versions = new Label_versions(system_setting);
        label_versions->setObjectName(QString::fromUtf8("label_versions"));
        label_versions->setGeometry(QRect(820, 80, 360, 320));
        label_versions->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/versioninfo.png);"));
        label_b = new QLabel(system_setting);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 800));
        label_b->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/background.png);"));
        label_b->raise();
        label_formatting->raise();
        label_reset->raise();
        label_time->raise();
        label_language->raise();
        label_return->raise();
        label_versions->raise();

        retranslateUi(system_setting);

        QMetaObject::connectSlotsByName(system_setting);
    } // setupUi

    void retranslateUi(QWidget *system_setting)
    {
        system_setting->setWindowTitle(QApplication::translate("system_setting", "Form", nullptr));
        label_formatting->setText(QString());
        label_reset->setText(QString());
        label_time->setText(QString());
        label_language->setText(QString());
        label_return->setText(QString());
        label_versions->setText(QString());
        label_b->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class system_setting: public Ui_system_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_SETTING_H
