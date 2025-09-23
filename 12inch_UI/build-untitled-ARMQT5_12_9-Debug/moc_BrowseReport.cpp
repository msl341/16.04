/****************************************************************************
** Meta object code from reading C++ file 'BrowseReport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/BrowseReport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BrowseReport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrowseReport_t {
    QByteArrayData data[22];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrowseReport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrowseReport_t qt_meta_stringdata_BrowseReport = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BrowseReport"
QT_MOC_LITERAL(1, 13, 4), // "back"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "showKeyBoard"
QT_MOC_LITERAL(4, 32, 16), // "showFullKeyboard"
QT_MOC_LITERAL(5, 49, 20), // "backControlInterface"
QT_MOC_LITERAL(6, 70, 11), // "showComfirm"
QT_MOC_LITERAL(7, 82, 12), // "backZhukuang"
QT_MOC_LITERAL(8, 95, 14), // "fullBtnClicked"
QT_MOC_LITERAL(9, 110, 3), // "pid"
QT_MOC_LITERAL(10, 114, 5), // "where"
QT_MOC_LITERAL(11, 120, 16), // "addReportClicked"
QT_MOC_LITERAL(12, 137, 16), // "chooseBtnClicked"
QT_MOC_LITERAL(13, 154, 10), // "patient_id"
QT_MOC_LITERAL(14, 165, 6), // "obj_id"
QT_MOC_LITERAL(15, 172, 11), // "patientName"
QT_MOC_LITERAL(16, 184, 18), // "on_backBtn_clicked"
QT_MOC_LITERAL(17, 203, 23), // "on_addReportBtn_clicked"
QT_MOC_LITERAL(18, 227, 20), // "on_searchBtn_clicked"
QT_MOC_LITERAL(19, 248, 26), // "on_searchInput_textChanged"
QT_MOC_LITERAL(20, 275, 4), // "arg1"
QT_MOC_LITERAL(21, 280, 29) // "on_backBtn_noDatabase_clicked"

    },
    "BrowseReport\0back\0\0showKeyBoard\0"
    "showFullKeyboard\0backControlInterface\0"
    "showComfirm\0backZhukuang\0fullBtnClicked\0"
    "pid\0where\0addReportClicked\0chooseBtnClicked\0"
    "patient_id\0obj_id\0patientName\0"
    "on_backBtn_clicked\0on_addReportBtn_clicked\0"
    "on_searchBtn_clicked\0on_searchInput_textChanged\0"
    "arg1\0on_backBtn_noDatabase_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrowseReport[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    2,   95,    2, 0x06 /* Public */,
       8,    1,  100,    2, 0x26 /* Public | MethodCloned */,
      11,    0,  103,    2, 0x06 /* Public */,
      12,    3,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    1,  114,    2, 0x08 /* Private */,
      21,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

       0        // eod
};

void BrowseReport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BrowseReport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->showKeyBoard(); break;
        case 2: _t->showFullKeyboard(); break;
        case 3: _t->backControlInterface(); break;
        case 4: _t->showComfirm(); break;
        case 5: _t->backZhukuang(); break;
        case 6: _t->fullBtnClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->fullBtnClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->addReportClicked(); break;
        case 9: _t->chooseBtnClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->on_backBtn_clicked(); break;
        case 11: _t->on_addReportBtn_clicked(); break;
        case 12: _t->on_searchBtn_clicked(); break;
        case 13: _t->on_searchInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_backBtn_noDatabase_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::back)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::showKeyBoard)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::showFullKeyboard)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::backControlInterface)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::showComfirm)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::backZhukuang)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::fullBtnClicked)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::addReportClicked)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (BrowseReport::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrowseReport::chooseBtnClicked)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BrowseReport::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_BrowseReport.data,
    qt_meta_data_BrowseReport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BrowseReport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrowseReport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrowseReport.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BrowseReport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void BrowseReport::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BrowseReport::showKeyBoard()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BrowseReport::showFullKeyboard()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BrowseReport::backControlInterface()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BrowseReport::showComfirm()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BrowseReport::backZhukuang()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void BrowseReport::fullBtnClicked(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void BrowseReport::addReportClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void BrowseReport::chooseBtnClicked(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
