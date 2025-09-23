/****************************************************************************
** Meta object code from reading C++ file 'lansetwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/lansetwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lansetwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lansetwindow_t {
    QByteArrayData data[9];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lansetwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lansetwindow_t qt_meta_stringdata_lansetwindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "lansetwindow"
QT_MOC_LITERAL(1, 13, 17), // "sigReturnTowidget"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "On_Btn_SimpleCh_Clicked"
QT_MOC_LITERAL(4, 56, 26), // "On_Btn_TraditionCh_Clicked"
QT_MOC_LITERAL(5, 83, 22), // "On_Btn_English_Clicked"
QT_MOC_LITERAL(6, 106, 21), // "On_Btn_French_Clicked"
QT_MOC_LITERAL(7, 128, 21), // "On_Btn_German_Clicked"
QT_MOC_LITERAL(8, 150, 21) // "On_Btn_Cancel_Clicked"

    },
    "lansetwindow\0sigReturnTowidget\0\0"
    "On_Btn_SimpleCh_Clicked\0"
    "On_Btn_TraditionCh_Clicked\0"
    "On_Btn_English_Clicked\0On_Btn_French_Clicked\0"
    "On_Btn_German_Clicked\0On_Btn_Cancel_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lansetwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lansetwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lansetwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReturnTowidget(); break;
        case 1: _t->On_Btn_SimpleCh_Clicked(); break;
        case 2: _t->On_Btn_TraditionCh_Clicked(); break;
        case 3: _t->On_Btn_English_Clicked(); break;
        case 4: _t->On_Btn_French_Clicked(); break;
        case 5: _t->On_Btn_German_Clicked(); break;
        case 6: _t->On_Btn_Cancel_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lansetwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lansetwindow::sigReturnTowidget)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject lansetwindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_lansetwindow.data,
    qt_meta_data_lansetwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lansetwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lansetwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lansetwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int lansetwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void lansetwindow::sigReturnTowidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
