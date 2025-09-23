#include "photo_browse_single.h"
#include "ui_photo_browse_single.h"

photo_browse_single::photo_browse_single(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::photo_browse_single)
{
    ui->setupUi(this);
    ui->label_full_screen->setVisible(false);

    timer_switchable = new QTimer(this);

    connect(timer_switchable, &QTimer::timeout, this,[=](){
        switchable_flag=0;
    });

    connect(ui->label_full_screen,&Label_full_screen::doubleClicked,this,[=](){
        ui->label_full_screen->setVisible(false);

        ui->label_b->setVisible(true);
        ui->label_delete->setVisible(true);
        ui->label_left->setVisible(true);
        ui->label_right->setVisible(true);
        ui->label_return->setVisible(true);
        ui->label_screen->setVisible(true);
    });
    connect(ui->label_screen,&Label_screen::doubleClicked,this,[=](){
        ui->label_full_screen->setVisible(true);
        if(flag_USB==1)
        {
            ui->label_full_screen->setStyleSheet(QString("image: url(/mnt/USB_FLASH/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
        }
        else if(flag_USB==0 && flag_SD==1)
        {
            ui->label_full_screen->setStyleSheet(QString("image: url(/mnt/SD_CARD/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
        }
        ui->label_b->setVisible(false);
        ui->label_delete->setVisible(false);
        ui->label_left->setVisible(false);
        ui->label_right->setVisible(false);
        ui->label_return->setVisible(false);
        ui->label_screen->setVisible(false);
    });
    connect(ui->label_return,&Label_return_ps::clicked_1,this,[=](){
        emit return_photo();
    });
    connect(ui->label_left,&Label_left_ps::clicked_1,this,[=](){
        if(photo_labelnum>0)
        {
            photo_labelnum--;
            if(flag_USB==1)
            {
                ui->label_screen->setStyleSheet(QString("image: url(/mnt/USB_FLASH/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
            }
            else if(flag_USB==0 && flag_SD==1)
            {
                ui->label_screen->setStyleSheet(QString("image: url(/mnt/SD_CARD/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
            }
        }
    });
    connect(ui->label_right,&Label_right_ps::clicked_1,this,[=](){
        if(photo_labelnum<photo_max-1)
        {
            photo_labelnum++;
            if(flag_USB==1)
            {
                ui->label_screen->setStyleSheet(QString("image: url(/mnt/USB_FLASH/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
            }
            else if(flag_USB==0 && flag_SD==1)
            {
                ui->label_screen->setStyleSheet(QString("image: url(/mnt/SD_CARD/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
            }
        }
    });
    connect(ui->label_delete,&Label_delete_ps::clicked_1,this,[=](){
        if(switchable_flag == 0){
            switchable_flag=1;
            if(flag_USB==1)
            {
                QString filePath = QString("/mnt/USB_FLASH/Picture/%2/%1").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath));
                QFile file(filePath);
                if (file.exists())
                {
                    file.remove();
                }
                file.close();

                photo_name.clear();
                emit update_photo_name();

                if(photo_labelnum==photo_max && photo_max!=0)
                {
                    photo_labelnum--;
                    ui->label_screen->setStyleSheet(QString("image: url(/mnt/USB_FLASH/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
                }
                else if(photo_labelnum==photo_max && photo_max==0)
                {
                    emit return_photo();
                }
                else
                {
                    ui->label_screen->setStyleSheet(QString("image: url(/mnt/USB_FLASH/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
                }
            }
            else if(flag_USB==0 && flag_SD==1)
            {
                QString filePath = QString("/mnt/SD_CARD/Picture/%2/%1").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath));
                QFile file(filePath);
                if (file.exists())
                {
                    file.remove();
                }
                file.close();

                photo_name.clear();
                emit update_photo_name();

                if(photo_labelnum==photo_max && photo_max!=0)
                {
                    photo_labelnum--;
                    ui->label_screen->setStyleSheet(QString("image: url(/mnt/SD_CARD/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
                }
                else if(photo_labelnum==photo_max && photo_max==0)
                {
                    emit return_photo();
                }
                else
                {
                    ui->label_screen->setStyleSheet(QString("image: url(/mnt/SD_CARD/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
                }
            }
            timer_switchable->start(500);
        }
    });
}

void photo_browse_single::photo_update()
{
    if(photo_num!=1)
    {
        photo_labelnum=photo_labelnum+(6*(photo_num-1));
    }
    photo_labelnum=photo_labelnum-1;

    if(flag_USB==1)
    {
        ui->label_screen->setStyleSheet(QString("image: url(/mnt/USB_FLASH/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
    }
    else if(flag_USB==0 && flag_SD==1)
    {
        ui->label_screen->setStyleSheet(QString("image: url(/mnt/SD_CARD/Picture/%2/%1);").arg(photo_name.at(photo_labelnum)).arg(QString::fromStdString(FolderPath)));
    }
   printf("photo_labelnum===%d===88\n",photo_labelnum);
}


photo_browse_single::~photo_browse_single()
{
    delete ui;
}

void photo_browse_single::sd_convert_usb()
{
    emit return_photo();
}

Label_full_screen::Label_full_screen(QWidget *parent): QLabel(parent)
{

}
void Label_full_screen::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit doubleClicked();
}
Label_screen::Label_screen(QWidget *parent) : QLabel(parent)
{

}
void Label_screen::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit doubleClicked();
}
Label_return_ps::Label_return_ps(QWidget *parent): QLabel(parent)
{

}
void Label_return_ps::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_left_ps::Label_left_ps(QWidget *parent): QLabel(parent)
{

}
void Label_left_ps::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_right_ps::Label_right_ps(QWidget *parent): QLabel(parent)
{

}
void Label_right_ps::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_delete_ps::Label_delete_ps(QWidget *parent): QLabel(parent)
{

}
void Label_delete_ps::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
