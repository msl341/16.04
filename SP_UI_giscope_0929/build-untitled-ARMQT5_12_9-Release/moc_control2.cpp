/****************************************************************************
** Meta object code from reading C++ file 'control2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/control2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_control2_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_control2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_control2_t qt_meta_stringdata_control2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "control2"
QT_MOC_LITERAL(1, 9, 17), // "socket_photograph"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "socket_photograph_name"
QT_MOC_LITERAL(4, 51, 9), // "nosd_card"
QT_MOC_LITERAL(5, 61, 18), // "onNewPhotoReceived"
QT_MOC_LITERAL(6, 80, 9) // "photoPath"

    },
    "control2\0socket_photograph\0\0"
    "socket_photograph_name\0nosd_card\0"
    "onNewPhotoReceived\0photoPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_control2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void control2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<control2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->socket_photograph(); break;
        case 1: _t->socket_photograph_name(); break;
        case 2: _t->nosd_card(); break;
        case 3: _t->onNewPhotoReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (control2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&control2::socket_photograph)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (control2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&control2::socket_photograph_name)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (control2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&control2::nosd_card)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject control2::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_control2.data,
    qt_meta_data_control2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *control2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *control2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_control2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int control2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void control2::socket_photograph()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void control2::socket_photograph_name()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void control2::nosd_card()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
