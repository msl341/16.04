#ifndef COMFIRMDELETE_H
#define COMFIRMDELETE_H

#include <QWidget>

namespace Ui {
class ComfirmDelete;
}

class ComfirmDelete : public QWidget
{
    Q_OBJECT

public:
    explicit ComfirmDelete(QWidget *parent = nullptr);
    ~ComfirmDelete();

    void refreshUI();

signals:
    void deleteBtnClicked();
    void cancelBtnClicked();
    void back();

private slots:
    void on_deleteBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ComfirmDelete *ui;
};

#endif // COMFIRMDELETE_H
