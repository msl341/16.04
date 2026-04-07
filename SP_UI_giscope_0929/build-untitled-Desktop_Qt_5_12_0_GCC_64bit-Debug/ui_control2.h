/********************************************************************************
** Form generated from reading UI file 'control2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL2_H
#define UI_CONTROL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_control2
{
public:
    QLabel *label_versions;
    QLabel *label;
    QLabel *label_versions_num;
    QLabel *labelw_time;
    QLabel *label_timenum;
    QLabel *labelw_number;
    QLabel *label_use_num;
    QWidget *widget;
    QLabel *small;
    QLabel *small2;
    QLabel *small3;
    QLabel *small4;

    void setupUi(QWidget *control2)
    {
        if (control2->objectName().isEmpty())
            control2->setObjectName(QString::fromUtf8("control2"));
        control2->resize(1920, 1080);
        label_versions = new QLabel(control2);
        label_versions->setObjectName(QString::fromUtf8("label_versions"));
        label_versions->setGeometry(QRect(19, 950, 81, 40));
        label_versions->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_versions->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(control2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/1920.png);"));
        label_versions_num = new QLabel(control2);
        label_versions_num->setObjectName(QString::fromUtf8("label_versions_num"));
        label_versions_num->setGeometry(QRect(100, 960, 90, 20));
        label_versions_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labelw_time = new QLabel(control2);
        labelw_time->setObjectName(QString::fromUtf8("labelw_time"));
        labelw_time->setGeometry(QRect(50, 230, 70, 40));
        labelw_time->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labelw_time->setAlignment(Qt::AlignCenter);
        label_timenum = new QLabel(control2);
        label_timenum->setObjectName(QString::fromUtf8("label_timenum"));
        label_timenum->setGeometry(QRect(130, 240, 140, 30));
        label_timenum->setLayoutDirection(Qt::RightToLeft);
        label_timenum->setStyleSheet(QString::fromUtf8(""));
        labelw_number = new QLabel(control2);
        labelw_number->setObjectName(QString::fromUtf8("labelw_number"));
        labelw_number->setGeometry(QRect(50, 280, 70, 40));
        labelw_number->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labelw_number->setAlignment(Qt::AlignCenter);
        label_use_num = new QLabel(control2);
        label_use_num->setObjectName(QString::fromUtf8("label_use_num"));
        label_use_num->setGeometry(QRect(130, 280, 70, 40));
        label_use_num->setLayoutDirection(Qt::RightToLeft);
        label_use_num->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(control2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(340, 20, 300, 1053));
        small = new QLabel(widget);
        small->setObjectName(QString::fromUtf8("small"));
        small->setGeometry(QRect(10, 0, 285, 246));
        small->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/smallk.png);"));
        small2 = new QLabel(widget);
        small2->setObjectName(QString::fromUtf8("small2"));
        small2->setGeometry(QRect(10, 260, 285, 246));
        small2->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/smallk.png);"));
        small3 = new QLabel(widget);
        small3->setObjectName(QString::fromUtf8("small3"));
        small3->setGeometry(QRect(10, 520, 285, 246));
        small3->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/smallk.png);"));
        small4 = new QLabel(widget);
        small4->setObjectName(QString::fromUtf8("small4"));
        small4->setGeometry(QRect(10, 780, 285, 246));
        small4->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/smallk.png);"));
        label->raise();
        label_versions->raise();
        label_versions_num->raise();
        labelw_time->raise();
        label_timenum->raise();
        labelw_number->raise();
        label_use_num->raise();
        widget->raise();

        retranslateUi(control2);

        QMetaObject::connectSlotsByName(control2);
    } // setupUi

    void retranslateUi(QWidget *control2)
    {
        control2->setWindowTitle(QApplication::translate("control2", "Form", nullptr));
        label_versions->setText(QApplication::translate("control2", "\347\211\210\346\234\254\344\277\241\346\201\257\357\274\232", nullptr));
        label->setText(QString());
        label_versions_num->setText(QApplication::translate("control2", "SPv4.30823", nullptr));
        labelw_time->setText(QApplication::translate("control2", "\344\275\277\347\224\250\346\227\266\351\225\277:", nullptr));
        label_timenum->setText(QString());
        labelw_number->setText(QApplication::translate("control2", "\344\275\277\347\224\250\346\254\241\346\225\260:", nullptr));
        label_use_num->setText(QApplication::translate("control2", "1", nullptr));
        small->setText(QString());
        small2->setText(QString());
        small3->setText(QString());
        small4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class control2: public Ui_control2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL2_H
