/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutwindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *m_pLb_Verm;
    QPushButton *m_pBtn_Confirm;
    QLabel *label_2;
    QLabel *label;
    QPushButton *m_pBtn_Cancel;
    QWidget *page_2;
    QLabel *label_3;
    QLabel *m_pLb_Msg;

    void setupUi(QWidget *aboutwindow)
    {
        if (aboutwindow->objectName().isEmpty())
            aboutwindow->setObjectName(QString::fromUtf8("aboutwindow"));
        aboutwindow->resize(1280, 800);
        aboutwindow->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Res/btn_nosel.png);"));
        stackedWidget = new QStackedWidget(aboutwindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 50, 1311, 761));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        m_pLb_Verm = new QLabel(page);
        m_pLb_Verm->setObjectName(QString::fromUtf8("m_pLb_Verm"));
        m_pLb_Verm->setGeometry(QRect(340, 70, 491, 91));
        m_pLb_Verm->setStyleSheet(QString::fromUtf8("color:white;font-size: 55px;font: bold;background-color: transparent;"));
        m_pBtn_Confirm = new QPushButton(page);
        m_pBtn_Confirm->setObjectName(QString::fromUtf8("m_pBtn_Confirm"));
        m_pBtn_Confirm->setGeometry(QRect(380, 440, 371, 141));
        m_pBtn_Confirm->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/sj.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-origin: content-box; /* \347\241\256\344\277\235\350\203\214\346\231\257\345\233\276\345\222\214\346\226\207\346\234\254\345\214\272\345\237\237\345\210\206\347\246\273 */\n"
"text-align: center;"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 260, 361, 71));
        label_2->setStyleSheet(QString::fromUtf8("color:white;font-size: 55px;font: bold;background-color: transparent;"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 170, 341, 81));
        label->setStyleSheet(QString::fromUtf8("color:white;font-size: 55px;font: bold;background-color: transparent;"));
        m_pBtn_Cancel = new QPushButton(page);
        m_pBtn_Cancel->setObjectName(QString::fromUtf8("m_pBtn_Cancel"));
        m_pBtn_Cancel->setGeometry(QRect(1020, 630, 131, 81));
        m_pBtn_Cancel->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/return.png);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 90, 201, 141));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/sj-1.png);"));
        m_pLb_Msg = new QLabel(page_2);
        m_pLb_Msg->setObjectName(QString::fromUtf8("m_pLb_Msg"));
        m_pLb_Msg->setGeometry(QRect(60, 310, 1151, 291));
        m_pLb_Msg->setStyleSheet(QString::fromUtf8("color:white;font-size: 55px;font: bold;background-color: transparent;"));
        stackedWidget->addWidget(page_2);

        retranslateUi(aboutwindow);

        QMetaObject::connectSlotsByName(aboutwindow);
    } // setupUi

    void retranslateUi(QWidget *aboutwindow)
    {
        aboutwindow->setWindowTitle(QApplication::translate("aboutwindow", "Form", nullptr));
        m_pLb_Verm->setText(QApplication::translate("aboutwindow", "\345\275\223\345\211\215\347\211\210\346\234\254", nullptr));
        m_pBtn_Confirm->setText(QString());
        label_2->setText(QApplication::translate("aboutwindow", "SPC20220408", nullptr));
        label->setText(QApplication::translate("aboutwindow", "OTV_01_05", nullptr));
        m_pBtn_Cancel->setText(QString());
        label_3->setText(QString());
        m_pLb_Msg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class aboutwindow: public Ui_aboutwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
