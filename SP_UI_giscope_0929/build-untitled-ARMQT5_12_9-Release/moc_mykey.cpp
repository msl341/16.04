/****************************************************************************
** Meta object code from reading C++ file 'mykey.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/mykey.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mykey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_usb_mcu_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usb_mcu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usb_mcu_t qt_meta_stringdata_usb_mcu = {
    {
QT_MOC_LITERAL(0, 0, 7), // "usb_mcu"
QT_MOC_LITERAL(1, 8, 14), // "update_display"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13) // "mythread_work"

    },
    "usb_mcu\0update_display\0\0mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usb_mcu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void usb_mcu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<usb_mcu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_display(); break;
        case 1: _t->mythread_work(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (usb_mcu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usb_mcu::update_display)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject usb_mcu::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_usb_mcu.data,
    qt_meta_data_usb_mcu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *usb_mcu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usb_mcu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_usb_mcu.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int usb_mcu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void usb_mcu::update_display()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_rev_usb_mcu_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rev_usb_mcu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rev_usb_mcu_t qt_meta_stringdata_rev_usb_mcu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "rev_usb_mcu"
QT_MOC_LITERAL(1, 12, 13), // "mythread_work"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "rev_usb_mcu\0mythread_work\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rev_usb_mcu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void rev_usb_mcu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rev_usb_mcu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mythread_work(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject rev_usb_mcu::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_rev_usb_mcu.data,
    qt_meta_data_rev_usb_mcu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rev_usb_mcu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rev_usb_mcu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rev_usb_mcu.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rev_usb_mcu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_uart_key_thread_t {
    QByteArrayData data[12];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uart_key_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uart_key_thread_t qt_meta_stringdata_uart_key_thread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "uart_key_thread"
QT_MOC_LITERAL(1, 16, 9), // "key_photo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "key_video"
QT_MOC_LITERAL(4, 37, 10), // "key_freeze"
QT_MOC_LITERAL(5, 48, 8), // "key_mode"
QT_MOC_LITERAL(6, 57, 11), // "key_led_add"
QT_MOC_LITERAL(7, 69, 13), // "key_led_minus"
QT_MOC_LITERAL(8, 83, 8), // "key_pump"
QT_MOC_LITERAL(9, 92, 6), // "key_wb"
QT_MOC_LITERAL(10, 99, 8), // "key_zoom"
QT_MOC_LITERAL(11, 108, 13) // "mythread_work"

    },
    "uart_key_thread\0key_photo\0\0key_video\0"
    "key_freeze\0key_mode\0key_led_add\0"
    "key_led_minus\0key_pump\0key_wb\0key_zoom\0"
    "mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uart_key_thread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   73,    2, 0x0a /* Public */,

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

       0        // eod
};

void uart_key_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<uart_key_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->key_photo(); break;
        case 1: _t->key_video(); break;
        case 2: _t->key_freeze(); break;
        case 3: _t->key_mode(); break;
        case 4: _t->key_led_add(); break;
        case 5: _t->key_led_minus(); break;
        case 6: _t->key_pump(); break;
        case 7: _t->key_wb(); break;
        case 8: _t->key_zoom(); break;
        case 9: _t->mythread_work(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_photo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_video)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_freeze)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_mode)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_led_add)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_led_minus)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_pump)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_wb)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (uart_key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uart_key_thread::key_zoom)) {
                *result = 8;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject uart_key_thread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_uart_key_thread.data,
    qt_meta_data_uart_key_thread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *uart_key_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uart_key_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_uart_key_thread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int uart_key_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void uart_key_thread::key_photo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void uart_key_thread::key_video()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void uart_key_thread::key_freeze()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void uart_key_thread::key_mode()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void uart_key_thread::key_led_add()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void uart_key_thread::key_led_minus()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void uart_key_thread::key_pump()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void uart_key_thread::key_wb()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void uart_key_thread::key_zoom()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
struct qt_meta_stringdata_key_thread_t {
    QByteArrayData data[10];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_key_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_key_thread_t qt_meta_stringdata_key_thread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "key_thread"
QT_MOC_LITERAL(1, 11, 9), // "first_key"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "second_key"
QT_MOC_LITERAL(4, 33, 9), // "third_key"
QT_MOC_LITERAL(5, 43, 10), // "fourth_key"
QT_MOC_LITERAL(6, 54, 15), // "fourth_key_long"
QT_MOC_LITERAL(7, 70, 13), // "insertion_key"
QT_MOC_LITERAL(8, 84, 15), // "uninsertion_key"
QT_MOC_LITERAL(9, 100, 13) // "mythread_work"

    },
    "key_thread\0first_key\0\0second_key\0"
    "third_key\0fourth_key\0fourth_key_long\0"
    "insertion_key\0uninsertion_key\0"
    "mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_key_thread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void key_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<key_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->first_key(); break;
        case 1: _t->second_key(); break;
        case 2: _t->third_key(); break;
        case 3: _t->fourth_key(); break;
        case 4: _t->fourth_key_long(); break;
        case 5: _t->insertion_key(); break;
        case 6: _t->uninsertion_key(); break;
        case 7: _t->mythread_work(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::first_key)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::second_key)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::third_key)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::fourth_key)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::fourth_key_long)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::insertion_key)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (key_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread::uninsertion_key)) {
                *result = 6;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject key_thread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_key_thread.data,
    qt_meta_data_key_thread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *key_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *key_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_key_thread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int key_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void key_thread::first_key()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void key_thread::second_key()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void key_thread::third_key()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void key_thread::fourth_key()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void key_thread::fourth_key_long()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void key_thread::insertion_key()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void key_thread::uninsertion_key()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
struct qt_meta_stringdata_key_thread_mipi0_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_key_thread_mipi0_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_key_thread_mipi0_t qt_meta_stringdata_key_thread_mipi0 = {
    {
QT_MOC_LITERAL(0, 0, 16), // "key_thread_mipi0"
QT_MOC_LITERAL(1, 17, 9), // "first_key"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "first_long_key"
QT_MOC_LITERAL(4, 43, 13), // "insertion_key"
QT_MOC_LITERAL(5, 57, 15), // "uninsertion_key"
QT_MOC_LITERAL(6, 73, 13) // "mythread_work"

    },
    "key_thread_mipi0\0first_key\0\0first_long_key\0"
    "insertion_key\0uninsertion_key\0"
    "mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_key_thread_mipi0[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void key_thread_mipi0::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<key_thread_mipi0 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->first_key(); break;
        case 1: _t->first_long_key(); break;
        case 2: _t->insertion_key(); break;
        case 3: _t->uninsertion_key(); break;
        case 4: _t->mythread_work(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (key_thread_mipi0::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_mipi0::first_key)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (key_thread_mipi0::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_mipi0::first_long_key)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (key_thread_mipi0::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_mipi0::insertion_key)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (key_thread_mipi0::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_mipi0::uninsertion_key)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject key_thread_mipi0::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_key_thread_mipi0.data,
    qt_meta_data_key_thread_mipi0,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *key_thread_mipi0::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *key_thread_mipi0::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_key_thread_mipi0.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int key_thread_mipi0::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void key_thread_mipi0::first_key()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void key_thread_mipi0::first_long_key()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void key_thread_mipi0::insertion_key()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void key_thread_mipi0::uninsertion_key()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_key_thread_mipi3_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_key_thread_mipi3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_key_thread_mipi3_t qt_meta_stringdata_key_thread_mipi3 = {
    {
QT_MOC_LITERAL(0, 0, 16), // "key_thread_mipi3"
QT_MOC_LITERAL(1, 17, 13), // "insertion_key"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "uninsertion_key"
QT_MOC_LITERAL(4, 48, 13) // "mythread_work"

    },
    "key_thread_mipi3\0insertion_key\0\0"
    "uninsertion_key\0mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_key_thread_mipi3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void key_thread_mipi3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<key_thread_mipi3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertion_key(); break;
        case 1: _t->uninsertion_key(); break;
        case 2: _t->mythread_work(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (key_thread_mipi3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_mipi3::insertion_key)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (key_thread_mipi3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_mipi3::uninsertion_key)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject key_thread_mipi3::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_key_thread_mipi3.data,
    qt_meta_data_key_thread_mipi3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *key_thread_mipi3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *key_thread_mipi3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_key_thread_mipi3.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int key_thread_mipi3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void key_thread_mipi3::insertion_key()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void key_thread_mipi3::uninsertion_key()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
