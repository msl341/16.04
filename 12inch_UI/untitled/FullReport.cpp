#include "FullReport.h"
#include "ui_FullReport.h"

FullReport::FullReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullReport)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

FullReport::~FullReport()
{
    delete ui;
}

void FullReport::setFrom(int where)
{
    from = where;
}

void FullReport::previewReport(int where, int patient_id, int age, QList<QString> photoPaths, QList<QString> others)
{
    from = where;

    scene->clear();
    StartX = 150;
    StartY = 230;

    ui->ID->setText(QString::number(patient_id));
    ui->Age->setText(QString::number(age));
    ui->Name->setText(others[0]);
    ui->Birth->setText(others[1]);
    ui->Describe->setText(others[2]);
    ui->Gender->setText(others[3]);
    ui->Part->setText(others[4]);
    ui->Situation->setText(others[5]);
    ui->Result->setText(others[6]);
    ui->Opinion->setText(others[7]);
    ui->Doctor->setText(others[8]);
    ui->Date->setText(others[9]);

    for (QString photoPath : photoPaths){
        PickPhotoItem *pickItem = new PickPhotoItem(false);
        pickItem->itemSetPhoto(photoPath);
        pickItem->itemResize(250, 180);
        QGraphicsProxyWidget *proxyWidget = scene->addWidget(pickItem);
        proxyWidget->setPos(StartX, StartY);
        StartX += 300;
        if(StartX >= 900){
            StartY += 220;
            StartX = 150;
        }
    }

    ui->graphicsView->verticalScrollBar()->setValue(0);

    scene->setSceneRect(scene->itemsBoundingRect());

    QPixmapCache::clear();
}

void FullReport::viewFullReport(int where, int obj_id)
{
    from = where;
    OID = obj_id;

    QString searchQuery = QString("SELECT * FROM report WHERE OID = %1").arg(OID);
    QSqlQuery query(QSqlDatabase::database());
    if(!query.exec(searchQuery)){
        qDebug() << "Error fullReport Search : " << query.lastError().text();
    }
    else{
        if(query.next()){
            ui->ID->setText(QString::number(query.value(1).toInt()));
            ui->Name->setText(query.value(2).toString());
            ui->Birth->setText(query.value(3).toString());
            ui->Age->setText(QString::number(query.value(4).toInt()));
            ui->Gender->setText(query.value(5).toString());
            ui->Date->setText(query.value(6).toString());
            ui->Describe->setText(query.value(7).toString());
            ui->Part->setText(query.value(8).toString());
            ui->Situation->setText(query.value(9).toString());
            ui->Result->setText(query.value(10).toString());
            ui->Opinion->setText(query.value(11).toString());
            ui->Doctor->setText(query.value(12).toString());
        }
    }


    scene->clear();
    StartX = 150;
    StartY = 230;

    scene->setSceneRect(scene->itemsBoundingRect());

    searchQuery = QString("SELECT path FROM photos WHERE PID = %1").arg(OID);
    if(!query.exec(searchQuery)){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        while (query.next()) {
            PickPhotoItem *pickItem = new PickPhotoItem(false);
            pickItem->itemSetPhoto(query.value(0).toString());
            pickItem->itemResize(250, 180);
            QGraphicsProxyWidget *proxyWidget = scene->addWidget(pickItem);
            proxyWidget->setPos(StartX, StartY);
            StartX += 300;
            if(StartX >= 900){
                StartY += 220;
                StartX = 150;
            }
        }
        scene->setSceneRect(scene->itemsBoundingRect());
        ui->graphicsView->verticalScrollBar()->setValue(0);
    }
}

void FullReport::updateReport(int obj_id)
{
    QString searchQuery = QString("SELECT * FROM report WHERE OID = %1").arg(obj_id);
    QSqlQuery query(QSqlDatabase::database());

    if(!query.exec(searchQuery)){
        qDebug() << "Search Error : " << query.lastError().text();
    }
    else{
        if(query.next()){
            ui->ID->setText(QString::number(query.value(1).toInt()));
            ui->Name->setText(query.value(2).toString());
            ui->Birth->setText(query.value(3).toString());
            ui->Age->setText(QString::number(query.value(4).toInt()));
            ui->Gender->setText(query.value(5).toString());
            ui->Date->setText(query.value(6).toString());
            ui->Describe->setText(query.value(7).toString());
            ui->Part->setText(query.value(8).toString());
            ui->Situation->setText(query.value(9).toString());
            ui->Result->setText(query.value(10).toString());
            ui->Opinion->setText(query.value(11).toString());
            ui->Doctor->setText(query.value(12).toString());
        }
    }

    scene->clear();
    scene->setSceneRect(scene->itemsBoundingRect());
    StartX = 150;
    StartY = 230;

    searchQuery = QString("SELECT path FROM photos WHERE PID = %1").arg(obj_id);
    if(!query.exec(searchQuery)){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        while (query.next()) {
            PickPhotoItem *pickItem = new PickPhotoItem(false);
            pickItem->itemSetPhoto(query.value(0).toString());
            pickItem->itemResize(250, 180);
            QGraphicsProxyWidget *proxyWidget = scene->addWidget(pickItem);
            proxyWidget->setPos(StartX, StartY);
            StartX += 300;
            if(StartX >= 900){
                StartY += 220;
                StartX = 150;
            }
        }
        ui->graphicsView->verticalScrollBar()->setValue(0);
    }
}

void FullReport::restoreReport()
{
    QString searchQuery = QString("SELECT * FROM report WHERE OID = %1").arg(OID);
    QSqlQuery query(QSqlDatabase::database());

    if(!query.exec(searchQuery)){
        qDebug() << "Search Error : " << query.lastError().text();
    }
    else{
        if(query.next()){
            ui->ID->setText(QString::number(query.value(1).toInt()));
            ui->Name->setText(query.value(2).toString());
            ui->Birth->setText(query.value(3).toString());
            ui->Age->setText(QString::number(query.value(4).toInt()));
            ui->Gender->setText(query.value(5).toString());
            ui->Date->setText(query.value(6).toString());
            ui->Describe->setText(query.value(7).toString());
            ui->Part->setText(query.value(8).toString());
            ui->Situation->setText(query.value(9).toString());
            ui->Result->setText(query.value(10).toString());
            ui->Opinion->setText(query.value(11).toString());
            ui->Doctor->setText(query.value(12).toString());
        }
    }

    scene->clear();
    StartX = 150;
    StartY = 230;

    searchQuery = QString("SELECT path FROM photos WHERE PID = %1").arg(OID);
    if(!query.exec(searchQuery)){
        qDebug() << "Error Search : " << query.lastError().text();
    }
    else{
        qDebug() << "Search Success";
        while (query.next()) {
            qDebug() << query.value(0).toString();
            PickPhotoItem *pickItem = new PickPhotoItem(false);
            pickItem->itemSetPhoto(query.value(0).toString());
            pickItem->itemResize(250, 180);
            QGraphicsProxyWidget *proxyWidget = scene->addWidget(pickItem);
            proxyWidget->setPos(StartX, StartY);
            StartX += 300;
            if(StartX >= 900){
                StartY += 220;
                StartX = 150;
            }
        }
        ui->graphicsView->verticalScrollBar()->setValue(0);
    }
}

void FullReport::refreshUI()
{
    ui->retranslateUi(this);
}

void FullReport::hideEdit()
{
    ui->editBtn->setVisible(false);
    ui->editBtn->setEnabled(false);
}

void FullReport::on_backBtn_clicked()
{
    emit back(from);
    StartX = 150;
    StartY = 230;
    from = -1;
    scene->clear();
    scene->setSceneRect(scene->itemsBoundingRect());

    if(!ui->editBtn->isVisible()){
        ui->editBtn->setVisible(true);
        ui->editBtn->setEnabled(true);
    }
}

void FullReport::on_editBtn_clicked()
{
    StartX = 150;
    StartY = 230;
    scene->clear();
    scene->setSceneRect(scene->itemsBoundingRect());
    emit edit(OID);
}
