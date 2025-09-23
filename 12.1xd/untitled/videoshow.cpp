#include "videoshow.h"
#include "ui_videoshow.h"
#include "widget.h"

videoshow::videoshow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videoshow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->m_pLb_VideoPlayer_Play,SIGNAL(clicked()),this,SLOT(On_File_Clicked()));

    connect(ui->m_pBtn_Left,SIGNAL(clicked()),this,SLOT(On_Btn_Pre_Photo_Clicked()));
    connect(ui->m_pBtn_Right,SIGNAL(clicked()),this,SLOT(On_Btn_Next_Photo_Clicked()));

    connect(ui->m_pBtn_Del_File,SIGNAL(clicked()),this,SLOT(On_Btn_Del_File_Clicked()));
    connect(ui->m_pBtn_Return,SIGNAL(clicked()),this,SLOT(On_Btn_Return_Clicked()));



    //初始化
    m_iCurrIndex = 0;

    //检查文件并处理
    CheckFileAndDeal_F();
    //刷新文件并显示
    RefreshFileAndShow();


}



//检查文件并处理
qint8 videoshow::CheckFileAndDeal(QDir &Dir1,QDir &Dir2)
{
    int iCmp = 0;
    char cTemp[200];
    int Dir1Count = Dir1.count();
    int Dir2Count = Dir2.count();
    QString imagePath1;
    QString imagePath2;
    QString imagePathTemp1;
    QString imagePathTemp2;
    qint8 iRet = 0;
    int iLen1,iLen2;
    if (Dir2Count == 0)//Dir2没文件了，清空Dir1
    {
        sprintf(cTemp,"rm %s*;sync",PATH_VIDEO_SMALL);
        system(cTemp);

        iRet = 1;
    }
    else//Dir2还有文件，对比进行清除Dir1里多余的文件
    {
        for(int i=0,t=0;i<Dir1Count;)
        {
            if (t >= Dir2Count)//Dir2后面已经没文件了，把Dir1后面的文件都删除
            {
                imagePath1 = QString("%1").arg(Dir1[i]);
                std::string utf8Str = imagePath1.toUtf8().constData();
                const char* charData = utf8Str.c_str();

                sprintf(cTemp,"rm %s%s",PATH_VIDEO_SMALL,charData);
                system(cTemp);
                i++;
                iRet = 1;
            }
            else//Dir2后面还有文件，继续比较
            {
                imagePath1 = QString("%1").arg(Dir1[i]);
                imagePath2 = QString("%1").arg(Dir2[t]);
                iLen1 = imagePath1.length()-4;
                iLen2 = imagePath2.length()-4;
                imagePathTemp1 = imagePath1.left(iLen1);
                imagePathTemp2 = imagePath2.left(iLen2);
                if (imagePathTemp1 < imagePathTemp2)//小于
                {
                    std::string utf8Str = imagePath1.toUtf8().constData();
                    const char* charData = utf8Str.c_str();

                    sprintf(cTemp,"rm %s%s",PATH_VIDEO_SMALL,charData);
                    system(cTemp);
                    i++;
                    iRet = 1;
                }
                else if (imagePathTemp1 == imagePathTemp2)//等于
                {
                    i++;
                    t++;
                }
                else if (imagePathTemp1 > imagePathTemp2)//大于
                {
                    t++;
                }
            }
        }
        if (iRet == 1)
            system("sync");
    }
    return iRet;
}

bool videoshow::isValid() const
{
    if (m_isDestroying) {  // 优先检查：对象正在析构
        return false;
    }
    if (ui == nullptr) {   // 次要检查：UI 已释放（冗余但保险）
        return false;
    }
    if (!m_VideoDir.exists()) {  // 目录合法性检查
        return false;
    }
    return true;
}









//检查文件并处理
void videoshow::CheckFileAndDeal_F()
{
    QDir dir(PATH_VIDEO_SMALL);
    QStringList filters;
    filters<<"*.jpg";  // 设置哪些格式图片的可以显示
    dir.setNameFilters(filters);

    QDir dir2(PATH_VIDEO);
    QStringList filters2;
    filters2<<"*.mp4";  // 设置哪些格式图片的可以显示
    dir2.setNameFilters(filters2);

    int iRet = CheckFileAndDeal(dir,dir2);

    if (iRet == 1)//有删除文件，则刷新
        dir.setNameFilters(filters);//刷新
}

//刷新文件信息
void videoshow::RefreshFileMsg()
{
    char cTemp[100];
    int iCount = m_VideoDir.count();

    //刷新文件索引以及总数
    if (iCount > 0)
        sprintf(cTemp,"%d/%d",m_iCurrIndex+1,iCount);
    else
        sprintf(cTemp,"%d/%d",0,0);
    ui->m_pLb_FileIndTotal->setText(cTemp);
    ui->m_pLb_FileIndTotal->show();

    //刷新文件名字
    if (iCount > 0)
    {
        ui->m_pLb_FileName->setText(QString("%1").arg(m_VideoDir[m_iCurrIndex]));
        ui->m_pLb_FileName->show();
    }
    else
    {
        ui->m_pLb_FileName->setText("");
        ui->m_pLb_FileName->show();
    }
}

//刷新文件并显示
void videoshow::RefreshFileAndShow()
{

    m_VideoDir.setPath(PATH_VIDEO_SMALL);
    qDebug() << "视频缩略图目录：" << m_VideoDir.path() << "，文件数量：" << m_VideoDir.count();
    QStringList filters;
    filters<<"*.jpg";  // 设置哪些格式图片的可以显示
    m_VideoDir.setNameFilters(filters);
    if (m_VideoDir.count() >= (m_iCurrIndex+1))
    {
        QImage mImage;

        //mImage.load(PATH_VIDEO_SMALL+QString("%1").arg(m_VideoDir[m_iCurrIndex]));
        QString fileName = m_VideoDir[m_iCurrIndex];
        QString filePath = m_VideoDir.filePath(fileName); // 使用QDir的方法拼接路径，自动处理分隔符
        if (!mImage.load(filePath)) {
            qDebug() << "缩略图加载失败，路径：" << filePath;
        }
        ui->m_pLb_VideoPlayer->setScaledContents(true);
        ui->m_pLb_VideoPlayer->setPixmap(QPixmap::fromImage(mImage));
        ui->m_pLb_VideoPlayer->show();
    }
    else
    {
        ui->m_pLb_VideoPlayer->hide();
    }

    RefreshFileMsg();
}

//上一张图片
void videoshow::On_Btn_Pre_Photo_Clicked()
{
    QImage mImage;

    if (m_iCurrIndex == 0)
        return;
    if (m_VideoDir.count() >= (m_iCurrIndex+1-1))
    {
        mImage.load(PATH_VIDEO_SMALL+QString("%1").arg(m_VideoDir[m_iCurrIndex-1]));
        ui->m_pLb_VideoPlayer->setScaledContents(true);
        ui->m_pLb_VideoPlayer->setPixmap(QPixmap::fromImage(mImage));
        ui->m_pLb_VideoPlayer->show();
        m_iCurrIndex--;
    }

    RefreshFileMsg();
}

//下一张图片
void videoshow::On_Btn_Next_Photo_Clicked()
{
    QImage mImage;

    if ((m_iCurrIndex + 1) >= m_VideoDir.count())
        return;
    if (m_VideoDir.count() >= (m_iCurrIndex+1+1))
    {
        mImage.load(PATH_VIDEO_SMALL+QString("%1").arg(m_VideoDir[m_iCurrIndex+1]));
        ui->m_pLb_VideoPlayer->setScaledContents(true);
        ui->m_pLb_VideoPlayer->setPixmap(QPixmap::fromImage(mImage));
        ui->m_pLb_VideoPlayer->show();
        m_iCurrIndex++;
    }

    RefreshFileMsg();
}

//点击文件

void videoshow::On_File_Clicked()
{
    if (m_VideoDir.count() == 0 || m_iCurrIndex < 0 || m_iCurrIndex >= m_VideoDir.count()) {
        qDebug() << "无效的文件索引";
        return;
    }

    // 1. 获取缩略图文件名
    QString fileName = m_VideoDir[m_iCurrIndex];

    QString baseName = fileName.left(fileName.length() - 4);
    QString videoName = baseName + ".mp4";

    // 3. 强制使用QDir拼接
    QDir videoDir(PATH_VIDEO);
    QString videoPath = videoDir.filePath(videoName);

    // 4. 验证路径并输出日志
    qDebug() << "生成的视频路径：" << videoPath;
    if (QFile::exists(videoPath)) {
        // 5. 确保字符串终止符，避免溢出
        strncpy(g_c_FilePath, videoPath.toUtf8().constData(), sizeof(g_c_FilePath) - 1);
        g_c_FilePath[sizeof(g_c_FilePath) - 1] = '\0';
        emit sigShowVideoPlayer();
    } else {
        qDebug() << "视频文件不存在！路径：" << videoPath;
    }
}

//删除文件
void videoshow::DelFile()
{
    int iCount = m_VideoDir.count();
    if (iCount == 0)
        return;

    std::string utf8Str = QString("%1").arg(m_VideoDir[m_iCurrIndex]).toUtf8().constData();
    const char* charData = utf8Str.c_str();
    char cTemp[300];

    sprintf(cTemp,"rm %s%s",PATH_VIDEO_SMALL,charData);
    system(cTemp);
    system("sync");

    if ((m_iCurrIndex+1) >= iCount)
    {
        if (m_iCurrIndex > 0)
            m_iCurrIndex--;
    }

    //刷新文件并显示
    RefreshFileAndShow();
}

//删除文件确认
void videoshow::On_Btn_Del_File_Clicked()
{

    int iCount = m_VideoDir.count();
    if (iCount == 0)
        return;

    char cLngTextStr[100];
    strcpy(cLngTextStr,"确定删除该视频吗?");
    QMessageBox messageBox(QMessageBox::NoIcon,"",cLngTextStr, QMessageBox::Yes|QMessageBox::No, NULL);

    int iResult = messageBox.exec();
        switch (iResult) {
        case QMessageBox::Yes:
            DelFile();
            break;
        case QMessageBox::No:
            break;
        default:
            break;
    }
}

//返回
void videoshow::On_Btn_Return_Clicked()
{

    emit sigReturnTowidget();
}




videoshow::~videoshow()
{
    m_isDestroying = true;  // 析构开始时标记

    delete ui;
}
