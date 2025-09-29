/********************************************************************************
** Form generated from reading UI file 'tips_no_sd_card.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPS_NO_SD_CARD_H
#define UI_TIPS_NO_SD_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tips_no_sd_card
{
public:
    QLabel *label_backdrop;
    QLabel *label_num;
    QLabel *label;

    void setupUi(QWidget *tips_no_sd_card)
    {
        if (tips_no_sd_card->objectName().isEmpty())
            tips_no_sd_card->setObjectName(QString::fromUtf8("tips_no_sd_card"));
        tips_no_sd_card->resize(1280, 800);
        label_backdrop = new QLabel(tips_no_sd_card);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: rgb(110, 215, 230);"));
        label_num = new QLabel(tips_no_sd_card);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(280, 380, 720, 40));
        label = new QLabel(tips_no_sd_card);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label->raise();
        label_backdrop->raise();
        label_num->raise();

        retranslateUi(tips_no_sd_card);

        QMetaObject::connectSlotsByName(tips_no_sd_card);
    } // setupUi

    void retranslateUi(QWidget *tips_no_sd_card)
    {
        tips_no_sd_card->setWindowTitle(QApplication::translate("tips_no_sd_card", "Form", nullptr));
        label_backdrop->setText(QString());
        label_num->setText(QApplication::translate("tips_no_sd_card", "\350\257\267\346\217\222\345\205\245SD\345\215\241", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tips_no_sd_card: public Ui_tips_no_sd_card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPS_NO_SD_CARD_H
