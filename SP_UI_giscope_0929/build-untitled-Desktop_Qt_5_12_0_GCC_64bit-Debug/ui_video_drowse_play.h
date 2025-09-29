/********************************************************************************
** Form generated from reading UI file 'video_drowse_play.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_DROWSE_PLAY_H
#define UI_VIDEO_DROWSE_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "video_drowse_play.h"

QT_BEGIN_NAMESPACE

class Ui_video_drowse_play
{
public:
    QLabel *label;
    Label_return_vs *label_return;
    Label_right_vs *label_right;
    Label_delete_vs *label_delete;
    Label_left_vs *label_left;
    Label_recoil_vs *label_recoil;
    Label_pause_vs *label_pause;
    Label_advance_vs *label_advance;
    QLabel *label_time;
    QSlider *horizontalSlider;

    void setupUi(QWidget *video_drowse_play)
    {
        if (video_drowse_play->objectName().isEmpty())
            video_drowse_play->setObjectName(QString::fromUtf8("video_drowse_play"));
        video_drowse_play->resize(1280, 800);
        label = new QLabel(video_drowse_play);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label_return = new Label_return_vs(video_drowse_play);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(1140, 20, 120, 70));
        label_return->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/return.png);"));
        label_right = new Label_right_vs(video_drowse_play);
        label_right->setObjectName(QString::fromUtf8("label_right"));
        label_right->setGeometry(QRect(1205, 298, 55, 205));
        label_right->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/right.png);"));
        label_delete = new Label_delete_vs(video_drowse_play);
        label_delete->setObjectName(QString::fromUtf8("label_delete"));
        label_delete->setGeometry(QRect(1140, 710, 120, 70));
        label_delete->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/delete.png);"));
        label_left = new Label_left_vs(video_drowse_play);
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_left->setGeometry(QRect(20, 298, 55, 205));
        label_left->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/left.png);"));
        label_recoil = new Label_recoil_vs(video_drowse_play);
        label_recoil->setObjectName(QString::fromUtf8("label_recoil"));
        label_recoil->setGeometry(QRect(20, 710, 70, 70));
        label_recoil->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/recoil.png);"));
        label_pause = new Label_pause_vs(video_drowse_play);
        label_pause->setObjectName(QString::fromUtf8("label_pause"));
        label_pause->setGeometry(QRect(100, 710, 70, 70));
        label_pause->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/pause.png);"));
        label_advance = new Label_advance_vs(video_drowse_play);
        label_advance->setObjectName(QString::fromUtf8("label_advance"));
        label_advance->setGeometry(QRect(180, 710, 70, 70));
        label_advance->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/advance.png);"));
        label_time = new QLabel(video_drowse_play);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(930, 710, 200, 70));
        label_time->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider = new QSlider(video_drowse_play);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(280, 710, 630, 70));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(video_drowse_play);

        QMetaObject::connectSlotsByName(video_drowse_play);
    } // setupUi

    void retranslateUi(QWidget *video_drowse_play)
    {
        video_drowse_play->setWindowTitle(QApplication::translate("video_drowse_play", "Form", nullptr));
        label->setText(QString());
        label_return->setText(QString());
        label_right->setText(QString());
        label_delete->setText(QString());
        label_left->setText(QString());
        label_recoil->setText(QString());
        label_pause->setText(QString());
        label_advance->setText(QString());
        label_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class video_drowse_play: public Ui_video_drowse_play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_DROWSE_PLAY_H
