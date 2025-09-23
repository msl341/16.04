/********************************************************************************
** Form generated from reading UI file 'BrowseReport.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEREPORT_H
#define UI_BROWSEREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <addReport.h>
#include "mykey.h"

QT_BEGIN_NAMESPACE

class Ui_BrowseReport
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widgetB;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBrowseReport;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    showKeyBoardLineEdit *searchInput;
    QPushButton *searchBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addReportBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *backBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelName;
    QLabel *labelAge;
    QLabel *labelGender;
    QLabel *labelDate;
    DraggableListWidget *listWidget;
    QWidget *page_2;
    QLabel *label;
    QPushButton *backBtn_noDatabase;

    void setupUi(QWidget *BrowseReport)
    {
        if (BrowseReport->objectName().isEmpty())
            BrowseReport->setObjectName(QString::fromUtf8("BrowseReport"));
        BrowseReport->setEnabled(true);
        BrowseReport->resize(1280, 800);
        BrowseReport->setAutoFillBackground(false);
        BrowseReport->setStyleSheet(QString::fromUtf8("border-image: url(:/tu/ALL-IN-ONE ICON/BKG.png);"));
        stackedWidget = new QStackedWidget(BrowseReport);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1280, 800));
        stackedWidget->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	text-align: left;\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widgetB = new QWidget(page);
        widgetB->setObjectName(QString::fromUtf8("widgetB"));
        widgetB->setGeometry(QRect(40, 30, 1202, 751));
        widgetB->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border:none;"));
        verticalLayout = new QVBoxLayout(widgetB);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        widget = new QWidget(widgetB);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 80));
        widget->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"background-color: transparent;\n"
"border:none;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelBrowseReport = new QLabel(widget);
        labelBrowseReport->setObjectName(QString::fromUtf8("labelBrowseReport"));
        labelBrowseReport->setMinimumSize(QSize(250, 0));
        labelBrowseReport->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setPointSize(18);
        labelBrowseReport->setFont(font);
        labelBrowseReport->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        horizontalLayout->addWidget(labelBrowseReport, 0, Qt::AlignLeft);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(350, 50));
        widget_3->setMaximumSize(QSize(350, 50));
        searchInput = new showKeyBoardLineEdit(widget_3);
        searchInput->setObjectName(QString::fromUtf8("searchInput"));
        searchInput->setGeometry(QRect(0, 0, 300, 50));
        searchInput->setFocusPolicy(Qt::ClickFocus);
        searchInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));
        searchBtn = new QPushButton(widget_3);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setGeometry(QRect(300, 0, 50, 50));
        searchBtn->setFocusPolicy(Qt::NoFocus);
        searchBtn->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:none;"));
        searchBtn->setFlat(false);

        horizontalLayout->addWidget(widget_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        addReportBtn = new QPushButton(widget);
        addReportBtn->setObjectName(QString::fromUtf8("addReportBtn"));
        addReportBtn->setMinimumSize(QSize(120, 50));
        addReportBtn->setMaximumSize(QSize(120, 50));
        addReportBtn->setFocusPolicy(Qt::NoFocus);
        addReportBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));
        addReportBtn->setFlat(false);

        horizontalLayout->addWidget(addReportBtn);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        backBtn = new QPushButton(widget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setMinimumSize(QSize(100, 50));
        backBtn->setMaximumSize(QSize(100, 50));
        backBtn->setFocusPolicy(Qt::NoFocus);
        backBtn->setStyleSheet(QString::fromUtf8("color: white;\n"
"border:1px solid black;\n"
"border-image: url(:/tu/ALL-IN-ONE ICON/BKG_long_small.png);"));

        horizontalLayout->addWidget(backBtn);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widgetB);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 50));
        widget_2->setMaximumSize(QSize(16777215, 30));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);\n"
"border-image: none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelName = new QLabel(widget_2);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMinimumSize(QSize(272, 0));
        labelName->setMaximumSize(QSize(272, 30));
        QFont font1;
        font1.setPointSize(15);
        labelName->setFont(font1);
        labelName->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        horizontalLayout_2->addWidget(labelName);

        labelAge = new QLabel(widget_2);
        labelAge->setObjectName(QString::fromUtf8("labelAge"));
        labelAge->setMaximumSize(QSize(150, 30));
        labelAge->setFont(font1);
        labelAge->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        horizontalLayout_2->addWidget(labelAge);

        labelGender = new QLabel(widget_2);
        labelGender->setObjectName(QString::fromUtf8("labelGender"));
        labelGender->setMaximumSize(QSize(150, 30));
        labelGender->setFont(font1);
        labelGender->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        horizontalLayout_2->addWidget(labelGender);

        labelDate = new QLabel(widget_2);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));
        labelDate->setMaximumSize(QSize(16777215, 30));
        labelDate->setFont(font1);
        labelDate->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));

        horizontalLayout_2->addWidget(labelDate);


        verticalLayout->addWidget(widget_2);

        listWidget = new DraggableListWidget(widgetB);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(1200, 0));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border:none;\n"
"	border-image:none;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	margin-top:5px;\n"
"}\n"
"\n"
"QWidget{\n"
"	border: none;\n"
"	border-image:none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	background-color: transparent;\n"
"	border-image:none;\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	width: 10px;\n"
"	margin-top:0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	background-color: rgb(60,100,242);\n"
"	border-image:none;\n"
"	min-height: 20px;\n"
"	border-radius: 5px;\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"	/*background-color: rgba(222,83,66,255);*/\n"
"	border: none;\n"
"	border-image:none;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"	border: none;\n"
"	border-image:none;\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"	border: none;\n"
"	border-image:none;\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"	border-image:none;\n"
"	background-color: "
                        "rgb(80, 80, 80);  /* \346\267\261\347\201\260\350\211\262\347\267\232\346\242\235 */\n"
"	width: 2px;  /* \350\250\255\347\275\256\347\267\232\346\242\235\345\257\254\345\272\246 */\n"
"	margin-left: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-right: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-bottom:5px;\n"
"	border: none;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical{\n"
"	border-image:none;\n"
"	background-color: rgb(80, 80, 80);  /* \346\267\261\347\201\260\350\211\262\347\267\232\346\242\235 */\n"
"	width: 2px;  /* \350\250\255\347\275\256\347\267\232\346\242\235\345\257\254\345\272\246 */\n"
"	margin-top:5px;\n"
"	margin-left: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	margin-right: 4px;  /* \344\275\277\347\267\232\346\242\235\345\261\205\344\270\255 */\n"
"	border: none;\n"
"}"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setProperty("showDropIndicator", QVariant(false));
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setGridSize(QSize(1180, 80));
        listWidget->setBatchSize(100);
        listWidget->setItemAlignment(Qt::AlignLeading);

        verticalLayout->addWidget(listWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 150, 500, 500));
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

        retranslateUi(BrowseReport);

        QMetaObject::connectSlotsByName(BrowseReport);
    } // setupUi

    void retranslateUi(QWidget *BrowseReport)
    {
        BrowseReport->setWindowTitle(QApplication::translate("BrowseReport", "Form", nullptr));
        labelBrowseReport->setText(QApplication::translate("BrowseReport", "Browse Report", nullptr));
        searchBtn->setText(QApplication::translate("BrowseReport", "S", nullptr));
        addReportBtn->setText(QApplication::translate("BrowseReport", "add Report", nullptr));
        backBtn->setText(QApplication::translate("BrowseReport", "Back", nullptr));
        labelName->setText(QApplication::translate("BrowseReport", "Name", nullptr));
        labelAge->setText(QApplication::translate("BrowseReport", "Age", nullptr));
        labelGender->setText(QApplication::translate("BrowseReport", "Gender", nullptr));
        labelDate->setText(QApplication::translate("BrowseReport", "Date", nullptr));
        label->setText(QApplication::translate("BrowseReport", "Fail to Connect Database", nullptr));
        backBtn_noDatabase->setText(QApplication::translate("BrowseReport", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrowseReport: public Ui_BrowseReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEREPORT_H
