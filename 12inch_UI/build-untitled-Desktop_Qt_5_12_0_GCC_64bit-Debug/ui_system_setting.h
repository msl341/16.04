/********************************************************************************
** Form generated from reading UI file 'system_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_SETTING_H
#define UI_SYSTEM_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "system_setting.h"

QT_BEGIN_NAMESPACE

class Ui_system_setting
{
public:
    QLabel *label_b;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    Label_formatting *label_formatting;
    Label_reset *label_reset;
    Label_versions *label_versions;
    Label_time *label_time;
    Label_language *label_language;
    Label_return *label_return;
    QPushButton *nameBtnFormat;
    QPushButton *nameBtnReset;
    QPushButton *nameBtnVersion;
    QPushButton *nameBtnTimeSet;
    QPushButton *nameBtnLanSet;
    QPushButton *nameBtnLanSet_2;

    void setupUi(QWidget *system_setting)
    {
        if (system_setting->objectName().isEmpty())
            system_setting->setObjectName(QString::fromUtf8("system_setting"));
        system_setting->resize(1280, 800);
        system_setting->setStyleSheet(QString::fromUtf8(""));
        label_b = new QLabel(system_setting);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 805));
        label_b->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/BKG.png);"));
        layoutWidget = new QWidget(system_setting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 70, 1081, 681));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_formatting = new Label_formatting(layoutWidget);
        label_formatting->setObjectName(QString::fromUtf8("label_formatting"));
        label_formatting->setMinimumSize(QSize(290, 290));
        label_formatting->setMaximumSize(QSize(290, 290));
        label_formatting->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_formatting->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_format.png")));
        label_formatting->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_formatting, 0, 0, 1, 1);

        label_reset = new Label_reset(layoutWidget);
        label_reset->setObjectName(QString::fromUtf8("label_reset"));
        label_reset->setMaximumSize(QSize(290, 290));
        label_reset->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_reset->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_reset.png")));
        label_reset->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_reset, 0, 1, 1, 1);

        label_versions = new Label_versions(layoutWidget);
        label_versions->setObjectName(QString::fromUtf8("label_versions"));
        label_versions->setMaximumSize(QSize(290, 290));
        label_versions->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_versions->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_info.png")));
        label_versions->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_versions, 0, 2, 1, 1);

        label_time = new Label_time(layoutWidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setMaximumSize(QSize(16777215, 290));
        label_time->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_time->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_time.png")));
        label_time->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_time, 1, 0, 1, 1);

        label_language = new Label_language(layoutWidget);
        label_language->setObjectName(QString::fromUtf8("label_language"));
        label_language->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_language->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_language.png")));
        label_language->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_language, 1, 1, 1, 1);

        label_return = new Label_return(layoutWidget);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_return->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_back.png")));
        label_return->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_return, 1, 2, 1, 1);

        gridLayout->setColumnMinimumWidth(0, 290);
        gridLayout->setColumnMinimumWidth(1, 290);
        gridLayout->setColumnMinimumWidth(2, 290);
        gridLayout->setRowMinimumHeight(0, 290);
        gridLayout->setRowMinimumHeight(1, 290);
        nameBtnFormat = new QPushButton(system_setting);
        nameBtnFormat->setObjectName(QString::fromUtf8("nameBtnFormat"));
        nameBtnFormat->setGeometry(QRect(140, 330, 290, 40));
        QFont font;
        font.setPointSize(20);
        nameBtnFormat->setFont(font);
        nameBtnFormat->setFocusPolicy(Qt::NoFocus);
        nameBtnFormat->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnFormat->setFlat(true);
        nameBtnReset = new QPushButton(system_setting);
        nameBtnReset->setObjectName(QString::fromUtf8("nameBtnReset"));
        nameBtnReset->setGeometry(QRect(485, 330, 290, 40));
        nameBtnReset->setFont(font);
        nameBtnReset->setFocusPolicy(Qt::NoFocus);
        nameBtnReset->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnReset->setFlat(true);
        nameBtnVersion = new QPushButton(system_setting);
        nameBtnVersion->setObjectName(QString::fromUtf8("nameBtnVersion"));
        nameBtnVersion->setGeometry(QRect(830, 330, 290, 40));
        nameBtnVersion->setFont(font);
        nameBtnVersion->setFocusPolicy(Qt::NoFocus);
        nameBtnVersion->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnVersion->setFlat(true);
        nameBtnTimeSet = new QPushButton(system_setting);
        nameBtnTimeSet->setObjectName(QString::fromUtf8("nameBtnTimeSet"));
        nameBtnTimeSet->setGeometry(QRect(140, 660, 290, 40));
        nameBtnTimeSet->setFont(font);
        nameBtnTimeSet->setFocusPolicy(Qt::NoFocus);
        nameBtnTimeSet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnTimeSet->setFlat(true);
        nameBtnLanSet = new QPushButton(system_setting);
        nameBtnLanSet->setObjectName(QString::fromUtf8("nameBtnLanSet"));
        nameBtnLanSet->setGeometry(QRect(485, 660, 290, 40));
        nameBtnLanSet->setFont(font);
        nameBtnLanSet->setFocusPolicy(Qt::NoFocus);
        nameBtnLanSet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnLanSet->setFlat(true);
        nameBtnLanSet_2 = new QPushButton(system_setting);
        nameBtnLanSet_2->setObjectName(QString::fromUtf8("nameBtnLanSet_2"));
        nameBtnLanSet_2->setGeometry(QRect(830, 660, 290, 40));
        nameBtnLanSet_2->setFont(font);
        nameBtnLanSet_2->setFocusPolicy(Qt::NoFocus);
        nameBtnLanSet_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnLanSet_2->setFlat(true);

        retranslateUi(system_setting);

        QMetaObject::connectSlotsByName(system_setting);
    } // setupUi

    void retranslateUi(QWidget *system_setting)
    {
        system_setting->setWindowTitle(QApplication::translate("system_setting", "Form", nullptr));
        label_b->setText(QString());
        label_formatting->setText(QString());
        label_reset->setText(QString());
        label_versions->setText(QString());
        label_time->setText(QString());
        label_language->setText(QString());
        label_return->setText(QString());
        nameBtnFormat->setText(QApplication::translate("system_setting", "Format", nullptr));
        nameBtnReset->setText(QApplication::translate("system_setting", "Reset", nullptr));
        nameBtnVersion->setText(QApplication::translate("system_setting", "Version Info", nullptr));
        nameBtnTimeSet->setText(QApplication::translate("system_setting", "Time Set", nullptr));
        nameBtnLanSet->setText(QApplication::translate("system_setting", "Language Set", nullptr));
        nameBtnLanSet_2->setText(QApplication::translate("system_setting", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class system_setting: public Ui_system_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_SETTING_H
