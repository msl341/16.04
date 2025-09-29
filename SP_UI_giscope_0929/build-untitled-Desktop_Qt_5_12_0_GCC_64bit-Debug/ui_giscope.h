/********************************************************************************
** Form generated from reading UI file 'giscope.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GISCOPE_H
#define UI_GISCOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GiScope
{
public:
    QLabel *previewlabel;
    QLabel *pic1;
    QLabel *pic2;
    QLabel *pic3;
    QLabel *pic4;
    QLabel *handleName;
    QLabel *labelw_size;
    QLabel *labelw_channel;
    QLabel *labelw_length;
    QLabel *labelw_duration;
    QLabel *labelw_number;
    QLabel *labelw_sw1;
    QLabel *labelw_sw2;
    QLabel *labelw_sw3;
    QLabel *labelw_version;
    QLabel *labelw_positive;
    QLabel *labelw_negtive;
    QLabel *labelw_reocrd;
    QLabel *label_record;
    QLabel *label_sw3;
    QLabel *label_sw2;
    QLabel *label_sw1;
    QLabel *label_number;
    QLabel *label_duration;
    QLabel *label_length;
    QLabel *label_channel;
    QLabel *label_size;
    QLabel *label_freeze;
    QLabel *label_version;

    void setupUi(QWidget *GiScope)
    {
        if (GiScope->objectName().isEmpty())
            GiScope->setObjectName(QString::fromUtf8("GiScope"));
        GiScope->resize(1920, 1080);
        previewlabel = new QLabel(GiScope);
        previewlabel->setObjectName(QString::fromUtf8("previewlabel"));
        previewlabel->setGeometry(QRect(850, 40, 1000, 1000));
        previewlabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        previewlabel->setScaledContents(false);
        previewlabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pic1 = new QLabel(GiScope);
        pic1->setObjectName(QString::fromUtf8("pic1"));
        pic1->setEnabled(true);
        pic1->setGeometry(QRect(540, 40, 240, 240));
        pic1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pic2 = new QLabel(GiScope);
        pic2->setObjectName(QString::fromUtf8("pic2"));
        pic2->setGeometry(QRect(540, 293, 240, 240));
        pic2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pic3 = new QLabel(GiScope);
        pic3->setObjectName(QString::fromUtf8("pic3"));
        pic3->setGeometry(QRect(540, 547, 240, 240));
        pic3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pic4 = new QLabel(GiScope);
        pic4->setObjectName(QString::fromUtf8("pic4"));
        pic4->setGeometry(QRect(540, 800, 240, 240));
        pic4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        handleName = new QLabel(GiScope);
        handleName->setObjectName(QString::fromUtf8("handleName"));
        handleName->setGeometry(QRect(50, 10, 241, 31));
        QFont font;
        font.setPointSize(15);
        handleName->setFont(font);
        handleName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelw_size = new QLabel(GiScope);
        labelw_size->setObjectName(QString::fromUtf8("labelw_size"));
        labelw_size->setGeometry(QRect(50, 50, 101, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        labelw_size->setFont(font1);
        labelw_size->setLayoutDirection(Qt::LeftToRight);
        labelw_size->setFrameShape(QFrame::NoFrame);
        labelw_size->setTextFormat(Qt::AutoText);
        labelw_size->setScaledContents(false);
        labelw_size->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelw_size->setWordWrap(false);
        labelw_channel = new QLabel(GiScope);
        labelw_channel->setObjectName(QString::fromUtf8("labelw_channel"));
        labelw_channel->setGeometry(QRect(50, 80, 81, 31));
        QFont font2;
        font2.setPointSize(14);
        labelw_channel->setFont(font2);
        labelw_length = new QLabel(GiScope);
        labelw_length->setObjectName(QString::fromUtf8("labelw_length"));
        labelw_length->setGeometry(QRect(50, 110, 91, 31));
        labelw_length->setFont(font2);
        labelw_duration = new QLabel(GiScope);
        labelw_duration->setObjectName(QString::fromUtf8("labelw_duration"));
        labelw_duration->setGeometry(QRect(50, 200, 141, 41));
        labelw_duration->setFont(font2);
        labelw_number = new QLabel(GiScope);
        labelw_number->setObjectName(QString::fromUtf8("labelw_number"));
        labelw_number->setGeometry(QRect(50, 240, 131, 31));
        labelw_number->setFont(font2);
        labelw_sw1 = new QLabel(GiScope);
        labelw_sw1->setObjectName(QString::fromUtf8("labelw_sw1"));
        labelw_sw1->setGeometry(QRect(50, 300, 41, 31));
        QFont font3;
        font3.setPointSize(12);
        labelw_sw1->setFont(font3);
        labelw_sw2 = new QLabel(GiScope);
        labelw_sw2->setObjectName(QString::fromUtf8("labelw_sw2"));
        labelw_sw2->setGeometry(QRect(50, 330, 41, 31));
        labelw_sw2->setFont(font3);
        labelw_sw3 = new QLabel(GiScope);
        labelw_sw3->setObjectName(QString::fromUtf8("labelw_sw3"));
        labelw_sw3->setGeometry(QRect(50, 360, 41, 31));
        labelw_sw3->setFont(font3);
        labelw_version = new QLabel(GiScope);
        labelw_version->setObjectName(QString::fromUtf8("labelw_version"));
        labelw_version->setGeometry(QRect(30, 1000, 181, 41));
        QFont font4;
        font4.setPointSize(11);
        labelw_version->setFont(font4);
        labelw_positive = new QLabel(GiScope);
        labelw_positive->setObjectName(QString::fromUtf8("labelw_positive"));
        labelw_positive->setGeometry(QRect(46, 490, 181, 41));
        QFont font5;
        font5.setPointSize(13);
        labelw_positive->setFont(font5);
        labelw_negtive = new QLabel(GiScope);
        labelw_negtive->setObjectName(QString::fromUtf8("labelw_negtive"));
        labelw_negtive->setGeometry(QRect(50, 530, 181, 31));
        labelw_negtive->setFont(font5);
        labelw_reocrd = new QLabel(GiScope);
        labelw_reocrd->setObjectName(QString::fromUtf8("labelw_reocrd"));
        labelw_reocrd->setGeometry(QRect(46, 600, 161, 31));
        labelw_reocrd->setFont(font5);
        label_record = new QLabel(GiScope);
        label_record->setObjectName(QString::fromUtf8("label_record"));
        label_record->setGeometry(QRect(220, 600, 101, 31));
        label_record->setFont(font5);
        label_sw3 = new QLabel(GiScope);
        label_sw3->setObjectName(QString::fromUtf8("label_sw3"));
        label_sw3->setGeometry(QRect(90, 360, 251, 31));
        label_sw3->setFont(font3);
        label_sw2 = new QLabel(GiScope);
        label_sw2->setObjectName(QString::fromUtf8("label_sw2"));
        label_sw2->setGeometry(QRect(90, 330, 251, 31));
        label_sw2->setFont(font3);
        label_sw1 = new QLabel(GiScope);
        label_sw1->setObjectName(QString::fromUtf8("label_sw1"));
        label_sw1->setGeometry(QRect(90, 300, 241, 31));
        label_sw1->setFont(font3);
        label_number = new QLabel(GiScope);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setGeometry(QRect(183, 240, 161, 31));
        label_number->setFont(font2);
        label_duration = new QLabel(GiScope);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));
        label_duration->setGeometry(QRect(190, 200, 161, 41));
        label_duration->setFont(font2);
        label_length = new QLabel(GiScope);
        label_length->setObjectName(QString::fromUtf8("label_length"));
        label_length->setGeometry(QRect(120, 110, 141, 31));
        label_length->setFont(font2);
        label_length->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_channel = new QLabel(GiScope);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setGeometry(QRect(130, 80, 141, 31));
        label_channel->setFont(font2);
        label_size = new QLabel(GiScope);
        label_size->setObjectName(QString::fromUtf8("label_size"));
        label_size->setGeometry(QRect(153, 50, 141, 31));
        label_size->setFont(font2);
        label_freeze = new QLabel(GiScope);
        label_freeze->setObjectName(QString::fromUtf8("label_freeze"));
        label_freeze->setGeometry(QRect(430, 690, 350, 350));
        label_freeze->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_version = new QLabel(GiScope);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setGeometry(QRect(30, 1036, 191, 31));

        retranslateUi(GiScope);

        QMetaObject::connectSlotsByName(GiScope);
    } // setupUi

    void retranslateUi(QWidget *GiScope)
    {
        GiScope->setWindowTitle(QApplication::translate("GiScope", "Form", nullptr));
        previewlabel->setText(QString());
        pic1->setText(QString());
        pic2->setText(QString());
        pic3->setText(QString());
        pic4->setText(QString());
        handleName->setText(QString());
        labelw_size->setText(QApplication::translate("GiScope", "Scope size:", nullptr));
        labelw_channel->setText(QApplication::translate("GiScope", "Channel:", nullptr));
        labelw_length->setText(QApplication::translate("GiScope", "Length:", nullptr));
        labelw_duration->setText(QApplication::translate("GiScope", "Duration of use:", nullptr));
        labelw_number->setText(QApplication::translate("GiScope", "Number of use:", nullptr));
        labelw_sw1->setText(QApplication::translate("GiScope", "SW1:", nullptr));
        labelw_sw2->setText(QApplication::translate("GiScope", "SW2:", nullptr));
        labelw_sw3->setText(QApplication::translate("GiScope", "SW3:", nullptr));
        labelw_version->setText(QApplication::translate("GiScope", "Version Information", nullptr));
        labelw_positive->setText(QApplication::translate("GiScope", " Positive Pressure On", nullptr));
        labelw_negtive->setText(QApplication::translate("GiScope", "Negative Pressure On", nullptr));
        labelw_reocrd->setText(QApplication::translate("GiScope", " Recording Duration:", nullptr));
        label_record->setText(QString());
        label_sw3->setText(QApplication::translate("GiScope", "TextLabel", nullptr));
        label_sw2->setText(QApplication::translate("GiScope", "TextLabel", nullptr));
        label_sw1->setText(QApplication::translate("GiScope", "TextLabel", nullptr));
        label_number->setText(QString());
        label_duration->setText(QString());
        label_length->setText(QString());
        label_channel->setText(QString());
        label_size->setText(QString());
        label_freeze->setText(QString());
        label_version->setText(QApplication::translate("GiScope", "V1.0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiScope: public Ui_GiScope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GISCOPE_H
