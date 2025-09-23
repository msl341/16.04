/****************************************************************************
** Meta object code from reading C++ file 'ListReportItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/ListReportItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListReportItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListReportItem_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListReportItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListReportItem_t qt_meta_stringdata_ListReportItem = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ListReportItem"
QT_MOC_LITERAL(1, 15, 12), // "click_delete"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "click_full"
QT_MOC_LITERAL(4, 40, 12), // "click_choose"
QT_MOC_LITERAL(5, 53, 20), // "on_deleteBtn_clicked"
QT_MOC_LITERAL(6, 74, 18), // "on_fullBtn_clicked"
QT_MOC_LITERAL(7, 93, 20) // "on_chooseBtn_clicked"

    },
    "ListReportItem\0click_delete\0\0click_full\0"
    "click_choose\0on_deleteBtn_clicked\0"
    "on_fullBtn_clicked\0on_chooseBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListReportItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ListReportItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListReportItem *_t = static_cast<ListReportItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->click_delete(); break;
        case 1: _t->click_full(); break;
        case 2: _t->click_choose(); break;
        case 3: _t->on_deleteBtn_clicked(); break;
        case 4: _t->on_fullBtn_clicked(); break;
        case 5: _t->on_chooseBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListReportItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReportItem::click_delete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ListReportItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReportItem::click_full)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ListReportItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReportItem::click_choose)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ListReportItem::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ListReportItem.data,
    qt_meta_data_ListReportItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ListReportItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListReportItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListReportItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ListReportItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ListReportItem::click_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ListReportItem::click_full()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ListReportItem::click_choose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
