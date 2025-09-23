/********************************************************************************
** Form generated from reading UI file 'PickPhotoItem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKPHOTOITEM_H
#define UI_PICKPHOTOITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PickPhotoItem
{
public:
    QPushButton *pickPhoto;
    QLabel *selectedIcon;

    void setupUi(QWidget *PickPhotoItem)
    {
        if (PickPhotoItem->objectName().isEmpty())
            PickPhotoItem->setObjectName(QString::fromUtf8("PickPhotoItem"));
        PickPhotoItem->resize(150, 110);
        PickPhotoItem->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        pickPhoto = new QPushButton(PickPhotoItem);
        pickPhoto->setObjectName(QString::fromUtf8("pickPhoto"));
        pickPhoto->setGeometry(QRect(0, 0, 140, 100));
        pickPhoto->setFocusPolicy(Qt::NoFocus);
        pickPhoto->setFlat(true);
        selectedIcon = new QLabel(PickPhotoItem);
        selectedIcon->setObjectName(QString::fromUtf8("selectedIcon"));
        selectedIcon->setGeometry(QRect(120, 80, 30, 30));
        selectedIcon->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(115, 210, 22);"));
        selectedIcon->setAlignment(Qt::AlignCenter);

        retranslateUi(PickPhotoItem);

        QMetaObject::connectSlotsByName(PickPhotoItem);
    } // setupUi

    void retranslateUi(QWidget *PickPhotoItem)
    {
        PickPhotoItem->setWindowTitle(QApplication::translate("PickPhotoItem", "Form", nullptr));
        pickPhoto->setText(QString());
        selectedIcon->setText(QApplication::translate("PickPhotoItem", "V", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PickPhotoItem: public Ui_PickPhotoItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKPHOTOITEM_H
