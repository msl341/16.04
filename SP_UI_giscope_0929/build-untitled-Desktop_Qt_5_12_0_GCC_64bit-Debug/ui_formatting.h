/********************************************************************************
** Form generated from reading UI file 'formatting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATTING_H
#define UI_FORMATTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "formatting.h"

QT_BEGIN_NAMESPACE

class Ui_formatting
{
public:
    QLabel *label;
    Label_yes_format *label_yes;
    QLabel *label_backdrop;
    QLabel *label_num;
    Label_no_format *label_no;

    void setupUi(QWidget *formatting)
    {
        if (formatting->objectName().isEmpty())
            formatting->setObjectName(QString::fromUtf8("formatting"));
        formatting->resize(1280, 800);
        label = new QLabel(formatting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_yes = new Label_yes_format(formatting);
        label_yes->setObjectName(QString::fromUtf8("label_yes"));
        label_yes->setGeometry(QRect(410, 490, 100, 60));
        label_backdrop = new QLabel(formatting);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: rgb(110, 215, 230);"));
        label_num = new QLabel(formatting);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 330, 720, 40));
        label_no = new Label_no_format(formatting);
        label_no->setObjectName(QString::fromUtf8("label_no"));
        label_no->setGeometry(QRect(790, 490, 100, 60));
        label->raise();
        label_backdrop->raise();
        label_yes->raise();
        label_num->raise();
        label_no->raise();

        retranslateUi(formatting);

        QMetaObject::connectSlotsByName(formatting);
    } // setupUi

    void retranslateUi(QWidget *formatting)
    {
        formatting->setWindowTitle(QApplication::translate("formatting", "Form", nullptr));
        label->setText(QString());
        label_yes->setText(QApplication::translate("formatting", "\346\230\257", nullptr));
        label_backdrop->setText(QString());
        label_num->setText(QApplication::translate("formatting", "\346\230\257\345\220\246\350\277\233\350\241\214\346\240\274\345\274\217\345\214\226\357\274\237", nullptr));
        label_no->setText(QApplication::translate("formatting", "\345\220\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formatting: public Ui_formatting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATTING_H
