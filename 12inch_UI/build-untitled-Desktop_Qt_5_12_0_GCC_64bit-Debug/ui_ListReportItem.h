/********************************************************************************
** Form generated from reading UI file 'ListReportItem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTREPORTITEM_H
#define UI_LISTREPORTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListReportItem
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelName;
    QLabel *labelAge;
    QLabel *labelGender;
    QLabel *labelDate;
    QPushButton *chooseBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *fullBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ListReportItem)
    {
        if (ListReportItem->objectName().isEmpty())
            ListReportItem->setObjectName(QString::fromUtf8("ListReportItem"));
        ListReportItem->resize(1180, 80);
        ListReportItem->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        widget = new QWidget(ListReportItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1180, 80));
        widget->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"background-color: transparent;\n"
"border-bottom:2px solid white;"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1181, 82));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(layoutWidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMinimumSize(QSize(280, 80));
        QFont font;
        font.setPointSize(16);
        labelName->setFont(font);
        labelName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        labelName->setText(QString::fromUtf8("name"));
        labelName->setMargin(10);

        horizontalLayout->addWidget(labelName);

        labelAge = new QLabel(layoutWidget);
        labelAge->setObjectName(QString::fromUtf8("labelAge"));
        labelAge->setMinimumSize(QSize(150, 80));
        labelAge->setFont(font);
        labelAge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        labelAge->setText(QString::fromUtf8("age"));

        horizontalLayout->addWidget(labelAge);

        labelGender = new QLabel(layoutWidget);
        labelGender->setObjectName(QString::fromUtf8("labelGender"));
        labelGender->setMinimumSize(QSize(150, 80));
        labelGender->setFont(font);
        labelGender->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';\n"
"color: rgb(255, 255, 255);"));
        labelGender->setText(QString::fromUtf8("gender"));

        horizontalLayout->addWidget(labelGender);

        labelDate = new QLabel(layoutWidget);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));
        labelDate->setMinimumSize(QSize(280, 80));
        labelDate->setFont(font);
        labelDate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignLeft';\n"
"qproperty-alignment: 'AlignVCenter';"));
        labelDate->setText(QString::fromUtf8("yyyy-mm-dd"));

        horizontalLayout->addWidget(labelDate);

        chooseBtn = new QPushButton(layoutWidget);
        chooseBtn->setObjectName(QString::fromUtf8("chooseBtn"));
        chooseBtn->setMinimumSize(QSize(100, 50));
        chooseBtn->setFocusPolicy(Qt::NoFocus);
        chooseBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(chooseBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        fullBtn = new QPushButton(layoutWidget);
        fullBtn->setObjectName(QString::fromUtf8("fullBtn"));
        fullBtn->setMinimumSize(QSize(100, 50));
        fullBtn->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(12);
        fullBtn->setFont(font1);
        fullBtn->setFocusPolicy(Qt::NoFocus);
        fullBtn->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(fullBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        deleteBtn = new QPushButton(layoutWidget);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setMinimumSize(QSize(100, 50));
        deleteBtn->setMaximumSize(QSize(100, 50));
        deleteBtn->setFont(font1);
        deleteBtn->setFocusPolicy(Qt::NoFocus);
        deleteBtn->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(deleteBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        retranslateUi(ListReportItem);

        QMetaObject::connectSlotsByName(ListReportItem);
    } // setupUi

    void retranslateUi(QWidget *ListReportItem)
    {
        ListReportItem->setWindowTitle(QApplication::translate("ListReportItem", "Form", nullptr));
        chooseBtn->setText(QApplication::translate("ListReportItem", "Choose", nullptr));
        fullBtn->setText(QApplication::translate("ListReportItem", "Full Report", nullptr));
        deleteBtn->setText(QApplication::translate("ListReportItem", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListReportItem: public Ui_ListReportItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTREPORTITEM_H
