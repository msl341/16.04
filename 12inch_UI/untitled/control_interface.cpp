#include "control_interface.h"
#include "ui_control_interface.h"
control_interface::control_interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::control_interface)
{
    ui->setupUi(this);

    ui->label_host_led->setVisible(false);

    timer = new QTimer(this);

    timer_t = new QTimer(this);

    timer_switchable = new QTimer(this);

    connect(timer_t, SIGNAL(timeout()), this, SLOT(updateTime_date()));
    timer_t->start(1000);

    connect(timer_t, &QTimer::timeout, this,[=](){
        updateTime_date();
    });

    connect(timer_switchable, &QTimer::timeout, this,[=](){
        switchable_flag=0;
    });

    updateTime_date();

    ui->label_time->setText("00:00:00");
    ui->label_screen_left->setStyleSheet("border-radius: 50px 50px 50px 50px;");
    ui->label_screen_right->setStyleSheet("border-radius: 50px 50px 50px 50px;");

    ui->label_status->setStyleSheet("font-size: 20px;");
    ui->labelw_awb->setStyleSheet("font-size: 15px;");
    ui->label_atom->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_mtoa->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->labelw_zoom->setStyleSheet("font-size: 15px;");
    ui->labelw_picture->setStyleSheet("font-size: 15px;");
    ui->label_picture_1->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_picture_2->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_picture_3->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_picture_4->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_picture_5->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->labelw_show->setStyleSheet("font-size: 15px;");
    ui->label_display_1->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_display_2->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_display_3->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->labelw_language->setStyleSheet("font-size: 15px;");
    ui->label_language_c->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_language_ct->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_language_e->setStyleSheet("font-size: 11px;background-color: black;border: 1px solid white;color: white;");
    ui->label_store->setStyleSheet("font-size: 45px;color: white;border: 5px solid white;border-radius: 10px 10px 10px 10px;font-weight: bold;");
    ui->labelw_number->setStyleSheet("font-size: 15px;");
    ui->labelw_time->setStyleSheet("font-size: 15px;");
    ui->label_timenum->setStyleSheet("font-size: 20px;");
    ui->label_use_num->setStyleSheet("font-size: 20px;");
    ui->label_versions->setStyleSheet("font-size: 15px;");
    ui->label_versions_num->setStyleSheet("font-size: 15px;qproperty-alignment: AlignLeft;");
    ui->label_1->setStyleSheet("font-size: 15px;");
    ui->label_2->setStyleSheet("font-size: 15px;");
    ui->label_3->setStyleSheet("font-size: 15px;");

    ui->label_use_num->setStyleSheet("font-size: 20px;qproperty-alignment: AlignLeft;");
    ui->label_zoomnum->setStyleSheet("font-size: 20px;");

     connect(ui->label_screen_left,&Label_screen_left::clicked_1,this,[=](){
        display_flag=3;
        read_socket_display();
        emit socket_screen_left();
     });
     connect(ui->label_screen_right,&Label_screen_right::clicked_1,this,[=](){
        display_flag=3;
        read_socket_display();
        emit socket_screen_right();
     });

    //左测白平衡
    //左测图形画面
    connect(ui->label_picture_mode,&Label_picture_mode::clicked_1,this,[=](){
        if(switchable_flag == 0){
            switchable_flag=1;
            if(display_flag != 2)
            {
                if(picture_flag<5)
                {
                    picture_flag++;
                }
                else
                {
                    picture_flag=1;
                }
                update_picture_mode();
            }
            else
            {
                //加提示
            }
             timer_switchable->start(300);
            }


    });
    //左测画面显示
    connect(ui->label_display_mode,&Label_display_mode::clicked_1,this,[=](){
        click_display();
    });
    //左测语言

    connect(ui->label_custom1,&Label_custom1::clicked_1,this,[=](){
        if (custom1_flag < 4)
        {
            custom1_flag++;
        } else
        {
            custom1_flag = 0;
        }

        while ((custom1_flag == custom2_flag || custom1_flag == custom3_flag) && custom1_flag!=0)
        {
            if (custom1_flag < 4)
            {
                custom1_flag++;
            } else
            {
                custom1_flag = 0;
            }
        }
        custom_add_switch(1);
    });
    connect(ui->label_custom2,&Label_custom2::clicked_1,this,[=](){
        if (custom2_flag < 4)
        {
            custom2_flag++;
        } else
        {
            custom2_flag = 0;
        }

        while ((custom2_flag == custom1_flag || custom2_flag == custom3_flag) && custom2_flag!=0)
        {
            if (custom2_flag < 4)
            {
                custom2_flag++;
            } else
            {
                custom2_flag = 0;
            }
        }
        custom_add_switch(2);
    });
    connect(ui->label_custom3,&Label_custom3::clicked_1,this,[=](){
        if (custom3_flag < 4)
        {
            custom3_flag++;
        } else
        {
            custom3_flag = 0;
        }

        while ((custom3_flag == custom1_flag || custom3_flag == custom2_flag) && custom3_flag!=0)
        {
            if (custom3_flag < 4)
            {
                custom3_flag++;
            } else
            {
                custom3_flag = 0;
            }
        }
        custom_add_switch(3);
    });



    connect(ui->label_awb,&Label_awb::clicked_1,this,[=](){
        if(switchable_flag == 0)
        {
            switchable_flag=1;
            set_awb();
            timer_switchable->start(300); //tony
        }
    });
    connect(ui->label_freeze,&Label_freeze::clicked_1,this,[=](){
        if(switchable_flag == 0)
        {
            switchable_flag=1;
            set_freeze();
            timer_switchable->start(300);
        }
    });
    connect(ui->label_store,&Label_store::clicked_1,this,[=](){
        if(flag_SD==1 || flag_USB==1)
        {
            if(freeze_flag==1)
            {
                freeze_flag=0;
                emit socket_store();
                ui->label_freeze->setStyleSheet("background-image: url(:/tu/Freeze/freeze.png);");

                ui->label_store->setVisible(false);
                ui->label_frames->setVisible(true);

                ui->label_picture_mode->setEnabled(true);
                ui->label_display_mode->setEnabled(true);
                ui->label_custom1->setEnabled(true);
                ui->label_custom2->setEnabled(true);
                ui->label_custom3->setEnabled(true);
                ui->label_awb->setEnabled(true);
                ui->label_photograph->setEnabled(true);
                ui->label_video->setEnabled(true);
                ui->label_ae->setEnabled(true);
            }
        }
        else if(flag_SD==0 && flag_USB==0)
        {
            emit nosd_card();
        }
    });
    connect(ui->label_rotate,&Label_rotate::clicked_1,this,[=](){
        if(display_flag != 2)
        {
            if(rotate_flag<5)
            {
                rotate_flag++;
            }
            else
            {
                rotate_flag=1;
            }
            set_rotate();
        }
        else
        {
            //加提示
        }

    });
    connect(ui->label_photograph,&Label_photograph::clicked_1,this,[=](){
        set_photograph();
    });
    connect(ui->label_video,&Label_videoint::clicked_1,this,[=](){
        set_video();
    });
    connect(ui->label_ae,&Label_ae::clicked_1,this,[=](){
        if(switchable_flag == 0)
        {
            switchable_flag=1;
            if(ae_flag<5)
            {
                ae_flag++;
            }
            else
            {
                ae_flag=1;
            }
            set_gpio_ae();
            timer_switchable->start(300);
        }
    });
//    connect(ui->label_host_led,&Label_host_led::clicked_1,this,[=](){
//        if(led_host_flag<4)
//        {
//            led_host_flag++;
//        }
//        else
//        {
//            led_host_flag=0;
//        }
//        set_gpio_host_led();
//    });
    connect(ui->label_led,&Label_led::clicked_1,this,[=](){
        set_ledup();
    });
    connect(ui->label_pump,&Label_pump::clicked_1,this,[=](){
        click_pump();
    });
    connect(ui->label_interface,&Label_interface::clicked_1,this,[=](){
            if(!freeze_flag)
            {
                emit clicked_interface();
            }
    });

    //大小切换
    connect(ui->label_frames,&Label_frames::clicked_1,this,[=](){
        emit socket_frames();
        qDebug()<<"qwerdfb";
    });
    //双击变成双画面
    connect(ui->label_frames,&Label_frames::clicked_double,this,[=](){
        qDebug()<<"qwerdfb111";
        emit socket_dual_screen();
        display_flag=2;
        ui->label_frames->setVisible(false);
        ui->label_screen_left->setVisible(true);
        ui->label_screen_right->setVisible(true);
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(true);
        ui->label_display_3->setVisible(false);
        ui->label_b->setStyleSheet("border-image: url(:/tu/Display/background.png);");
    });

    ui->label_screen_left->setVisible(false);
    ui->label_screen_right->setVisible(false);
    ui->label_frames->setVisible(false);
    ui->label_store->setVisible(false);
    ui->label_time->setVisible(false);
    ui->label_time->setStyleSheet("color: red;");


    ui->label_timenum->setVisible(true);
    ui->labelw_time->setVisible(true);
    ui->labelw_number->setVisible(true);
    ui->label_use_num->setVisible(true);
    // hide unused things


    ui->label_1->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_custom1->setVisible(false);
    ui->label_custom2->setVisible(false);
    ui->label_custom3->setVisible(false);
}

control_interface::~control_interface()
{
    delete ui;
}

void control_interface::update_duration()
{
    int hours = iRemainTime / 3600;
    int minutes = (iRemainTime % 3600) / 60;
    int seconds = iRemainTime % 60;
    QString timeText = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));

    ui->label_timenum->setText(timeText);
    ui->label_use_num->setText(QString::number(iTotalCount));

    iRemainTime=0;
    iTotalCount=0;
    //printf("control_interface::update_duration\n");
}

void control_interface::update_zoomnum()
{
    switch (zoom_num) {
        case 1:
        {
            ui->label_zoomnum->setText(QString("x1"));
            break;
        }
        case 2:
        {
            ui->label_zoomnum->setText(QString("x2"));
            break;
        }
        case 3:
        {
            ui->label_zoomnum->setText(QString("x3"));
            break;
        }
        case 4:
        {
            ui->label_zoomnum->setText(QString("x4"));
            break;
        }
    }
}

void control_interface::setCurPatient(QString name)
{
    ui->label_curPatient->setText(name);
}

void control_interface::setBatteryStatus(int status)
{
//    qDebug() << "in set battery";
    QPixmap batteryStatus(QString(":/tu/battery_icon/battery%1.png").arg(status));
    if(batteryStatus.isNull()){
        qDebug() << "fail load photo";
    }
    ui->battery->setPixmap(batteryStatus);
    ui->battery->raise();
}

void control_interface::setCharging()
{
    QPixmap batteryStatus(QString(":/tu/battery_icon/charging4.png"));
    if(batteryStatus.isNull()){
        qDebug() << "fail load photo";
    }
    ui->battery->setPixmap(batteryStatus);
    ui->battery->raise();
}

void control_interface::set_awb()
{
    awb_atom_flag=1;
    ui->label_atom->setVisible(false);
    ui->label_mtoa->setVisible(true);
    ui->label_awb->setStyleSheet("background-image: url(:/tu/AWBl.png);");
    emit socket_awb();
}

void control_interface::set_freeze()
{
    if(display_flag != 2)
    {
        if(freeze_flag==0)
        {
            freeze_flag=1;//冻结
            emit socket_freeze1();

            ui->label_frames->setVisible(false);

            ui->label_picture_mode->setEnabled(false);
            ui->label_display_mode->setEnabled(false);
            ui->label_custom1->setEnabled(false);
            ui->label_custom2->setEnabled(false);
            ui->label_custom3->setEnabled(false);
            ui->label_awb->setEnabled(false);
            ui->label_photograph->setEnabled(false);
            ui->label_video->setEnabled(false);
            ui->label_ae->setEnabled(false);
        }
        else if(freeze_flag==1)
        {
            freeze_flag=0;
            emit socket_cancel_freeze1();
            ui->label_freeze->setStyleSheet("background-image: url(:/tu/Freeze/freeze.png);");

            ui->label_store->setVisible(false);
            ui->label_frames->setVisible(true);

            ui->label_picture_mode->setEnabled(true);
            ui->label_display_mode->setEnabled(true);
            ui->label_custom1->setEnabled(true);
            ui->label_custom2->setEnabled(true);
            ui->label_custom3->setEnabled(true);
            ui->label_awb->setEnabled(true);
            ui->label_photograph->setEnabled(true);
            ui->label_video->setEnabled(true);
            ui->label_ae->setEnabled(true);
        }
    }
    else
    {
        //加提示
    }
}

void control_interface::set_video()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(check_disk()==0)
        {
            if(flag_SD==1 || flag_USB==1)
            {
                if(video_flag==0)
                {
                    video_flag=1;
                    ui->label_video->setStyleSheet("background-image: url(:/tu/recl.png);");

                    startTime = QDateTime::currentDateTime();
                    timer->setInterval(1000);
                    connect(timer, &QTimer::timeout, this, &control_interface::updateTimer);
                    timer->start();
                    ui->label_time->setVisible(true);

                    ui->label_frames->setEnabled(false);
                    ui->label_picture_mode->setEnabled(false);
                    ui->label_display_mode->setEnabled(false);
                    ui->label_custom1->setEnabled(false);
                    ui->label_custom2->setEnabled(false);
                    ui->label_custom3->setEnabled(false);
                    ui->label_awb->setEnabled(false);
                    ui->label_freeze->setEnabled(false);
                    ui->label_rotate->setEnabled(false);
                    ui->label_photograph->setEnabled(false);
                    ui->label_ae->setEnabled(false);
                    ui->label_led->setEnabled(false);
                    ui->label_host_led->setEnabled(false);
                    ui->label_pump->setEnabled(false);
                    ui->label_interface->setEnabled(false);

                    emit socket_videoon();
                }
                else if(video_flag==1)
                {
                    video_flag=0;
                    ui->label_video->setStyleSheet("background-image: url(:/tu/rec.png);");

                    timer->stop();
                    ui->label_time->clear();
                    ui->label_time->setVisible(false);

                    ui->label_frames->setEnabled(true);
                    ui->label_picture_mode->setEnabled(true);
                    ui->label_display_mode->setEnabled(true);
                    ui->label_custom1->setEnabled(true);
                    ui->label_custom2->setEnabled(true);
                    ui->label_custom3->setEnabled(true);
                    ui->label_awb->setEnabled(true);
                    ui->label_freeze->setEnabled(true);
                    ui->label_rotate->setEnabled(true);
                    ui->label_photograph->setEnabled(true);
                    ui->label_ae->setEnabled(true);
                    ui->label_led->setEnabled(true);
                    ui->label_host_led->setEnabled(true);
                    ui->label_pump->setEnabled(true);
                    ui->label_interface->setEnabled(true);

                    emit socket_videooff();
                }
            }
            else if(flag_SD==0 || flag_USB==0)
            {
                emit nosd_card();
            }
        }
        else
        {
            emit stock_full();
        }
        timer_switchable->start(2000);
    }
}

void control_interface::set_photograph()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(check_disk()==0)
        {
            if(flag_SD==1 || flag_USB==1)
            {
                ui->label_photograph->setStyleSheet("background-image: url(:/tu/takephotol.png);");
                emit socket_photograph();
                emit socket_photograph_name();
            }
            else if(flag_SD==0 || flag_USB==0)
            {
                emit nosd_card();
            }
        }
        else
        {
            emit stock_full();
        }
        timer_switchable->start(300);
    }
}

void control_interface::set_zoomup()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(zoom_num<4)
        {
            zoom_num++;
        }
        else
        {
            zoom_num=1;
        }
        printf("======zoom_num=======%d=======\n",zoom_num);
        update_zoomnum();
        emit socket_set_zoom();
        timer_switchable->start(300);
    }
}

void control_interface::set_zoomdown()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(zoom_num>1)
        {
            zoom_num--;
        }
        else
        {
            zoom_num=4;
        }
        printf("======zoom_num=======%d=======\n",zoom_num);
        update_zoomnum();
        emit socket_set_zoom();
        timer_switchable->start(300);
    }
}

void control_interface::set_ledup()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(led_flag<4)
        {
            led_flag++;
        }
        else
        {
            led_flag=0;
        }
        set_gpio_led();
        timer_switchable->start(300);
    }
}

void control_interface::set_leddown()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(led_flag>0)
        {
            led_flag--;
        }
        else
        {
            led_flag=4;
        }
        set_gpio_led();
        timer_switchable->start(300);
    }
}

void control_interface::click_display()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(sensor_num==2)
        {
            if(display_flag<3)
            {
                display_flag++;
            }
            else
            {
                display_flag=1;
            }
            set_display_mode();
        }
        timer_switchable->start(300);
    }
}

void control_interface::click_pump()
{
    if(switchable_flag == 0)
    {
        switchable_flag=1;
        if(pump_flag<3)
        {
            pump_flag++;
        }
        else
        {
            pump_flag=1;
        }
        set_gpio_pump();
        timer_switchable->start(300);
    }
}

void control_interface::first_key_set()
{
    switch (custom1_flag) {
    case 1:
    {
        set_awb();
        break;
    }
    case 2:
    {
        set_freeze();
        break;
    }
    case 3:
    {
        if(ae_flag<5)
        {
            ae_flag++;
        }
        else
        {
            ae_flag=1;
        }
        set_gpio_ae();
        break;
    }
    case 4:
    {
        if(pump_flag<3)
        {
            pump_flag++;
        }
        else
        {
            pump_flag=1;
        }
        set_gpio_pump();
        break;
    }
    }
}

void control_interface::second_key_set()
{
    switch (custom2_flag) {
    case 1:
    {
        set_awb();
        break;
    }
    case 2:
    {
        set_freeze();
        break;
    }
    case 3:
    {
        if(ae_flag<5)
        {
            ae_flag++;
        }
        else
        {
            ae_flag=1;
        }
        set_gpio_ae();
        break;
    }
    case 4:
    {
        if(pump_flag<3)
        {
            pump_flag++;
        }
        else
        {
            pump_flag=1;
        }
        set_gpio_pump();
        break;
    }
    }
}

void control_interface::third_key_set()
{
    switch (custom3_flag) {
    case 1:
    {
        set_awb();
        break;
    }
    case 2:
    {
        set_freeze();
        break;
    }
    case 3:
    {
        if(ae_flag<5)
        {
            ae_flag++;
        }
        else
        {
            ae_flag=1;
        }
        set_gpio_ae();
        break;
    }
    case 4:
    {
        if(pump_flag<3)
        {
            pump_flag++;
        }
        else
        {
            pump_flag=1;
        }
        set_gpio_pump();
        break;
    }
    }
}

void control_interface::fourth_key_set()
{
    if(flag_SD==0 || flag_USB==0)
    {
        ui->label_photograph->setStyleSheet("background-image: url(:/tu/takephotol.png);");
        emit socket_photograph();
        emit socket_photograph_name();
    }
    else if(flag_SD==0 || flag_USB==0)
    {
        emit nosd_card();
    }
}

void control_interface::fourth_key_long_set()
{
    set_video();
}

void control_interface::custom_add_switch(int data)
{
    if(data==1)
    {
        switch (custom1_flag) {
        case 0:
            ui->label_custom1->setStyleSheet("image: url(:/tu/nofunc.png);");
            break;
        case 1:
            ui->label_custom1->setStyleSheet("image: url(:/tu/awbmin.png);");
            break;
        case 2:
            ui->label_custom1->setStyleSheet("image: url(:/tu/freezemin.png);");
            break;
        case 3:
            ui->label_custom1->setStyleSheet("image: url(:/tu/aemin.png);");
            break;
        case 4:
            ui->label_custom1->setStyleSheet("image: url(:/tu/pumpmin.png);");
            break;
        }
    }
    if(data==2)
    {
        switch (custom2_flag) {
        case 0:
            ui->label_custom2->setStyleSheet("image: url(:/tu/nofunc.png);");
            break;
        case 1:
            ui->label_custom2->setStyleSheet("image: url(:/tu/awbmin.png);");
            break;
        case 2:
            ui->label_custom2->setStyleSheet("image: url(:/tu/freezemin.png);");
            break;
        case 3:
            ui->label_custom2->setStyleSheet("image: url(:/tu/aemin.png);");
            break;
        case 4:
            ui->label_custom2->setStyleSheet("image: url(:/tu/pumpmin.png);");
            break;
        }
    }
    if(data==3)
    {
        switch (custom3_flag) {
        case 0:
            ui->label_custom3->setStyleSheet("image: url(:/tu/nofunc.png);");
            break;
        case 1:
            ui->label_custom3->setStyleSheet("image: url(:/tu/awbmin.png);");
            break;
        case 2:
            ui->label_custom3->setStyleSheet("image: url(:/tu/freezemin.png);");
            break;
        case 3:
            ui->label_custom3->setStyleSheet("image: url(:/tu/aemin.png);");
            break;
        case 4:
            ui->label_custom3->setStyleSheet("image: url(:/tu/pumpmin.png);");
            break;
        }
    }
}

void control_interface::updateTime_date()
{
     QDate date = QDate::currentDate();
     QTime time = QTime::currentTime();

     QString year = QString::number(date.year());
     QString month = QString::number(date.month()).rightJustified(2, '0');
     QString day = QString::number(date.day()).rightJustified(2, '0');
     QString hour = QString::number(time.hour()).rightJustified(2, '0');
     QString minute = QString::number(time.minute()).rightJustified(2, '0');
     QString second = QString::number(time.second()).rightJustified(2, '0');

     year0_data=year.toInt();
     time_num.num_year1=QString::number(year0_data / 1000);
     time_num.num_year2=QString::number((year0_data / 100) % 10);
     time_num.num_year3=QString::number((year0_data / 10) % 10);
     time_num.num_year4=QString::number(year0_data % 10);
     time_num.num_year = year;
     time_num.num_month = month;
     time_num.num_day = day;
     time_num.num_hour = hour;
     time_num.num_minute = minute;
     time_num.num_second = second;

     ui->label_years->setText(time_num.num_year);
     ui->label_month_day->setText(QString("%1/%2").arg(time_num.num_month).arg(time_num.num_day));
     ui->label_times->setText(QString("%1:%2:%3").arg(time_num.num_hour).arg(time_num.num_minute).arg(time_num.num_second));

    ui->label_years ->setStyleSheet("font-size: 34px;");
    ui->label_month_day ->setStyleSheet("font-size: 32px;");
    ui->label_times ->setStyleSheet("font-size: 17px;");
}

void control_interface::settext()
{
    ui->label_status->setText(tr("状态信息"));
    ui->labelw_awb->setText(tr("白平衡:"));
    ui->label_mtoa->setText(tr("自动"));
    ui->label_atom->setText(tr("手动"));
    ui->labelw_zoom->setText(tr("缩放倍数:"));
    ui->labelw_picture->setText(tr("画面模式:"));
    ui->label_picture_1->setText(tr("初始"));
    ui->label_picture_2->setText(tr("圆形"));
    ui->label_picture_3->setText(tr("八角形"));
    ui->label_picture_4->setText(tr("椭圆"));
    ui->label_picture_5->setText(tr("矩形"));
    ui->labelw_show->setText(tr("显示模式:"));
    ui->label_display_1->setText(tr("单画面模式"));
    ui->label_display_2->setText(tr("双画面模式"));
    ui->label_display_3->setText(tr("子母模式"));
    ui->labelw_language->setText(tr("语言:"));
    ui->label_language_c->setText(tr("简体中文"));
    ui->label_language_ct->setText(tr("繁体中文"));
    ui->label_language_e->setText(tr("英文"));

    ui->label_store->setText(tr("储存"));

    ui->labelw_number->setText(tr("使用次数:"));
    ui->labelw_time->setText(tr("使用时长:"));

    ui->label_versions->setText(tr("当前版本:"));
}

void control_interface::updateTimer()
{
    if(check_disk()==0)
    {
        qint64 timeElapsed = startTime.msecsTo(QDateTime::currentDateTime());

        int hours = timeElapsed / 3600000;
        int minutes = (timeElapsed % 3600000) / 60000;
        int seconds = (timeElapsed % 60000) / 1000;
        QString timeText = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));

        ui->label_time->setStyleSheet("color: red;");
        ui->label_time->setText(timeText);
    }
    else
    {
        emit stock_full();
        video_flag=0;
        ui->label_video->setStyleSheet("background-image: url(:/tu/rec.png);");

        timer->stop();
        ui->label_time->clear();
        ui->label_time->setVisible(false);

        ui->label_frames->setEnabled(true);
        ui->label_picture_mode->setEnabled(true);
        ui->label_display_mode->setEnabled(true);
        ui->label_custom1->setEnabled(true);
        ui->label_custom2->setEnabled(true);
        ui->label_custom3->setEnabled(true);
        ui->label_awb->setEnabled(true);
        ui->label_freeze->setEnabled(true);
        ui->label_rotate->setEnabled(true);
        ui->label_photograph->setEnabled(true);
        ui->label_ae->setEnabled(true);
        ui->label_led->setEnabled(true);
//        ui->label_host_led->setEnabled(true);
        ui->label_pump->setEnabled(true);
        ui->label_interface->setEnabled(true);

        emit socket_videooff();
    }
}

void control_interface::read_socket_awb()
{
    usleep(1000*1000);
    awb_atom_flag=0;
    ui->label_awb->setStyleSheet("background-image: url(:/tu/AWB.png);");
    ui->label_atom->setVisible(true);
    ui->label_mtoa->setVisible(false);
}

void control_interface::read_socket_freeze()
{
    ui->label_freeze->setStyleSheet("background-image: url(:/tu/Freeze/freezeF.png);");
    ui->label_store->setVisible(true);
}

void control_interface::read_socket_photograph()
{
    usleep(1000*1000);
    ui->label_photograph->setStyleSheet("background-image: url(:/tu/takephoto.png);");
}

void control_interface::update_data()
{
    if(awb_atom_flag==0)
    {
        ui->label_atom->setVisible(true);
        ui->label_mtoa->setVisible(false);
    }
    else if(awb_atom_flag==1)
    {
        ui->label_atom->setVisible(false);
        ui->label_mtoa->setVisible(true);
    }

    update_picture_mode();

    switch (display_flag) {
    case 1:
        ui->label_display_1->setVisible(true);
        ui->label_display_2->setVisible(false);
        ui->label_display_3->setVisible(false);
        switch (picture_flag) {
        case 1:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        case 2:
            ui->label_b->setStyleSheet("background-image: url(:/tu/circle.png);");
            break;
        case 3:
            ui->label_b->setStyleSheet("background-image: url(:/tu/octagon.png);");
            break;
        case 4:
            ui->label_b->setStyleSheet("background-image: url(:/tu/oval.png);");
            break;
        case 5:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        }
        break;
    case 2:
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(true);
        ui->label_display_3->setVisible(false);
        ui->label_b->setStyleSheet("background-image: url(:/tu/Display/background.png);");
        break;
    case 3:
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(false);
        ui->label_display_3->setVisible(true);
        break;
    }

    switch (language_flag) {
    case 1:
    {
        ui->label_language_c->setVisible(true);
        ui->label_language_ct->setVisible(false);
        ui->label_language_e->setVisible(false);
        break;
    }
    case 2:
    {
        ui->label_language_c->setVisible(false);
        ui->label_language_ct->setVisible(true);
        ui->label_language_e->setVisible(false);
        break;
    }
    case 3:
    {
        ui->label_language_c->setVisible(false);
        ui->label_language_ct->setVisible(false);
        ui->label_language_e->setVisible(true);
        break;
    }
    }

    if(freeze_flag==1)
    {//冻结
        ui->label_freeze->setStyleSheet("background-image: url(:/tu/Freeze/freezeF.png);");
    }
    else if(freeze_flag==0)
    {
        ui->label_freeze->setStyleSheet("background-image: url(:/tu/Freeze/freeze.png);");
    }

    switch (rotate_flag) {
    case 1:
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate0.png);");
        break;
    case 2:
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate1.png);");
        break;
    case 3:
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate2.png);");
        break;
    case 4:
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate3.png);");
        break;
    case 5:
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate4.png);");
        break;
    }



    switch (ae_flag) {
    case 1:
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE1.png);");
        break;
    case 2:
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE2.png);");
        break;
    case 3:
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE3.png);");
        break;
    case 4:
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE4.png);");
        break;
    case 5:
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE5.png);");
        break;
    }

    if(mipi3_in_flag==1)
    {
        switch (led_host_flag) {
        case 1:
        {
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled1.png);");
            break;
        }
        case 2:
        {
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled2.png);");
            break;
        }
        case 3:
        {
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled3.png);");
            break;
        }
        case 4:
        {
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled4.png);");
            break;
        }
        default:
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled0.png);");
            break;
        }
    }

    switch (led_flag) {
    case 1:
    {
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED1.png);");
        break;
    }
    case 2:
    {
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED2.png);");
        break;
    }
    case 3:
    {
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED3.png);");
        break;
    }
    case 4:
    {
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED4.png);");
        break;
    }
    default:
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED0.png);");
        break;
    }

    switch (pump_flag) {
    case 1:
        ui->label_pump->setStyleSheet("background-image: url(:/tu/Pump/pump0.png);");
        break;
    case 2:
        ui->label_pump->setStyleSheet("background-image: url(:/tu/Pump/pump1.png);");
        break;
    case 3:
        ui->label_pump->setStyleSheet("background-image: url(:/tu/Pump/pump2.png);");
        break;
    }

    set_gpio_led();
    set_gpio_host_led();
    set_gpio_pump();
    update_zoomnum();
}

void control_interface::set_display_mode()
{
    switch (display_flag) {
    case 1:
    {
        emit socket_single_screen();
        ui->label_frames->setVisible(false);
        ui->label_screen_left->setVisible(false);
        ui->label_screen_right->setVisible(false);
        ui->label_display_1->setVisible(true);
        ui->label_display_2->setVisible(false);
        ui->label_display_3->setVisible(false);
        switch (picture_flag) {
        case 1:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        case 2:
            ui->label_b->setStyleSheet("background-image: url(:/tu/circle.png);");
            break;
        case 3:
            ui->label_b->setStyleSheet("background-image: url(:/tu/octagon.png);");
            break;
        case 4:
            ui->label_b->setStyleSheet("background-image: url(:/tu/oval.png);");
            break;
        case 5:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        }
        break;
    }
    case 2:
    {
        emit socket_dual_screen();

        ui->label_frames->setVisible(false);
        ui->label_screen_left->setVisible(true);
        ui->label_screen_right->setVisible(true);
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(true);
        ui->label_display_3->setVisible(false);
        ui->label_b->setStyleSheet("border-image: url(:/tu/Display/background.png);");
        break;
    }
    case 3:
    {
        emit socket_size_screen();

        ui->label_frames->setVisible(true);

        ui->label_screen_left->setVisible(false);
        ui->label_screen_right->setVisible(false);
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(false);
        ui->label_display_3->setVisible(true);
        switch (picture_flag) {
        case 1:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        case 2:
            ui->label_b->setStyleSheet("background-image: url(:/tu/circle.png);");
            break;
        case 3:
            ui->label_b->setStyleSheet("background-image: url(:/tu/octagon.png);");
            break;
        case 4:
            ui->label_b->setStyleSheet("background-image: url(:/tu/oval.png);");
            break;
        case 5:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        }
        break;
    }
    }
}

void control_interface::set_rotate()
{
    switch (rotate_flag) {
    case 1:
    {
        if(freeze_flag==1)
        {
            emit socket_rotate_freeze1();
        }
        else if(freeze_flag==0)
        {
            emit socket_rotate1();
        }
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate0.png);");
        break;
    }
    case 2:
    {
        if(freeze_flag==1)
        {
            emit socket_rotate_freeze2();
        }
        else if(freeze_flag==0)
        {
            emit socket_rotate2();
        }
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate1.png);");
        break;
    }
    case 3:
    {
        if(freeze_flag==1)
        {
            emit socket_rotate_freeze3();
        }
        else if(freeze_flag==0)
        {
            emit socket_rotate3();
        }
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate2.png);");
        break;
    }
    case 4:
    {
        if(freeze_flag==1)
        {
            emit socket_rotate_freeze4();
        }
        else if(freeze_flag==0)
        {
            emit socket_rotate4();
        }
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate3.png);");
        break;
    }
    case 5:
    {
        if(freeze_flag==1)
        {
            emit socket_rotate_freeze5();
        }
        else if(freeze_flag==0)
        {
            emit socket_rotate5();
        }
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate4.png);");
        break;
    }
    }
}

void control_interface::set_gpio_ae()
{
    switch (ae_flag) {
    case 1:
    {
        emit socket_ae1();
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE1.png);");
        break;
    }
    case 2:
    {
        emit socket_ae2();
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE2.png);");
        break;
    }
    case 3:
    {
        emit socket_ae3();
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE3.png);");
        break;
    }
    case 4:
    {
        emit socket_ae4();
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE4.png);");
        break;
    }
    case 5:
    {
        emit socket_ae5();
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE5.png);");
        break;
    }
    }
}

void control_interface::set_gpio_host_led()
{
    if(mipi3_in_flag==1)
    {
        switch (led_host_flag) {
        case 1:
        {
            system("echo 25000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/duty_cycle");
            usleep(10 * 1000);
            system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/enable");
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled1.png);");
            break;
        }
        case 2:
        {
            system("echo 50000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/duty_cycle");
            usleep(10 * 1000);
            system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/enable");
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled2.png);");
            break;
        }
        case 3:
        {
            system("echo 75000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/duty_cycle");
            usleep(10 * 1000);
            system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/enable");
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled3.png);");
            break;
        }
        case 4:
        {
            system("echo 95000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/duty_cycle");
            usleep(10 * 1000);
            system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/enable");
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled4.png);");
            break;
        }
        default:
            system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/enable");//关
            ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled0.png);");
            break;
        }
    }
}

void control_interface::set_gpio_host_led_logo()
{
    system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm6/enable");//关
    ui->label_host_led->setStyleSheet("background-image: url(:/tu/LED/hostled0.png);");
}
void control_interface::set_gpio_led()
{
    switch (led_flag) {
    case 1:
    {
        system("echo 25000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/enable");

        system("echo 25000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/enable");

        system("echo 25000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/enable");
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED1.png);");

        write(fd_uartkey, pLED1, sizeof(pLED1));
        break;
    }
    case 2:
    {
        system("echo 50000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/enable");

        system("echo 50000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/enable");

        system("echo 50000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/enable");
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED2.png);");

        write(fd_uartkey, pLED2, sizeof(pLED2));
        break;
    }
    case 3:
    {
        system("echo 75000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/enable");

        system("echo 75000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/enable");

        system("echo 75000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/enable");
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED3.png);");

        write(fd_uartkey, pLED3, sizeof(pLED3));
        break;
    }
    case 4:
    {
        system("echo 90000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/enable");

        system("echo 90000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/enable");

        system("echo 95000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/enable");
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED4.png);");

        write(fd_uartkey, pLED4, sizeof(pLED4));
        break;
    }
    default:
    {
        system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm7/enable");//关
        system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm5/enable");//关
        system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm0/enable");//关
        ui->label_led->setStyleSheet("background-image: url(:/tu/LED/LED0.png);");

        write(fd_uartkey, pLED0, sizeof(pLED0));
        break;
    }
    }
}

void control_interface::set_gpio_pump()
{
    switch (pump_flag) {
    case 1:
    {
        system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm1/enable");
        usleep(10 * 1000);
        ui->label_pump->setStyleSheet("background-image: url(:/tu/Pump/pump0.png);");
        break;
    }
    case 2:
    {
        system("echo 65000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm1/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm1/enable");
        ui->label_pump->setStyleSheet("background-image: url(:/tu/Pump/pump1.png);");
        break;
    }
    case 3:
    {
        system("echo 100000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm1/duty_cycle");
        usleep(10 * 1000);
        system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm1/enable");
        ui->label_pump->setStyleSheet("background-image: url(:/tu/Pump/pump2.png);");
        break;
    }
    }
}

void control_interface::read_socket_display()
{
    switch (display_flag) {
    case 1:
    {
        ui->label_frames->setVisible(false);
        ui->label_screen_left->setVisible(false);
        ui->label_screen_right->setVisible(false);
        ui->label_display_1->setVisible(true);
        ui->label_display_2->setVisible(false);
        ui->label_display_3->setVisible(false);
        switch (picture_flag) {
        case 1:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        case 2:
            ui->label_b->setStyleSheet("background-image: url(:/tu/circle.png);");
            break;
        case 3:
            ui->label_b->setStyleSheet("background-image: url(:/tu/octagon.png);");
            break;
        case 4:
            ui->label_b->setStyleSheet("background-image: url(:/tu/oval.png);");
            break;
        case 5:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        }
        break;
    }
    case 2:
    {
        ui->label_frames->setVisible(false);
        ui->label_screen_left->setVisible(true);
        ui->label_screen_right->setVisible(true);
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(true);
        ui->label_display_3->setVisible(false);
        ui->label_b->setStyleSheet("background-image: url(:/tu/Display/background.png);");
        break;
    }
    case 3:
    {
        ui->label_frames->setVisible(true);
        ui->label_screen_left->setVisible(false);
        ui->label_screen_right->setVisible(false);
        ui->label_display_1->setVisible(false);
        ui->label_display_2->setVisible(false);
        ui->label_display_3->setVisible(true);
        switch (picture_flag) {
        case 1:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        case 2:
            ui->label_b->setStyleSheet("background-image: url(:/tu/circle.png);");
            break;
        case 3:
            ui->label_b->setStyleSheet("background-image: url(:/tu/octagon.png);");
            break;
        case 4:
            ui->label_b->setStyleSheet("background-image: url(:/tu/oval.png);");
            break;
        case 5:
            ui->label_b->setStyleSheet("background-image: url(:/tu/square.png);");
            break;
        }
        break;
    }
    }
}


void control_interface::reset_the_settings()
{
    //缩放

    //画面
    picture_flag=1;
    update_picture_mode();
    //显示
    display_flag=1;
    set_display_mode();
    //自定义

    //旋转
    rotate_flag=1;
    freeze_flag=0;
    set_rotate();
    //AE
    ae_flag=3;
    set_gpio_ae();
    //Host_LED
    led_host_flag=2;
    if(mipi3_in_flag==1)
    {
        set_gpio_host_led();
    }
    //LED
    led_flag=2;
    set_gpio_led();
    //气泵
    pump_flag=1;
    set_gpio_pump();
}

void control_interface::update_picture_mode()
{
    switch (picture_flag) {
    case 1:
    {
        ui->label_picture_1->setVisible(true);
        ui->label_picture_2->setVisible(false);
        ui->label_picture_3->setVisible(false);
        ui->label_picture_4->setVisible(false);
        ui->label_picture_5->setVisible(false);
        ui->label_b->setStyleSheet("image: url(:/tu/square.png);");
        break;
    }
    case 2:
    {
        ui->label_picture_1->setVisible(false);
        ui->label_picture_2->setVisible(true);
        ui->label_picture_3->setVisible(false);
        ui->label_picture_4->setVisible(false);
        ui->label_picture_5->setVisible(false);
        ui->label_b->setStyleSheet("image: url(:/tu/circle.png);");
        break;
    }
    case 3:
    {
        ui->label_picture_1->setVisible(false);
        ui->label_picture_2->setVisible(false);
        ui->label_picture_3->setVisible(true);
        ui->label_picture_4->setVisible(false);
        ui->label_picture_5->setVisible(false);
        ui->label_b->setStyleSheet("image: url(:/tu/octagon.png);");
        break;
    }
    case 4:
    {
        ui->label_picture_1->setVisible(false);
        ui->label_picture_2->setVisible(false);
        ui->label_picture_3->setVisible(false);
        ui->label_picture_4->setVisible(true);
        ui->label_picture_5->setVisible(false);
        ui->label_b->setStyleSheet("image: url(:/tu/oval.png);");
        break;
    }
    case 5:
    {
        ui->label_picture_1->setVisible(false);
        ui->label_picture_2->setVisible(false);
        ui->label_picture_3->setVisible(false);
        ui->label_picture_4->setVisible(false);
        ui->label_picture_5->setVisible(true);
        ui->label_b->setStyleSheet("image: url(:/tu/square.png);");
        break;
    }
    }
    ui->label_picture_mode->raise();
}

void control_interface::read_rotate()
{
    switch (rotate_flag) {
    case 1:
    {
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate0.png);");
        break;
    }
    case 2:
    {
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate1.png);");
        break;
    }
    case 3:
    {
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate2.png);");
        break;
    }
    case 4:
    {
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate3.png);");
        break;
    }
    case 5:
    {
        ui->label_rotate->setStyleSheet("background-image: url(:/tu/Rotate/rotate4.png);");
        break;
    }
    }
}

void control_interface::read_gpio_ae()
{
    switch (ae_flag) {
    case 1:
    {
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE1.png);");
        break;
    }
    case 2:
    {
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE2.png);");
        break;
    }
    case 3:
    {
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE3.png);");
        break;
    }
    case 4:
    {
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE4.png);");
        break;
    }
    case 5:
    {
        ui->label_ae->setStyleSheet("background-image: url(:/tu/AE/AE5.png);");
        break;
    }
    }
}

Label_screen_left::Label_screen_left(QWidget *parent): QLabel(parent)
{

}
void Label_screen_left::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_screen_right::Label_screen_right(QWidget *parent): QLabel(parent)
{

}
void Label_screen_right::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}


Label_picture_mode::Label_picture_mode(QWidget *parent): QLabel(parent)
{

}
void Label_picture_mode::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_display_mode::Label_display_mode(QWidget *parent): QLabel(parent)
{

}
void Label_display_mode::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_custom1::Label_custom1(QWidget *parent): QLabel(parent)
{

}
void Label_custom1::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_custom2::Label_custom2(QWidget *parent): QLabel(parent)
{

}
void Label_custom2::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_custom3::Label_custom3(QWidget *parent): QLabel(parent)
{

}
void Label_custom3::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}




Label_awb::Label_awb(QWidget *parent): QLabel(parent)
{

}
void Label_awb::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_freeze::Label_freeze(QWidget *parent): QLabel(parent)
{

}
void Label_freeze::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_store::Label_store(QWidget *parent): QLabel(parent)
{

}
void Label_store::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_rotate::Label_rotate(QWidget *parent): QLabel(parent)
{

}
void Label_rotate::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_photograph::Label_photograph(QWidget *parent): QLabel(parent)
{

}
void Label_photograph::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_videoint::Label_videoint(QWidget *parent): QLabel(parent)
{

}
void Label_videoint::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_ae::Label_ae(QWidget *parent): QLabel(parent)
{

}
void Label_ae::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_host_led::Label_host_led(QWidget *parent): QLabel(parent)
{

}
void Label_host_led::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_led::Label_led(QWidget *parent): QLabel(parent)
{

}
void Label_led::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_pump::Label_pump(QWidget *parent): QLabel(parent)
{

}
void Label_pump::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}
Label_interface::Label_interface(QWidget *parent): QLabel(parent)
{

}
void Label_interface::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
   QLabel::mousePressEvent(event);
}

Label_frames::Label_frames(QWidget *parent): QLabel(parent)
{
    doubleClickFlag = false;
    timre=new QTimer(this);
    connect(timre, &QTimer::timeout, this,[=](){
        emit clicked_1();
        doubleClickFlag = false;
        doubleClickTimer.invalidate();
        timre->stop();
    });
}
Label_frames::~Label_frames() {

}
void Label_frames::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (!doubleClickFlag)
        {
            doubleClickTimer.start();
            timre->start(400);
        }
        doubleClickFlag = true;
    }
}

void Label_frames::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (doubleClickTimer.elapsed() < 350)
        {
            doubleClickFlag = false;
            timre->stop();
            emit clicked_double();
        }
        doubleClickTimer.invalidate();
    }
}

void control_interface::on_browseReportBtn_clicked()
{
    if(!isChoosed){
        emit clicked_browseReport();
    }

    else{
        emit goEditReport(choosedOID.toInt());
    }
}

void control_interface::on_zoomBtn_clicked()
{
    set_zoomup();
}
