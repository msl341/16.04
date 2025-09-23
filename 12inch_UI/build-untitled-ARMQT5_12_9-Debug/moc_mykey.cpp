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
    QByteArrayData data[6];
    char stringdata0[58];
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
QT_MOC_LITERAL(3, 24, 9), // "key_photo"
QT_MOC_LITERAL(4, 34, 9), // "key_video"
QT_MOC_LITERAL(5, 44, 13) // "mythread_work"

    },
    "usb_mcu\0update_display\0\0key_photo\0"
    "key_video\0mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usb_mcu[] = {

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
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
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
        case 1: _t->key_photo(); break;
        case 2: _t->key_video(); break;
        case 3: _t->mythread_work(); break;
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
        {
            using _t = void (usb_mcu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usb_mcu::key_photo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (usb_mcu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usb_mcu::key_video)) {
                *result = 2;
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
void usb_mcu::update_display()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void usb_mcu::key_photo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void usb_mcu::key_video()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
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
struct qt_meta_stringdata_DraggableGraphicsView_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DraggableGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DraggableGraphicsView_t qt_meta_stringdata_DraggableGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 21) // "DraggableGraphicsView"

    },
    "DraggableGraphicsView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DraggableGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DraggableGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DraggableGraphicsView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_DraggableGraphicsView.data,
    qt_meta_data_DraggableGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DraggableGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DraggableGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DraggableGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int DraggableGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_key_thread_290_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_key_thread_290_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_key_thread_290_t qt_meta_stringdata_key_thread_290 = {
    {
QT_MOC_LITERAL(0, 0, 14), // "key_thread_290"
QT_MOC_LITERAL(1, 15, 9), // "key_photo"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "key_video"
QT_MOC_LITERAL(4, 36, 11), // "key_zoom_in"
QT_MOC_LITERAL(5, 48, 12), // "key_zoom_out"
QT_MOC_LITERAL(6, 61, 13) // "mythread_work"

    },
    "key_thread_290\0key_photo\0\0key_video\0"
    "key_zoom_in\0key_zoom_out\0mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_key_thread_290[] = {

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

void key_thread_290::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<key_thread_290 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->key_photo(); break;
        case 1: _t->key_video(); break;
        case 2: _t->key_zoom_in(); break;
        case 3: _t->key_zoom_out(); break;
        case 4: _t->mythread_work(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (key_thread_290::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_290::key_photo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (key_thread_290::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_290::key_video)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (key_thread_290::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_290::key_zoom_in)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (key_thread_290::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_thread_290::key_zoom_out)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject key_thread_290::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_key_thread_290.data,
    qt_meta_data_key_thread_290,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *key_thread_290::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *key_thread_290::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_key_thread_290.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int key_thread_290::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void key_thread_290::key_photo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void key_thread_290::key_video()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void key_thread_290::key_zoom_in()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void key_thread_290::key_zoom_out()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_shortcut_key_t {
    QByteArrayData data[12];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_shortcut_key_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_shortcut_key_t qt_meta_stringdata_shortcut_key = {
    {
QT_MOC_LITERAL(0, 0, 12), // "shortcut_key"
QT_MOC_LITERAL(1, 13, 9), // "key_photo"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "key_video"
QT_MOC_LITERAL(4, 34, 10), // "key_freeze"
QT_MOC_LITERAL(5, 45, 8), // "key_mode"
QT_MOC_LITERAL(6, 54, 11), // "key_led_add"
QT_MOC_LITERAL(7, 66, 13), // "key_led_minus"
QT_MOC_LITERAL(8, 80, 8), // "key_pump"
QT_MOC_LITERAL(9, 89, 6), // "key_wb"
QT_MOC_LITERAL(10, 96, 8), // "key_zoom"
QT_MOC_LITERAL(11, 105, 13) // "mythread_work"

    },
    "shortcut_key\0key_photo\0\0key_video\0"
    "key_freeze\0key_mode\0key_led_add\0"
    "key_led_minus\0key_pump\0key_wb\0key_zoom\0"
    "mythread_work"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_shortcut_key[] = {

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

void shortcut_key::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<shortcut_key *>(_o);
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
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_photo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_video)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_freeze)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_mode)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_led_add)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_led_minus)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_pump)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_wb)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (shortcut_key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&shortcut_key::key_zoom)) {
                *result = 8;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject shortcut_key::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_shortcut_key.data,
    qt_meta_data_shortcut_key,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *shortcut_key::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *shortcut_key::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_shortcut_key.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int shortcut_key::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void shortcut_key::key_photo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void shortcut_key::key_video()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void shortcut_key::key_freeze()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void shortcut_key::key_mode()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void shortcut_key::key_led_add()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void shortcut_key::key_led_minus()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void shortcut_key::key_pump()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void shortcut_key::key_wb()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void shortcut_key::key_zoom()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
struct qt_meta_stringdata_Battery_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Battery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Battery_t qt_meta_stringdata_Battery = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Battery"
QT_MOC_LITERAL(1, 8, 13), // "batteryStatus"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "status"
QT_MOC_LITERAL(4, 30, 8), // "charging"
QT_MOC_LITERAL(5, 39, 7), // "warning"
QT_MOC_LITERAL(6, 47, 12) // "batteryCheck"

    },
    "Battery\0batteryStatus\0\0status\0charging\0"
    "warning\0batteryCheck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Battery[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Battery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Battery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->batteryStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->charging(); break;
        case 2: _t->warning(); break;
        case 3: _t->batteryCheck(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Battery::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Battery::batteryStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Battery::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Battery::charging)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Battery::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Battery::warning)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Battery::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Battery.data,
    qt_meta_data_Battery,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Battery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Battery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Battery.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Battery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Battery::batteryStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Battery::charging()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Battery::warning()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_DraggableListWidget_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DraggableListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DraggableListWidget_t qt_meta_stringdata_DraggableListWidget = {
    {
QT_MOC_LITERAL(0, 0, 19) // "DraggableListWidget"

    },
    "DraggableListWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DraggableListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DraggableListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DraggableListWidget::staticMetaObject = { {
    &QListWidget::staticMetaObject,
    qt_meta_stringdata_DraggableListWidget.data,
    qt_meta_data_DraggableListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DraggableListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DraggableListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DraggableListWidget.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int DraggableListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DraggableWidget_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DraggableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DraggableWidget_t qt_meta_stringdata_DraggableWidget = {
    {
QT_MOC_LITERAL(0, 0, 15) // "DraggableWidget"

    },
    "DraggableWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DraggableWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DraggableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DraggableWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DraggableWidget.data,
    qt_meta_data_DraggableWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DraggableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DraggableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DraggableWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DraggableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_movablePushbutton_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_movablePushbutton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_movablePushbutton_t qt_meta_stringdata_movablePushbutton = {
    {
QT_MOC_LITERAL(0, 0, 17), // "movablePushbutton"
QT_MOC_LITERAL(1, 18, 9), // "moveDelta"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5) // "delta"

    },
    "movablePushbutton\0moveDelta\0\0delta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_movablePushbutton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

void movablePushbutton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<movablePushbutton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveDelta((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (movablePushbutton::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movablePushbutton::moveDelta)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject movablePushbutton::staticMetaObject = { {
    &QPushButton::staticMetaObject,
    qt_meta_stringdata_movablePushbutton.data,
    qt_meta_data_movablePushbutton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *movablePushbutton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *movablePushbutton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_movablePushbutton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int movablePushbutton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void movablePushbutton::moveDelta(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
