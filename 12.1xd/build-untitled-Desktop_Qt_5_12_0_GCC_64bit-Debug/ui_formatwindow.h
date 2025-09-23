/********************************************************************************
** Form generated from reading UI file 'formatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATWINDOW_H
#define UI_FORMATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formatwindow
{
public:
    QLabel *m_pLb_Msg;
    QPushButton *m_pBtn_Confirm;
    QPushButton *m_pBtn_Cancel;

    void setupUi(QWidget *formatwindow)
    {
        if (formatwindow->objectName().isEmpty())
            formatwindow->setObjectName(QString::fromUtf8("formatwindow"));
        formatwindow->resize(1280, 800);
        formatwindow->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Res/btn_nosel.png);"));
        m_pLb_Msg = new QLabel(formatwindow);
        m_pLb_Msg->setObjectName(QString::fromUtf8("m_pLb_Msg"));
        m_pLb_Msg->setGeometry(QRect(350, 330, 901, 141));
        m_pLb_Msg->setStyleSheet(QString::fromUtf8("color:white;font-size: 55px;font: bold;background-color: transparent;"));
        m_pBtn_Confirm = new QPushButton(formatwindow);
        m_pBtn_Confirm->setObjectName(QString::fromUtf8("m_pBtn_Confirm"));
        m_pBtn_Confirm->setGeometry(QRect(310, 540, 200, 130));
        m_pBtn_Confirm->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_confirm.png);\n"
"QPushButton{color:white;border:none;background:transparent;font-size: 35px;}"));
        m_pBtn_Cancel = new QPushButton(formatwindow);
        m_pBtn_Cancel->setObjectName(QString::fromUtf8("m_pBtn_Cancel"));
        m_pBtn_Cancel->setGeometry(QRect(590, 540, 200, 130));
        m_pBtn_Cancel->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_cancel.png);\n"
"color:white;border:none;background:transparent;font-size: 35px"));

        retranslateUi(formatwindow);

        QMetaObject::connectSlotsByName(formatwindow);
    } // setupUi

    void retranslateUi(QWidget *formatwindow)
    {
        formatwindow->setWindowTitle(QApplication::translate("formatwindow", "Form", nullptr));
        m_pLb_Msg->setText(QString());
        m_pBtn_Confirm->setText(QString());
        m_pBtn_Cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class formatwindow: public Ui_formatwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATWINDOW_H
