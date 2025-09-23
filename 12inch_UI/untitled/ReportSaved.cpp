#include "ReportSaved.h"
#include "ui_ReportSaved.h"

ReportSaved::ReportSaved(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportSaved)
{
    ui->setupUi(this);
}

ReportSaved::~ReportSaved()
{
    delete ui;
}

void ReportSaved::refreshUI()
{
    ui->retranslateUi(this);
}
