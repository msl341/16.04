/********************************************************************************
** Form generated from reading UI file 'language_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGE_SETTING_H
#define UI_LANGUAGE_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "language_setting.h"

QT_BEGIN_NAMESPACE

class Ui_language_setting
{
public:
    Label_Tchinese *label_Tchinese;
    QLabel *label;
    Label_return_L *label_return;
    QLabel *label_backdrop;
    Label_chinese *label_chinese;
    Label_save_L *label_save;
    Label_english *label_english;
    QLabel *label_D1;
    QLabel *label_D2;
    QLabel *label_D3;

    void setupUi(QWidget *language_setting)
    {
        if (language_setting->objectName().isEmpty())
            language_setting->setObjectName(QString::fromUtf8("language_setting"));
        language_setting->resize(1280, 800);
        label_Tchinese = new Label_Tchinese(language_setting);
        label_Tchinese->setObjectName(QString::fromUtf8("label_Tchinese"));
        label_Tchinese->setGeometry(QRect(565, 340, 150, 40));
        label = new QLabel(language_setting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_return = new Label_return_L(language_setting);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(790, 490, 100, 60));
        label_backdrop = new QLabel(language_setting);
        label_backdrop->setObjectName(QString::fromUtf8("label_backdrop"));
        label_backdrop->setGeometry(QRect(280, 220, 720, 360));
        label_backdrop->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"color: rgb(255, 255, 255);"));
        label_chinese = new Label_chinese(language_setting);
        label_chinese->setObjectName(QString::fromUtf8("label_chinese"));
        label_chinese->setGeometry(QRect(565, 260, 150, 40));
        label_save = new Label_save_L(language_setting);
        label_save->setObjectName(QString::fromUtf8("label_save"));
        label_save->setGeometry(QRect(410, 490, 100, 60));
        label_english = new Label_english(language_setting);
        label_english->setObjectName(QString::fromUtf8("label_english"));
        label_english->setGeometry(QRect(565, 420, 150, 40));
        label_D1 = new QLabel(language_setting);
        label_D1->setObjectName(QString::fromUtf8("label_D1"));
        label_D1->setGeometry(QRect(520, 260, 40, 40));
        label_D2 = new QLabel(language_setting);
        label_D2->setObjectName(QString::fromUtf8("label_D2"));
        label_D2->setGeometry(QRect(520, 340, 40, 40));
        label_D3 = new QLabel(language_setting);
        label_D3->setObjectName(QString::fromUtf8("label_D3"));
        label_D3->setGeometry(QRect(520, 420, 40, 40));
        label->raise();
        label_backdrop->raise();
        label_Tchinese->raise();
        label_return->raise();
        label_chinese->raise();
        label_save->raise();
        label_english->raise();
        label_D2->raise();
        label_D3->raise();
        label_D1->raise();

        retranslateUi(language_setting);

        QMetaObject::connectSlotsByName(language_setting);
    } // setupUi

    void retranslateUi(QWidget *language_setting)
    {
        language_setting->setWindowTitle(QApplication::translate("language_setting", "Form", nullptr));
        label_Tchinese->setText(QApplication::translate("language_setting", "\347\271\201\351\253\224\344\270\255\346\226\207", nullptr));
        label->setText(QString());
        label_return->setText(QApplication::translate("language_setting", "\351\200\200\345\207\272", nullptr));
        label_backdrop->setText(QString());
        label_chinese->setText(QApplication::translate("language_setting", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));
        label_save->setText(QApplication::translate("language_setting", "\344\277\235\345\255\230", nullptr));
        label_english->setText(QApplication::translate("language_setting", "English", nullptr));
        label_D1->setText(QApplication::translate("language_setting", "*", nullptr));
        label_D2->setText(QApplication::translate("language_setting", "*", nullptr));
        label_D3->setText(QApplication::translate("language_setting", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class language_setting: public Ui_language_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGE_SETTING_H
