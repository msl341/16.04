/********************************************************************************
** Form generated from reading UI file 'version_number.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSION_NUMBER_H
#define UI_VERSION_NUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "version_number.h"

QT_BEGIN_NAMESPACE

class Ui_version_number
{
public:
    QLabel *label_num;
    Label_version_return *label_return;
    QLabel *label_backdrop;
    QLabel *label;
    QLabel *label_version;
    Label_version_update *label_update;

    void setupUi(QWidget *version_number)
    {
        if (version_number->objectName().isEmpty())
            version_number->setObjectName(QString::fromUtf8("version_number"));
        version_number->resize(1280, 800);
        label_num = new QLabel(version_number);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 380, 720, 50));
        label_return = new Label_version_return(version_number);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(380, 490, 100, 60));
        label_return->setAlignment(Qt::AlignCenter);
        label_backdrop = new QLabel(version_number);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(version_number);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_version = new QLabel(version_number);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setGeometry(QRect(280, 260, 720, 40));
        label_update = new Label_version_update(version_number);
        label_update->setObjectName(QString::fromUtf8("label_update"));
        label_update->setGeometry(QRect(800, 490, 100, 60));
        label_update->setAlignment(Qt::AlignCenter);
        label->raise();
        label_backdrop->raise();
        label_num->raise();
        label_return->raise();
        label_version->raise();
        label_update->raise();

        retranslateUi(version_number);

        QMetaObject::connectSlotsByName(version_number);
    } // setupUi

    void retranslateUi(QWidget *version_number)
    {
        version_number->setWindowTitle(QApplication::translate("version_number", "Form", nullptr));
        label_num->setText(QApplication::translate("version_number", "AIOC12 v1.1.5_250612", nullptr));
        label_return->setText(QApplication::translate("version_number", "\351\200\200\345\207\272", nullptr));
        label_backdrop->setText(QString());
        label->setText(QString());
        label_version->setText(QApplication::translate("version_number", "\345\275\223\345\211\215\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
        label_update->setText(QApplication::translate("version_number", "\345\215\207\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class version_number: public Ui_version_number {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSION_NUMBER_H
