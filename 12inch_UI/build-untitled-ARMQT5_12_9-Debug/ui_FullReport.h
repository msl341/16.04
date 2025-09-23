/********************************************************************************
** Form generated from reading UI file 'FullReport.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLREPORT_H
#define UI_FULLREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "mykey.h"

QT_BEGIN_NAMESPACE

class Ui_FullReport
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *Date;
    QLabel *Part;
    QLabel *Opinion;
    QLabel *labelGraphicviewLBKG;
    QLabel *ReportTitle;
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *editBtn;
    QPushButton *backBtn;
    QLabel *labelName;
    QLabel *labelAge;
    QLabel *labelID;
    DraggableGraphicsView *graphicsView;
    QLabel *Age;
    QLabel *Result;
    QLabel *labelResult;
    QLabel *labelOpinion;
    QLabel *labelGraphicviewRBKG;
    QLabel *labelSituation;
    QLabel *Situation;
    QLabel *labelPart;
    QLabel *labelDate;
    QLabel *labelPhotos;
    QLabel *labelBirth;
    QLabel *labelGender;
    QLabel *Gender;
    QLabel *labelDoctor;
    QLabel *Name;
    QLabel *Birth;
    QLabel *Doctor;
    QLabel *ID;
    QLabel *labelDescribe;
    QLabel *Describe;
    QWidget *page_2;

    void setupUi(QWidget *FullReport)
    {
        if (FullReport->objectName().isEmpty())
            FullReport->setObjectName(QString::fromUtf8("FullReport"));
        FullReport->resize(1280, 800);
        stackedWidget = new QStackedWidget(FullReport);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1280, 800));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/BKG.png);"));
        gridLayoutWidget = new QWidget(page);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 1241, 761));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Date = new QLabel(gridLayoutWidget);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(15);
        Date->setFont(font);
        Date->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Date, 3, 5, 1, 3);

        Part = new QLabel(gridLayoutWidget);
        Part->setObjectName(QString::fromUtf8("Part"));
        Part->setFont(font);
        Part->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Part, 2, 4, 1, 2);

        Opinion = new QLabel(gridLayoutWidget);
        Opinion->setObjectName(QString::fromUtf8("Opinion"));
        Opinion->setFont(font);
        Opinion->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;\n"
"border-bottom: 2px solid black;"));

        gridLayout->addWidget(Opinion, 11, 1, 1, 7);

        labelGraphicviewLBKG = new QLabel(gridLayoutWidget);
        labelGraphicviewLBKG->setObjectName(QString::fromUtf8("labelGraphicviewLBKG"));
        labelGraphicviewLBKG->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image:none;"));

        gridLayout->addWidget(labelGraphicviewLBKG, 6, 0, 1, 1);

        ReportTitle = new QLabel(gridLayoutWidget);
        ReportTitle->setObjectName(QString::fromUtf8("ReportTitle"));
        ReportTitle->setMinimumSize(QSize(0, 60));
        ReportTitle->setMaximumSize(QSize(16777215, 60));
        QFont font1;
        font1.setPointSize(26);
        ReportTitle->setFont(font1);
        ReportTitle->setStyleSheet(QString::fromUtf8("border-bottom: 2px solid black;\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-image: none;"));
        ReportTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ReportTitle, 0, 0, 1, 8);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(980, 0, 261, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        editBtn = new QPushButton(layoutWidget);
        editBtn->setObjectName(QString::fromUtf8("editBtn"));
        editBtn->setMinimumSize(QSize(100, 35));
        editBtn->setMaximumSize(QSize(100, 35));
        editBtn->setFocusPolicy(Qt::NoFocus);
        editBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 13pt \"Ubuntu\";\n"
"background-color: rgb(136, 138, 133);\n"
"border-radius:10px;"));
        editBtn->setFlat(true);

        horizontalLayout->addWidget(editBtn);

        backBtn = new QPushButton(layoutWidget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setMinimumSize(QSize(100, 35));
        backBtn->setMaximumSize(QSize(100, 35));
        backBtn->setFocusPolicy(Qt::NoFocus);
        backBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 13pt \"Ubuntu\";\n"
"background-color: rgb(136, 138, 133);\n"
"border-radius:10px;\n"
""));
        backBtn->setFlat(true);

        horizontalLayout->addWidget(backBtn);


        gridLayout->addWidget(widget, 13, 0, 1, 8);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMinimumSize(QSize(0, 50));
        labelName->setFont(font);
        labelName->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        labelName->setMargin(0);

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        labelAge = new QLabel(gridLayoutWidget);
        labelAge->setObjectName(QString::fromUtf8("labelAge"));
        labelAge->setMinimumSize(QSize(0, 40));
        labelAge->setFont(font);
        labelAge->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelAge, 1, 6, 1, 1);

        labelID = new QLabel(gridLayoutWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setMinimumSize(QSize(0, 50));
        labelID->setFont(font);
        labelID->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelID, 2, 0, 1, 1);

        graphicsView = new DraggableGraphicsView(gridLayoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(920, 0));
        graphicsView->setFocusPolicy(Qt::NoFocus);
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"	border:none;\n"
"	border-image:none;\n"
"	background-color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QWidget{\n"
"	border: none;\n"
"	border-image:none;\n"
"	background-color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	background-color:rgb(255, 255, 255);\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	width: 10px;\n"
"	margin-top:0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	background-color: rgb(60,100,242);\n"
"	min-height: 20px;\n"
"	border-radius: 5px;\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"	/*background-color: rgba(222,83,66,255);*/\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"	border: none;\n"
"	border-image:none;\n"
"	background-color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"	border: none;\n"
"	border-image:none;\n"
"	background-color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"	border-image:none;\n"
"	background-color: rgb(80, 80, 80);  /* \346\267"
                        "\261\347\201\260\350\211\262\347\267\232\346\242\235 */\n"
"	width: 3px;  /* \350\250\255\347\275\256\347\267\232\346\242\235\345\257\254\345\272\246 */\n"
"	margin-left: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-right: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-bottom:10px;\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical{\n"
"	border-image:none;\n"
"	background-color: rgb(80, 80, 80);  /* \346\267\261\347\201\260\350\211\262\347\267\232\346\242\235 */\n"
"	width: 3px;  /* \350\250\255\347\275\256\347\267\232\346\242\235\345\257\254\345\272\246 */\n"
"	margin-top:10px;\n"
"	margin-left: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-right: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	border: none;\n"
"}"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(graphicsView, 6, 1, 1, 6);

        Age = new QLabel(gridLayoutWidget);
        Age->setObjectName(QString::fromUtf8("Age"));
        Age->setFont(font);
        Age->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Age, 1, 7, 1, 1);

        Result = new QLabel(gridLayoutWidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setFont(font);
        Result->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(Result, 10, 1, 1, 7);

        labelResult = new QLabel(gridLayoutWidget);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));
        labelResult->setMinimumSize(QSize(0, 50));
        labelResult->setFont(font);
        labelResult->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(labelResult, 10, 0, 1, 1);

        labelOpinion = new QLabel(gridLayoutWidget);
        labelOpinion->setObjectName(QString::fromUtf8("labelOpinion"));
        labelOpinion->setMinimumSize(QSize(0, 50));
        labelOpinion->setFont(font);
        labelOpinion->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;\n"
"border-bottom: 2px solid black;"));

        gridLayout->addWidget(labelOpinion, 11, 0, 1, 1);

        labelGraphicviewRBKG = new QLabel(gridLayoutWidget);
        labelGraphicviewRBKG->setObjectName(QString::fromUtf8("labelGraphicviewRBKG"));
        labelGraphicviewRBKG->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image:none;\n"
""));

        gridLayout->addWidget(labelGraphicviewRBKG, 6, 7, 1, 1);

        labelSituation = new QLabel(gridLayoutWidget);
        labelSituation->setObjectName(QString::fromUtf8("labelSituation"));
        labelSituation->setMinimumSize(QSize(0, 50));
        labelSituation->setFont(font);
        labelSituation->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(labelSituation, 8, 0, 1, 1);

        Situation = new QLabel(gridLayoutWidget);
        Situation->setObjectName(QString::fromUtf8("Situation"));
        Situation->setFont(font);
        Situation->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(Situation, 8, 1, 1, 7);

        labelPart = new QLabel(gridLayoutWidget);
        labelPart->setObjectName(QString::fromUtf8("labelPart"));
        labelPart->setFont(font);
        labelPart->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelPart, 2, 3, 1, 1);

        labelDate = new QLabel(gridLayoutWidget);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));
        labelDate->setMinimumSize(QSize(150, 0));
        labelDate->setMaximumSize(QSize(150, 16777215));
        labelDate->setFont(font);
        labelDate->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelDate, 3, 4, 1, 1);

        labelPhotos = new QLabel(gridLayoutWidget);
        labelPhotos->setObjectName(QString::fromUtf8("labelPhotos"));
        labelPhotos->setMinimumSize(QSize(0, 40));
        labelPhotos->setFont(font);
        labelPhotos->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(labelPhotos, 5, 0, 1, 8);

        labelBirth = new QLabel(gridLayoutWidget);
        labelBirth->setObjectName(QString::fromUtf8("labelBirth"));
        labelBirth->setMinimumSize(QSize(0, 50));
        labelBirth->setMaximumSize(QSize(16777215, 16777215));
        labelBirth->setFont(font);
        labelBirth->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelBirth, 3, 0, 1, 1);

        labelGender = new QLabel(gridLayoutWidget);
        labelGender->setObjectName(QString::fromUtf8("labelGender"));
        labelGender->setMinimumSize(QSize(0, 40));
        labelGender->setFont(font);
        labelGender->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelGender, 1, 3, 1, 1);

        Gender = new QLabel(gridLayoutWidget);
        Gender->setObjectName(QString::fromUtf8("Gender"));
        Gender->setFont(font);
        Gender->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Gender, 1, 4, 1, 2);

        labelDoctor = new QLabel(gridLayoutWidget);
        labelDoctor->setObjectName(QString::fromUtf8("labelDoctor"));
        labelDoctor->setFont(font);
        labelDoctor->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(labelDoctor, 2, 6, 1, 1);

        Name = new QLabel(gridLayoutWidget);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setMinimumSize(QSize(220, 0));
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Name, 1, 1, 1, 2);

        Birth = new QLabel(gridLayoutWidget);
        Birth->setObjectName(QString::fromUtf8("Birth"));
        Birth->setMinimumSize(QSize(0, 40));
        Birth->setMaximumSize(QSize(16777215, 16777215));
        Birth->setFont(font);
        Birth->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Birth, 3, 1, 1, 3);

        Doctor = new QLabel(gridLayoutWidget);
        Doctor->setObjectName(QString::fromUtf8("Doctor"));
        Doctor->setFont(font);
        Doctor->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Doctor, 2, 7, 1, 1);

        ID = new QLabel(gridLayoutWidget);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setFont(font);
        ID->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(ID, 2, 1, 1, 2);

        labelDescribe = new QLabel(gridLayoutWidget);
        labelDescribe->setObjectName(QString::fromUtf8("labelDescribe"));
        labelDescribe->setMinimumSize(QSize(0, 50));
        labelDescribe->setFont(font);
        labelDescribe->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(labelDescribe, 9, 0, 1, 1);

        Describe = new QLabel(gridLayoutWidget);
        Describe->setObjectName(QString::fromUtf8("Describe"));
        Describe->setFont(font);
        Describe->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-top: 2px solid black;"));

        gridLayout->addWidget(Describe, 9, 1, 1, 7);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(FullReport);

        QMetaObject::connectSlotsByName(FullReport);
    } // setupUi

    void retranslateUi(QWidget *FullReport)
    {
        FullReport->setWindowTitle(QApplication::translate("FullReport", "Form", nullptr));
        Date->setText(QApplication::translate("FullReport", "unknown", nullptr));
        Part->setText(QApplication::translate("FullReport", "unknown", nullptr));
        Opinion->setText(QApplication::translate("FullReport", "none", nullptr));
        labelGraphicviewLBKG->setText(QString());
        ReportTitle->setText(QApplication::translate("FullReport", "Report", nullptr));
        editBtn->setText(QApplication::translate("FullReport", "Edit", nullptr));
        backBtn->setText(QApplication::translate("FullReport", "Back", nullptr));
        labelName->setText(QApplication::translate("FullReport", "     Name :", nullptr));
        labelAge->setText(QApplication::translate("FullReport", "Age :", nullptr));
        labelID->setText(QApplication::translate("FullReport", "     ID :", nullptr));
        Age->setText(QApplication::translate("FullReport", "unknown", nullptr));
        Result->setText(QApplication::translate("FullReport", "none", nullptr));
        labelResult->setText(QApplication::translate("FullReport", "     Result :", nullptr));
        labelOpinion->setText(QApplication::translate("FullReport", "     Opinion :", nullptr));
        labelGraphicviewRBKG->setText(QString());
        labelSituation->setText(QApplication::translate("FullReport", "     Situation :", nullptr));
        Situation->setText(QApplication::translate("FullReport", "none", nullptr));
        labelPart->setText(QApplication::translate("FullReport", "Part :", nullptr));
        labelDate->setText(QApplication::translate("FullReport", "Date :", nullptr));
        labelPhotos->setText(QApplication::translate("FullReport", "    Photos :", nullptr));
        labelBirth->setText(QApplication::translate("FullReport", "     Birth :", nullptr));
        labelGender->setText(QApplication::translate("FullReport", "Gender :", nullptr));
        Gender->setText(QApplication::translate("FullReport", "unknown", nullptr));
        labelDoctor->setText(QApplication::translate("FullReport", "Doctor :", nullptr));
        Name->setText(QApplication::translate("FullReport", "unknown", nullptr));
        Birth->setText(QApplication::translate("FullReport", "unknown", nullptr));
        Doctor->setText(QApplication::translate("FullReport", "unknown", nullptr));
        ID->setText(QApplication::translate("FullReport", "unknown", nullptr));
        labelDescribe->setText(QApplication::translate("FullReport", "     Describe :", nullptr));
        Describe->setText(QApplication::translate("FullReport", "none", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FullReport: public Ui_FullReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLREPORT_H
