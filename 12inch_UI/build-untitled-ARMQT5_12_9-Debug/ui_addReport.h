/********************************************************************************
** Form generated from reading UI file 'addReport.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREPORT_H
#define UI_ADDREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <addReport.h>
#include "mykey.h"

QT_BEGIN_NAMESPACE

class Ui_addReport
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *infoWidget;
    QGridLayout *gridLayout_2;
    QLabel *patientGender;
    QWidget *genderWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *maleBtn;
    QLabel *maleLabel;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *femaleBtn;
    QLabel *femaleLabel;
    QSpacerItem *horizontalSpacer_6;
    QLabel *patientID;
    QSpacerItem *horizontalSpacer;
    QLabel *patientAge;
    QWidget *buttonWidget;
    QPushButton *saveBtn;
    QPushButton *checkBtn;
    showKeyBoardLineEdit *enterID;
    showKeyBoardLineEdit *enterName;
    QLabel *describeLabel;
    showKeyBoardLineEdit *enterAge;
    showKeyBoardPlainTextEdit *enterDescribe;
    QSpacerItem *horizontalSpacer_2;
    QLabel *infoLabel;
    QLabel *patientBirth;
    QLabel *patientName;
    focusOutLineEdit *enterBirth;
    QWidget *addPhotoWidget;
    QGridLayout *gridLayout_3;
    QLabel *labelResult;
    QLabel *labelOpinion;
    QWidget *buttonWidget2;
    QPushButton *previewBtn;
    QPushButton *backBtn;
    QPushButton *reselectBtn;
    focusOutLineEdit *enterDoctor;
    QLabel *labelPart;
    focusOutLineEdit *enterSituation;
    focusOutLineEdit *enterOpinion;
    QWidget *widget;
    QPushButton *addBtn;
    QPushButton *removeBtn;
    QLabel *labelDoctor;
    QSpacerItem *horizontalSpacer_4;
    focusOutLineEdit *enterPart;
    focusOutLineEdit *enterResult;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelSituation;
    QLabel *addPhotoLabel;
    DraggableGraphicsView *graphicsView;
    QWidget *page_2;
    QLabel *label;
    QPushButton *backBtn_noDatabase;

    void setupUi(QWidget *addReport)
    {
        if (addReport->objectName().isEmpty())
            addReport->setObjectName(QString::fromUtf8("addReport"));
        addReport->setWindowModality(Qt::NonModal);
        addReport->resize(1280, 800);
        stackedWidget = new QStackedWidget(addReport);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1280, 800));
        stackedWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/BKG.png);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        infoWidget = new QWidget(page);
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        infoWidget->setGeometry(QRect(70, 40, 550, 720));
        infoWidget->setContextMenuPolicy(Qt::NoContextMenu);
        infoWidget->setLayoutDirection(Qt::LeftToRight);
        infoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:35px;\n"
"border-image:none;\n"
"border:2px solid white"));
        gridLayout_2 = new QGridLayout(infoWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        patientGender = new QLabel(infoWidget);
        patientGender->setObjectName(QString::fromUtf8("patientGender"));
        patientGender->setMinimumSize(QSize(150, 50));
        patientGender->setMaximumSize(QSize(150, 1666666));
        QFont font;
        font.setPointSize(16);
        patientGender->setFont(font);
        patientGender->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        patientGender->setAlignment(Qt::AlignVCenter);
        patientGender->setMargin(0);
        patientGender->setIndent(-1);

        gridLayout_2->addWidget(patientGender, 5, 1, 1, 1);

        genderWidget = new QWidget(infoWidget);
        genderWidget->setObjectName(QString::fromUtf8("genderWidget"));
        genderWidget->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(genderWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        maleBtn = new QPushButton(genderWidget);
        maleBtn->setObjectName(QString::fromUtf8("maleBtn"));
        maleBtn->setMinimumSize(QSize(30, 30));
        maleBtn->setMaximumSize(QSize(30, 30));
        maleBtn->setFocusPolicy(Qt::NoFocus);
        maleBtn->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        maleBtn->setProperty("clicked", QVariant(false));

        horizontalLayout->addWidget(maleBtn);

        maleLabel = new QLabel(genderWidget);
        maleLabel->setObjectName(QString::fromUtf8("maleLabel"));
        maleLabel->setMinimumSize(QSize(0, 30));
        maleLabel->setMaximumSize(QSize(16777215, 30));
        maleLabel->setFont(font);
        maleLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        maleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(maleLabel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        femaleBtn = new QPushButton(genderWidget);
        femaleBtn->setObjectName(QString::fromUtf8("femaleBtn"));
        femaleBtn->setMinimumSize(QSize(30, 30));
        femaleBtn->setMaximumSize(QSize(30, 30));
        femaleBtn->setFocusPolicy(Qt::NoFocus);
        femaleBtn->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        femaleBtn->setProperty("clicked", QVariant(false));

        horizontalLayout->addWidget(femaleBtn);

        femaleLabel = new QLabel(genderWidget);
        femaleLabel->setObjectName(QString::fromUtf8("femaleLabel"));
        femaleLabel->setMinimumSize(QSize(0, 30));
        femaleLabel->setMaximumSize(QSize(16777215, 30));
        femaleLabel->setFont(font);
        femaleLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        femaleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(femaleLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout_2->addWidget(genderWidget, 5, 2, 1, 1);

        patientID = new QLabel(infoWidget);
        patientID->setObjectName(QString::fromUtf8("patientID"));
        patientID->setMinimumSize(QSize(150, 50));
        patientID->setFont(font);
        patientID->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        patientID->setAlignment(Qt::AlignVCenter);

        gridLayout_2->addWidget(patientID, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 7, 1);

        patientAge = new QLabel(infoWidget);
        patientAge->setObjectName(QString::fromUtf8("patientAge"));
        patientAge->setMinimumSize(QSize(150, 50));
        patientAge->setFont(font);
        patientAge->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        patientAge->setAlignment(Qt::AlignVCenter);

        gridLayout_2->addWidget(patientAge, 4, 1, 1, 1);

        buttonWidget = new QWidget(infoWidget);
        buttonWidget->setObjectName(QString::fromUtf8("buttonWidget"));
        buttonWidget->setMinimumSize(QSize(0, 80));
        buttonWidget->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent;\n"
"border-image:none;"));
        saveBtn = new QPushButton(buttonWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(0, 10, 80, 50));
        saveBtn->setMinimumSize(QSize(0, 0));
        saveBtn->setFont(font);
        saveBtn->setFocusPolicy(Qt::NoFocus);
        saveBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));
        checkBtn = new QPushButton(buttonWidget);
        checkBtn->setObjectName(QString::fromUtf8("checkBtn"));
        checkBtn->setGeometry(QRect(426, 10, 80, 50));
        checkBtn->setMinimumSize(QSize(0, 0));
        checkBtn->setFont(font);
        checkBtn->setFocusPolicy(Qt::NoFocus);
        checkBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));

        gridLayout_2->addWidget(buttonWidget, 9, 1, 1, 2, Qt::AlignTop);

        enterID = new showKeyBoardLineEdit(infoWidget);
        enterID->setObjectName(QString::fromUtf8("enterID"));
        enterID->setMinimumSize(QSize(350, 50));
        enterID->setFont(font);
        enterID->setFocusPolicy(Qt::ClickFocus);
        enterID->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        enterID->setInputMethodHints(Qt::ImhNone);
        enterID->setInputMask(QString::fromUtf8(""));

        gridLayout_2->addWidget(enterID, 1, 2, 1, 1);

        enterName = new showKeyBoardLineEdit(infoWidget);
        enterName->setObjectName(QString::fromUtf8("enterName"));
        enterName->setMinimumSize(QSize(350, 50));
        enterName->setFont(font);
        enterName->setFocusPolicy(Qt::ClickFocus);
        enterName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(enterName, 2, 2, 1, 1);

        describeLabel = new QLabel(infoWidget);
        describeLabel->setObjectName(QString::fromUtf8("describeLabel"));
        describeLabel->setFont(font);
        describeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(186, 189, 182);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"border:none;"));
        describeLabel->setMargin(0);

        gridLayout_2->addWidget(describeLabel, 6, 1, 1, 2);

        enterAge = new showKeyBoardLineEdit(infoWidget);
        enterAge->setObjectName(QString::fromUtf8("enterAge"));
        enterAge->setMinimumSize(QSize(350, 50));
        enterAge->setFont(font);
        enterAge->setFocusPolicy(Qt::ClickFocus);
        enterAge->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(enterAge, 4, 2, 1, 1);

        enterDescribe = new showKeyBoardPlainTextEdit(infoWidget);
        enterDescribe->setObjectName(QString::fromUtf8("enterDescribe"));
        enterDescribe->setFocusPolicy(Qt::ClickFocus);
        enterDescribe->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:0px;"));

        gridLayout_2->addWidget(enterDescribe, 7, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 5, 3, 1, 1);

        infoLabel = new QLabel(infoWidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setMinimumSize(QSize(0, 80));
        QFont font1;
        font1.setPointSize(20);
        infoLabel->setFont(font1);
        infoLabel->setStyleSheet(QString::fromUtf8("border:none;"));

        gridLayout_2->addWidget(infoLabel, 0, 1, 1, 2);

        patientBirth = new QLabel(infoWidget);
        patientBirth->setObjectName(QString::fromUtf8("patientBirth"));
        patientBirth->setMinimumSize(QSize(150, 50));
        patientBirth->setFont(font);
        patientBirth->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        patientBirth->setAlignment(Qt::AlignVCenter);

        gridLayout_2->addWidget(patientBirth, 3, 1, 1, 1);

        patientName = new QLabel(infoWidget);
        patientName->setObjectName(QString::fromUtf8("patientName"));
        patientName->setMinimumSize(QSize(150, 50));
        patientName->setFont(font);
        patientName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        patientName->setAlignment(Qt::AlignVCenter);

        gridLayout_2->addWidget(patientName, 2, 1, 1, 1);

        enterBirth = new focusOutLineEdit(infoWidget);
        enterBirth->setObjectName(QString::fromUtf8("enterBirth"));
        enterBirth->setMinimumSize(QSize(350, 50));
        enterBirth->setFont(font);
        enterBirth->setCursor(QCursor(Qt::IBeamCursor));
        enterBirth->setFocusPolicy(Qt::ClickFocus);
        enterBirth->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        enterBirth->setInputMask(QString::fromUtf8(""));
        enterBirth->setText(QString::fromUtf8(""));

        gridLayout_2->addWidget(enterBirth, 3, 2, 1, 1);

        addPhotoWidget = new QWidget(page);
        addPhotoWidget->setObjectName(QString::fromUtf8("addPhotoWidget"));
        addPhotoWidget->setGeometry(QRect(660, 40, 550, 720));
        addPhotoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:35px;\n"
"border-image:none;\n"
"border:2px solid white;"));
        gridLayout_3 = new QGridLayout(addPhotoWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelResult = new QLabel(addPhotoWidget);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));
        labelResult->setMinimumSize(QSize(150, 50));
        labelResult->setMaximumSize(QSize(150, 50));
        labelResult->setFont(font);
        labelResult->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        gridLayout_3->addWidget(labelResult, 5, 1, 1, 1);

        labelOpinion = new QLabel(addPhotoWidget);
        labelOpinion->setObjectName(QString::fromUtf8("labelOpinion"));
        labelOpinion->setMinimumSize(QSize(150, 50));
        labelOpinion->setMaximumSize(QSize(150, 50));
        labelOpinion->setFont(font);
        labelOpinion->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        gridLayout_3->addWidget(labelOpinion, 6, 1, 1, 1);

        buttonWidget2 = new QWidget(addPhotoWidget);
        buttonWidget2->setObjectName(QString::fromUtf8("buttonWidget2"));
        buttonWidget2->setMinimumSize(QSize(0, 80));
        buttonWidget2->setMaximumSize(QSize(16777215, 80));
        buttonWidget2->setStyleSheet(QString::fromUtf8("border:none;"));
        previewBtn = new QPushButton(buttonWidget2);
        previewBtn->setObjectName(QString::fromUtf8("previewBtn"));
        previewBtn->setGeometry(QRect(0, 10, 80, 50));
        previewBtn->setMinimumSize(QSize(0, 0));
        previewBtn->setFont(font);
        previewBtn->setFocusPolicy(Qt::NoFocus);
        previewBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));
        backBtn = new QPushButton(buttonWidget2);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(426, 10, 80, 50));
        backBtn->setMinimumSize(QSize(0, 0));
        backBtn->setFont(font);
        backBtn->setFocusPolicy(Qt::NoFocus);
        backBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));
        reselectBtn = new QPushButton(buttonWidget2);
        reselectBtn->setObjectName(QString::fromUtf8("reselectBtn"));
        reselectBtn->setGeometry(QRect(300, 10, 110, 50));
        reselectBtn->setFont(font);
        reselectBtn->setFocusPolicy(Qt::NoFocus);
        reselectBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));

        gridLayout_3->addWidget(buttonWidget2, 8, 1, 1, 2);

        enterDoctor = new focusOutLineEdit(addPhotoWidget);
        enterDoctor->setObjectName(QString::fromUtf8("enterDoctor"));
        enterDoctor->setMinimumSize(QSize(350, 50));
        enterDoctor->setMaximumSize(QSize(16777215, 50));
        enterDoctor->setFont(font);
        enterDoctor->setFocusPolicy(Qt::ClickFocus);
        enterDoctor->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(enterDoctor, 7, 2, 1, 1);

        labelPart = new QLabel(addPhotoWidget);
        labelPart->setObjectName(QString::fromUtf8("labelPart"));
        labelPart->setMinimumSize(QSize(150, 50));
        labelPart->setMaximumSize(QSize(150, 50));
        labelPart->setFont(font);
        labelPart->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        gridLayout_3->addWidget(labelPart, 3, 1, 1, 1);

        enterSituation = new focusOutLineEdit(addPhotoWidget);
        enterSituation->setObjectName(QString::fromUtf8("enterSituation"));
        enterSituation->setMinimumSize(QSize(350, 50));
        enterSituation->setMaximumSize(QSize(16777215, 50));
        enterSituation->setFont(font);
        enterSituation->setMouseTracking(true);
        enterSituation->setFocusPolicy(Qt::ClickFocus);
        enterSituation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        enterSituation->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout_3->addWidget(enterSituation, 4, 2, 1, 1);

        enterOpinion = new focusOutLineEdit(addPhotoWidget);
        enterOpinion->setObjectName(QString::fromUtf8("enterOpinion"));
        enterOpinion->setMinimumSize(QSize(350, 50));
        enterOpinion->setMaximumSize(QSize(16777215, 50));
        enterOpinion->setFont(font);
        enterOpinion->setFocusPolicy(Qt::ClickFocus);
        enterOpinion->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(enterOpinion, 6, 2, 1, 1);

        widget = new QWidget(addPhotoWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 80));
        widget->setStyleSheet(QString::fromUtf8("border:none;"));
        addBtn = new QPushButton(widget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(270, 15, 80, 50));
        addBtn->setMinimumSize(QSize(80, 50));
        addBtn->setMaximumSize(QSize(80, 50));
        addBtn->setFont(font);
        addBtn->setFocusPolicy(Qt::NoFocus);
        addBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:none;"));
        removeBtn = new QPushButton(widget);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));
        removeBtn->setGeometry(QRect(180, 15, 80, 50));
        removeBtn->setMinimumSize(QSize(80, 50));
        removeBtn->setMaximumSize(QSize(80, 50));
        removeBtn->setFont(font);
        removeBtn->setFocusPolicy(Qt::NoFocus);
        removeBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:none;"));

        gridLayout_3->addWidget(widget, 0, 2, 1, 1);

        labelDoctor = new QLabel(addPhotoWidget);
        labelDoctor->setObjectName(QString::fromUtf8("labelDoctor"));
        labelDoctor->setMinimumSize(QSize(150, 50));
        labelDoctor->setMaximumSize(QSize(150, 50));
        labelDoctor->setFont(font);
        labelDoctor->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        gridLayout_3->addWidget(labelDoctor, 7, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        enterPart = new focusOutLineEdit(addPhotoWidget);
        enterPart->setObjectName(QString::fromUtf8("enterPart"));
        enterPart->setMinimumSize(QSize(350, 50));
        enterPart->setMaximumSize(QSize(16777215, 50));
        enterPart->setFont(font);
        enterPart->setMouseTracking(true);
        enterPart->setFocusPolicy(Qt::ClickFocus);
        enterPart->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(enterPart, 3, 2, 1, 1);

        enterResult = new focusOutLineEdit(addPhotoWidget);
        enterResult->setObjectName(QString::fromUtf8("enterResult"));
        enterResult->setMinimumSize(QSize(350, 50));
        enterResult->setMaximumSize(QSize(16777215, 50));
        enterResult->setFont(font);
        enterResult->setFocusPolicy(Qt::ClickFocus);
        enterResult->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(enterResult, 5, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        labelSituation = new QLabel(addPhotoWidget);
        labelSituation->setObjectName(QString::fromUtf8("labelSituation"));
        labelSituation->setMinimumSize(QSize(150, 50));
        labelSituation->setMaximumSize(QSize(150, 50));
        labelSituation->setFont(font);
        labelSituation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        gridLayout_3->addWidget(labelSituation, 4, 1, 1, 1);

        addPhotoLabel = new QLabel(addPhotoWidget);
        addPhotoLabel->setObjectName(QString::fromUtf8("addPhotoLabel"));
        addPhotoLabel->setMinimumSize(QSize(0, 80));
        addPhotoLabel->setMaximumSize(QSize(16777215, 80));
        addPhotoLabel->setFont(font1);
        addPhotoLabel->setStyleSheet(QString::fromUtf8("border:none;"));

        gridLayout_3->addWidget(addPhotoLabel, 0, 1, 1, 1);

        graphicsView = new DraggableGraphicsView(addPhotoWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFocusPolicy(Qt::NoFocus);
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"	border:none;\n"
"	border-image:none;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QWidget{\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	background-color: transparent;\n"
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
"	background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"	border: none;\n"
"	border-image:none;\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"	border-image:none;\n"
"	background-color: rgb(80, 80, 80);  /* \346\267\261\347\201\260\350\211\262\347\267\232\346\242\235 */\n"
"	width: 1px;  /* \350\250"
                        "\255\347\275\256\347\267\232\346\242\235\345\257\254\345\272\246 */\n"
"	margin-left: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-right: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-bottom:10px;\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical{\n"
"	border-image:none;\n"
"	background-color: rgb(80, 80, 80);  /* \346\267\261\347\201\260\350\211\262\347\267\232\346\242\235 */\n"
"	width: 1px;  /* \350\250\255\347\275\256\347\267\232\346\242\235\345\257\254\345\272\246 */\n"
"	margin-top:10px;\n"
"	margin-left: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-right: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	border: none;\n"
"}"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(0);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_3->addWidget(graphicsView, 1, 1, 2, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 150, 600, 500));
        QFont font2;
        font2.setPointSize(32);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border-image: none;"));
        label->setAlignment(Qt::AlignCenter);
        backBtn_noDatabase = new QPushButton(page_2);
        backBtn_noDatabase->setObjectName(QString::fromUtf8("backBtn_noDatabase"));
        backBtn_noDatabase->setGeometry(QRect(1110, 710, 130, 50));
        backBtn_noDatabase->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border-image: none;"));
        stackedWidget->addWidget(page_2);

        retranslateUi(addReport);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(addReport);
    } // setupUi

    void retranslateUi(QWidget *addReport)
    {
        addReport->setWindowTitle(QApplication::translate("addReport", "Form", nullptr));
        patientGender->setText(QApplication::translate("addReport", " Gender :", nullptr));
        maleBtn->setText(QString());
        maleLabel->setText(QApplication::translate("addReport", "male", nullptr));
        femaleBtn->setText(QString());
        femaleLabel->setText(QApplication::translate("addReport", "female", nullptr));
        patientID->setText(QApplication::translate("addReport", " ID :", nullptr));
        patientAge->setText(QApplication::translate("addReport", " Age :", nullptr));
        saveBtn->setText(QApplication::translate("addReport", "Save", nullptr));
        checkBtn->setText(QApplication::translate("addReport", "Check", nullptr));
        enterID->setPlaceholderText(QApplication::translate("addReport", "15", nullptr));
        enterName->setPlaceholderText(QApplication::translate("addReport", "tony", nullptr));
        describeLabel->setText(QApplication::translate("addReport", "   Describe :", nullptr));
        enterAge->setPlaceholderText(QApplication::translate("addReport", "25", nullptr));
        infoLabel->setText(QApplication::translate("addReport", "Info", nullptr));
        patientBirth->setText(QApplication::translate("addReport", " Birth :", nullptr));
        patientName->setText(QApplication::translate("addReport", " Name :", nullptr));
        enterBirth->setPlaceholderText(QApplication::translate("addReport", "yyyy-mm-dd", nullptr));
        labelResult->setText(QApplication::translate("addReport", " Result :", nullptr));
        labelOpinion->setText(QApplication::translate("addReport", " Opinion :", nullptr));
        previewBtn->setText(QApplication::translate("addReport", "Preview", nullptr));
        backBtn->setText(QApplication::translate("addReport", "Back", nullptr));
        reselectBtn->setText(QApplication::translate("addReport", "Reselect", nullptr));
        labelPart->setText(QApplication::translate("addReport", " Part : ", nullptr));
        addBtn->setText(QApplication::translate("addReport", "add", nullptr));
        removeBtn->setText(QApplication::translate("addReport", "remove", nullptr));
        labelDoctor->setText(QApplication::translate("addReport", " Doctor :", nullptr));
        labelSituation->setText(QApplication::translate("addReport", " Situation :", nullptr));
        addPhotoLabel->setText(QApplication::translate("addReport", "add Photo", nullptr));
        label->setText(QApplication::translate("addReport", "Fail to Connect Database", nullptr));
        backBtn_noDatabase->setText(QApplication::translate("addReport", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addReport: public Ui_addReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREPORT_H
