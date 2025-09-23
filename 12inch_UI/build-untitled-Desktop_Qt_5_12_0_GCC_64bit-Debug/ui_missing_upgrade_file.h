/********************************************************************************
** Form generated from reading UI file 'missing_upgrade_file.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSING_UPGRADE_FILE_H
#define UI_MISSING_UPGRADE_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_missing_upgrade_file
{
public:
    QLabel *label_backdrop;
    QLabel *label_num;
    QLabel *label;

    void setupUi(QWidget *missing_upgrade_file)
    {
        if (missing_upgrade_file->objectName().isEmpty())
            missing_upgrade_file->setObjectName(QString::fromUtf8("missing_upgrade_file"));
        missing_upgrade_file->resize(1280, 800);
        label_backdrop = new QLabel(missing_upgrade_file);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"color: rgb(255, 255, 255);"));
        label_num = new QLabel(missing_upgrade_file);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 380, 720, 40));
        label = new QLabel(missing_upgrade_file);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label->raise();
        label_backdrop->raise();
        label_num->raise();

        retranslateUi(missing_upgrade_file);

        QMetaObject::connectSlotsByName(missing_upgrade_file);
    } // setupUi

    void retranslateUi(QWidget *missing_upgrade_file)
    {
        missing_upgrade_file->setWindowTitle(QApplication::translate("missing_upgrade_file", "Form", nullptr));
        label_backdrop->setText(QString());
        label_num->setText(QApplication::translate("missing_upgrade_file", "\347\274\272\345\260\221\345\215\207\347\272\247\346\226\207\344\273\266", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class missing_upgrade_file: public Ui_missing_upgrade_file {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSING_UPGRADE_FILE_H
