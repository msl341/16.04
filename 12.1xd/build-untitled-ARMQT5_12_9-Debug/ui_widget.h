/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *two_stack;
    QWidget *page_3;
    QWidget *page_4;
    QStackedWidget *one_stack;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1280, 800);
        Widget->setStyleSheet(QString::fromUtf8(""));
        two_stack = new QStackedWidget(Widget);
        two_stack->setObjectName(QString::fromUtf8("two_stack"));
        two_stack->setGeometry(QRect(0, 0, 1280, 800));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        two_stack->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        two_stack->addWidget(page_4);
        one_stack = new QStackedWidget(Widget);
        one_stack->setObjectName(QString::fromUtf8("one_stack"));
        one_stack->setGeometry(QRect(0, 0, 1280, 800));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        one_stack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        one_stack->addWidget(page_2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
