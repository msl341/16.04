#ifndef BROWSEREPORT_H
#define BROWSEREPORT_H

#include <QWidget>
#include <QListWidgetItem>

#include "mykey.h"
#include "ListReportItem.h"
#include "ComfirmDelete.h"

namespace Ui {
class BrowseReport;
}

class BrowseReport : public QWidget
{
    Q_OBJECT

public:
    explicit BrowseReport(QWidget *parent = nullptr);
    ~BrowseReport();

    void showErrorConnect();
    void successConnect();
    void updateReport(int obj_id);
    void addNewReport();
    void chooseReport();
    void resetAfterChoose();
    void refreshUI();
    void clearAllFocus();
    void setFocus(QPoint pos);
    void deleteBtnClicked(ListReportItem *rItem);

    ListReportItem *rItem;

signals:
    void back();
    void showKeyBoard();
    void showFullKeyboard();
    void backControlInterface();
    void showComfirm();
    void backZhukuang();
    void fullBtnClicked(int pid, int where = 1);
    void addReportClicked();
    void chooseBtnClicked(QString patient_id, QString obj_id, QString patientName);

private slots:

    void on_backBtn_clicked();

    void on_addReportBtn_clicked();

    void on_searchBtn_clicked();

    void on_searchInput_textChanged(const QString &arg1);

    void on_backBtn_noDatabase_clicked();

private:
    Ui::BrowseReport *ui;

    int StartX = 0, StartY = 0, index = 0;
    int curFull = -1;
    QList<QGraphicsProxyWidget *> proxyWidgetList;
    QList<int> selectToRemove;
    QList<ListReportItem *> reportItemList;

    bool chooseStatus = false;
};

#endif // BROWSEREPORT_H
