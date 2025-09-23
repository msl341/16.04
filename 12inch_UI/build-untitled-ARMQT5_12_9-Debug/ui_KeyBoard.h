/********************************************************************************
** Form generated from reading UI file 'KeyBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"
#include "mykey.h"

QT_BEGIN_NAMESPACE

class Ui_KeyBoard
{
public:
    QWidget *keyboardWidget;
    movablePushbutton *moveLBtn;
    movablePushbutton *moveRBtn;
    QQuickWidget *quickWidget;

    void setupUi(QWidget *KeyBoard)
    {
        if (KeyBoard->objectName().isEmpty())
            KeyBoard->setObjectName(QString::fromUtf8("KeyBoard"));
        KeyBoard->resize(1280, 800);
        keyboardWidget = new QWidget(KeyBoard);
        keyboardWidget->setObjectName(QString::fromUtf8("keyboardWidget"));
        keyboardWidget->setEnabled(true);
        keyboardWidget->setGeometry(QRect(110, 400, 1070, 371));
        keyboardWidget->setStyleSheet(QString::fromUtf8("border-image: none;"));
        moveLBtn = new movablePushbutton(keyboardWidget);
        moveLBtn->setObjectName(QString::fromUtf8("moveLBtn"));
        moveLBtn->setGeometry(QRect(6, 60, 40, 306));
        moveLBtn->setFocusPolicy(Qt::NoFocus);
        moveLBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(56,53,51);\n"
"color: rgb(0, 0, 0);\n"
"border-image: none;\n"
"border:none;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-left-radius:10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/move_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveLBtn->setIcon(icon);
        moveLBtn->setIconSize(QSize(30, 30));
        moveRBtn = new movablePushbutton(keyboardWidget);
        moveRBtn->setObjectName(QString::fromUtf8("moveRBtn"));
        moveRBtn->setGeometry(QRect(1026, 60, 40, 306));
        moveRBtn->setFocusPolicy(Qt::NoFocus);
        moveRBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(56,53,51);\n"
"color: rgb(0, 0, 0);\n"
"border-image: none;\n"
"border:none;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius:10px;"));
        moveRBtn->setIcon(icon);
        moveRBtn->setIconSize(QSize(30, 30));
        quickWidget = new QQuickWidget(keyboardWidget);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        quickWidget->setGeometry(QRect(46, 60, 980, 306));
        quickWidget->setFocusPolicy(Qt::NoFocus);
        quickWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        quickWidget->setSource(QUrl(QString::fromUtf8("qrc:/VKeyboard.qml")));

        retranslateUi(KeyBoard);

        QMetaObject::connectSlotsByName(KeyBoard);
    } // setupUi

    void retranslateUi(QWidget *KeyBoard)
    {
        KeyBoard->setWindowTitle(QApplication::translate("KeyBoard", "Form", nullptr));
        moveLBtn->setText(QString());
        moveRBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KeyBoard: public Ui_KeyBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
