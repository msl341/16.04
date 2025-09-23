#include "zhukuang.h"
#include "ui_zhukuang.h"
#include "widget.h"
zhukuang* zhukuang::myzhukuang = nullptr;  // 全局定义静态指针
zhukuang::zhukuang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhukuang),
    m_isGnjSelected(true),  // 初始选中gnj
    m_isSzSelected(false)   // 初始未选中sz
{
    ui->setupUi(this);
    myzhukuang = this;
    San_ReadConfig(&g_S_CfgData);  // 读取保存的配置（包括语言设置）
    // 新增：初始化时调用SetLanguageText，根据读取的语言配置更新文字
    SetLanguageText();  // 关键：启动时立即更新label_6和label_7
    San_ReadConfig(&g_S_CfgData);
    m_i_BrightVal_1 = 8;
    m_i_BrightVal_2 = 14;
    m_i_BrightVal_3 = 20;
    m_i_DrawShapeOpenFlag = 0;
    m_i_BrightVal = m_i_BrightVal_1;
    m_iSel_Btn = -1;
    ui->prompt_photo->setVisible(false);
    // 连接点击信号
    connect(ui->gnj, &Gnj::clicked_1, this, &zhukuang::onGnjClicked);
    connect(ui->sz, &SZ::clicked_1, this, &zhukuang::onSzClicked);
    // 手动触发初始状态：显示page，更新样式
    updateGnjStyle(true);  // gnj初始为选中样式
    updateSzStyle(false);  // sz初始为未选中样式
    ui->third_stack->setCurrentWidget(ui->page);  // 初始显示page（绑定gnj）

    // 连接点击信号到拍照功能
    // zhukuang.cpp 中连接按钮点击事件
    connect(ui->label_photograph, &QPushButton::clicked, this, [this]() {

        ui->prompt_photo->setVisible(true);
        Widget::mywidget->On_Btn_TakePhoto_Clicked();
    });

    connect(ui->seek_photo, &QPushButton::clicked, this, &zhukuang::seekPhotoClicked);
    connect(ui->seek_video, &QPushButton::clicked, this, &zhukuang::seekVideoClicked);
    connect(ui->m_pBtn_DateSet, &QPushButton::clicked, this, &zhukuang::settimeClicked);
    connect(ui->m_pBtn_LanSet, &QPushButton::clicked, this, &zhukuang::setlansetClicked);

    connect(ui->m_pBtn_Format, &QPushButton::clicked, this, &zhukuang::formatClicked);
    connect(ui->m_pBtn_Reset, &QPushButton::clicked, this, &zhukuang::resetClicked);
    connect(ui->m_pBtn_Upgrade, &QPushButton::clicked, this, &zhukuang::aboutClicked);



    connect(ui->m_pBtn_Awb,&QPushButton::clicked,this,&zhukuang::On_Btn_Awb_Clicked);
    connect(ui->m_pBtn_Freeze,&QPushButton::clicked,this,&zhukuang::On_Btn_Negative_Clicked);
    connect(ui->m_pBtn_AE,&QPushButton::clicked,this,&zhukuang::On_Btn_Ae_Clicked);
    connect(ui->m_pBtn_Rot,&QPushButton::clicked,this,&zhukuang::On_Btn_Rot_Clicked);
    connect(ui->m_pBtn_DrawShape,&QPushButton::clicked,this,&zhukuang::On_Btn_DrawShape_Clicked);
    connect(ui->m_pBtn_DrawShape_FX,&QPushButton::clicked,this,&zhukuang::On_Btn_DrawShapeFx_Clicked);
    connect(ui->m_pBtn_DrawShape_YX,&QPushButton::clicked,this,&zhukuang::On_Btn_DrawShapeYx_Clicked);
    connect(ui->m_pBtn_DrawShape_BJX,&QPushButton::clicked,this,&zhukuang::On_Btn_DrawShapeBjx_Clicked);


    // 连接视频按钮点击信号到Widget的处理函数
    connect(ui->label_video, &QPushButton::clicked, Widget::mywidget, &Widget::On_Btn_RecordVideo_Clicked);
    // 初始隐藏时间标签
    ui->video_time->setVisible(false);
    ui->m_pWdg_Panel_DrawShape->hide();

    connect(this, &zhukuang::sigSetLabel18Visible, ui->label_18, &QLabel::setVisible, Qt::QueuedConnection); // 跨线程必须用队列连接


}

zhukuang::~zhukuang()
{
    delete ui;
}
void zhukuang::SetLanguageText() {
    ui->label_4->setWordWrap(true);
    ui->label_5->setWordWrap(true);
    ui->label_12->setWordWrap(true);

    ui->label_8->setWordWrap(true);
    ui->label_9->setWordWrap(true);
    ui->label_13->setWordWrap(true);
    ui->label_14->setWordWrap(true);
    ui->label_15->setWordWrap(true);
    //ui->label_16->setWordWrap(true);
    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH) {

        ui->label_4->setText("图片查看");
        ui->label_5->setText("视频查看");
        ui->label_12->setText("时间设置");
        ui->label_13->setText("语言设置");
        ui->label_14->setText("格式化");
        ui->label_15->setText("重置设置");
        ui->label_16->setText("版本信息");
        ui->label_19->setText("保存图片");
        ui->label_20->setText("保存视频");

        ui->label_6->setText("白平衡");
        ui->label_7->setText("冻结画面");
        ui->label_8->setText("AE");
        ui->label_9->setText("画面旋转");
        ui->label_10->setText("图像窗口形状");


    } else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH) {
        ui->label_4->setText("圖片查看");
        ui->label_5->setText("視頻查看");
        ui->label_12->setText("時間設置");
        ui->label_13->setText("語言設置");
        ui->label_14->setText("格式化");
        ui->label_15->setText("重設設定");
        ui->label_16->setText("版本資訊");
        ui->label_19->setText("保存圖片");
        ui->label_20->setText("保存視頻");

        ui->label_6->setText("白平衡");
        ui->label_7->setText("凍結畫面");
        ui->label_8->setText("AE");
        ui->label_9->setText("畫面旋轉");
        ui->label_10->setText("圖像視窗形狀");

    } else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH) {
        ui->label_4->setText("Image Viewing");
        ui->label_5->setText("Video Viewing");
        ui->label_12->setText("Time Settings");
        ui->label_13->setText("Language Settings");
        ui->label_14->setText("Format");
        ui->label_15->setText("Reset Settings");
        ui->label_16->setText("Version Information");
        ui->label_19->setText("Save Image");
        ui->label_20->setText("Save Video");

        ui->label_6->setText("White Balance");
        ui->label_7->setText("Freeze Frame");
        ui->label_8->setText("AE");
        ui->label_9->setText("Screen Rotation");
        ui->label_10->setText("Image Window Shape");

    } else if (g_S_CfgData.iLanSetLan == LAN_FRENCH) {
        ui->label_4->setText("Visualisation d'images");
        ui->label_5->setText("Visualisation de vidéos");
        ui->label_12->setText("Réglages de l'heure");
        ui->label_13->setText("Paramètres de langue");
        ui->label_14->setText("Formater");
        ui->label_15->setText("Réinitialiser les paramètres");
        ui->label_16->setText("Informations de version");
        ui->label_19->setText("Enregistrer l'image");
        ui->label_20->setText("Enregistrer la vidéo");

        ui->label_6->setText("Balance Blanche");
        ui->label_7->setText("Image Gelée");
        ui->label_8->setText("AE");
        ui->label_9->setText("Rotation de l'écran");
        ui->label_10->setText("Forme de la fenêtre d'image");

    } else if (g_S_CfgData.iLanSetLan == LAN_GERMAN) {
        ui->label_4->setText("Bildansicht");
        ui->label_5->setText("Videansicht");
        ui->label_12->setText("Zeiteinstellungen");
        ui->label_13->setText("Spracheinstellungen");
        ui->label_14->setText("Formatieren");
        ui->label_15->setText("Einstellungen zurücksetzen");
        ui->label_16->setText("Versionsinformationen");
        ui->label_19->setText("Bild speichern");
        ui->label_20->setText("Video speichern");
        ui->label_6->setText("Weißabgleich");
        ui->label_7->setText("Gefrorener Frame");
        ui->label_8->setText("AE");
        ui->label_9->setText("Rotation des Bildschirms");
        ui->label_10->setText("Form des Bildfensters");

    }
}

//鼠标按下
void zhukuang::mousePressEvent(QMouseEvent *event)
{
    DrawShapeClose();//画图形状面板关闭

}


//画图形状面板关闭
void zhukuang::DrawShapeClose()
{
    if (m_i_DrawShapeOpenFlag == 1)//已经打开
    {
        ui->m_pWdg_Panel_DrawShape->hide();
        m_i_DrawShapeOpenFlag = 0;
    }
}

//画图形状面板开关
void zhukuang::DrawShapeOpenClose()
{
    if (m_i_DrawShapeOpenFlag == 0)//未打开
    {

        ui->m_pWdg_Panel_DrawShape->show();
        m_i_DrawShapeOpenFlag = 1;
    }
    else//已经打开
    {
        ui->m_pWdg_Panel_DrawShape->hide();
        m_i_DrawShapeOpenFlag = 0;



    }
}

//画图形状
void zhukuang::On_Btn_DrawShape_Clicked()
{
    m_iSel_Btn = 2;

    DrawShapeOpenClose();
    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
        ui->m_pLb_DrawShape_Title->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_title.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
        ui->m_pLb_DrawShape_Title->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_title_ft.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
        ui->m_pLb_DrawShape_Title->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_title_en.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
        ui->m_pLb_DrawShape_Title->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_title_fr.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
        ui->m_pLb_DrawShape_Title->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_title_gm.png);");
}

//方形
void zhukuang::On_Btn_DrawShapeFx_Clicked()
{

    ui->label->setStyleSheet("border-image: url(:/tu/Res/Set/1-drawshape_fx_bg.png);");

    ui->m_pBtn_DrawShape_FX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_fx_sel.png);");
    ui->m_pBtn_DrawShape_YX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_yx.png);");
    ui->m_pBtn_DrawShape_BJX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_bjx.png);");


    g_S_CfgData.iDrawShape = DS_FX;
    San_WriteConfig(&g_S_CfgData);
}

//圆形
void zhukuang::On_Btn_DrawShapeYx_Clicked()
{
    ui->label->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_yx_bg.png);");

    ui->m_pBtn_DrawShape_FX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_fx.png);");
    ui->m_pBtn_DrawShape_YX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_yx_sel.png);");
    ui->m_pBtn_DrawShape_BJX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_bjx.png);");

    g_S_CfgData.iDrawShape = DS_YX;
    San_WriteConfig(&g_S_CfgData);
}

//八角形
void zhukuang::On_Btn_DrawShapeBjx_Clicked()
{
    ui->label->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_bjx_bg.png);");

    ui->m_pBtn_DrawShape_FX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_fx.png);");
    ui->m_pBtn_DrawShape_YX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_yx.png);");
    ui->m_pBtn_DrawShape_BJX->setStyleSheet("border-image: url(:/tu/Res/Set/drawshape_bjx_sel.png);");

    g_S_CfgData.iDrawShape = DS_BJX;
    San_WriteConfig(&g_S_CfgData);
}










//翻转
void zhukuang::On_Btn_Rot_Clicked()
{
    if (Widget::mywidget->m_i_Recording == 1)
        Widget::mywidget->On_Btn_RecordVideo_Stop_Clicked();//录像停止
    Rot_Deal(1);
    DrawShapeClose();//画图形状面板关闭

}

//翻转处理
void zhukuang::Rot_Deal(int iFlag)
{
    if (g_S_CfgData.iRot == 3)
    {
        g_S_CfgData.iRot = 0;
        g_i_Rotate_Flag = 0;
    }
    else
    {
        g_S_CfgData.iRot++;
        g_i_Rotate_Flag = 1;
    }

    if (g_S_CfgData.iRot == 0)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot.png);");

    }
    else if (g_S_CfgData.iRot == 1)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot_up_left.png);");

    }
    else if (g_S_CfgData.iRot == 2)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot_down_right.png);");

    }
    else if (g_S_CfgData.iRot == 3)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot_down_left.png);");

    }

    if (iFlag == 1)
        SendMsgToUvc("Rot",CMD_SET_ROTATE,g_S_CfgData.iRot,"");

    //    San_WriteConfig(&g_S_CfgData);
}




//翻转0度处理
void zhukuang::Rot_0_Deal(int iFlag)
{
    g_S_CfgData.iRot = 0;
    g_i_Rotate_Flag = 0;

    if (g_S_CfgData.iRot == 0)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot.png);");

    }
    else if (g_S_CfgData.iRot == 1)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot_up_left.png);");

    }
    else if (g_S_CfgData.iRot == 2)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot_down_right.png);");

    }
    else if (g_S_CfgData.iRot == 3)
    {
        ui->m_pBtn_Rot->setStyleSheet("border-image: url(:/tu/Res/MainWindow/rot_down_left.png);");

    }

    if (iFlag == 1)
        SendMsgToUvc("Rot",CMD_SET_ROTATE,g_S_CfgData.iRot,"");

    //    San_WriteConfig(&g_S_CfgData);
}

//曝光
void zhukuang::On_Btn_Ae_Clicked()
{
    DrawShapeClose();//画图形状面板关闭

    int iVal = 10;
    if (g_S_CfgData.iAe == 3)
        g_S_CfgData.iAe = 1;
    else
        g_S_CfgData.iAe++;

    int currentAe = g_S_CfgData.iAe;
    QString styleSheet = QString(R"(
                                 QPushButton {
                                 border-image: url(:/tu/Res/MainWindow/ae-%1.png); /* 常态图标：ae-1/2/3.png */
                                 }
                                 QPushButton:pressed {
                                 border-image: url(:/tu/Res/MainWindow/ae-0.png); /* 按下图标：固定 ae-0.png */
                                 }
                                 QPushButton {
                                 border: none; background: transparent; /* 透明背景，去除边框 */
                                 }
                                 )").arg(currentAe);  // 替换 %1 为 currentAe 的值（1、2、3）

    ui->m_pBtn_AE->setStyleSheet(styleSheet);
    if (g_S_CfgData.iAe == 1)
    {

        iVal = m_i_BrightVal_1;
        m_i_BrightVal = m_i_BrightVal_1;
    }
    else if (g_S_CfgData.iAe == 2)
    {

        iVal = m_i_BrightVal_2;
        m_i_BrightVal = m_i_BrightVal_2;
    }
    else if (g_S_CfgData.iAe == 3)
    {

        iVal = m_i_BrightVal_3;
        m_i_BrightVal = m_i_BrightVal_3;
    }


    SendMsgToUvc("SetBrightness",CMD_SET_BRIGHTNESS,iVal,"");

}

void zhukuang::setDateLabelText(const QString &text)
{
    ui->m_pLb_Date->setText(text);
    ui->m_pLb_Date->show();

}

//白平衡
void zhukuang::On_Btn_Awb_Clicked()
{
    DrawShapeClose();//画图形状面板关闭

    SendMsgToUvc("Awb",CMD_SET_AWB,0,"");
}


//冻结
void zhukuang::On_Btn_Negative_Clicked()
{
    DrawShapeClose();//画图形状面板关闭


    SendMsgToUvc("Freeze",CMD_SET_FREEZE,1,"");
}


// 控制视频时间标签显示/隐藏
void zhukuang::showVideoTime(bool show) {
    ui->video_time->setVisible(show);
}

// 更新视频时间标签文本
void zhukuang::updateVideoTimeText(const QString &text) {
    ui->video_time->setText(text);
}
void zhukuang::hidePromptPhoto() {
    ui->prompt_photo->setVisible(false); // 此处可正常访问 ui
}
void zhukuang::showPromptPhoto() {

    ui->prompt_photo->setVisible(true);
    ui->prompt_photo->raise();  // 置于顶层

}
// gnj点击处理
void zhukuang::onGnjClicked()
{
    DrawShapeClose();//画图形状面板关闭

    if (!m_isGnjSelected)  // 仅当未选中时才更新
    {
        m_isGnjSelected = true;
        m_isSzSelected = false;

        updateGnjStyle(true);
        updateSzStyle(false);
        ui->third_stack->setCurrentWidget(ui->page);  // 切换到page
    }
}

// sz点击处理：无论当前状态，点击后选中sz、显示page_2
void zhukuang::onSzClicked()
{
    DrawShapeClose();//画图形状面板关闭

    if (!m_isSzSelected)  // 仅当未选中时才更新
    {
        m_isSzSelected = true;
        m_isGnjSelected = false;

        updateSzStyle(true);
        updateGnjStyle(false);
        ui->third_stack->setCurrentWidget(ui->page_2);  // 切换到page_2
    }
}
void zhukuang::updateGnjStyle(bool selected)
{
    if (selected) {
        // 选中态
        ui->gnj->setStyleSheet("border-image: url(:/tu/Res/gnj.png);");

    } else {
        // 未选中态
        ui->gnj->setStyleSheet("border-image: url(:/tu/Res/gnj-1.png);");

    }
}

void zhukuang::updateSzStyle(bool selected)
{
    if (selected) {
        ui->sz->setStyleSheet("border-image: url(:/tu/Res/sz.png);");

    } else {
        ui->sz->setStyleSheet("border-image: url(:/tu/Res/sz-1.png);");

    }
}



Gnj::Gnj(QWidget *parent)
    : QLabel(parent)
{

}

void Gnj::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
    QLabel::mousePressEvent(event);
}
SZ::SZ(QWidget *parent)
    : QLabel(parent)
{

}

void SZ::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked_1();
    }
    QLabel::mousePressEvent(event);
}

