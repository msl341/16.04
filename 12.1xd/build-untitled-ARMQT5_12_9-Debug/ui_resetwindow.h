/********************************************************************************
** Form generated from reading UI file 'resetwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETWINDOW_H
#define UI_RESETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resetwindow
{
public:
    QLabel *m_pLb_Msg;
    QPushButton *m_pBtn_Confirm;
    QPushButton *m_pBtn_Cancel;

    void setupUi(QWidget *resetwindow)
    {
        if (resetwindow->objectName().isEmpty())
            resetwindow->setObjectName(QString::fromUtf8("resetwindow"));
        resetwindow->resize(1280, 800);
        resetwindow->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Res/btn_nosel.png);"));
        m_pLb_Msg = new QLabel(resetwindow);
        m_pLb_Msg->setObjectName(QString::fromUtf8("m_pLb_Msg"));
        m_pLb_Msg->setGeometry(QRect(350, 330, 891, 131));
        m_pLb_Msg->setStyleSheet(QString::fromUtf8("color:white;font-size: 55px;font: bold;background-color: transparent"));
        m_pBtn_Confirm = new QPushButton(resetwindow);
        m_pBtn_Confirm->setObjectName(QString::fromUtf8("m_pBtn_Confirm"));
        m_pBtn_Confirm->setGeometry(QRect(310, 540, 200, 130));
        m_pBtn_Confirm->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_confirm.png);\n"
"QPushButton{color:white;border:none;background:transparent;font-size: 35px;}"));
        m_pBtn_Cancel = new QPushButton(resetwindow);
        m_pBtn_Cancel->setObjectName(QString::fromUtf8("m_pBtn_Cancel"));
        m_pBtn_Cancel->setGeometry(QRect(610, 540, 200, 130));
        m_pBtn_Cancel->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_cancel.png);\n"
"QPushButton{color:white;border:none;background:transparent;font-size: 35px;}"));

        retranslateUi(resetwindow);

        QMetaObject::connectSlotsByName(resetwindow);
    } // setupUi

    void retranslateUi(QWidget *resetwindow)
    {
        resetwindow->setWindowTitle(QApplication::translate("resetwindow", "Form", nullptr));
        m_pLb_Msg->setText(QString());
        m_pBtn_Confirm->setText(QString());
        m_pBtn_Cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class resetwindow: public Ui_resetwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETWINDOW_H
