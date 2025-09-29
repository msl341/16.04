/********************************************************************************
** Form generated from reading UI file 'video_browse.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_BROWSE_H
#define UI_VIDEO_BROWSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "photo_browse.h"
#include "video_browse.h"

QT_BEGIN_NAMESPACE

class Ui_video_browse
{
public:
    Label_select_v *label_select;
    Label_select_all_v *label_select_all;
    QLabel *label_line;
    Label_left_v *label_left;
    Label_return_v *label_return;
    Label_deselect_all_v *label_deselect_all;
    Label_right_v *label_right;
    Label_delete_v *label_delete;
    QLabel *label_21;
    Label_video_1 *label_play_1;
    Label_video_2 *label_play_2;
    Label_video_3 *label_play_3;
    Label_video_4 *label_play_4;
    Label_video_6 *label_play_6;
    Label_video_5 *label_play_5;
    QLabel *label_num;
    Label_photo_5 *label_5;
    QLabel *label_tick4;
    Label_photo_6 *label_6;
    QLabel *label_tick6;
    QLabel *label_tick5;
    QLabel *label_tick2;
    Label_photo_1 *label_1;
    QLabel *label_tick1;
    Label_photo_3 *label_3;
    Label_photo_2 *label_2;
    QLabel *label_tick3;
    Label_photo_4 *label_4;

    void setupUi(QWidget *video_browse)
    {
        if (video_browse->objectName().isEmpty())
            video_browse->setObjectName(QString::fromUtf8("video_browse"));
        video_browse->resize(1280, 800);
        label_select = new Label_select_v(video_browse);
        label_select->setObjectName(QString::fromUtf8("label_select"));
        label_select->setGeometry(QRect(20, 20, 79, 50));
        label_select->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/single.png);"));
        label_select_all = new Label_select_all_v(video_browse);
        label_select_all->setObjectName(QString::fromUtf8("label_select_all"));
        label_select_all->setGeometry(QRect(120, 20, 79, 50));
        label_select_all->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/all.png);"));
        label_line = new QLabel(video_browse);
        label_line->setObjectName(QString::fromUtf8("label_line"));
        label_line->setGeometry(QRect(0, 110, 1280, 2));
        label_line->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/boundary.png);"));
        label_left = new Label_left_v(video_browse);
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_left->setGeometry(QRect(10, 304, 54, 205));
        label_left->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/left.png);"));
        label_return = new Label_return_v(video_browse);
        label_return->setObjectName(QString::fromUtf8("label_return"));
        label_return->setGeometry(QRect(1140, 20, 122, 74));
        label_return->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/return.png);"));
        label_deselect_all = new Label_deselect_all_v(video_browse);
        label_deselect_all->setObjectName(QString::fromUtf8("label_deselect_all"));
        label_deselect_all->setGeometry(QRect(220, 20, 79, 50));
        label_deselect_all->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/cancelall.png);"));
        label_right = new Label_right_v(video_browse);
        label_right->setObjectName(QString::fromUtf8("label_right"));
        label_right->setGeometry(QRect(1216, 304, 54, 205));
        label_right->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/right.png);"));
        label_delete = new Label_delete_v(video_browse);
        label_delete->setObjectName(QString::fromUtf8("label_delete"));
        label_delete->setGeometry(QRect(1120, 700, 142, 88));
        label_delete->setStyleSheet(QString::fromUtf8("background-image: url(:/tu/Photo/delete.png);"));
        label_21 = new QLabel(video_browse);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 0, 1280, 800));
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_play_1 = new Label_video_1(video_browse);
        label_play_1->setObjectName(QString::fromUtf8("label_play_1"));
        label_play_1->setGeometry(QRect(80, 130, 356, 265));
        label_play_1->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/videoflag.png);"));
        label_play_2 = new Label_video_2(video_browse);
        label_play_2->setObjectName(QString::fromUtf8("label_play_2"));
        label_play_2->setGeometry(QRect(461, 130, 356, 265));
        label_play_2->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/videoflag.png);"));
        label_play_3 = new Label_video_3(video_browse);
        label_play_3->setObjectName(QString::fromUtf8("label_play_3"));
        label_play_3->setGeometry(QRect(842, 130, 356, 265));
        label_play_3->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/videoflag.png);"));
        label_play_4 = new Label_video_4(video_browse);
        label_play_4->setObjectName(QString::fromUtf8("label_play_4"));
        label_play_4->setGeometry(QRect(80, 420, 356, 265));
        label_play_4->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/videoflag.png);"));
        label_play_6 = new Label_video_6(video_browse);
        label_play_6->setObjectName(QString::fromUtf8("label_play_6"));
        label_play_6->setGeometry(QRect(842, 420, 356, 265));
        label_play_6->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/videoflag.png);"));
        label_play_5 = new Label_video_5(video_browse);
        label_play_5->setObjectName(QString::fromUtf8("label_play_5"));
        label_play_5->setGeometry(QRect(461, 420, 356, 265));
        label_play_5->setStyleSheet(QString::fromUtf8("image: url(:/tu/Video/videoflag.png);"));
        label_num = new QLabel(video_browse);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(1000, 40, 120, 51));
        label_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";"));
        label_5 = new Label_photo_5(video_browse);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(461, 420, 356, 265));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_tick4 = new QLabel(video_browse);
        label_tick4->setObjectName(QString::fromUtf8("label_tick4"));
        label_tick4->setGeometry(QRect(386, 655, 20, 20));
        label_tick4->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/selectflag.png);"));
        label_6 = new Label_photo_6(video_browse);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(842, 420, 356, 265));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_tick6 = new QLabel(video_browse);
        label_tick6->setObjectName(QString::fromUtf8("label_tick6"));
        label_tick6->setGeometry(QRect(1148, 655, 20, 20));
        label_tick6->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/selectflag.png);"));
        label_tick5 = new QLabel(video_browse);
        label_tick5->setObjectName(QString::fromUtf8("label_tick5"));
        label_tick5->setGeometry(QRect(767, 655, 20, 20));
        label_tick5->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/selectflag.png);"));
        label_tick2 = new QLabel(video_browse);
        label_tick2->setObjectName(QString::fromUtf8("label_tick2"));
        label_tick2->setGeometry(QRect(767, 365, 20, 20));
        label_tick2->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/selectflag.png);"));
        label_1 = new Label_photo_1(video_browse);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(80, 130, 356, 265));
        label_1->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_tick1 = new QLabel(video_browse);
        label_tick1->setObjectName(QString::fromUtf8("label_tick1"));
        label_tick1->setGeometry(QRect(386, 365, 20, 20));
        label_tick1->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/selectflag.png);"));
        label_3 = new Label_photo_3(video_browse);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(842, 130, 356, 265));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_2 = new Label_photo_2(video_browse);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(461, 130, 356, 265));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_tick3 = new QLabel(video_browse);
        label_tick3->setObjectName(QString::fromUtf8("label_tick3"));
        label_tick3->setGeometry(QRect(1148, 365, 20, 20));
        label_tick3->setStyleSheet(QString::fromUtf8("image: url(:/tu/Photo/selectflag.png);"));
        label_4 = new Label_photo_4(video_browse);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 420, 356, 265));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        label_21->raise();
        label_2->raise();
        label_4->raise();
        label_select->raise();
        label_select_all->raise();
        label_line->raise();
        label_left->raise();
        label_return->raise();
        label_deselect_all->raise();
        label_right->raise();
        label_delete->raise();
        label_num->raise();
        label_5->raise();
        label_tick4->raise();
        label_6->raise();
        label_tick6->raise();
        label_tick5->raise();
        label_tick2->raise();
        label_1->raise();
        label_tick1->raise();
        label_3->raise();
        label_tick3->raise();
        label_play_1->raise();
        label_play_2->raise();
        label_play_3->raise();
        label_play_5->raise();
        label_play_4->raise();
        label_play_6->raise();

        retranslateUi(video_browse);

        QMetaObject::connectSlotsByName(video_browse);
    } // setupUi

    void retranslateUi(QWidget *video_browse)
    {
        video_browse->setWindowTitle(QApplication::translate("video_browse", "Form", nullptr));
        label_select->setText(QString());
        label_select_all->setText(QString());
        label_line->setText(QString());
        label_left->setText(QString());
        label_return->setText(QString());
        label_deselect_all->setText(QString());
        label_right->setText(QString());
        label_delete->setText(QString());
        label_21->setText(QString());
        label_play_1->setText(QString());
        label_play_2->setText(QString());
        label_play_3->setText(QString());
        label_play_4->setText(QString());
        label_play_6->setText(QString());
        label_play_5->setText(QString());
        label_num->setText(QApplication::translate("video_browse", "1/10", nullptr));
        label_5->setText(QString());
        label_tick4->setText(QString());
        label_6->setText(QString());
        label_tick6->setText(QString());
        label_tick5->setText(QString());
        label_tick2->setText(QString());
        label_1->setText(QString());
        label_tick1->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label_tick3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class video_browse: public Ui_video_browse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_BROWSE_H
