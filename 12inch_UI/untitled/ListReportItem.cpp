#include "ListReportItem.h"
#include "ui_ListReportItem.h"

ListReportItem::ListReportItem(QWidget *parent, bool chooseStatus) :
    QWidget(parent),
    ui(new Ui::ListReportItem)
{
    ui->setupUi(this);

    itemSetChooseBtnVisible(chooseStatus);
}

ListReportItem::~ListReportItem()
{
    delete ui;
}

void ListReportItem::itemSetName(QString name)
{
    ui->labelName->setText(name);
}

void ListReportItem::itemSetAge(int age)
{
    ui->labelAge->setText(QString::number(age));
}

void ListReportItem::itemSetEmptyAge()
{
    ui->labelAge->setText("");
}

void ListReportItem::itemSetGender(QString gender)
{
    ui->labelGender->setText(gender);
}

void ListReportItem::itemSetDate(QString date)
{
    ui->labelDate->setText(date);
}

void ListReportItem::itemSetIndex(int idx)
{
    index = idx;
}

void ListReportItem::itemSetChooseBtnVisible(bool status)
{
    ui->chooseBtn->setVisible(status);
    ui->chooseBtn->setEnabled(status);
}

void ListReportItem::itemSetDeleteBtnVisible(bool status)
{
    ui->deleteBtn->setVisible(status);
    ui->deleteBtn->setEnabled(status);
}

void ListReportItem::itemSetFullBtnVisible(bool status)
{
    ui->fullBtn->setVisible(status);
    ui->fullBtn->setVisible(status);
}

void ListReportItem::itemSetOID(int oid)
{
    OID = oid;
}

int ListReportItem::itemGetOID()
{
    return OID;
}

bool ListReportItem::itemGetChooseBtnVisible()
{
    return ui->chooseBtn->isVisible();
}

void ListReportItem::refreshUI()
{
    ui->retranslateUi(this);
}

void ListReportItem::on_deleteBtn_clicked()
{
    emit click_delete();
}

void ListReportItem::on_fullBtn_clicked()
{
    emit click_full();
}

void ListReportItem::on_chooseBtn_clicked()
{
    emit click_choose();
}
