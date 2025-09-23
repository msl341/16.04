#include "PickPhotoItem.h"
#include "ui_PickPhotoItem.h"

PickPhotoItem::PickPhotoItem(bool enableClick, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PickPhotoItem)
{
    ui->setupUi(this);

    ui->selectedIcon->setVisible(false);

    clickable = enableClick;
}

PickPhotoItem::~PickPhotoItem()
{
    delete ui;
}

void PickPhotoItem::itemSetIconVisible(bool status)
{
    ui->selectedIcon->setVisible(status);
}

bool PickPhotoItem::itemGetIconVisible()
{
    return ui->selectedIcon->isVisible();
}

void PickPhotoItem::itemSetPhoto(QString path)
{
    ui->pickPhoto->setStyleSheet(QString("border-image:url(%1)").arg(path));
    photoPath = path;
}

void PickPhotoItem::itemSetPhotoPath(QString path)
{
    photoPath = path;
}

QString PickPhotoItem::itemGetPhotoPath()
{
    return photoPath;
}

void PickPhotoItem::itemSetIndex(int idx)
{
    index = idx;
}

void PickPhotoItem::itemResize(int width, int height)
{
    setFixedSize(width + 10, height + 10);
    ui->pickPhoto->setFixedSize(width, height);
}

void PickPhotoItem::on_pickPhoto_clicked()
{
    if(clickable){
        if(ui->selectedIcon->isVisible()){
            ui->selectedIcon->setVisible(false);
            emit clicked(index, true);
        }
        else{
            ui->selectedIcon->setVisible(true);
            emit clicked(index, false);
        }
    }
}
