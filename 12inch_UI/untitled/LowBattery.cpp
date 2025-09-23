#include "LowBattery.h"
#include "ui_LowBattery.h"

LowBattery::LowBattery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LowBattery)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
}

LowBattery::~LowBattery()
{
    delete ui;
}

void LowBattery::refreshUI()
{
    ui->retranslateUi(this);
}

void LowBattery::on_closeBtn_clicked()
{
    close();
}
