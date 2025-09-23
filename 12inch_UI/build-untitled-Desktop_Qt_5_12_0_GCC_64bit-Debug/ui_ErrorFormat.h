/********************************************************************************
** Form generated from reading UI file 'ErrorFormat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORFORMAT_H
#define UI_ERRORFORMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorFormat
{
public:
    QWidget *widget;
    QLabel *errMsg;
    QPushButton *closeBtn;
    QLabel *bkg;

    void setupUi(QWidget *ErrorFormat)
    {
        if (ErrorFormat->objectName().isEmpty())
            ErrorFormat->setObjectName(QString::fromUtf8("ErrorFormat"));
        ErrorFormat->resize(1280, 800);
        widget = new QWidget(ErrorFormat);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(315, 250, 650, 300));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:65px;"));
        errMsg = new QLabel(widget);
        errMsg->setObjectName(QString::fromUtf8("errMsg"));
        errMsg->setGeometry(QRect(0, 0, 651, 231));
        QFont font;
        errMsg->setFont(font);
        errMsg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-image: none;\n"
"background-color: none;\n"
"font-size:36px;"));
        errMsg->setAlignment(Qt::AlignCenter);
        errMsg->setWordWrap(true);
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(460, 220, 191, 81));
        QFont font1;
        font1.setPointSize(16);
        closeBtn->setFont(font1);
        closeBtn->setFocusPolicy(Qt::NoFocus);
        closeBtn->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"background-color: none;"));
        bkg = new QLabel(widget);
        bkg->setObjectName(QString::fromUtf8("bkg"));
        bkg->setGeometry(QRect(0, 0, 650, 300));
        bkg->setStyleSheet(QString::fromUtf8("border-image:url(:/tu/ALL-IN-ONE ICON/BKG_long.png);"));
        bkg->raise();
        errMsg->raise();
        closeBtn->raise();

        retranslateUi(ErrorFormat);

        QMetaObject::connectSlotsByName(ErrorFormat);
    } // setupUi

    void retranslateUi(QWidget *ErrorFormat)
    {
        ErrorFormat->setWindowTitle(QApplication::translate("ErrorFormat", "Form", nullptr));
        errMsg->setText(QString());
        closeBtn->setText(QApplication::translate("ErrorFormat", "close", nullptr));
        bkg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ErrorFormat: public Ui_ErrorFormat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORFORMAT_H
