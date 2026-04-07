/****************************************************************************
** Meta object code from reading C++ file 'system_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/system_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'system_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_system_setting_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_system_setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_system_setting_t qt_meta_stringdata_system_setting = {
    {
QT_MOC_LITERAL(0, 0, 14), // "system_setting"
QT_MOC_LITERAL(1, 15, 18), // "clicked_formatting"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "clicked_reset"
QT_MOC_LITERAL(4, 49, 16), // "clicked_versions"
QT_MOC_LITERAL(5, 66, 12), // "clicked_time"
QT_MOC_LITERAL(6, 79, 16), // "clicked_language"
QT_MOC_LITERAL(7, 96, 14) // "clicked_return"

    },
    "system_setting\0clicked_formatting\0\0"
    "clicked_reset\0clicked_versions\0"
    "clicked_time\0clicked_language\0"
    "clicked_return"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_system_setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void system_setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        system_setting *_t = static_cast<system_setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_formatting(); break;
        case 1: _t->clicked_reset(); break;
        case 2: _t->clicked_versions(); break;
        case 3: _t->clicked_time(); break;
        case 4: _t->clicked_language(); break;
        case 5: _t->clicked_return(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (system_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&system_setting::clicked_formatting)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (system_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&system_setting::clicked_reset)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (system_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&system_setting::clicked_versions)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (system_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&system_setting::clicked_time)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (system_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&system_setting::clicked_language)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (system_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&system_setting::clicked_return)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject system_setting::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_system_setting.data,
    qt_meta_data_system_setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *system_setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *system_setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_system_setting.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int system_setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void system_setting::clicked_formatting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void system_setting::clicked_reset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void system_setting::clicked_versions()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void system_setting::clicked_time()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void system_setting::clicked_language()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void system_setting::clicked_return()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
struct qt_meta_stringdata_Label_formatting_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_formatting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_formatting_t qt_meta_stringdata_Label_formatting = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Label_formatting"
QT_MOC_LITERAL(1, 17, 9), // "clicked_1"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "Label_formatting\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_formatting[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Label_formatting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_formatting *_t = static_cast<Label_formatting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_formatting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_formatting::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_formatting::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_formatting.data,
    qt_meta_data_Label_formatting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_formatting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_formatting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_formatting.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_formatting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label_formatting::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_reset_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_reset_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_reset_t qt_meta_stringdata_Label_reset = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Label_reset"
QT_MOC_LITERAL(1, 12, 9), // "clicked_1"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "Label_reset\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_reset[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Label_reset::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_reset *_t = static_cast<Label_reset *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_reset::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_reset::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_reset::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_reset.data,
    qt_meta_data_Label_reset,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_reset::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_reset::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_reset.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_reset::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label_reset::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_versions_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_versions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_versions_t qt_meta_stringdata_Label_versions = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_versions"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_versions\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_versions[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Label_versions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_versions *_t = static_cast<Label_versions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_versions::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_versions::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_versions::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_versions.data,
    qt_meta_data_Label_versions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_versions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_versions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_versions.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_versions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label_versions::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_time_t {
    QByteArrayData data[3];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_time_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_time_t qt_meta_stringdata_Label_time = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Label_time"
QT_MOC_LITERAL(1, 11, 9), // "clicked_1"
QT_MOC_LITERAL(2, 21, 0) // ""

    },
    "Label_time\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_time[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Label_time::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_time *_t = static_cast<Label_time *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_time::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_time::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_time::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_time.data,
    qt_meta_data_Label_time,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_time::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_time::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_time.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_time::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label_time::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_language_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_language_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_language_t qt_meta_stringdata_Label_language = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_language"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_language\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_language[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Label_language::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_language *_t = static_cast<Label_language *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_language::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_language::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_language::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_language.data,
    qt_meta_data_Label_language,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_language::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_language::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_language.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_language::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label_language::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_return_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_return_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_return_t qt_meta_stringdata_Label_return = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Label_return"
QT_MOC_LITERAL(1, 13, 9), // "clicked_1"
QT_MOC_LITERAL(2, 23, 0) // ""

    },
    "Label_return\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_return[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Label_return::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_return *_t = static_cast<Label_return *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_return::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_return::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_return::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_return.data,
    qt_meta_data_Label_return,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_return::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_return::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_return.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_return::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void Label_return::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
