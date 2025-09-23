#include "ComfirmDelete.h"
#include "ui_ComfirmDelete.h"

ComfirmDelete::ComfirmDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComfirmDelete)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

ComfirmDelete::~ComfirmDelete()
{
    delete ui;
}

void ComfirmDelete::refreshUI()
{
    ui->retranslateUi(this);
}

void ComfirmDelete::on_deleteBtn_clicked()
{
    emit deleteBtnClicked();
    emit back();
}

void ComfirmDelete::on_cancelBtn_clicked()
{
    emit cancelBtnClicked();
    emit back();
}
