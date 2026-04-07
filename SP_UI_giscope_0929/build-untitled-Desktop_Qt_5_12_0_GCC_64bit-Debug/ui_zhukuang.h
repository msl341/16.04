/********************************************************************************
** Form generated from reading UI file 'zhukuang.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUKUANG_H
#define UI_ZHUKUANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "zhukuang.h"

QT_BEGIN_NAMESPACE

class Ui_zhukuang
{
public:
    Label_start *label_start;
    Label_photo *label_photo;
    Label_video *label_video;
    Label_system *label_system;
    QLabel *label_b;
    QLabel *label;

    void setupUi(QWidget *zhukuang)
    {
        if (zhukuang->objectName().isEmpty())
            zhukuang->setObjectName(QString::fromUtf8("zhukuang"));
        zhukuang->resize(1280, 800);
        zhukuang->setStyleSheet(QString::fromUtf8(""));
        label_start = new Label_start(zhukuang);
        label_start->setObjectName(QString::fromUtf8("label_start"));
        label_start->setGeometry(QRect(-20, 245, 360, 320));
        label_start->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/startchecking.png);"));
        label_photo = new Label_photo(zhukuang);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(300, 240, 360, 320));
        label_photo->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/photoview.png);"));
        label_video = new Label_video(zhukuang);
        label_video->setObjectName(QString::fromUtf8("label_video"));
        label_video->setGeometry(QRect(620, 245, 360, 320));
        label_video->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/videoview.png);"));
        label_system = new Label_system(zhukuang);
        label_system->setObjectName(QString::fromUtf8("label_system"));
        label_system->setGeometry(QRect(940, 245, 360, 320));
        label_system->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/systemset.png);"));
        label_b = new QLabel(zhukuang);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 800));
        label_b->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/background.png);"));
        label = new QLabel(zhukuang);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 80, 341, 91));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_b->raise();
        label_start->raise();
        label_photo->raise();
        label_video->raise();
        label_system->raise();
        label->raise();

        retranslateUi(zhukuang);

        QMetaObject::connectSlotsByName(zhukuang);
    } // setupUi

    void retranslateUi(QWidget *zhukuang)
    {
        zhukuang->setWindowTitle(QApplication::translate("zhukuang", "Form", nullptr));
        label_start->setText(QString());
        label_photo->setText(QString());
        label_video->setText(QString());
        label_system->setText(QString());
        label_b->setText(QString());
        label->setText(QApplication::translate("zhukuang", "Test 2024/12/10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zhukuang: public Ui_zhukuang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUKUANG_H
