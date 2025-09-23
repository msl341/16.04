/********************************************************************************
** Form generated from reading UI file 'zhukuang.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUKUANG_H
#define UI_ZHUKUANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "zhukuang.h"

QT_BEGIN_NAMESPACE

class Ui_zhukuang
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    Gnj *gnj;
    SZ *sz;
    QStackedWidget *third_stack;
    QWidget *page;
    QPushButton *label_photograph;
    QPushButton *label_video;
    QPushButton *m_pBtn_Awb;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *m_pBtn_Freeze;
    QLabel *label_8;
    QPushButton *m_pBtn_AE;
    QLabel *label_9;
    QPushButton *m_pBtn_Rot;
    QLabel *label_10;
    QPushButton *m_pBtn_DrawShape;
    QLabel *label_19;
    QLabel *label_20;
    QWidget *page_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *seek_photo;
    QPushButton *seek_video;
    QLabel *label_12;
    QPushButton *m_pBtn_DateSet;
    QLabel *label_13;
    QPushButton *m_pBtn_LanSet;
    QLabel *label_14;
    QPushButton *m_pBtn_Format;
    QLabel *label_15;
    QPushButton *m_pBtn_Reset;
    QPushButton *m_pBtn_Upgrade;
    QLabel *label_16;
    QLabel *prompt_photo;
    QLabel *video_time;
    QWidget *m_pWdg_Panel_DrawShape;
    QLabel *m_pLb_DrawShape_Title;
    QPushButton *m_pBtn_DrawShape_FX;
    QPushButton *m_pBtn_DrawShape_YX;
    QPushButton *m_pBtn_DrawShape_BJX;
    QLabel *label_11;
    QLabel *m_pLb_Date;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QWidget *zhukuang)
    {
        if (zhukuang->objectName().isEmpty())
            zhukuang->setObjectName(QString::fromUtf8("zhukuang"));
        zhukuang->resize(1280, 800);
        zhukuang->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(zhukuang);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/1-drawshape_fx_bg.png);"));
        label_2 = new QLabel(zhukuang);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(970, 20, 311, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/tu/Res/Set/boundary.png")));
        label_3 = new QLabel(zhukuang);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(970, 120, 321, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/tu/Res/Set/boundary.png")));
        gnj = new Gnj(zhukuang);
        gnj->setObjectName(QString::fromUtf8("gnj"));
        gnj->setGeometry(QRect(1000, 50, 81, 51));
        gnj->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/gnj-1.png);"));
        sz = new SZ(zhukuang);
        sz->setObjectName(QString::fromUtf8("sz"));
        sz->setGeometry(QRect(1160, 50, 81, 51));
        sz->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/sz-1.png);"));
        third_stack = new QStackedWidget(zhukuang);
        third_stack->setObjectName(QString::fromUtf8("third_stack"));
        third_stack->setGeometry(QRect(970, 140, 311, 651));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_photograph = new QPushButton(page);
        label_photograph->setObjectName(QString::fromUtf8("label_photograph"));
        label_photograph->setGeometry(QRect(0, 60, 161, 111));
        label_photograph->setFocusPolicy(Qt::NoFocus);
        label_photograph->setStyleSheet(QString::fromUtf8("#label_photograph { \n"
"    border-image: url(:/tu/Res/pz.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#label_photograph:pressed { \n"
"    border-image: url(:/tu/Res/pz.png); \n"
"}"));
        label_video = new QPushButton(page);
        label_video->setObjectName(QString::fromUtf8("label_video"));
        label_video->setGeometry(QRect(165, 60, 141, 111));
        label_video->setFocusPolicy(Qt::NoFocus);
        label_video->setStyleSheet(QString::fromUtf8("#label_video { \n"
"    border-image: url(:/tu/Res/sx.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#label_video:pressed { \n"
"    border-image: url(:/tu/Res/sx.png); \n"
"}"));
        m_pBtn_Awb = new QPushButton(page);
        m_pBtn_Awb->setObjectName(QString::fromUtf8("m_pBtn_Awb"));
        m_pBtn_Awb->setGeometry(QRect(30, 230, 81, 71));
        m_pBtn_Awb->setFocusPolicy(Qt::NoFocus);
        m_pBtn_Awb->setStyleSheet(QString::fromUtf8("#m_pBtn_Awb { \n"
"    border-image: url(:/tu/Res/MainWindow/awb.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_Awb:pressed { \n"
"    border-image: url(:/tu/Res/MainWindow/awb_sel.png); \n"
"}"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 180, 101, 51));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 180, 121, 51));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_Freeze = new QPushButton(page);
        m_pBtn_Freeze->setObjectName(QString::fromUtf8("m_pBtn_Freeze"));
        m_pBtn_Freeze->setGeometry(QRect(180, 220, 101, 81));
        m_pBtn_Freeze->setFocusPolicy(Qt::NoFocus);
        m_pBtn_Freeze->setStyleSheet(QString::fromUtf8("#m_pBtn_Freeze { \n"
"	border-image: url(:/tu/Res/free-1.png);\n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_Freeze:pressed { \n"
"   	border-image: url(:/tu/Res/free-2.png);\n"
"}"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 300, 121, 61));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_AE = new QPushButton(page);
        m_pBtn_AE->setObjectName(QString::fromUtf8("m_pBtn_AE"));
        m_pBtn_AE->setGeometry(QRect(30, 350, 81, 71));
        m_pBtn_AE->setFocusPolicy(Qt::NoFocus);
        m_pBtn_AE->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/MainWindow/ae-1.png);"));
        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(180, 300, 131, 61));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_Rot = new QPushButton(page);
        m_pBtn_Rot->setObjectName(QString::fromUtf8("m_pBtn_Rot"));
        m_pBtn_Rot->setGeometry(QRect(180, 350, 91, 71));
        m_pBtn_Rot->setFocusPolicy(Qt::NoFocus);
        m_pBtn_Rot->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/MainWindow/rot.png);"));
        label_10 = new QLabel(page);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 430, 241, 41));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_DrawShape = new QPushButton(page);
        m_pBtn_DrawShape->setObjectName(QString::fromUtf8("m_pBtn_DrawShape"));
        m_pBtn_DrawShape->setGeometry(QRect(30, 480, 91, 61));
        m_pBtn_DrawShape->setFocusPolicy(Qt::NoFocus);
        m_pBtn_DrawShape->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/drawshape.png);"));
        label_19 = new QLabel(page);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 20, 101, 51));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        label_20 = new QLabel(page);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(180, 20, 101, 51));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        third_stack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 101, 51));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 20, 111, 51));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        seek_photo = new QPushButton(page_2);
        seek_photo->setObjectName(QString::fromUtf8("seek_photo"));
        seek_photo->setGeometry(QRect(30, 70, 91, 61));
        seek_photo->setFocusPolicy(Qt::NoFocus);
        seek_photo->setStyleSheet(QString::fromUtf8("#seek_photo { \n"
"    border-image: url(:/tu/Res/Set/photoshow.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#seek_photo:pressed { \n"
"    border-image: url(:/tu/Res/Set/photoshow_sel.png); \n"
"}"));
        seek_video = new QPushButton(page_2);
        seek_video->setObjectName(QString::fromUtf8("seek_video"));
        seek_video->setGeometry(QRect(180, 70, 91, 61));
        seek_video->setFocusPolicy(Qt::NoFocus);
        seek_video->setStyleSheet(QString::fromUtf8("#seek_video { \n"
"    border-image: url(:/tu/Res/Set/videoplay.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#seek_video:pressed { \n"
"    border-image: url(:/tu/Res/Set/videoplay_sel.png); \n"
"}"));
        label_12 = new QLabel(page_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 150, 121, 51));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_DateSet = new QPushButton(page_2);
        m_pBtn_DateSet->setObjectName(QString::fromUtf8("m_pBtn_DateSet"));
        m_pBtn_DateSet->setGeometry(QRect(30, 200, 81, 71));
        m_pBtn_DateSet->setFocusPolicy(Qt::NoFocus);
        m_pBtn_DateSet->setStyleSheet(QString::fromUtf8("#m_pBtn_DateSet { \n"
"    border-image: url(:/tu/Res/Set/dateset.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_DateSet:pressed { \n"
"    border-image: url(:/tu/Res/Set/dateset_sel.png); \n"
"}"));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(180, 150, 121, 51));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_LanSet = new QPushButton(page_2);
        m_pBtn_LanSet->setObjectName(QString::fromUtf8("m_pBtn_LanSet"));
        m_pBtn_LanSet->setGeometry(QRect(180, 200, 81, 71));
        m_pBtn_LanSet->setFocusPolicy(Qt::NoFocus);
        m_pBtn_LanSet->setStyleSheet(QString::fromUtf8("#m_pBtn_LanSet { \n"
"    border-image: url(:/tu/Res/Set/lanset.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_LanSet:pressed { \n"
"    border-image: url(:/tu/Res/Set/lanset_sel.png); \n"
"}\n"
""));
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 280, 121, 61));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_Format = new QPushButton(page_2);
        m_pBtn_Format->setObjectName(QString::fromUtf8("m_pBtn_Format"));
        m_pBtn_Format->setGeometry(QRect(30, 330, 81, 71));
        m_pBtn_Format->setFocusPolicy(Qt::NoFocus);
        m_pBtn_Format->setStyleSheet(QString::fromUtf8("#m_pBtn_Format { \n"
"    border-image: url(:/tu/Res/Set/format.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_Format:pressed { \n"
"    border-image: url(:/tu/Res/Set/format_sel.png); \n"
"}\n"
""));
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 280, 121, 61));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        m_pBtn_Reset = new QPushButton(page_2);
        m_pBtn_Reset->setObjectName(QString::fromUtf8("m_pBtn_Reset"));
        m_pBtn_Reset->setGeometry(QRect(180, 330, 81, 71));
        m_pBtn_Reset->setFocusPolicy(Qt::NoFocus);
        m_pBtn_Reset->setStyleSheet(QString::fromUtf8("#m_pBtn_Reset { \n"
"    border-image: url(:/tu/Res/Set/reset.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_Reset:pressed { \n"
"    border-image: url(:/tu/Res/Set/reset_sel.png); \n"
"}"));
        m_pBtn_Upgrade = new QPushButton(page_2);
        m_pBtn_Upgrade->setObjectName(QString::fromUtf8("m_pBtn_Upgrade"));
        m_pBtn_Upgrade->setGeometry(QRect(30, 460, 81, 71));
        m_pBtn_Upgrade->setFocusPolicy(Qt::NoFocus);
        m_pBtn_Upgrade->setStyleSheet(QString::fromUtf8("#m_pBtn_Upgrade { \n"
"    border-image: url(:/tu/Res/Set/upgrade.png); \n"
"    border: none; \n"
"    background: transparent; \n"
"}\n"
"#m_pBtn_Upgrade:pressed { \n"
"    border-image: url(:/tu/Res/Set/upgrade_sel.png); \n"
"}"));
        label_16 = new QLabel(page_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 410, 161, 51));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        third_stack->addWidget(page_2);
        prompt_photo = new QLabel(zhukuang);
        prompt_photo->setObjectName(QString::fromUtf8("prompt_photo"));
        prompt_photo->setGeometry(QRect(150, 100, 231, 41));
        prompt_photo->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);font-size: 32px;font: bold;"));
        video_time = new QLabel(zhukuang);
        video_time->setObjectName(QString::fromUtf8("video_time"));
        video_time->setGeometry(QRect(160, 180, 141, 41));
        video_time->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);font-size: 32px;font: bold;\n"
""));
        m_pWdg_Panel_DrawShape = new QWidget(zhukuang);
        m_pWdg_Panel_DrawShape->setObjectName(QString::fromUtf8("m_pWdg_Panel_DrawShape"));
        m_pWdg_Panel_DrawShape->setGeometry(QRect(780, 540, 151, 191));
        m_pLb_DrawShape_Title = new QLabel(m_pWdg_Panel_DrawShape);
        m_pLb_DrawShape_Title->setObjectName(QString::fromUtf8("m_pLb_DrawShape_Title"));
        m_pLb_DrawShape_Title->setGeometry(QRect(0, 0, 91, 31));
        m_pLb_DrawShape_Title->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/drawshape_title.png);"));
        m_pBtn_DrawShape_FX = new QPushButton(m_pWdg_Panel_DrawShape);
        m_pBtn_DrawShape_FX->setObjectName(QString::fromUtf8("m_pBtn_DrawShape_FX"));
        m_pBtn_DrawShape_FX->setGeometry(QRect(90, 0, 60, 60));
        m_pBtn_DrawShape_FX->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/drawshape_fx_sel.png);"));
        m_pBtn_DrawShape_YX = new QPushButton(m_pWdg_Panel_DrawShape);
        m_pBtn_DrawShape_YX->setObjectName(QString::fromUtf8("m_pBtn_DrawShape_YX"));
        m_pBtn_DrawShape_YX->setGeometry(QRect(90, 60, 60, 60));
        m_pBtn_DrawShape_YX->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/drawshape_yx.png);"));
        m_pBtn_DrawShape_BJX = new QPushButton(m_pWdg_Panel_DrawShape);
        m_pBtn_DrawShape_BJX->setObjectName(QString::fromUtf8("m_pBtn_DrawShape_BJX"));
        m_pBtn_DrawShape_BJX->setGeometry(QRect(90, 120, 60, 60));
        m_pBtn_DrawShape_BJX->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/Set/drawshape_bjx.png);"));
        label_11 = new QLabel(zhukuang);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 0, 81, 41));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/lg.png);"));
        m_pLb_Date = new QLabel(zhukuang);
        m_pLb_Date->setObjectName(QString::fromUtf8("m_pLb_Date"));
        m_pLb_Date->setGeometry(QRect(500, 20, 400, 28));
        m_pLb_Date->setStyleSheet(QString::fromUtf8("color:white;font-size: 25px;"));
        label_17 = new QLabel(zhukuang);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 720, 61, 31));
        label_17->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/MainWindow/elec2.png);"));
        label_18 = new QLabel(zhukuang);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 120, 61, 31));
        label_18->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/Res/usb_ts.png);"));

        retranslateUi(zhukuang);

        third_stack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(zhukuang);
    } // setupUi

    void retranslateUi(QWidget *zhukuang)
    {
        zhukuang->setWindowTitle(QApplication::translate("zhukuang", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        gnj->setText(QString());
        sz->setText(QString());
        label_photograph->setText(QString());
        label_video->setText(QString());
        m_pBtn_Awb->setText(QString());
        label_6->setText(QString());
        label_7->setText(QApplication::translate("zhukuang", "\345\206\273\347\273\223\347\224\273\351\235\242", nullptr));
        m_pBtn_Freeze->setText(QString());
        label_8->setText(QApplication::translate("zhukuang", "AE", nullptr));
        m_pBtn_AE->setText(QString());
        label_9->setText(QApplication::translate("zhukuang", "\347\224\273\351\235\242\346\227\213\350\275\254", nullptr));
        m_pBtn_Rot->setText(QString());
        label_10->setText(QApplication::translate("zhukuang", "\345\233\276\345\203\217\347\252\227\345\217\243\345\275\242\347\212\266", nullptr));
        m_pBtn_DrawShape->setText(QString());
        label_19->setText(QApplication::translate("zhukuang", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        label_20->setText(QApplication::translate("zhukuang", "\344\277\235\345\255\230\350\247\206\351\242\221", nullptr));
        label_4->setText(QApplication::translate("zhukuang", "\345\233\276\347\211\207\346\237\245\347\234\213", nullptr));
        label_5->setText(QApplication::translate("zhukuang", "\350\247\206\351\242\221\346\237\245\347\234\213", nullptr));
        seek_photo->setText(QString());
        seek_video->setText(QString());
        label_12->setText(QApplication::translate("zhukuang", "\346\227\266\351\227\264\350\256\276\347\275\256", nullptr));
        m_pBtn_DateSet->setText(QString());
        label_13->setText(QApplication::translate("zhukuang", "\350\257\255\350\250\200\350\256\276\347\275\256", nullptr));
        m_pBtn_LanSet->setText(QString());
        label_14->setText(QApplication::translate("zhukuang", "\346\240\274\345\274\217\345\214\226", nullptr));
        m_pBtn_Format->setText(QString());
        label_15->setText(QApplication::translate("zhukuang", "\351\207\215\347\275\256\350\256\276\347\275\256", nullptr));
        m_pBtn_Reset->setText(QString());
        m_pBtn_Upgrade->setText(QString());
        label_16->setText(QApplication::translate("zhukuang", "\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
        prompt_photo->setText(QApplication::translate("zhukuang", "taking a photo", nullptr));
        video_time->setText(QString());
        m_pLb_DrawShape_Title->setText(QString());
        m_pBtn_DrawShape_FX->setText(QString());
        m_pBtn_DrawShape_YX->setText(QString());
        m_pBtn_DrawShape_BJX->setText(QString());
        label_11->setText(QString());
        m_pLb_Date->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class zhukuang: public Ui_zhukuang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUKUANG_H
