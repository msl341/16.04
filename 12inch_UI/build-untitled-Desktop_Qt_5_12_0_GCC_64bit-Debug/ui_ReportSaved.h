/********************************************************************************
** Form generated from reading UI file 'ReportSaved.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTSAVED_H
#define UI_REPORTSAVED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportSaved
{
public:
    QLabel *label;

    void setupUi(QWidget *ReportSaved)
    {
        if (ReportSaved->objectName().isEmpty())
            ReportSaved->setObjectName(QString::fromUtf8("ReportSaved"));
        ReportSaved->resize(1280, 800);
        label = new QLabel(ReportSaved);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 220, 720, 360));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:75px;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(ReportSaved);

        QMetaObject::connectSlotsByName(ReportSaved);
    } // setupUi

    void retranslateUi(QWidget *ReportSaved)
    {
        ReportSaved->setWindowTitle(QApplication::translate("ReportSaved", "Form", nullptr));
        label->setText(QApplication::translate("ReportSaved", "Report Saved !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportSaved: public Ui_ReportSaved {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTSAVED_H
