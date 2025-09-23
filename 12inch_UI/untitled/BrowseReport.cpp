#include "BrowseReport.h"
#include "ui_BrowseReport.h"

BrowseReport::BrowseReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrowseReport)
{
    ui->setupUi(this);

    connect(ui->searchInput, &showKeyBoardLineEdit::showKeyBoard, this, [=]{
        emit showKeyBoard();
    });

    connect(ui->searchInput, &showKeyBoardLineEdit::showFullKeyBoard, this, [=]{
        emit showFullKeyboard();
    });

//    QScroller::grabGesture(ui->listWidget->viewport(), QScroller::LeftMouseButtonGesture);
}

BrowseReport::~BrowseReport()
{
    delete ui;
}

void BrowseReport::showErrorConnect()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void BrowseReport::successConnect()
{
    ui->stackedWidget->setCurrentIndex(0);
    int listWidgetCount = ui->listWidget->count();
    if(listWidgetCount > 0){
        for(int i = 0; i < listWidgetCount; i++){
            QListWidgetItem* itemDelete = ui->listWidget->takeItem(0);
            delete itemDelete;
        }
    }
    QSqlQuery query(QSqlDatabase::database());
    QString searchQuery = "SELECT name, age, gender, date, OID, patient_id FROM report";
    if(!query.exec(searchQuery)){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        while(query.next()){
//            qDebug() << query.value(0).toString() << query.value(1).toInt()
//                     << query.value(2).toString() << query.value(3).toString()
//                     << query.value(4).toInt() << query.value(5).toInt();
            int obj_id = query.value(4).toInt();
            int patient_id = query.value(5).toInt();
            QString patient_name = query.value(0).toString();

            ListReportItem *reportItem = new ListReportItem(ui->listWidget);
            reportItem->itemSetName(query.value(0).toString());
            reportItem->itemSetAge(query.value(1).toInt());
            reportItem->itemSetGender(query.value(2).toString());
            reportItem->itemSetDate(query.value(3).toString());
            reportItem->itemSetOID(obj_id);

            QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);
            widgetItem->setSizeHint(QSize(1180, 80));
            ui->listWidget->setItemWidget(widgetItem, reportItem);
            connect(reportItem, &ListReportItem::click_delete, this, [=]{
                emit showComfirm();
                rItem = reportItem;
            });

            connect(reportItem, &ListReportItem::click_full, this, [=]{
                curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));
                emit fullBtnClicked(obj_id);
                ui->searchInput->clearFocus();
            });

            connect(reportItem, &ListReportItem::click_choose, this, [=]{
                curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));
                emit chooseBtnClicked(QString::number(patient_id), QString::number(obj_id), patient_name);
                resetAfterChoose();
                ui->searchInput->clearFocus();
            });
        }
    }
}

void BrowseReport::updateReport(int obj_id)
{
    QSqlQuery query(QSqlDatabase::database());
    QString searchQuery = QString("SELECT name, age, gender, date FROM report "
                                  "WHERE OID = %1").arg(obj_id);
    if(!query.exec(searchQuery)){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        if(query.next()){
            qDebug() << curFull;
            QWidget *widgetItem = ui->listWidget->itemWidget(ui->listWidget->item(curFull));
            if(widgetItem){
                ListReportItem *updateItem = qobject_cast<ListReportItem *>(widgetItem);

                updateItem->itemSetName(query.value(0).toString());
                updateItem->itemSetAge(query.value(1).toInt());
                updateItem->itemSetGender(query.value(2).toString());
                updateItem->itemSetDate(query.value(3).toString());
            }
            else{
                qDebug() << "no widgetItem";
            }
        }
    }
}

void BrowseReport::addNewReport()
{
    QSqlQuery query(QSqlDatabase::database());
    QString searchQuery = QString("SELECT name, age, gender, date, patient_id, OID FROM report "
                                  "ORDER BY OID desc "
                                  "LIMIT 1");
    if(!query.exec(searchQuery)){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        while(query.next()){
            int patient_id = query.value(4).toInt();
            int oid = query.value(5).toInt();
            QString patient_name = query.value(0).toString();

            ListReportItem *reportItem = new ListReportItem(ui->listWidget, chooseStatus);
            qDebug() << query.value(0).toString() << query.value(1).toInt()
                     << query.value(2).toString() << query.value(3).toString();

            reportItem->itemSetName(query.value(0).toString());
            reportItem->itemSetAge(query.value(1).toInt());
            reportItem->itemSetGender(query.value(2).toString());
            reportItem->itemSetDate(query.value(3).toString());
            reportItem->itemSetOID(oid);

            QListWidgetItem *widgetItem = new QListWidgetItem();
            widgetItem->setSizeHint(QSize(1180, 80));
            connect(reportItem, &ListReportItem::click_delete, this, [=]{
                emit showComfirm();
                rItem = reportItem;
            });

            connect(reportItem, &ListReportItem::click_full, this, [=]{
                curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));

                emit fullBtnClicked(oid);
                ui->searchInput->clearFocus();
            });

            connect(reportItem, &ListReportItem::click_choose, this, [=]{
                curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));
                emit chooseBtnClicked(QString::number(patient_id), QString::number(oid), patient_name);
                resetAfterChoose();
                ui->searchInput->clearFocus();
            });

            if(chooseStatus){
                int curLastRow = ui->listWidget->count() - 1;
                ui->listWidget->insertItem(curLastRow, widgetItem);
            }
            else{
                ui->listWidget->addItem(widgetItem);
            }
            ui->listWidget->setItemWidget(widgetItem, reportItem);
        }
    }
}

void BrowseReport::chooseReport()
{
    chooseStatus = true;
    int itemCount = ui->listWidget->count();

    for(int i = 0; i < itemCount; ++i){
        QListWidgetItem* item = ui->listWidget->item(i);
        QWidget* widget = ui->listWidget->itemWidget(item);

        if(widget){
            ListReportItem *item = qobject_cast<ListReportItem *>(widget);
            if(item){
                if(item->itemGetChooseBtnVisible()){
                    return;
                }
                else{
                    item->itemSetChooseBtnVisible(true);
                }
            }
        }
    }

    ListReportItem *reportItem = new ListReportItem(ui->listWidget, true);
    reportItem->itemSetName("default");
    reportItem->itemSetEmptyAge();
    reportItem->itemSetGender("");
    reportItem->itemSetDate("");
    reportItem->itemSetFullBtnVisible(false);
    reportItem->itemSetDeleteBtnVisible(false);

    QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);
    widgetItem->setSizeHint(QSize(1180, 80));
    ui->listWidget->setItemWidget(widgetItem, reportItem);

    connect(reportItem, &ListReportItem::click_choose, this, [=]{
        emit chooseBtnClicked("default", "", "default");
        resetAfterChoose();
        ui->searchInput->clearFocus();
    });

}

void BrowseReport::resetAfterChoose()
{
    int itemCount = ui->listWidget->count();

    for(int i = 0; i < itemCount; ++i){
        if(i == itemCount - 1){
            QListWidgetItem* item = ui->listWidget->takeItem(i);
            delete item;
        }
        else{
            QListWidgetItem* item = ui->listWidget->item(i);
            QWidget* widget = ui->listWidget->itemWidget(item);

            if(widget){
                ListReportItem *rItem = qobject_cast<ListReportItem *>(widget);
                if(rItem){
                    rItem->itemSetChooseBtnVisible(false);
                }
            }
        }
    }

    chooseStatus = false;

    emit backControlInterface();
    ui->searchInput->clearFocus();
}

void BrowseReport::refreshUI()
{
    ui->retranslateUi(this);

    int itemCount = ui->listWidget->count();

    for(int i = 0; i < itemCount; ++i){
        QListWidgetItem* item = ui->listWidget->item(i);
        QWidget* widget = ui->listWidget->itemWidget(item);

        if(widget){
            ListReportItem *rItem = qobject_cast<ListReportItem *>(widget);
            if(rItem){
                rItem->refreshUI();
            }
        }
    }
}

void BrowseReport::clearAllFocus()
{
    ui->searchInput->clearFocus();
}

void BrowseReport::setFocus(QPoint pos)
{
    QPoint relativeToMainWidget = ui->searchInput->mapTo(ui->stackedWidget, QPoint(0, 0));
    QRect relativeGeometry(relativeToMainWidget, ui->searchInput->size());

    if(relativeGeometry.contains(pos)){
        ui->searchInput->setFocus();
        QPoint cursor = pos - relativeToMainWidget;
        simulateClick(ui->searchInput, cursor);
//        emit showKeyBoard();
    }
}

void BrowseReport::deleteBtnClicked(ListReportItem *rItem)
{
    int patient_id;
    int row = ui->listWidget->row(ui->listWidget->itemAt(rItem->x(), rItem->y()));
    QListWidgetItem *removedItem = ui->listWidget->takeItem(row);
    delete removedItem;

    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM photos WHERE PID = :PID");
    query.bindValue(":PID", rItem->itemGetOID());

    if(!query.exec()){
        qDebug() << "Photo Error Delete : " << query.lastError().text();
        QSqlDatabase::database().rollback();
    }
    else{
        qDebug() << "Photo Delete Successfully";
        QSqlDatabase::database().commit();
    }

    query.prepare("SELECT patient_id FROM report WHERE OID = :OID");
    query.bindValue(":OID", rItem->itemGetOID());
    if(!query.exec()){
        qDebug() << "Report Error Search : " << query.lastError().text();
    }
    else{
        if(query.next()){
            patient_id = query.value(0).toInt();
            QString rmPhotoPath = (flag_USB == 1) ? QString("/mnt/USB_FLASH/Picture/%1/%2").arg(patient_id).arg(rItem->itemGetOID())
                                                  : QString("/mnt/SD_CARD/Picture/%1/%2").arg(patient_id).arg(rItem->itemGetOID());
            QString rmVideoPath = (flag_USB == 1) ? QString("/mnt/USB_FLASH/Video/%1/%2").arg(patient_id).arg(rItem->itemGetOID())
                                                  : QString("/mnt/SD_CARD/Video/%1/%2").arg(patient_id).arg(rItem->itemGetOID());
            QString rmVideoheadPath = (flag_USB == 1) ? QString("/mnt/USB_FLASH/Videohead/%1/%2").arg(patient_id).arg(rItem->itemGetOID())
                                                      : QString("/mnt/SD_CARD/Videohead/%1/%2").arg(patient_id).arg(rItem->itemGetOID());
            QStringList FolderPaths;
            FolderPaths << rmPhotoPath << rmVideoPath << rmVideoheadPath;
            for(QString rmfolderpath : FolderPaths){
                QString command = "rm -r " + rmfolderpath;
                int result = system(command.toStdString().c_str());
                if (result == 0) {
                    qDebug() << "Command executed successfully!";
                } else {
                    qDebug() << "Command failed with return code : " << result;
                }
            }
            system("sync");
        }
    }

    query.prepare("DELETE FROM report WHERE OID = :OID");
    query.bindValue(":OID", rItem->itemGetOID());

    if(!query.exec()){
        qDebug() << "Report Error Delete : " << query.lastError().text();
        QSqlDatabase::database().rollback();
    }
    else{
        qDebug() << "Report Delete Successfully";
        QSqlDatabase::database().commit();
    }
}

void BrowseReport::on_backBtn_clicked()
{
    if(chooseStatus){
        resetAfterChoose();
    }
    else{
        emit back();
    }

    ui->searchInput->clearFocus();
}

void BrowseReport::on_addReportBtn_clicked()
{
    emit addReportClicked();
    ui->searchInput->clearFocus();
}

void BrowseReport::on_searchBtn_clicked()
{
    QSqlQuery query(QSqlDatabase::database());
    QString text = ui->searchInput->text();

    if(!text.isEmpty() || !text.trimmed().isEmpty()){
        bool isNumber = false;
        int num = text.toInt(&isNumber, 10);

        int itemCount = ui->listWidget->count();

        for(int i = 0; i < itemCount; ++i){
            QListWidgetItem* item = ui->listWidget->takeItem(0);
            delete item;
        }

        if(isNumber){
            qDebug() << "in num";
            query.prepare("SELECT name, age, gender, date, OID, patient_id FROM report "
                          "WHERE patient_id = :number OR OID = :number OR age = :number");
            query.bindValue(":number", num);

            if(!query.exec()){
                qDebug() << "Error Search : " << query.lastError().text();
                return;
            }
        }
        else{
            qDebug() << "in QString";
            text = "%" + text + "%";
            query.prepare("SELECT name, age, gender, date, OID, patient_id FROM report "
                          "WHERE name LIKE :text "
                          "OR birth LIKE :text "
                          "OR gender LIKE :text "
                          "OR date LIKE :text "
                          "OR describe LIKE :text "
                          "OR part LIKE :text "
                          "OR situation LIKE :text "
                          "OR result LIKE :text "
                          "OR opinion LIKE :text "
                          "OR doctor LIKE :text ");
            query.bindValue(":text", text);

            if(!query.exec()){
                qDebug() << "Error Search : " << query.lastError().text();
                return;
            }
        }

        while(query.next()){

            ListReportItem *reportItem = new ListReportItem(ui->listWidget, chooseStatus);
            int oid = query.value(4).toInt();
            int pid = query.value(5).toInt();
            QString patient_name = query.value(0).toString();

            reportItem->itemSetName(query.value(0).toString());
            reportItem->itemSetAge(query.value(1).toInt());
            reportItem->itemSetGender(query.value(2).toString());
            reportItem->itemSetDate(query.value(3).toString());
            reportItem->itemSetOID(oid);

            QListWidgetItem *widgetItem = new QListWidgetItem();
            widgetItem->setSizeHint(QSize(1180, 80));
            connect(reportItem, &ListReportItem::click_delete, this, [=]{
                emit showComfirm();
                rItem = reportItem;
            });

            connect(reportItem, &ListReportItem::click_full, this, [=]{
                curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));

                emit fullBtnClicked(oid);
                ui->searchInput->clearFocus();
            });

            connect(reportItem, &ListReportItem::click_choose, this, [=]{
                curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));
                emit chooseBtnClicked(QString::number(pid), QString::number(oid), patient_name);
                ui->searchInput->clearFocus();
                resetAfterChoose();
            });

            if(chooseStatus){
                int curLastRow = ui->listWidget->count() - 1;
                ui->listWidget->insertItem(curLastRow, widgetItem);
            }
            else{
                ui->listWidget->addItem(widgetItem);
            }
            ui->listWidget->setItemWidget(widgetItem, reportItem);
        }

        if(chooseStatus){
            ListReportItem *reportItem = new ListReportItem(ui->listWidget, true);
            reportItem->itemSetName("default");
            reportItem->itemSetEmptyAge();
            reportItem->itemSetGender("");
            reportItem->itemSetDate("");
            reportItem->itemSetFullBtnVisible(false);
            reportItem->itemSetDeleteBtnVisible(false);

            QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);
            widgetItem->setSizeHint(QSize(1180, 80));
            ui->listWidget->setItemWidget(widgetItem, reportItem);

            connect(reportItem, &ListReportItem::click_choose, this, [=]{
                emit chooseBtnClicked("default", "", "default");
                resetAfterChoose();
                ui->searchInput->clearFocus();
            });
        }
    }
}

void BrowseReport::on_searchInput_textChanged(const QString &arg1)
{
    if(arg1 == ""){
        int itemCount = ui->listWidget->count();

        for(int i = 0; i < itemCount; ++i){
            QListWidgetItem* item = ui->listWidget->takeItem(0);
            delete item;
        }

        QSqlQuery query(QSqlDatabase::database());
        QString searchQuery = "SELECT name, age, gender, date, OID, patient_id FROM report";
        if(!query.exec(searchQuery)){
            qDebug() << "Error Search : " << query.lastError().text();
        }
        else{
            while(query.next()){
                int obj_id = query.value(4).toInt();
                int patient_id = query.value(5).toInt();
                QString patient_name = query.value(0).toString();

                ListReportItem *reportItem = new ListReportItem(ui->listWidget, chooseStatus);
                reportItem->itemSetName(query.value(0).toString());
                reportItem->itemSetAge(query.value(1).toInt());
                reportItem->itemSetGender(query.value(2).toString());
                reportItem->itemSetDate(query.value(3).toString());
                reportItem->itemSetOID(obj_id);

                QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);
                widgetItem->setSizeHint(QSize(1180, 80));
                ui->listWidget->setItemWidget(widgetItem, reportItem);
                connect(reportItem, &ListReportItem::click_delete, this, [=]{
                    emit showComfirm();
                    rItem = reportItem;
                });

                connect(reportItem, &ListReportItem::click_full, this, [=]{
                    curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));
                    emit fullBtnClicked(obj_id);
                    ui->searchInput->clearFocus();
                });

                connect(reportItem, &ListReportItem::click_choose, this, [=]{
                    curFull = ui->listWidget->row(ui->listWidget->itemAt(reportItem->x(), reportItem->y()));
                    emit chooseBtnClicked(QString::number(patient_id), QString::number(obj_id), patient_name);
                    resetAfterChoose();
                    ui->searchInput->clearFocus();
                });
            }

            if(chooseStatus){
                ListReportItem *reportItem = new ListReportItem(ui->listWidget, true);
                reportItem->itemSetName("default");
                reportItem->itemSetEmptyAge();
                reportItem->itemSetGender("");
                reportItem->itemSetDate("");
                reportItem->itemSetFullBtnVisible(false);
                reportItem->itemSetDeleteBtnVisible(false);

                QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);
                widgetItem->setSizeHint(QSize(1180, 80));
                ui->listWidget->setItemWidget(widgetItem, reportItem);

                connect(reportItem, &ListReportItem::click_choose, this, [=]{
                    emit chooseBtnClicked("default", "", "default");
                    resetAfterChoose();
                    ui->searchInput->clearFocus();
                });
            }
        }
    }
}

void BrowseReport::on_backBtn_noDatabase_clicked()
{
    emit backZhukuang();
}
