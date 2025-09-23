#ifndef VIDEOSHOW_H
#define VIDEOSHOW_H

#include "mykey.h"
#include "videoshow_sel.h"


namespace Ui {
class videoshow;
}

class videoshow : public QMainWindow
{
    Q_OBJECT

public:
    explicit videoshow(QWidget *parent = nullptr);
    ~videoshow();
public:

    QDir m_VideoDir;
    int m_iCurrIndex;
    bool isValid() const;  // const 修饰，确保只读
public:
    //检查文件并处理
    qint8 CheckFileAndDeal(QDir &Dir1,QDir &Dir2);
    //检查文件并处理
    void CheckFileAndDeal_F();
    //刷新文件信息
    void RefreshFileMsg();
    //刷新文件并显示
    void RefreshFileAndShow();
    //删除文件
    void DelFile();
private slots:
    //上一张图片
    void On_Btn_Pre_Photo_Clicked();
    //下一张图片
    void On_Btn_Next_Photo_Clicked();
    //点击文件
    void On_File_Clicked();
    //删除文件确认
    void On_Btn_Del_File_Clicked();
    //返回
    void On_Btn_Return_Clicked();


//    void onShowVideoPlayer();
//       // 新增：视频播放器关闭回调
//    void onVideoPlayerClosed();
signals:
    void sigReturnTowidget();

    void sigShowVideoPlayer();
//public:
//    videoshow_sel *m_pWin_Video_Player_Play;
private:

bool m_isDestroying = false;  // 新增：析构标记
private:
    Ui::videoshow *ui;


};














#endif // VIDEOSHOW_H
