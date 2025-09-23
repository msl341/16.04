/********************************************************************************
** Form generated from reading UI file 'ComfirmDelete.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMFIRMDELETE_H
#define UI_COMFIRMDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComfirmDelete
{
public:
    QLabel *title;
    QPushButton *deleteBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *ComfirmDelete)
    {
        if (ComfirmDelete->objectName().isEmpty())
            ComfirmDelete->setObjectName(QString::fromUtf8("ComfirmDelete"));
        ComfirmDelete->resize(1280, 800);
        ComfirmDelete->setStyleSheet(QString::fromUtf8(""));
        title = new QLabel(ComfirmDelete);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(440, 250, 401, 301));
        QFont font;
        font.setPointSize(24);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:50px;"));
        title->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        title->setWordWrap(false);
        title->setMargin(80);
        deleteBtn = new QPushButton(ComfirmDelete);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setGeometry(QRect(720, 490, 89, 31));
        deleteBtn->setFocusPolicy(Qt::NoFocus);
        deleteBtn->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"border:none;\n"
"border-radius:10px;\n"
"background-color: rgb(239, 41, 41);\n"
"color: rgb(255, 255, 255);"));
        cancelBtn = new QPushButton(ComfirmDelete);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(490, 490, 89, 30));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"border:none;\n"
"border-radius:10px;\n"
"background-color: rgb(136, 138, 133);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(ComfirmDelete);

        QMetaObject::connectSlotsByName(ComfirmDelete);
    } // setupUi

    void retranslateUi(QWidget *ComfirmDelete)
    {
        ComfirmDelete->setWindowTitle(QApplication::translate("ComfirmDelete", "Form", nullptr));
        title->setText(QApplication::translate("ComfirmDelete", "Confirm Delete", nullptr));
        deleteBtn->setText(QApplication::translate("ComfirmDelete", "Delete", nullptr));
        cancelBtn->setText(QApplication::translate("ComfirmDelete", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComfirmDelete: public Ui_ComfirmDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMFIRMDELETE_H
