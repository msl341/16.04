#include "addReport.h"
#include "ui_addReport.h"

addReport::addReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addReport)
{
    ui->setupUi(this);

    ui->removeBtn->setVisible(false);
    ui->reselectBtn->setVisible(false);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    setRestriction();
    connectLineEdits();
}

addReport::~addReport()
{
    delete ui;
}

void addReport::getPatientID(int where) {
    from = where;

    QString searchMaxPid = "SELECT max(patient_id) FROM report";
    QSqlQuery query(QSqlDatabase::database());
    if(!query.exec(searchMaxPid)){
        qDebug() << "Error pid Search : " << query.lastError().text();
    }
    else{
        if(query.next()){
            qDebug() << "cur max patient_id : " << query.value(0).toInt();
            id = query.value(0).toInt() + 1;
        }
        else{
            id = 0;
        }
    }
    ui->enterID->setText(QString::number(id));

    QString getOID("SELECT seq FROM sqlite_sequence WHERE name = 'report';");
    if(!query.exec(getOID)){
        qDebug() << "Get OID Error : " << query.lastError().text();
    }
    else{
        if(query.next()){
            qDebug() << "cur OID : " << query.value(0).toInt();
            OID = query.value(0).toInt() + 1;
        }
        else{
            qDebug() << "first data, OID : " << 1;
            OID = 1;
        }
    }
    scene->setSceneRect(scene->itemsBoundingRect());

}

void addReport::editReport(int obj_id)
{
    from = 1;

    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT * FROM report WHERE OID = :OID");
    query.bindValue(":OID", obj_id);

    if(!query.exec()){
        qDebug() << "report Error Search : " << query.lastError().text();
    }
    else{
        while(query.next()){
            OID = query.value(0).toInt();
            ui->enterID->setText(query.value(1).toString());
            ui->enterAge->setText(query.value(4).toString());
            ui->enterName->setText(query.value(2).toString());
            ui->enterPart->setText(query.value(8).toString());
            ui->enterBirth->setText(query.value(3).toString());
            ui->enterDoctor->setText(query.value(12).toString());
            ui->enterResult->setText(query.value(10).toString());
            ui->enterOpinion->setText(query.value(11).toString());
            ui->enterDescribe->setPlainText(query.value(7).toString());
            ui->enterSituation->setText(query.value(9).toString());

            gender = query.value(5).toString();
            if(gender == "male" || gender == "男"){
                gender = ui->maleLabel->text();
                ui->maleBtn->setText("V");
                ui->femaleBtn->setText("");
                ui->femaleBtn->setProperty("clicked", false);
                ui->maleBtn->setProperty("clicked", true);
            }
            else if (gender == "female" || gender == "女"){
                gender = ui->femaleLabel->text();
                ui->femaleBtn->setText("V");
                ui->maleBtn->setText("");
                ui->maleBtn->setProperty("clicked", false);
                ui->femaleBtn->setProperty("clicked", true);
            }
            else{
                gender = "";
                ui->femaleBtn->setText("");
                ui->maleBtn->setText("");
                ui->maleBtn->setProperty("clicked", false);
                ui->femaleBtn->setProperty("clicked", false);
            }
        }
    }

    query.prepare("SELECT path FROM photos WHERE PID = :PID");
    query.bindValue(":PID", obj_id);

    if(!query.exec()){
        qDebug() << "Photos Error Search : " << query.lastError().text();
    }
    else{
        while(query.next()){
            QString photoPath = query.value(0).toString();
            photoPaths.append(photoPath);
            PickPhotoItem *pickItem = new PickPhotoItem();
            pickItem->itemSetPhoto(photoPath);
            pickItem->itemSetIndex(index);
            pickPhotoList.append(pickItem);
            index += 1;
            QGraphicsProxyWidget *proxyWidget = scene->addWidget(pickItem);
            proxyWidgetList.append(proxyWidget);
            proxyWidget->setPos(StartX, StartY);
            StartX += 168;
            if(StartX >= 504){
                StartY += 120;
                StartX = 0;
            }
            connect(pickItem, &PickPhotoItem::clicked, this, [=](int idx, bool clickStatus){
                if(!ui->removeBtn->isVisible()){
                    ui->removeBtn->setVisible(true);
                    ui->addBtn->setEnabled(false);
                }

                if(!clickStatus){
                    selectToRemove.append(idx);
                }
                else{
                    selectToRemove.removeOne(idx);
                    if(ui->removeBtn->isVisible() && selectToRemove.isEmpty()){
                        ui->removeBtn->setVisible(false);
                        ui->addBtn->setEnabled(true);
                    }
                }
            });
            scene->setSceneRect(scene->itemsBoundingRect());
        }
    }

    editState = true;

    QPixmapCache::clear();
}

void addReport::refreshUI()
{
    ui->retranslateUi(this);
    translateErrMsg();
}

void addReport::setStackWidget(bool status)
{
    if(status){
        ui->stackedWidget->setCurrentIndex(0);
    }
    else{
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void addReport::ResetAll()
{
    clearAllLists();
    clearAllLineEdit();
    scene->clear();
    StartX = 0;
    StartY = 0;
    index = 0;
    age = 0;
    id = 0;
    gender = "";
    name = "";
    birth = "";
    describe = "";
    part = "";
    situation = "";
    result = "";
    opinion = "";
    doctor = "";
    ui->maleBtn->setText("");
    ui->femaleBtn->setText("");
    ui->maleBtn->setProperty("clicked", false);
    ui->femaleBtn->setProperty("clicked", false);
    if(ui->removeBtn->isVisible()){
        ui->removeBtn->setVisible(false);
    }

    ui->addBtn->setEnabled(true);

    if(ui->reselectBtn->isVisible()){
        ui->reselectBtn->setVisible(false);
    }

    editState = false;
    show_saved = true;
}

void addReport::clearAllLineEdit()
{
    ui->enterID->clear();
    ui->enterAge->clear();
    ui->enterName->clear();
    ui->enterPart->clear();
    ui->enterBirth->clear();
    ui->enterDoctor->clear();
    ui->enterResult->clear();
    ui->enterOpinion->clear();
    ui->enterDescribe->clear();
    ui->enterSituation->clear();

    ui->enterID->clearFocus();
    ui->enterAge->clearFocus();
    ui->enterName->clearFocus();
    ui->enterPart->clearFocus();
    ui->enterBirth->clearFocus();
    ui->enterDoctor->clearFocus();
    ui->enterResult->clearFocus();
    ui->enterOpinion->clearFocus();
    ui->enterDescribe->clearFocus();
    ui->enterSituation->clearFocus();
}

void addReport::clearAllFocus()
{
    if (ui->enterID->hasFocus()) {
        ui->enterID->clearFocus();
    }
    else if(ui->enterAge->hasFocus()) {
        ui->enterAge->clearFocus();
    }
    else if(ui->enterName->hasFocus()) {
        ui->enterName->clearFocus();
    }
    else if(ui->enterDescribe->hasFocus()) {
        ui->enterDescribe->clearFocus();
    }
    else if(ui->enterPart->hasFocus()) {
        ui->enterPart->customClearFocus();
    }
    else if(ui->enterBirth->hasFocus()) {
        ui->enterBirth->customClearFocus();
    }
    else if(ui->enterDoctor->hasFocus()) {
        ui->enterDoctor->customClearFocus();
    }
    else if(ui->enterResult->hasFocus()) {
        ui->enterResult->customClearFocus();
    }
    else if(ui->enterOpinion->hasFocus()) {
        ui->enterOpinion->customClearFocus();
    }
    else if(ui->enterSituation->hasFocus()) {
        ui->enterSituation->customClearFocus();
    }
}

void addReport::clearAllLists()
{
    photoPaths.clear();
    proxyWidgetList.clear();
    selectToRemove.clear();
    pickPhotoList.clear();
}

void addReport::on_addBtn_clicked()
{
    pickPW = new PickPhoto(this, QString("%1/%2").arg(ui->enterID->text()).arg(OID));
    connect(pickPW, &PickPhoto::selected, this, &addReport::pickPhoto_selected);
    pickPW->refreshUI();
    pickPW->show();
}

void addReport::pickPhoto_selected(QList<QString> selectedList)
{
    for(QString path : selectedList){
        QString photoPath = (flag_USB == 1) ? QString("/mnt/USB_FLASH/Picture/%2/%3/%1").arg(path).arg(ui->enterID->text()).arg(OID)
                                            : QString("/mnt/SD_CARD/Picture/%2/%3/%1").arg(path).arg(ui->enterID->text()).arg(OID);
        photoPaths.append(photoPath);
        PickPhotoItem *pickItem = new PickPhotoItem();
        pickItem->itemSetPhoto(photoPath);
        pickItem->itemSetIndex(index);
        pickPhotoList.append(pickItem);
        index += 1;
        QGraphicsProxyWidget *proxyWidget = scene->addWidget(pickItem);
        proxyWidgetList.append(proxyWidget);
        proxyWidget->setPos(StartX, StartY);
        StartX += 168;
        if(StartX >= 504){
            StartY += 120;
            StartX = 0;
        }
        connect(pickItem, &PickPhotoItem::clicked, this, [=](int idx, bool clickStatus){
            if(!ui->removeBtn->isVisible()){
                ui->removeBtn->setVisible(true);
                ui->addBtn->setEnabled(false);
            }

            if(!clickStatus){
                selectToRemove.append(idx);
            }
            else{
                selectToRemove.removeOne(idx);
                if(ui->removeBtn->isVisible() && selectToRemove.isEmpty()){
                    ui->removeBtn->setVisible(false);
                    ui->addBtn->setEnabled(true);
                }
            }
        });

        scene->setSceneRect(scene->itemsBoundingRect());

    }

    QPixmapCache::clear();
}

void addReport::setRestriction()
{
    QIntValidator *validatorID = new QIntValidator(1, 100000, this);
    ui->enterID->setValidator(validatorID);

    QRegExp regexName("^[A-Za-z0-9\u4e00-\u9fa5\uAC00-\uD7AF\u3040-\u30ff\u4e00-\u9fff ]*$");
    QRegExpValidator* validatorName = new QRegExpValidator(regexName, this);
    ui->enterName->setValidator(validatorName);


    setValidator(ui->enterBirth,
                 QRegExp("^(19[1-9][0-9]|20[0-9]{2}|21[0-9]{3}|22[0-9]{3}|23[0-9]{3}|24[0-9]{3}|25[0-9]{3}|26[0-9]{3}|27[0-9]{3}|28[0-9]{3}|29[0-9]{3})"
                         "-(0[1-9]|1[0-2])"
                         "-(0[1-9]|[12][0-9]|3[01])$"),
                 tr("無效的格式 (yyyy-mm-dd)"));


    QIntValidator *validatorAge = new QIntValidator(1, 200, this);
    ui->enterAge->setValidator(validatorAge);

    QRegExp noSymbols = QRegExp("^[A-Za-z0-9\u4e00-\u9fa5\uAC00-\uD7AF\u3040-\u30ff\u4e00-\u9fff ]*$");
    setValidator(ui->enterPart, noSymbols, tr("請勿輸入特殊符號"));
    setValidator(ui->enterDoctor, noSymbols, tr("請勿輸入特殊符號"));
    setValidator(ui->enterResult, noSymbols, tr("請勿輸入特殊符號"));
    setValidator(ui->enterOpinion, noSymbols, tr("請勿輸入特殊符號"));
    setValidator(ui->enterSituation, noSymbols, tr("請勿輸入特殊符號"));
}

void addReport::setValidator(focusOutLineEdit *input, QRegExp reg, QString msg)
{
    input->setRegex(reg);
    input->setErrMsg(msg);
    QRegExpValidator* validator = new QRegExpValidator(input->getRegex(), this);
    input->setValidator(validator);
}

void addReport::translateErrMsg()
{
    ui->enterBirth->setErrMsg(tr("無效的格式 (yyyy-mm-dd)"));
    ui->enterPart->setErrMsg(tr("請勿輸入特殊符號"));
    ui->enterDoctor->setErrMsg(tr("請勿輸入特殊符號"));
    ui->enterResult->setErrMsg(tr("請勿輸入特殊符號"));
    ui->enterOpinion->setErrMsg(tr("請勿輸入特殊符號"));
    ui->enterSituation->setErrMsg(tr("請勿輸入特殊符號"));
}

void addReport::setReselectVisible(bool status)
{
    ui->reselectBtn->setVisible(status);
}

void addReport::setFrom(int where)
{
    from = where;
}

void addReport::connectLineEdits()
{
    connect(ui->enterID, &showKeyBoardLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterAge, &showKeyBoardLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterName, &showKeyBoardLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterPart, &focusOutLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterBirth, &focusOutLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterDoctor, &focusOutLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterResult, &focusOutLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterOpinion, &focusOutLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterSituation, &focusOutLineEdit::showKeyBoard, this, [=]{emit showKeyBoard();});
    connect(ui->enterDescribe, &showKeyBoardPlainTextEdit::showKeyBoard, this, [=]{emit showKeyBoard();});

    connect(ui->enterID, &showKeyBoardLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterAge, &showKeyBoardLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterName, &showKeyBoardLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterPart, &focusOutLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterBirth, &focusOutLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterDoctor, &focusOutLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterResult, &focusOutLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterOpinion, &focusOutLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterSituation, &focusOutLineEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});
    connect(ui->enterDescribe, &showKeyBoardPlainTextEdit::showFullKeyBoard, this, [=]{emit showFullKeyBoard();});

    connect(ui->enterBirth, &focusOutLineEdit::showErrorFormat, this, [=](QString errMsg){emit showErrorFormat(errMsg);});
}

void addReport::setFocus(QPoint pos)
{
    if(QRect(ui->enterID->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterID->size()).contains(pos)){
        ui->enterID->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterID->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterID, cursor);
    }
    else if(QRect(ui->enterAge->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterAge->size()).contains(pos)){
        ui->enterAge->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterAge->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterAge, cursor);
    }
    else if(QRect(ui->enterName->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterName->size()).contains(pos)){
        ui->enterName->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterName->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterName, cursor);
    }
    else if(QRect(ui->enterPart->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterPart->size()).contains(pos)){
        ui->enterPart->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterPart->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterPart, cursor);
    }
    else if(QRect(ui->enterBirth->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterBirth->size()).contains(pos)){
        ui->enterBirth->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterBirth->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterBirth, cursor);
    }
    else if(QRect(ui->enterDoctor->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterDoctor->size()).contains(pos)){
        ui->enterDoctor->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterDoctor->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterDoctor, cursor);
    }
    else if(QRect(ui->enterResult->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterResult->size()).contains(pos)){
        ui->enterResult->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterResult->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterResult, cursor);
    }
    else if(QRect(ui->enterOpinion->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterOpinion->size()).contains(pos)){
        ui->enterOpinion->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterOpinion->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterOpinion, cursor);
    }
    else if(QRect(ui->enterDescribe->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterDescribe->size()).contains(pos)){
        ui->enterDescribe->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterDescribe->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterDescribe->childAt(cursor), ui->enterDescribe->childAt(cursor)->mapToParent(cursor));
    }
    else if(QRect(ui->enterSituation->mapTo(ui->stackedWidget, QPoint(0, 0)), ui->enterSituation->size()).contains(pos)){
        ui->enterSituation->setFocus(Qt::MouseFocusReason);
        QPoint cursor = pos - ui->enterSituation->mapTo(ui->stackedWidget, QPoint(0, 0));
        simulateClick(ui->enterSituation, cursor);
    }
}

void addReport::plainTextReClick()
{
    qDebug() << "in reClick";
    simulateClick(ui->enterDescribe->childAt(QPoint(10, 10)), ui->enterDescribe->childAt(QPoint(10, 10))->mapToParent(QPoint(10, 10)));
}

void addReport::on_removeBtn_clicked()
{
    QList<QGraphicsProxyWidget*> tmp;
    QList<PickPhotoItem*> tmpItem;
    QList<QString> tmpPaths;
    index = 0;
    for(int i = 0; i < proxyWidgetList.size(); i++){
        if(!selectToRemove.contains(i)){
            tmp.append(proxyWidgetList[i]);
            pickPhotoList[i]->itemSetIndex(index);
            tmpItem.append(pickPhotoList[i]);
            tmpPaths.append(photoPaths[i]);
            index += 1;
        }
    }

    for(int index : selectToRemove){
        QGraphicsProxyWidget *removeProxy = proxyWidgetList[index];
        scene->removeItem(removeProxy);
        delete removeProxy;
    }

    proxyWidgetList.clear();
    pickPhotoList.clear();
    photoPaths.clear();
    proxyWidgetList = tmp;
    pickPhotoList = tmpItem;
    photoPaths = tmpPaths;

    StartX = 0;
    StartY = 0;

    for(QGraphicsProxyWidget *proxy : proxyWidgetList){
        proxy->setPos(StartX, StartY);
        StartX += 168;
        if(StartX >= 504){
            StartY += 120;
            StartX = 0;
        }
    }
    selectToRemove.clear();

    ui->removeBtn->setVisible(false);
    ui->addBtn->setEnabled(true);
    scene->setSceneRect(scene->itemsBoundingRect());
}

void addReport::on_saveBtn_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    int year = curDateTime.date().year();
    int month = curDateTime.date().month();
    int day = curDateTime.date().day();
    int hour = curDateTime.time().hour();
    int minute = curDateTime.time().minute();
    int second = curDateTime.time().second();

    QString dateTime = QString("%1-%2-%3 %4:%5:%6").arg(year).arg(month, 2, 10, QChar('0')).arg(day, 2, 10, QChar('0')).arg(hour, 2, 10, QChar('0')).arg(minute, 2, 10, QChar('0')).arg(second, 2, 10, QChar('0'));

    id = ui->enterID->text().trimmed().isEmpty() ? id : ui->enterID->text().toInt();
    age = ui->enterAge->text().toInt();

    name = ui->enterName->text().isEmpty() ? "" : ui->enterName->text();
    birth = ui->enterBirth->text().isEmpty() ? "" : ui->enterBirth->text();
    describe = ui->enterDescribe->toPlainText().isEmpty() ? "" : ui->enterDescribe->toPlainText();
    part = ui->enterPart->text().isEmpty() ? "" : ui->enterPart->text();
    situation = ui->enterSituation->text().isEmpty() ? "" : ui->enterSituation->text();
    result = ui->enterResult->text().isEmpty() ? "" : ui->enterResult->text();
    opinion = ui->enterOpinion->text().isEmpty() ? "" : ui->enterOpinion->text();
    doctor = ui->enterDoctor->text().isEmpty() ? "" : ui->enterDoctor->text();

    QSqlQuery query(QSqlDatabase::database());

    if(!editState){
        query.prepare("INSERT INTO report (patient_id, name, birth, age, gender, date, describe, part, situation, result, opinion, doctor) "
                      "VALUES (:patient_id, :name, :birth, :age, :gender, :date, :describe, :part, :situation, :result, :opinion, :doctor) ");

        query.bindValue(":patient_id", id);
        query.bindValue(":name", name);
        query.bindValue(":birth", birth);
        query.bindValue(":age", age);
        query.bindValue(":gender", gender);
        query.bindValue(":date", dateTime);
        query.bindValue(":describe", describe);
        query.bindValue(":part", part);
        query.bindValue(":situation", situation);
        query.bindValue(":result", result);
        query.bindValue(":opinion", opinion);
        query.bindValue(":doctor", doctor);

        if (!query.exec()) {
            qDebug() << "Error inserting data:" << query.lastError().text();
            QSqlDatabase::database().rollback();
        } else {
            qDebug() << "Data inserted successfully.";
            QSqlDatabase::database().commit();
        }


    }
    else{
        query.prepare("UPDATE report "
                      "SET patient_id = :patient_id, name = :name, birth = :birth, age = :age, gender = :gender, date = :date, describe = :describe, part = :part, situation = :situation, result = :result, opinion = :opinion, doctor = :doctor "
                      "WHERE OID = :OID");

        query.bindValue(":patient_id", id);
        query.bindValue(":name", name);
        query.bindValue(":birth", birth);
        query.bindValue(":age", age);
        query.bindValue(":gender", gender);
        query.bindValue(":date", dateTime);
        query.bindValue(":describe", describe);
        query.bindValue(":part", part);
        query.bindValue(":situation", situation);
        query.bindValue(":result", result);
        query.bindValue(":opinion", opinion);
        query.bindValue(":doctor", doctor);
        query.bindValue(":OID", OID);

        if (!query.exec()) {
            qDebug() << "Error Updating Data:" << query.lastError().text();
        } else {
            qDebug() << "Data Updated Successfully.";
        }

        query.prepare("DELETE FROM photos WHERE PID = :PID");
        query.bindValue(":PID", OID);

        if(!query.exec()){
            qDebug() << "Photos Error Delete : " << query.lastError().text();
            QSqlDatabase::database().rollback();
        }
        else{
            qDebug() << "Delete Successfully";
            QSqlDatabase::database().commit();
        }

    }

    if(!pickPhotoList.isEmpty()){
        for (PickPhotoItem *pItem : pickPhotoList){
            QString itemPath = pItem->itemGetPhotoPath();
            query.prepare("INSERT INTO photos (path, PID) "
                          "VALUES (:path, :PID) ");
            query.bindValue(":path", itemPath);
            query.bindValue(":PID", OID);

            if (!query.exec()) {
                qDebug() << "Error inserting data:" << query.lastError().text();
                QSqlDatabase::database().rollback();
            } else {
                qDebug() << "Photos inserted successfully.";
                QSqlDatabase::database().commit();
            }
        }
    }

    if(!editState){
        if(show_saved){
            emit back(OID, 4);
        }
        else{
            emit back(OID, -1);
        }

        if(flag_USB == 1){
            photoFolderPath = QString("/mnt/USB_FLASH/Picture/%1/%2").arg(id).arg(OID);
            videoFolderPath = QString("/mnt/USB_FLASH/Video/%1/%2").arg(id).arg(OID);
            videoheadFolderPath = QString("/mnt/USB_FLASH/Videohead/%1/%2").arg(id).arg(OID);
        }
        else if(flag_USB == 0 && flag_SD == 1){
            photoFolderPath = QString("/mnt/SD_CARD/Picture/%1/%2").arg(id).arg(OID);
            videoFolderPath = QString("/mnt/SD_CARD/Video/%1/%2").arg(id).arg(OID);
            videoheadFolderPath = QString("/mnt/SD_CARD/Videohead/%1/%2").arg(id).arg(OID);
        }

        QStringList FolderPaths;
        QDir Directory;
        FolderPaths << photoFolderPath << videoFolderPath << videoheadFolderPath;
        for(QString folderPath : FolderPaths){
            Directory = folderPath;
            if(!Directory.exists()){
                QString command = "mkdir -p " + folderPath;
                qDebug() << command;
                int result = system(command.toStdString().c_str());
                if (result == 0) {
                    qDebug() << "Command executed successfully!";
                } else {
                    qDebug() << "Command failed with return code:" << result;
                }
            }
        }


        system("sync");

        editState = true;
    }
    else{
        emit edited(OID, show_saved);
    }
}

void addReport::on_checkBtn_clicked()
{
//    ResetAll();
    show_saved = false;
    on_saveBtn_clicked();

    QSqlQuery query(QSqlDatabase::database());
    QString pid, patient_name;
    query.prepare("SELECT patient_id, name FROM report WHERE OID = :OID");
    query.bindValue(":OID", OID);

    if(!query.exec()){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        if(query.next()){
            pid = query.value(0).toString();
            patient_name = query.value(1).toString();
            qDebug() << "pid : " << pid << "OID : " << OID;
            emit check(pid, QString::number(OID), patient_name);
        }
        else{
            qDebug() << "Search No patient_id";
            emit check("default", "", "default");
        }
    }
    ResetAll();
}

void addReport::on_previewBtn_clicked()
{
    QList<QString> others;
    id = ui->enterID->text().toInt();
    age = ui->enterAge->text().toInt();

    name = ui->enterName->text();
    birth = ui->enterBirth->text();
    describe = ui->enterDescribe->toPlainText();
    part = ui->enterPart->text();
    situation = ui->enterSituation->text();
    result = ui->enterResult->text();
    opinion = ui->enterOpinion->text();
    doctor = ui->enterDoctor->text();

    QDateTime curDateTime = QDateTime::currentDateTime();
    int year = curDateTime.date().year();
    int month = curDateTime.date().month();
    int day = curDateTime.date().day();
    int hour = curDateTime.time().hour();
    int minute = curDateTime.time().minute();
    int second = curDateTime.time().second();

    QString dateTime = QString("%1-%2-%3 %4:%5:%6").arg(year).arg(month, 2, 10, QChar('0')).arg(day, 2, 10, QChar('0')).arg(hour, 2, 10, QChar('0')).arg(minute, 2, 10, QChar('0')).arg(second, 2, 10, QChar('0'));

    others << name << birth << describe << gender << part <<
              situation << result << opinion << doctor << dateTime;
    emit previewClicked(0, id, age, photoPaths, others);
}

void addReport::on_backBtn_clicked()
{
    ResetAll();
    qDebug() << "from = " << from;
    emit back(-1, from);
}

void addReport::on_femaleBtn_clicked()
{
    bool isClicked = ui->femaleBtn->property("clicked").toBool();
    if(isClicked){
        gender = "";
        ui->femaleBtn->setText("");

    }
    else{
        gender = ui->femaleLabel->text();
        ui->femaleBtn->setText("V");
        ui->maleBtn->setText("");
        ui->maleBtn->setProperty("clicked", false);
    }
    ui->femaleBtn->setProperty("clicked", !isClicked);
}

void addReport::on_maleBtn_clicked()
{
    bool isClicked = ui->maleBtn->property("clicked").toBool();
    if(isClicked){
        gender = "";
        ui->maleBtn->setText("");
    }
    else{
        gender = ui->maleLabel->text();
        ui->maleBtn->setText("V");
        ui->femaleBtn->setText("");
        ui->femaleBtn->setProperty("clicked", false);
    }
    ui->maleBtn->setProperty("clicked", !isClicked);
}

void addReport::on_enterBirth_textChanged(const QString &arg1)
{
    if(arg1.length() == 4 || arg1.length() == 7){
        ui->enterBirth->setText(arg1 + "-");
        ui->enterBirth->setCursorPosition(ui->enterBirth->text().length());
    }
}

void addReport::on_enterDoctor_editingFinished()
{
    qDebug() << "finish";
}

void addReport::on_backBtn_noDatabase_clicked()
{
    emit backZhukuang();
}

void addReport::on_reselectBtn_clicked()
{
    ResetAll();
    emit reselect();
}
