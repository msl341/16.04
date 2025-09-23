/********************************************************************************
** Form generated from reading UI file 'no_memory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NO_MEMORY_H
#define UI_NO_MEMORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_no_memory
{
public:
    QLabel *label_num;
    QLabel *label_b;
    QLabel *label_backdrop;
    QLabel *label;

    void setupUi(QWidget *no_memory)
    {
        if (no_memory->objectName().isEmpty())
            no_memory->setObjectName(QString::fromUtf8("no_memory"));
        no_memory->resize(1280, 800);
        label_num = new QLabel(no_memory);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 450, 720, 80));
        label_b = new QLabel(no_memory);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 800));
        label_b->setStyleSheet(QString::fromUtf8(""));
        label_backdrop = new QLabel(no_memory);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(no_memory);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(565, 250, 150, 150));
        label->setStyleSheet(QString::fromUtf8("image: url(:/tu/warn.png);"));
        label_b->raise();
        label_backdrop->raise();
        label->raise();
        label_num->raise();

        retranslateUi(no_memory);

        QMetaObject::connectSlotsByName(no_memory);
    } // setupUi

    void retranslateUi(QWidget *no_memory)
    {
        no_memory->setWindowTitle(QApplication::translate("no_memory", "Form", nullptr));
        label_num->setText(QApplication::translate("no_memory", "\345\255\230\345\202\250\350\256\276\345\244\207\347\251\272\351\227\264\344\270\215\350\266\263", nullptr));
        label_b->setText(QString());
        label_backdrop->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class no_memory: public Ui_no_memory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NO_MEMORY_H
