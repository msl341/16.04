/********************************************************************************
** Form generated from reading UI file 'time_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIME_SETTING_H
#define UI_TIME_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "time_setting.h"

QT_BEGIN_NAMESPACE

class Ui_time_setting
{
public:
    QLabel *label;
    QLabel *label_backdrop;
    Label_return_time *label_return;
    Label_save_time *label_save;
    QLabel *label_num;
    Label_year1_time *label_year1;
    Label_year2_time *label_year2;
    Label_year3_time *label_year3;
    Label_year4_time *label_year4;
    Label_month_time *label_month;
    Label_day_time *label_day;
    Label_hour_time *label_hour;
    Label_minute_time *label_minute;
    Label_up1_time *label_up1;
    Label_up2_time *label_up2;
    Label_up3_time *label_up3;
    Label_down1_time *label_down1;
    Label_down2_time *label_down2;
    Label_down3_time *label_down3;

    void setupUi(QWidget *time_setting)
    {
        if (time_setting->objectName().isEmpty())
            time_setting->setObjectName(QString::fromUtf8("time_setting"));
        time_setting->resize(1280, 800);
        label = new QLabel(time_setting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_backdrop = new QLabel(time_setting);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: rgb(110, 215, 230);"));
        label_return = new Label_return_time(time_setting);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(790, 500, 100, 60));
        label_return->setStyleSheet(QString::fromUtf8(""));
        label_return->setAlignment(Qt::AlignCenter);
        label_save = new Label_save_time(time_setting);
        label_save->setObjectName(QString::fromUtf8("label_save"));
        label_save->setGeometry(QRect(410, 500, 100, 60));
        label_save->setStyleSheet(QString::fromUtf8(""));
        label_save->setAlignment(Qt::AlignCenter);
        label_num = new QLabel(time_setting);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 240, 720, 40));
        label_num->setStyleSheet(QString::fromUtf8(""));
        label_num->setAlignment(Qt::AlignCenter);
        label_year1 = new Label_year1_time(time_setting);
        label_year1->setObjectName(QString::fromUtf8("label_year1"));
        label_year1->setGeometry(QRect(355, 360, 60, 60));
        label_year1->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_year2 = new Label_year2_time(time_setting);
        label_year2->setObjectName(QString::fromUtf8("label_year2"));
        label_year2->setGeometry(QRect(417, 360, 60, 60));
        label_year2->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_year3 = new Label_year3_time(time_setting);
        label_year3->setObjectName(QString::fromUtf8("label_year3"));
        label_year3->setGeometry(QRect(479, 360, 60, 60));
        label_year3->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_year4 = new Label_year4_time(time_setting);
        label_year4->setObjectName(QString::fromUtf8("label_year4"));
        label_year4->setGeometry(QRect(541, 360, 60, 60));
        label_year4->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_month = new Label_month_time(time_setting);
        label_month->setObjectName(QString::fromUtf8("label_month"));
        label_month->setGeometry(QRect(641, 360, 60, 60));
        label_month->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_day = new Label_day_time(time_setting);
        label_day->setObjectName(QString::fromUtf8("label_day"));
        label_day->setGeometry(QRect(703, 360, 60, 60));
        label_day->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_hour = new Label_hour_time(time_setting);
        label_hour->setObjectName(QString::fromUtf8("label_hour"));
        label_hour->setGeometry(QRect(803, 360, 60, 60));
        label_hour->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_minute = new Label_minute_time(time_setting);
        label_minute->setObjectName(QString::fromUtf8("label_minute"));
        label_minute->setGeometry(QRect(865, 360, 60, 60));
        label_minute->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_up1 = new Label_up1_time(time_setting);
        label_up1->setObjectName(QString::fromUtf8("label_up1"));
        label_up1->setGeometry(QRect(448, 295, 60, 60));
        label_up1->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_up2 = new Label_up2_time(time_setting);
        label_up2->setObjectName(QString::fromUtf8("label_up2"));
        label_up2->setGeometry(QRect(672, 295, 60, 60));
        label_up2->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_up3 = new Label_up3_time(time_setting);
        label_up3->setObjectName(QString::fromUtf8("label_up3"));
        label_up3->setGeometry(QRect(832, 295, 60, 60));
        label_up3->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_down1 = new Label_down1_time(time_setting);
        label_down1->setObjectName(QString::fromUtf8("label_down1"));
        label_down1->setGeometry(QRect(448, 425, 60, 60));
        label_down1->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_down2 = new Label_down2_time(time_setting);
        label_down2->setObjectName(QString::fromUtf8("label_down2"));
        label_down2->setGeometry(QRect(672, 425, 60, 60));
        label_down2->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));
        label_down3 = new Label_down3_time(time_setting);
        label_down3->setObjectName(QString::fromUtf8("label_down3"));
        label_down3->setGeometry(QRect(832, 425, 60, 60));
        label_down3->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 167, 242);"));

        retranslateUi(time_setting);

        QMetaObject::connectSlotsByName(time_setting);
    } // setupUi

    void retranslateUi(QWidget *time_setting)
    {
        time_setting->setWindowTitle(QApplication::translate("time_setting", "Form", nullptr));
        label->setText(QString());
        label_backdrop->setText(QString());
        label_return->setText(QApplication::translate("time_setting", "\351\200\200\345\207\272", nullptr));
        label_save->setText(QApplication::translate("time_setting", "\344\277\235\345\255\230", nullptr));
        label_num->setText(QApplication::translate("time_setting", "\346\227\266\351\227\264\350\256\276\347\275\256", nullptr));
        label_year1->setText(QApplication::translate("time_setting", "1", nullptr));
        label_year2->setText(QApplication::translate("time_setting", "1", nullptr));
        label_year3->setText(QApplication::translate("time_setting", "1", nullptr));
        label_year4->setText(QApplication::translate("time_setting", "1", nullptr));
        label_month->setText(QApplication::translate("time_setting", "03", nullptr));
        label_day->setText(QApplication::translate("time_setting", "21", nullptr));
        label_hour->setText(QApplication::translate("time_setting", "11", nullptr));
        label_minute->setText(QApplication::translate("time_setting", "00", nullptr));
        label_up1->setText(QApplication::translate("time_setting", "+", nullptr));
        label_up2->setText(QApplication::translate("time_setting", "+", nullptr));
        label_up3->setText(QApplication::translate("time_setting", "+", nullptr));
        label_down1->setText(QApplication::translate("time_setting", "-", nullptr));
        label_down2->setText(QApplication::translate("time_setting", "-", nullptr));
        label_down3->setText(QApplication::translate("time_setting", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class time_setting: public Ui_time_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIME_SETTING_H
