/********************************************************************************
** Form generated from reading UI file 'PickPhoto.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKPHOTO_H
#define UI_PICKPHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PickPhoto
{
public:
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QListView *listView;
    QLabel *label;
    QLabel *bkg;

    void setupUi(QDialog *PickPhoto)
    {
        if (PickPhoto->objectName().isEmpty())
            PickPhoto->setObjectName(QString::fromUtf8("PickPhoto"));
        PickPhoto->resize(500, 450);
        PickPhoto->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: black;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QListView {\n"
"	\n"
"	background-color: transparent;\n"
"}"));
        cancelBtn = new QPushButton(PickPhoto);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(290, 420, 89, 25));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);\n"
"color: rgb(0, 0, 0);"));
        cancelBtn->setAutoDefault(false);
        cancelBtn->setFlat(true);
        okBtn = new QPushButton(PickPhoto);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(390, 420, 89, 25));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);\n"
"color: rgb(0, 0, 0);"));
        okBtn->setFlat(true);
        listView = new QListView(PickPhoto);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 480, 400));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSelectionMode(QAbstractItemView::MultiSelection);
        listView->setIconSize(QSize(120, 120));
        listView->setMovement(QListView::Static);
        listView->setSpacing(20);
        listView->setViewMode(QListView::IconMode);
        label = new QLabel(PickPhoto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 140, 120, 100));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);
        bkg = new QLabel(PickPhoto);
        bkg->setObjectName(QString::fromUtf8("bkg"));
        bkg->setGeometry(QRect(0, 0, 500, 450));
        bkg->setStyleSheet(QString::fromUtf8("background-color: white;  /* \350\203\214\346\231\257\351\241\217\350\211\262 */\n"
"border: 2px solid #000000;   /* \351\202\212\346\241\206\351\241\217\350\211\262\345\222\214\345\257\254\345\272\246 */\n"
"border-radius: 10px;         /* \351\202\212\346\241\206\345\234\223\350\247\222 */"));
        bkg->raise();
        cancelBtn->raise();
        okBtn->raise();
        listView->raise();
        label->raise();

        retranslateUi(PickPhoto);

        QMetaObject::connectSlotsByName(PickPhoto);
    } // setupUi

    void retranslateUi(QDialog *PickPhoto)
    {
        PickPhoto->setWindowTitle(QApplication::translate("PickPhoto", "Dialog", nullptr));
        cancelBtn->setText(QApplication::translate("PickPhoto", "Cancel", nullptr));
        okBtn->setText(QApplication::translate("PickPhoto", "OK", nullptr));
        label->setText(QApplication::translate("PickPhoto", "No Photos", nullptr));
        bkg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PickPhoto: public Ui_PickPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKPHOTO_H
