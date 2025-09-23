/********************************************************************************
** Form generated from reading UI file 'lansetwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANSETWINDOW_H
#define UI_LANSETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lansetwindow
{
public:
    QWidget *m_pWdg_Panel_LanSet;
    QPushButton *m_pBtn_SimpleCh;
    QPushButton *m_pBtn_TraditionCh;
    QPushButton *m_pBtn_English;
    QPushButton *m_pBtn_French;
    QPushButton *m_pBtn_German;
    QPushButton *m_pBtn_Return;

    void setupUi(QWidget *lansetwindow)
    {
        if (lansetwindow->objectName().isEmpty())
            lansetwindow->setObjectName(QString::fromUtf8("lansetwindow"));
        lansetwindow->resize(1280, 800);
        lansetwindow->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Res/btn_nosel.png);"));
        m_pWdg_Panel_LanSet = new QWidget(lansetwindow);
        m_pWdg_Panel_LanSet->setObjectName(QString::fromUtf8("m_pWdg_Panel_LanSet"));
        m_pWdg_Panel_LanSet->setGeometry(QRect(360, 100, 500, 500));
        m_pWdg_Panel_LanSet->setStyleSheet(QString::fromUtf8(""));
        m_pBtn_SimpleCh = new QPushButton(m_pWdg_Panel_LanSet);
        m_pBtn_SimpleCh->setObjectName(QString::fromUtf8("m_pBtn_SimpleCh"));
        m_pBtn_SimpleCh->setGeometry(QRect(50, 10, 300, 81));
        m_pBtn_SimpleCh->setStyleSheet(QString::fromUtf8("color:white;border:none;background:transparent;font-size: 35px"));
        m_pBtn_TraditionCh = new QPushButton(m_pWdg_Panel_LanSet);
        m_pBtn_TraditionCh->setObjectName(QString::fromUtf8("m_pBtn_TraditionCh"));
        m_pBtn_TraditionCh->setGeometry(QRect(50, 110, 300, 81));
        m_pBtn_TraditionCh->setStyleSheet(QString::fromUtf8("color:white;border:none;background:transparent;font-size: 35px"));
        m_pBtn_English = new QPushButton(m_pWdg_Panel_LanSet);
        m_pBtn_English->setObjectName(QString::fromUtf8("m_pBtn_English"));
        m_pBtn_English->setGeometry(QRect(50, 210, 300, 81));
        m_pBtn_English->setStyleSheet(QString::fromUtf8("color:white;border:none;background:transparent;font-size: 35px"));
        m_pBtn_French = new QPushButton(m_pWdg_Panel_LanSet);
        m_pBtn_French->setObjectName(QString::fromUtf8("m_pBtn_French"));
        m_pBtn_French->setGeometry(QRect(50, 310, 300, 81));
        m_pBtn_French->setStyleSheet(QString::fromUtf8("color:white;border:none;background:transparent;font-size: 35px;"));
        m_pBtn_German = new QPushButton(m_pWdg_Panel_LanSet);
        m_pBtn_German->setObjectName(QString::fromUtf8("m_pBtn_German"));
        m_pBtn_German->setGeometry(QRect(50, 410, 300, 81));
        m_pBtn_German->setStyleSheet(QString::fromUtf8("color:white;border:none;background:transparent;font-size: 35px;"));
        m_pBtn_Return = new QPushButton(lansetwindow);
        m_pBtn_Return->setObjectName(QString::fromUtf8("m_pBtn_Return"));
        m_pBtn_Return->setGeometry(QRect(1090, 690, 111, 71));
        m_pBtn_Return->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/return.png);"));

        retranslateUi(lansetwindow);

        QMetaObject::connectSlotsByName(lansetwindow);
    } // setupUi

    void retranslateUi(QWidget *lansetwindow)
    {
        lansetwindow->setWindowTitle(QApplication::translate("lansetwindow", "Form", nullptr));
        m_pBtn_SimpleCh->setText(QString());
        m_pBtn_TraditionCh->setText(QString());
        m_pBtn_English->setText(QString());
        m_pBtn_French->setText(QString());
        m_pBtn_German->setText(QString());
        m_pBtn_Return->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lansetwindow: public Ui_lansetwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANSETWINDOW_H
