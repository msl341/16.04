#ifndef ADDREPORT_H
#define ADDREPORT_H

#include <QWidget>
#include <QDebug>
#include <QModelIndexList>
#include <QGraphicsProxyWidget>
#include <QScrollBar>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QRegExp>
#include <QLineEdit>
#include <QMessageBox>
#include <QFocusEvent>
#include <QInputMethod>
#include <QGuiApplication>
#include <QApplication>
#include <QPlainTextEdit>
#include <QWidget> // 若用到 QWidget 相关功能
#include "mykey.h"
#include "PickPhoto.h"
#include "PickPhotoItem.h"

namespace Ui {
class addReport;
}

class focusOutLineEdit;

class addReport : public QWidget
{
    Q_OBJECT

public:
    explicit addReport(QWidget *parent = nullptr);
    ~addReport();

    void setStackWidget(bool status);
    void ResetAll();
    void clearAllLineEdit();
    void clearAllFocus();
    void clearAllLists();
    void getPatientID(int where = 0);
    void editReport(int obj_id);
    void refreshUI();
    void pickPhoto_selected(QList<QString> selectedList);
    void setRestriction();
    void setValidator(focusOutLineEdit *input, QRegExp reg, QString msg);
    void translateErrMsg();
    void setReselectVisible(bool status);
    void setFrom(int where);
    void connectLineEdits();
    void setFocus(QPoint pos);
    void plainTextReClick();

signals:
    void showErrorFormat(QString errMsg);
    void showKeyBoard();
    void showFullKeyBoard();
    void edited(int obj_id, bool showStatus);
    void reselect();
    void back(int obj_id = -1, int where = 0);
    void backZhukuang();
    void previewClicked(int where = 0, int pid = 0, int age = 0,
                        QList<QString> photoPaths = {}, QList<QString> others = {});
    void check(QString pid, QString oid, QString name);
    void showNoID();

private slots:

    void on_addBtn_clicked();

    void on_removeBtn_clicked();

    void on_saveBtn_clicked();

    void on_checkBtn_clicked();

    void on_previewBtn_clicked();

    void on_backBtn_clicked();

    void on_femaleBtn_clicked();

    void on_maleBtn_clicked();

    void on_enterBirth_textChanged(const QString &arg1);

    void on_enterDoctor_editingFinished();

    void on_backBtn_noDatabase_clicked();

    void on_reselectBtn_clicked();

private:
    Ui::addReport *ui;
    PickPhoto *pickPW;

    QGraphicsScene *scene;

    int id = 0, age = 0, OID = 0;
    QList<QString> photoPaths;
    QString name = "", birth = "", describe = "", gender = "";
    QString part = "", situation = "", result = "", opinion = "", doctor = "";

    int StartX = 0, StartY = 0, index = 0;
    int from = 0; //0:zhukuang, 1:fullReport, 2:browseReport, 3:control interface
    bool editState = false, show_saved = true;
    QList<QGraphicsProxyWidget *> proxyWidgetList;
    QList<int> selectToRemove;
    QList<PickPhotoItem *> pickPhotoList;

    QString photoFolderPath, videoFolderPath, videoheadFolderPath;
    QRegExp regexDescribe;
    QRegExp regexBirth;
};

class showKeyBoardLineEdit : public QLineEdit {
    Q_OBJECT
public:
    showKeyBoardLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {
        connect(this, static_cast<void (QLineEdit::*)(const QString &)>(&QLineEdit::textEdited), this, &showKeyBoardLineEdit::onTextChanged);
    }

protected:
    void focusInEvent(QFocusEvent* event) override {
        QLineEdit::focusInEvent(event);

        emit showKeyBoard();
    }

    void inputMethodEvent(QInputMethodEvent *event) override
    {
        QLineEdit::inputMethodEvent(event);
        QString composingText = event->preeditString();
        emit showFullKeyBoard();
    }

signals:
    void showKeyBoard();
    void showFullKeyBoard();

public slots:
    void onTextChanged(const QString &text){
        emit showFullKeyBoard();
    }

private:
};

class showKeyBoardPlainTextEdit : public QPlainTextEdit {
    Q_OBJECT
public:
    showKeyBoardPlainTextEdit(QWidget *parent = nullptr) : QPlainTextEdit(parent) {
        connect(this, &QPlainTextEdit::textChanged, this, &showKeyBoardPlainTextEdit::onTextChanged);
    }

protected:
    void focusInEvent(QFocusEvent* event) override {
        QPlainTextEdit::focusInEvent(event);

        emit showKeyBoard();
    }

    void inputMethodEvent(QInputMethodEvent *event) override
    {
        QPlainTextEdit::inputMethodEvent(event);
        QString composingText = event->preeditString();
        emit showFullKeyBoard();
    }

signals:
    void showKeyBoard();
    void showFullKeyBoard();

public slots:
    void onTextChanged(){
        emit showFullKeyBoard();
    }

private:
};

class focusOutLineEdit : public QLineEdit {
    Q_OBJECT
public:
    focusOutLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {
        connect(this, static_cast<void (QLineEdit::*)(const QString &)>(&QLineEdit::textChanged), this, &focusOutLineEdit::onTextChanged);
    }

    void setRegex(QRegExp reg){
        regex = reg;
    };
    void setErrMsg(QString msg){
        errMsg = msg;
    };
    QRegExp getRegex(){
        return regex;
    };

    void customClearFocus(){
        clearFocus();
        QString text = this->text();

        // 檢查輸入格式
        if (!regex.exactMatch(text)) {
            emit showErrorFormat(errMsg);
            this->clear();
        }
    }

protected:
    void focusOutEvent(QFocusEvent* event) override {
        QLineEdit::focusOutEvent(event);  // 確保不打斷其他功能
        QString text = this->text();

        // 檢查輸入格式
        if (!regex.exactMatch(text) && event->reason() == Qt::MouseFocusReason) {
            emit showErrorFormat(errMsg);
            this->clear();
        }
    }

    void focusInEvent(QFocusEvent* event) override {
        QLineEdit::focusInEvent(event);

        emit showKeyBoard();
    }

    void inputMethodEvent(QInputMethodEvent *event) override
    {
        QLineEdit::inputMethodEvent(event);
        QString composingText = event->preeditString();
        emit showFullKeyBoard();
    }

public slots:
    void onTextChanged(const QString &text){
        emit showFullKeyBoard();
    }

signals:
    void showKeyBoard();
    void showFullKeyBoard();
    void showErrorFormat(QString errMsg);

private:
    QRegExp regex;
    QString errMsg;
};

#endif // ADDREPORT_H
