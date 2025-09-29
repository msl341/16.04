/****************************************************************************
** Meta object code from reading C++ file 'giscope.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/giscope.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'giscope.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GiScope_t {
    QByteArrayData data[16];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GiScope_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GiScope_t qt_meta_stringdata_GiScope = {
    {
QT_MOC_LITERAL(0, 0, 7), // "GiScope"
QT_MOC_LITERAL(1, 8, 17), // "socket_photograph"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 22), // "socket_photograph_name"
QT_MOC_LITERAL(4, 50, 14), // "socket_freeze1"
QT_MOC_LITERAL(5, 65, 21), // "socket_cancel_freeze1"
QT_MOC_LITERAL(6, 87, 10), // "socket_awb"
QT_MOC_LITERAL(7, 98, 9), // "nosd_card"
QT_MOC_LITERAL(8, 108, 10), // "stock_full"
QT_MOC_LITERAL(9, 119, 14), // "socket_videoon"
QT_MOC_LITERAL(10, 134, 15), // "socket_videooff"
QT_MOC_LITERAL(11, 150, 14), // "set_photograph"
QT_MOC_LITERAL(12, 165, 9), // "set_video"
QT_MOC_LITERAL(13, 175, 10), // "set_freeze"
QT_MOC_LITERAL(14, 186, 7), // "set_awb"
QT_MOC_LITERAL(15, 194, 11) // "updateTimer"

    },
    "GiScope\0socket_photograph\0\0"
    "socket_photograph_name\0socket_freeze1\0"
    "socket_cancel_freeze1\0socket_awb\0"
    "nosd_card\0stock_full\0socket_videoon\0"
    "socket_videooff\0set_photograph\0set_video\0"
    "set_freeze\0set_awb\0updateTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GiScope[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,
       8,    0,   90,    2, 0x06 /* Public */,
       9,    0,   91,    2, 0x06 /* Public */,
      10,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GiScope::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GiScope *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->socket_photograph(); break;
        case 1: _t->socket_photograph_name(); break;
        case 2: _t->socket_freeze1(); break;
        case 3: _t->socket_cancel_freeze1(); break;
        case 4: _t->socket_awb(); break;
        case 5: _t->nosd_card(); break;
        case 6: _t->stock_full(); break;
        case 7: _t->socket_videoon(); break;
        case 8: _t->socket_videooff(); break;
        case 9: _t->set_photograph(); break;
        case 10: _t->set_video(); break;
        case 11: _t->set_freeze(); break;
        case 12: _t->set_awb(); break;
        case 13: _t->updateTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_photograph)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_photograph_name)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_freeze1)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_cancel_freeze1)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_awb)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::nosd_card)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::stock_full)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_videoon)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GiScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GiScope::socket_videooff)) {
                *result = 8;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GiScope::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GiScope.data,
    qt_meta_data_GiScope,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GiScope::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GiScope::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GiScope.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GiScope::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GiScope::socket_photograph()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GiScope::socket_photograph_name()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GiScope::socket_freeze1()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GiScope::socket_cancel_freeze1()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GiScope::socket_awb()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GiScope::nosd_card()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void GiScope::stock_full()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void GiScope::socket_videoon()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void GiScope::socket_videooff()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
