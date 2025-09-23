#include "ErrorFormat.h"
#include "ui_ErrorFormat.h"

ErrorFormat::ErrorFormat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorFormat)
{
    ui->setupUi(this);
}

ErrorFormat::~ErrorFormat()
{
    delete ui;
}

void ErrorFormat::setErrroMsg(QString errMsg)
{
    ui->errMsg->setText(errMsg);
}

void ErrorFormat::on_closeBtn_clicked()
{
    ui->errMsg->clear();
    emit hideErrorFormat();
}
