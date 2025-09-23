/********************************************************************************
** Form generated from reading UI file 'datetimewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIMEWINDOW_H
#define UI_DATETIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_datetimewindow
{
public:
    QPushButton *m_pBtn_Year_Up;
    QLabel *m_pLb_Year;
    QPushButton *m_pBtn_Year_Down;
    QLabel *label;
    QPushButton *m_pBtn_Month_Up;
    QPushButton *m_pBtn_Day_Up;
    QPushButton *m_pBtn_Hour_Up;
    QPushButton *m_pBtn_Min_Up;
    QLabel *label_2;
    QLabel *m_pBtn_Month;
    QLabel *m_pBtn_Day;
    QPushButton *m_pBtn_Month_Down;
    QPushButton *m_pBtn_Day_Down;
    QPushButton *m_pBtn_Hour_Down;
    QPushButton *m_pBtn_Min_Down;
    QLabel *m_pBtn_Hour;
    QLabel *m_pBtn_Min;
    QPushButton *m_pBtn_Save;
    QPushButton *m_pBtn_Return;

    void setupUi(QWidget *datetimewindow)
    {
        if (datetimewindow->objectName().isEmpty())
            datetimewindow->setObjectName(QString::fromUtf8("datetimewindow"));
        datetimewindow->resize(1280, 800);
        datetimewindow->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Res/btn_nosel.png);"));
        m_pBtn_Year_Up = new QPushButton(datetimewindow);
        m_pBtn_Year_Up->setObjectName(QString::fromUtf8("m_pBtn_Year_Up"));
        m_pBtn_Year_Up->setGeometry(QRect(120, 170, 121, 81));
        m_pBtn_Year_Up->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_up.png);"));
        m_pLb_Year = new QLabel(datetimewindow);
        m_pLb_Year->setObjectName(QString::fromUtf8("m_pLb_Year"));
        m_pLb_Year->setGeometry(QRect(120, 320, 131, 61));
        m_pLb_Year->setStyleSheet(QString::fromUtf8("color:white;font-size: 50px;font: bold;background-color: transparent;"));
        m_pBtn_Year_Down = new QPushButton(datetimewindow);
        m_pBtn_Year_Down->setObjectName(QString::fromUtf8("m_pBtn_Year_Down"));
        m_pBtn_Year_Down->setGeometry(QRect(120, 450, 121, 81));
        m_pBtn_Year_Down->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_down.png);"));
        label = new QLabel(datetimewindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 160, 67, 381));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/spliter.png);"));
        m_pBtn_Month_Up = new QPushButton(datetimewindow);
        m_pBtn_Month_Up->setObjectName(QString::fromUtf8("m_pBtn_Month_Up"));
        m_pBtn_Month_Up->setGeometry(QRect(390, 170, 121, 81));
        m_pBtn_Month_Up->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_up.png);"));
        m_pBtn_Day_Up = new QPushButton(datetimewindow);
        m_pBtn_Day_Up->setObjectName(QString::fromUtf8("m_pBtn_Day_Up"));
        m_pBtn_Day_Up->setGeometry(QRect(580, 170, 121, 81));
        m_pBtn_Day_Up->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_up.png);"));
        m_pBtn_Hour_Up = new QPushButton(datetimewindow);
        m_pBtn_Hour_Up->setObjectName(QString::fromUtf8("m_pBtn_Hour_Up"));
        m_pBtn_Hour_Up->setGeometry(QRect(830, 170, 121, 81));
        m_pBtn_Hour_Up->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_up.png);"));
        m_pBtn_Min_Up = new QPushButton(datetimewindow);
        m_pBtn_Min_Up->setObjectName(QString::fromUtf8("m_pBtn_Min_Up"));
        m_pBtn_Min_Up->setGeometry(QRect(1010, 170, 121, 81));
        m_pBtn_Min_Up->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_up.png);"));
        label_2 = new QLabel(datetimewindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(740, 160, 67, 381));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/spliter.png);"));
        m_pBtn_Month = new QLabel(datetimewindow);
        m_pBtn_Month->setObjectName(QString::fromUtf8("m_pBtn_Month"));
        m_pBtn_Month->setGeometry(QRect(400, 320, 131, 61));
        m_pBtn_Month->setStyleSheet(QString::fromUtf8("color:white;font-size: 50px;font: bold;background-color: transparent;"));
        m_pBtn_Day = new QLabel(datetimewindow);
        m_pBtn_Day->setObjectName(QString::fromUtf8("m_pBtn_Day"));
        m_pBtn_Day->setGeometry(QRect(590, 320, 131, 61));
        m_pBtn_Day->setStyleSheet(QString::fromUtf8("color:white;font-size: 50px;font: bold;background-color: transparent;"));
        m_pBtn_Month_Down = new QPushButton(datetimewindow);
        m_pBtn_Month_Down->setObjectName(QString::fromUtf8("m_pBtn_Month_Down"));
        m_pBtn_Month_Down->setGeometry(QRect(390, 450, 121, 81));
        m_pBtn_Month_Down->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_down.png);"));
        m_pBtn_Day_Down = new QPushButton(datetimewindow);
        m_pBtn_Day_Down->setObjectName(QString::fromUtf8("m_pBtn_Day_Down"));
        m_pBtn_Day_Down->setGeometry(QRect(570, 450, 121, 81));
        m_pBtn_Day_Down->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_down.png);"));
        m_pBtn_Hour_Down = new QPushButton(datetimewindow);
        m_pBtn_Hour_Down->setObjectName(QString::fromUtf8("m_pBtn_Hour_Down"));
        m_pBtn_Hour_Down->setGeometry(QRect(840, 450, 121, 81));
        m_pBtn_Hour_Down->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_down.png);"));
        m_pBtn_Min_Down = new QPushButton(datetimewindow);
        m_pBtn_Min_Down->setObjectName(QString::fromUtf8("m_pBtn_Min_Down"));
        m_pBtn_Min_Down->setGeometry(QRect(1020, 450, 121, 81));
        m_pBtn_Min_Down->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_down.png);"));
        m_pBtn_Hour = new QLabel(datetimewindow);
        m_pBtn_Hour->setObjectName(QString::fromUtf8("m_pBtn_Hour"));
        m_pBtn_Hour->setGeometry(QRect(840, 320, 131, 61));
        m_pBtn_Hour->setStyleSheet(QString::fromUtf8("color:white;font-size: 50px;font: bold;background-color: transparent;"));
        m_pBtn_Min = new QLabel(datetimewindow);
        m_pBtn_Min->setObjectName(QString::fromUtf8("m_pBtn_Min"));
        m_pBtn_Min->setGeometry(QRect(1020, 320, 131, 61));
        m_pBtn_Min->setStyleSheet(QString::fromUtf8("color:white;font-size: 50px;font: bold;background-color: transparent;"));
        m_pBtn_Save = new QPushButton(datetimewindow);
        m_pBtn_Save->setObjectName(QString::fromUtf8("m_pBtn_Save"));
        m_pBtn_Save->setGeometry(QRect(600, 640, 121, 81));
        m_pBtn_Save->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/save.png);"));
        m_pBtn_Return = new QPushButton(datetimewindow);
        m_pBtn_Return->setObjectName(QString::fromUtf8("m_pBtn_Return"));
        m_pBtn_Return->setGeometry(QRect(1150, 720, 91, 61));
        m_pBtn_Return->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/return.png);"));

        retranslateUi(datetimewindow);

        QMetaObject::connectSlotsByName(datetimewindow);
    } // setupUi

    void retranslateUi(QWidget *datetimewindow)
    {
        datetimewindow->setWindowTitle(QApplication::translate("datetimewindow", "Form", nullptr));
        m_pBtn_Year_Up->setText(QString());
        m_pLb_Year->setText(QString());
        m_pBtn_Year_Down->setText(QString());
        label->setText(QString());
        m_pBtn_Month_Up->setText(QString());
        m_pBtn_Day_Up->setText(QString());
        m_pBtn_Hour_Up->setText(QString());
        m_pBtn_Min_Up->setText(QString());
        label_2->setText(QString());
        m_pBtn_Month->setText(QString());
        m_pBtn_Day->setText(QString());
        m_pBtn_Month_Down->setText(QString());
        m_pBtn_Day_Down->setText(QString());
        m_pBtn_Hour_Down->setText(QString());
        m_pBtn_Min_Down->setText(QString());
        m_pBtn_Hour->setText(QString());
        m_pBtn_Min->setText(QString());
        m_pBtn_Save->setText(QString());
        m_pBtn_Return->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class datetimewindow: public Ui_datetimewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIMEWINDOW_H
