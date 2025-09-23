#ifndef ZHUKUANG_H
#define ZHUKUANG_H
#include <QWidget>
#include "mykey.h"
#include <QTouchEvent>

namespace Ui {
class zhukuang;
}

class zhukuang : public QWidget
{
    Q_OBJECT

public:
    explicit zhukuang(QWidget *parent = nullptr);
    ~zhukuang();
public:
    void SetLanguageText();
    void setDateLabelText(const QString &text);
    void hidePromptPhoto();
    //画图形状面板关闭
    void DrawShapeClose();
    //画图形状面板开关
    void DrawShapeOpenClose();
    void showPromptPhoto();

static zhukuang* myzhukuang;  // 声明静态指针
    qint16 m_i_BrightVal;
    qint16 m_i_BrightVal_1;
    qint16 m_i_BrightVal_2;
    qint16 m_i_BrightVal_3;
    qint8 m_i_DrawShapeOpenFlag;
    int m_iSel_Btn;
    //翻转处理
    void Rot_Deal(int iFlag);
    //翻转0度处理
    void Rot_0_Deal(int iFlag);
private slots:
    void onGnjClicked();   // gnj点击处理
    void onSzClicked();    // sz点击处理
    //白平衡
    void On_Btn_Awb_Clicked();
    //冻结
    void On_Btn_Negative_Clicked();
    //曝光
    void On_Btn_Ae_Clicked();
    //翻转
    void On_Btn_Rot_Clicked();
    //画图形状
    void On_Btn_DrawShape_Clicked();
    //方形
    void On_Btn_DrawShapeFx_Clicked();
    //圆形
    void On_Btn_DrawShapeYx_Clicked();
    //八角形
    void On_Btn_DrawShapeBjx_Clicked();
private:
    Ui::zhukuang *ui;
    bool m_isGnjSelected;  // gnj是否选中（初始为true）
    bool m_isSzSelected;   // sz是否选中（初始为false）
    void updateGnjStyle(bool selected);  // 更新gnj样式
    void updateSzStyle(bool selected);   // 更新sz样式
signals:
    void seekPhotoClicked();
    void seekVideoClicked();
    void settimeClicked();
    void setlansetClicked();
    void formatClicked();
    void resetClicked();
    void aboutClicked();
    void sigSetLabel18Visible(bool visible);
protected:
    void mousePressEvent(QMouseEvent *event) override;
public slots:
    void showVideoTime(bool show); // 显示/隐藏时间标签
    void updateVideoTimeText(const QString &text); // 更新时间文本

};
class Gnj : public QLabel
{
    Q_OBJECT
public:
    explicit Gnj(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};

class SZ : public QLabel
{
    Q_OBJECT
public:
    explicit SZ(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};





#endif // ZHUKUANG_H
