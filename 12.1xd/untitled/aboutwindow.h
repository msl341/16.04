#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include "mykey.h"
namespace Ui {
class aboutwindow;
}

class aboutwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit aboutwindow(QWidget *parent = nullptr);
    ~aboutwindow();

private:
    Ui::aboutwindow *ui;
public:
    int m_iEvent;
    int m_i_SliderValue;
    void timerEvent(QTimerEvent* ev);

signals:
    void sigReturnTowidget();


private slots:
    //确认
    void On_Btn_Confirm_Clicked();
    //取消
    void On_Btn_Cancel_Clicked();


};









#endif // ABOUTWINDOW_H
