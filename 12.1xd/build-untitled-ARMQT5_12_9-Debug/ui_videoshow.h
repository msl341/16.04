/********************************************************************************
** Form generated from reading UI file 'videoshow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOSHOW_H
#define UI_VIDEOSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoshow
{
public:
    QLabel *m_pLb_VideoPlayer;
    QLabel *m_pLb_FileIndTotal;
    QLabel *m_pLb_FileName;
    QPushButton *m_pBtn_Return;
    QPushButton *m_pBtn_Del_File;
    QPushButton *m_pBtn_Left;
    QPushButton *m_pBtn_Right;
    QPushButton *m_pLb_VideoPlayer_Play;
    QLabel *label;

    void setupUi(QWidget *videoshow)
    {
        if (videoshow->objectName().isEmpty())
            videoshow->setObjectName(QString::fromUtf8("videoshow"));
        videoshow->resize(1280, 800);
        videoshow->setStyleSheet(QString::fromUtf8(""));
        m_pLb_VideoPlayer = new QLabel(videoshow);
        m_pLb_VideoPlayer->setObjectName(QString::fromUtf8("m_pLb_VideoPlayer"));
        m_pLb_VideoPlayer->setGeometry(QRect(179, 0, 931, 800));
        m_pLb_FileIndTotal = new QLabel(videoshow);
        m_pLb_FileIndTotal->setObjectName(QString::fromUtf8("m_pLb_FileIndTotal"));
        m_pLb_FileIndTotal->setGeometry(QRect(350, 10, 100, 30));
        m_pLb_FileIndTotal->setStyleSheet(QString::fromUtf8(" color: white;           \n"
"    background: transparent;"));
        m_pLb_FileName = new QLabel(videoshow);
        m_pLb_FileName->setObjectName(QString::fromUtf8("m_pLb_FileName"));
        m_pLb_FileName->setGeometry(QRect(550, 10, 401, 30));
        m_pLb_FileName->setStyleSheet(QString::fromUtf8(" color: white;           \n"
"    background: transparent;"));
        m_pBtn_Return = new QPushButton(videoshow);
        m_pBtn_Return->setObjectName(QString::fromUtf8("m_pBtn_Return"));
        m_pBtn_Return->setGeometry(QRect(1150, 700, 90, 50));
        m_pBtn_Return->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/return.png);"));
        m_pBtn_Del_File = new QPushButton(videoshow);
        m_pBtn_Del_File->setObjectName(QString::fromUtf8("m_pBtn_Del_File"));
        m_pBtn_Del_File->setGeometry(QRect(40, 690, 61, 71));
        m_pBtn_Del_File->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/delfile.png);"));
        m_pBtn_Left = new QPushButton(videoshow);
        m_pBtn_Left->setObjectName(QString::fromUtf8("m_pBtn_Left"));
        m_pBtn_Left->setGeometry(QRect(40, 300, 80, 146));
        m_pBtn_Left->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_left.png);"));
        m_pBtn_Right = new QPushButton(videoshow);
        m_pBtn_Right->setObjectName(QString::fromUtf8("m_pBtn_Right"));
        m_pBtn_Right->setGeometry(QRect(1160, 300, 80, 146));
        m_pBtn_Right->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_right.png);"));
        m_pLb_VideoPlayer_Play = new QPushButton(videoshow);
        m_pLb_VideoPlayer_Play->setObjectName(QString::fromUtf8("m_pLb_VideoPlayer_Play"));
        m_pLb_VideoPlayer_Play->setGeometry(QRect(560, 300, 141, 131));
        m_pLb_VideoPlayer_Play->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/videoflag.png);\n"
""));
        label = new QLabel(videoshow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/btn_nosel.png);"));
        label->raise();
        m_pLb_VideoPlayer->raise();
        m_pLb_FileIndTotal->raise();
        m_pLb_FileName->raise();
        m_pBtn_Return->raise();
        m_pBtn_Del_File->raise();
        m_pBtn_Left->raise();
        m_pBtn_Right->raise();
        m_pLb_VideoPlayer_Play->raise();

        retranslateUi(videoshow);

        QMetaObject::connectSlotsByName(videoshow);
    } // setupUi

    void retranslateUi(QWidget *videoshow)
    {
        videoshow->setWindowTitle(QApplication::translate("videoshow", "Form", nullptr));
        m_pLb_VideoPlayer->setText(QString());
        m_pLb_FileIndTotal->setText(QString());
        m_pLb_FileName->setText(QString());
        m_pBtn_Return->setText(QString());
        m_pBtn_Del_File->setText(QString());
        m_pBtn_Left->setText(QString());
        m_pBtn_Right->setText(QString());
        m_pLb_VideoPlayer_Play->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class videoshow: public Ui_videoshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOSHOW_H
