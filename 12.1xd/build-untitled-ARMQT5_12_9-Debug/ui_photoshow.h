/********************************************************************************
** Form generated from reading UI file 'photoshow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOSHOW_H
#define UI_PHOTOSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_photoshow
{
public:
    QLabel *m_pLb_PhotoShow;
    QLabel *m_pLb_FileIndTotal;
    QLabel *m_pLb_FileName;
    QPushButton *label_left;
    QPushButton *label_right;
    QPushButton *label_return;
    QPushButton *label_delete;

    void setupUi(QWidget *photoshow)
    {
        if (photoshow->objectName().isEmpty())
            photoshow->setObjectName(QString::fromUtf8("photoshow"));
        photoshow->resize(1280, 800);
        photoshow->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Res/MainWindow/blackbg.png);"));
        m_pLb_PhotoShow = new QLabel(photoshow);
        m_pLb_PhotoShow->setObjectName(QString::fromUtf8("m_pLb_PhotoShow"));
        m_pLb_PhotoShow->setGeometry(QRect(180, 0, 920, 811));
        m_pLb_FileIndTotal = new QLabel(photoshow);
        m_pLb_FileIndTotal->setObjectName(QString::fromUtf8("m_pLb_FileIndTotal"));
        m_pLb_FileIndTotal->setGeometry(QRect(350, 10, 100, 30));
        m_pLb_FileIndTotal->setStyleSheet(QString::fromUtf8(" color: white;           \n"
"    background: transparent;"));
        m_pLb_FileName = new QLabel(photoshow);
        m_pLb_FileName->setObjectName(QString::fromUtf8("m_pLb_FileName"));
        m_pLb_FileName->setGeometry(QRect(550, 10, 351, 30));
        m_pLb_FileName->setStyleSheet(QString::fromUtf8(" color: white;           \n"
"    background: transparent;"));
        label_left = new QPushButton(photoshow);
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_left->setGeometry(QRect(40, 300, 80, 146));
        label_left->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_left.png);"));
        label_right = new QPushButton(photoshow);
        label_right->setObjectName(QString::fromUtf8("label_right"));
        label_right->setGeometry(QRect(1160, 300, 80, 146));
        label_right->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_right.png);"));
        label_return = new QPushButton(photoshow);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(1160, 700, 91, 51));
        label_return->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/return.png);"));
        label_delete = new QPushButton(photoshow);
        label_delete->setObjectName(QString::fromUtf8("label_delete"));
        label_delete->setGeometry(QRect(50, 680, 61, 71));
        label_delete->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/delfile.png);"));

        retranslateUi(photoshow);

        QMetaObject::connectSlotsByName(photoshow);
    } // setupUi

    void retranslateUi(QWidget *photoshow)
    {
        photoshow->setWindowTitle(QApplication::translate("photoshow", "Form", nullptr));
        m_pLb_PhotoShow->setText(QString());
        m_pLb_FileIndTotal->setText(QString());
        m_pLb_FileName->setText(QString());
        label_left->setText(QString());
        label_right->setText(QString());
        label_return->setText(QString());
        label_delete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class photoshow: public Ui_photoshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOSHOW_H
