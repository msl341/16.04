#include "KeyBoard.h"
#include "ui_KeyBoard.h"

KeyBoard::KeyBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);

    ui->keyboardWidget->setVisible(false);
    ui->keyboardWidget->setEnabled(false);

    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    ui->quickWidget->setClearColor(QColor(Qt::transparent));

    QQuickItem *item = ui->quickWidget->rootObject();
    QQuickItem *inputPanel = item->childItems().first();
    if(inputPanel){
        connect(inputPanel, SIGNAL(keyboardVisibilityChanged(bool)), this, SLOT(setMoveBtnVisible(bool)));
    }

    connect(ui->moveLBtn, &movablePushbutton::moveDelta, this, [=](QPoint delta){
        ui->keyboardWidget->move(ui->keyboardWidget->pos().x() + delta.x(), ui->keyboardWidget->pos().y() + delta.y());
    });

    connect(ui->moveRBtn, &movablePushbutton::moveDelta, this, [=](QPoint delta){
        ui->keyboardWidget->move(ui->keyboardWidget->pos().x() + delta.x(), ui->keyboardWidget->pos().y() + delta.y());
    });
}

KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::moveKeyBoard()
{
    qDebug() << "in move keyboard";
    ui->keyboardWidget->move(90, 50);
}

void KeyBoard::showFullKeyBoard()
{
    ui->quickWidget->setGeometry(ui->quickWidget->x(), 5, ui->quickWidget->width(), 361);
}

bool KeyBoard::btnVisible()
{
    return ui->moveLBtn->isVisible();
}

void KeyBoard::setMoveBtnVisible(bool status)
{
    ui->quickWidget->setGeometry(ui->quickWidget->x(), 60, ui->quickWidget->width(), 306);
    ui->keyboardWidget->setVisible(status);
    ui->keyboardWidget->setEnabled(status);
    if(!status){
        emit hideKeyBoard();
        ui->quickWidget->setGeometry(ui->quickWidget->x(), 60, ui->quickWidget->width(), 306);
    }
    else{
        emit showStackTwo();
    }
}

void KeyBoard::mousePressEvent(QMouseEvent *event)
{
    if(!ui->keyboardWidget->geometry().contains(event->pos())) {
        emit hideKeyBoard();
        ui->quickWidget->setGeometry(ui->quickWidget->x(), 60, ui->quickWidget->width(), 306);
        emit clickPos(event->pos());
    }
}
