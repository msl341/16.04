/********************************************************************************
** Form generated from reading UI file 'photo_browse_single.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTO_BROWSE_SINGLE_H
#define UI_PHOTO_BROWSE_SINGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "photo_browse_single.h"

QT_BEGIN_NAMESPACE

class Ui_photo_browse_single
{
public:
    Label_delete_ps *label_delete;
    Label_return_ps *label_return;
    Label_screen *label_screen;
    Label_left_ps *label_left;
    Label_right_ps *label_right;
    QLabel *label_b;
    Label_full_screen *label_full_screen;

    void setupUi(QWidget *photo_browse_single)
    {
        if (photo_browse_single->objectName().isEmpty())
            photo_browse_single->setObjectName(QString::fromUtf8("photo_browse_single"));
        photo_browse_single->resize(1280, 800);
        label_delete = new Label_delete_ps(photo_browse_single);
        label_delete->setObjectName(QString::fromUtf8("label_delete"));
        label_delete->setGeometry(QRect(1120, 700, 142, 88));
        label_delete->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/delete.png);"));
        label_return = new Label_return_ps(photo_browse_single);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(1140, 20, 122, 74));
        label_return->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/return.png);"));
        label_screen = new Label_screen(photo_browse_single);
        label_screen->setObjectName(QString::fromUtf8("label_screen"));
        label_screen->setGeometry(QRect(180, 80, 920, 630));
        label_screen->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_left = new Label_left_ps(photo_browse_single);
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_left->setGeometry(QRect(50, 298, 54, 205));
        label_left->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/left.png);"));
        label_right = new Label_right_ps(photo_browse_single);
        label_right->setObjectName(QString::fromUtf8("label_right"));
        label_right->setGeometry(QRect(1176, 298, 54, 205));
        label_right->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/right.png);"));
        label_b = new QLabel(photo_browse_single);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 800));
        label_b->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_full_screen = new Label_full_screen(photo_browse_single);
        label_full_screen->setObjectName(QString::fromUtf8("label_full_screen"));
        label_full_screen->setGeometry(QRect(0, 0, 1280, 800));
        label_full_screen->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_full_screen->raise();
        label_b->raise();
        label_delete->raise();
        label_return->raise();
        label_screen->raise();
        label_left->raise();
        label_right->raise();

        retranslateUi(photo_browse_single);

        QMetaObject::connectSlotsByName(photo_browse_single);
    } // setupUi

    void retranslateUi(QWidget *photo_browse_single)
    {
        photo_browse_single->setWindowTitle(QApplication::translate("photo_browse_single", "Form", nullptr));
        label_delete->setText(QString());
        label_return->setText(QString());
        label_screen->setText(QString());
        label_left->setText(QString());
        label_right->setText(QString());
        label_b->setText(QString());
        label_full_screen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class photo_browse_single: public Ui_photo_browse_single {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTO_BROWSE_SINGLE_H
