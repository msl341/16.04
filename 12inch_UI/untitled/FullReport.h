#ifndef FULLREPORT_H
#define FULLREPORT_H

#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QScrollBar>

#include "mykey.h"
#include "PickPhotoItem.h"

namespace Ui {
class FullReport;
}

class FullReport : public QWidget
{
    Q_OBJECT

public:
    explicit FullReport(QWidget *parent = nullptr);
    ~FullReport();

    void setFrom(int where);
    void previewReport(int where, int patient_id, int age, QList<QString> photoPaths, QList<QString> others);
    void viewFullReport(int where, int obj_id);
    void updateReport(int obj_id);
    void restoreReport();
    void refreshUI();
    void hideEdit();

signals:
    void back(int where);
    void edit(int obj_id);

private slots:
    void on_backBtn_clicked();

    void on_editBtn_clicked();

private:
    Ui::FullReport *ui;

    QGraphicsScene *scene;

    int from = -1; // 0:addReport 1:browseReport
    int OID = 0;
    int StartX = 150, StartY = 230;
};

#endif // FULLREPORT_H
