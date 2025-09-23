#ifndef LISTREPORTITEM_H
#define LISTREPORTITEM_H

#include <QWidget>

namespace Ui {
class ListReportItem;
}

class ListReportItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListReportItem(QWidget *parent = nullptr, bool chooseStatus = false);
    ~ListReportItem();

    void itemSetName(QString name);
    void itemSetAge(int age);
    void itemSetEmptyAge();
    void itemSetGender(QString gender);
    void itemSetDate(QString date);
    void itemSetIndex(int idx);
    void itemSetChooseBtnVisible(bool status);
    void itemSetDeleteBtnVisible(bool status);
    void itemSetFullBtnVisible(bool status);
    void itemSetOID(int oid);

    int itemGetOID();
    bool itemGetChooseBtnVisible();

    void refreshUI();

signals:
    void click_delete();
    void click_full();
    void click_choose();

private slots:
    void on_deleteBtn_clicked();

    void on_fullBtn_clicked();

    void on_chooseBtn_clicked();

private:
    Ui::ListReportItem *ui;

    int index, OID;
};

#endif // LISTREPORTITEM_H
