/********************************************************************************
** Form generated from reading UI file 'videoshow_sel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOSHOW_SEL_H
#define UI_VIDEOSHOW_SEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoshow_sel
{
public:
    QPushButton *m_pBtn_Pause;
    QSlider *m_pSlider_Progress;
    QLabel *m_pLb_Time;
    QPushButton *m_pBtn_Return;
    QLabel *label;

    void setupUi(QWidget *videoshow_sel)
    {
        if (videoshow_sel->objectName().isEmpty())
            videoshow_sel->setObjectName(QString::fromUtf8("videoshow_sel"));
        videoshow_sel->resize(1280, 800);
        videoshow_sel->setStyleSheet(QString::fromUtf8(""));
        m_pBtn_Pause = new QPushButton(videoshow_sel);
        m_pBtn_Pause->setObjectName(QString::fromUtf8("m_pBtn_Pause"));
        m_pBtn_Pause->setGeometry(QRect(80, 700, 61, 51));
        m_pBtn_Pause->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Video/videoplayer_pause.png);"));
        m_pSlider_Progress = new QSlider(videoshow_sel);
        m_pSlider_Progress->setObjectName(QString::fromUtf8("m_pSlider_Progress"));
        m_pSlider_Progress->setGeometry(QRect(160, 690, 630, 70));
        m_pSlider_Progress->setOrientation(Qt::Horizontal);
        m_pLb_Time = new QLabel(videoshow_sel);
        m_pLb_Time->setObjectName(QString::fromUtf8("m_pLb_Time"));
        m_pLb_Time->setGeometry(QRect(830, 690, 171, 71));
        m_pLb_Time->setStyleSheet(QString::fromUtf8("color:white;font-size: 32px;font: bold;"));
        m_pBtn_Return = new QPushButton(videoshow_sel);
        m_pBtn_Return->setObjectName(QString::fromUtf8("m_pBtn_Return"));
        m_pBtn_Return->setGeometry(QRect(1090, 690, 111, 71));
        m_pBtn_Return->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/returnl.png);"));
        label = new QLabel(videoshow_sel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));

        retranslateUi(videoshow_sel);

        QMetaObject::connectSlotsByName(videoshow_sel);
    } // setupUi

    void retranslateUi(QWidget *videoshow_sel)
    {
        videoshow_sel->setWindowTitle(QApplication::translate("videoshow_sel", "Form", nullptr));
        m_pBtn_Pause->setText(QString());
        m_pLb_Time->setText(QApplication::translate("videoshow_sel", "00:00:00", nullptr));
        m_pBtn_Return->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class videoshow_sel: public Ui_videoshow_sel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOSHOW_SEL_H
