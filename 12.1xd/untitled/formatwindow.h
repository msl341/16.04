#ifndef FORMATWINDOW_H
#define FORMATWINDOW_H

#include "mykey.h"
namespace Ui {
class formatwindow;
}

class formatwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit formatwindow(QWidget *parent = nullptr);
    ~formatwindow();

private:
    Ui::formatwindow *ui;
public:


signals:
    void sigReturnTowidget();


private slots:
    //确认
    void On_Btn_Confirm_Clicked();
    //取消
    void On_Btn_Cancel_Clicked();


};









#endif // FORMATWINDOW_H
