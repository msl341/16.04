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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "zhukuang.h"

QT_BEGIN_NAMESPACE

class Ui_zhukuang
{
public:
    QLabel *label_b;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    Label_video *label_video;
    Label_start *label_start;
    Label_photo *label_photo;
    QPushButton *browseReportBtn;
    QPushButton *addReportBtn;
    Label_system *label_system;
    QPushButton *nameBtnStart;
    QPushButton *nameBtnPhoto;
    QPushButton *nameBtnVideo;
    QPushButton *nameBtnSysSet;
    QPushButton *nameBtnAdd;
    QPushButton *nameBtnBrowse;
    AW2 *aw2;

    void setupUi(QWidget *zhukuang)
    {
        if (zhukuang->objectName().isEmpty())
            zhukuang->setObjectName(QString::fromUtf8("zhukuang"));
        zhukuang->resize(1280, 800);
        zhukuang->setStyleSheet(QString::fromUtf8(""));
        label_b = new QLabel(zhukuang);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(0, 0, 1280, 805));
        label_b->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/BKG.png);"));
        layoutWidget = new QWidget(zhukuang);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 70, 1081, 681));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_video = new Label_video(layoutWidget);
        label_video->setObjectName(QString::fromUtf8("label_video"));
        label_video->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_video->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_video.png")));
        label_video->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_video, 0, 2, 1, 1);

        label_start = new Label_start(layoutWidget);
        label_start->setObjectName(QString::fromUtf8("label_start"));
        label_start->setMaximumSize(QSize(290, 290));
        label_start->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_start->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_start.png")));
        label_start->setScaledContents(false);
        label_start->setAlignment(Qt::AlignCenter);
        label_start->setMargin(0);

        gridLayout->addWidget(label_start, 0, 0, 1, 1);

        label_photo = new Label_photo(layoutWidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_photo->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_photo.png")));
        label_photo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_photo, 0, 1, 1, 1);

        browseReportBtn = new QPushButton(layoutWidget);
        browseReportBtn->setObjectName(QString::fromUtf8("browseReportBtn"));
        browseReportBtn->setMinimumSize(QSize(290, 290));
        browseReportBtn->setMaximumSize(QSize(290, 290));
        QFont font;
        font.setPointSize(32);
        browseReportBtn->setFont(font);
        browseReportBtn->setFocusPolicy(Qt::NoFocus);
        browseReportBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);\n"
"background-color: transparent;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_browseReport.png"), QSize(), QIcon::Normal, QIcon::Off);
        browseReportBtn->setIcon(icon);
        browseReportBtn->setIconSize(QSize(180, 180));

        gridLayout->addWidget(browseReportBtn, 1, 2, 1, 1);

        addReportBtn = new QPushButton(layoutWidget);
        addReportBtn->setObjectName(QString::fromUtf8("addReportBtn"));
        addReportBtn->setMinimumSize(QSize(290, 290));
        addReportBtn->setMaximumSize(QSize(290, 290));
        addReportBtn->setFont(font);
        addReportBtn->setFocusPolicy(Qt::NoFocus);
        addReportBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);\n"
"background-color: transparent;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_addReport.png"), QSize(), QIcon::Normal, QIcon::Off);
        addReportBtn->setIcon(icon1);
        addReportBtn->setIconSize(QSize(180, 180));

        gridLayout->addWidget(addReportBtn, 1, 1, 1, 1);

        label_system = new Label_system(layoutWidget);
        label_system->setObjectName(QString::fromUtf8("label_system"));
        label_system->setMinimumSize(QSize(290, 290));
        label_system->setMaximumSize(QSize(290, 290));
        label_system->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/iconBKG.png);"));
        label_system->setPixmap(QPixmap(QString::fromUtf8(":/tu/ALL-IN-ONE ICON/icon_system.png")));
        label_system->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_system, 1, 0, 1, 1);

        gridLayout->setColumnMinimumWidth(0, 290);
        gridLayout->setColumnMinimumWidth(1, 290);
        gridLayout->setColumnMinimumWidth(2, 290);
        gridLayout->setRowMinimumHeight(0, 290);
        gridLayout->setRowMinimumHeight(1, 290);
        nameBtnStart = new QPushButton(zhukuang);
        nameBtnStart->setObjectName(QString::fromUtf8("nameBtnStart"));
        nameBtnStart->setGeometry(QRect(140, 330, 290, 40));
        QFont font1;
        font1.setPointSize(20);
        nameBtnStart->setFont(font1);
        nameBtnStart->setFocusPolicy(Qt::NoFocus);
        nameBtnStart->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnStart->setFlat(true);
        nameBtnPhoto = new QPushButton(zhukuang);
        nameBtnPhoto->setObjectName(QString::fromUtf8("nameBtnPhoto"));
        nameBtnPhoto->setGeometry(QRect(485, 330, 290, 40));
        nameBtnPhoto->setFont(font1);
        nameBtnPhoto->setFocusPolicy(Qt::NoFocus);
        nameBtnPhoto->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnPhoto->setFlat(true);
        nameBtnVideo = new QPushButton(zhukuang);
        nameBtnVideo->setObjectName(QString::fromUtf8("nameBtnVideo"));
        nameBtnVideo->setGeometry(QRect(830, 330, 290, 40));
        nameBtnVideo->setFont(font1);
        nameBtnVideo->setFocusPolicy(Qt::NoFocus);
        nameBtnVideo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnVideo->setFlat(true);
        nameBtnSysSet = new QPushButton(zhukuang);
        nameBtnSysSet->setObjectName(QString::fromUtf8("nameBtnSysSet"));
        nameBtnSysSet->setGeometry(QRect(140, 660, 290, 40));
        nameBtnSysSet->setFont(font1);
        nameBtnSysSet->setFocusPolicy(Qt::NoFocus);
        nameBtnSysSet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnSysSet->setFlat(true);
        nameBtnAdd = new QPushButton(zhukuang);
        nameBtnAdd->setObjectName(QString::fromUtf8("nameBtnAdd"));
        nameBtnAdd->setGeometry(QRect(485, 660, 290, 40));
        nameBtnAdd->setFont(font1);
        nameBtnAdd->setFocusPolicy(Qt::NoFocus);
        nameBtnAdd->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnAdd->setFlat(false);
        nameBtnBrowse = new QPushButton(zhukuang);
        nameBtnBrowse->setObjectName(QString::fromUtf8("nameBtnBrowse"));
        nameBtnBrowse->setGeometry(QRect(830, 660, 290, 40));
        nameBtnBrowse->setFont(font1);
        nameBtnBrowse->setFocusPolicy(Qt::NoFocus);
        nameBtnBrowse->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"background-color:transparent;\n"
"border-image: none;"));
        nameBtnBrowse->setFlat(true);
        aw2 = new AW2(zhukuang);
        aw2->setObjectName(QString::fromUtf8("aw2"));
        aw2->setGeometry(QRect(1210, 220, 67, 17));

        retranslateUi(zhukuang);

        QMetaObject::connectSlotsByName(zhukuang);
    } // setupUi

    void retranslateUi(QWidget *zhukuang)
    {
        zhukuang->setWindowTitle(QApplication::translate("zhukuang", "Form", nullptr));
        label_b->setText(QString());
        label_video->setText(QString());
        label_start->setText(QString());
        label_photo->setText(QString());
        browseReportBtn->setText(QString());
        addReportBtn->setText(QString());
        label_system->setText(QString());
        nameBtnStart->setText(QApplication::translate("zhukuang", "Start", nullptr));
        nameBtnPhoto->setText(QApplication::translate("zhukuang", "Photo", nullptr));
        nameBtnVideo->setText(QApplication::translate("zhukuang", "Video", nullptr));
        nameBtnSysSet->setText(QApplication::translate("zhukuang", "System Set", nullptr));
        nameBtnAdd->setText(QApplication::translate("zhukuang", "Add Report", nullptr));
        nameBtnBrowse->setText(QApplication::translate("zhukuang", "Browse Report", nullptr));
        aw2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class zhukuang: public Ui_zhukuang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUKUANG_H
