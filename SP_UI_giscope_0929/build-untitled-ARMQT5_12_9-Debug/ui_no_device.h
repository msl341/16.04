/********************************************************************************
** Form generated from reading UI file 'no_device.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NO_DEVICE_H
#define UI_NO_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_no_device
{
public:
    QLabel *label_b;
    QLabel *label_backdrop;
    QLabel *label_num;
    QLabel *label;

    void setupUi(QWidget *no_device)
    {
        if (no_device->objectName().isEmpty())
            no_device->setObjectName(QString::fromUtf8("no_device"));
        no_device->resize(1280, 800);
        no_device->setStyleSheet(QString::fromUtf8(""));
        label_b = new QLabel(no_device);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 800));
        label_b->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/background.png);"));
        label_backdrop = new QLabel(no_device);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: rgb(110, 215, 230);"));
        label_num = new QLabel(no_device);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 450, 720, 80));
        label = new QLabel(no_device);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(565, 250, 150, 150));
        label->setStyleSheet(QString::fromUtf8("image: url(:/tu/warn.png);"));

        retranslateUi(no_device);

        QMetaObject::connectSlotsByName(no_device);
    } // setupUi

    void retranslateUi(QWidget *no_device)
    {
        no_device->setWindowTitle(QApplication::translate("no_device", "Form", nullptr));
        label_b->setText(QString());
        label_backdrop->setText(QString());
        label_num->setText(QApplication::translate("no_device", "\346\227\240\350\256\276\345\244\207\351\223\276\346\216\245    \350\257\267\346\216\245\345\205\245\350\256\276\345\244\207", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class no_device: public Ui_no_device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NO_DEVICE_H
