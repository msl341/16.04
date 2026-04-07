/********************************************************************************
** Form generated from reading UI file 'sensor_restart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_RESTART_H
#define UI_SENSOR_RESTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "sensor_restart.h"

QT_BEGIN_NAMESPACE

class Ui_sensor_restart
{
public:
    QLabel *label_b;
    QLabel *label;
    QLabel *label_num1;
    QLabel *label_num2;
    QLabel *label_2;
    Label_sensor *label_ok;

    void setupUi(QWidget *sensor_restart)
    {
        if (sensor_restart->objectName().isEmpty())
            sensor_restart->setObjectName(QString::fromUtf8("sensor_restart"));
        sensor_restart->resize(1280, 800);
        label_b = new QLabel(sensor_restart);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(280, 220, 720, 360));
        label_b->setStyleSheet(QString::fromUtf8("background-color: rgb(110, 215, 230);"));
        label = new QLabel(sensor_restart);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_num1 = new QLabel(sensor_restart);
        label_num1->setObjectName(QString::fromUtf8("label_num1"));
        label_num1->setGeometry(QRect(280, 440, 720, 50));
        label_num2 = new QLabel(sensor_restart);
        label_num2->setObjectName(QString::fromUtf8("label_num2"));
        label_num2->setGeometry(QRect(280, 380, 720, 50));
        label_2 = new QLabel(sensor_restart);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(575, 250, 120, 120));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/tu/warn.png);"));
        label_ok = new Label_sensor(sensor_restart);
        label_ok->setObjectName(QString::fromUtf8("label_ok"));
        label_ok->setGeometry(QRect(585, 510, 100, 60));
        label_ok->setAlignment(Qt::AlignCenter);
        label->raise();
        label_b->raise();
        label_num1->raise();
        label_num2->raise();
        label_2->raise();
        label_ok->raise();

        retranslateUi(sensor_restart);

        QMetaObject::connectSlotsByName(sensor_restart);
    } // setupUi

    void retranslateUi(QWidget *sensor_restart)
    {
        sensor_restart->setWindowTitle(QApplication::translate("sensor_restart", "Form", nullptr));
        label_b->setText(QString());
        label->setText(QString());
        label_num1->setText(QApplication::translate("sensor_restart", "\344\270\272\347\241\256\344\277\235\346\255\243\345\270\270\344\275\277\347\224\250\350\257\267\346\213\224\345\207\272\345\205\266\344\270\255\344\270\200\346\235\241\346\211\213\346\237\204\351\207\215\345\220\257\357\274\201", nullptr));
        label_num2->setText(QApplication::translate("sensor_restart", "\346\243\200\346\265\213\345\210\260\345\267\262\346\217\222\345\205\245\344\270\211\346\235\241\346\211\213\346\237\204", nullptr));
        label_2->setText(QString());
        label_ok->setText(QApplication::translate("sensor_restart", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sensor_restart: public Ui_sensor_restart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_RESTART_H
