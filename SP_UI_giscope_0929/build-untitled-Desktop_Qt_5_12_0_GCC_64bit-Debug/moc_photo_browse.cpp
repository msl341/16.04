/****************************************************************************
** Meta object code from reading C++ file 'photo_browse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/photo_browse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photo_browse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_photo_browse_t {
    QByteArrayData data[4];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_photo_browse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_photo_browse_t qt_meta_stringdata_photo_browse = {
    {
QT_MOC_LITERAL(0, 0, 12), // "photo_browse"
QT_MOC_LITERAL(1, 13, 14), // "clicked_return"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17) // "goto_photo_browse"

    },
    "photo_browse\0clicked_return\0\0"
    "goto_photo_browse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_photo_browse[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void photo_browse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        photo_browse *_t = static_cast<photo_browse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_return(); break;
        case 1: _t->goto_photo_browse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (photo_browse::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&photo_browse::clicked_return)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (photo_browse::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&photo_browse::goto_photo_browse)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject photo_browse::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_photo_browse.data,
    qt_meta_data_photo_browse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *photo_browse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *photo_browse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_photo_browse.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int photo_browse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void photo_browse::clicked_return()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void photo_browse::goto_photo_browse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_Label_return_p_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_return_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_return_p_t qt_meta_stringdata_Label_return_p = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_return_p"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_return_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_return_p[] = {

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

void Label_return_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_return_p *_t = static_cast<Label_return_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_return_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_return_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_return_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_return_p.data,
    qt_meta_data_Label_return_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_return_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_return_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_return_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_return_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_return_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_select_p_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_select_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_select_p_t qt_meta_stringdata_Label_select_p = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_select_p"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_select_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_select_p[] = {

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

void Label_select_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_select_p *_t = static_cast<Label_select_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_select_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_select_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_select_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_select_p.data,
    qt_meta_data_Label_select_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_select_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_select_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_select_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_select_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_select_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_select_all_p_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_select_all_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_select_all_p_t qt_meta_stringdata_Label_select_all_p = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Label_select_all_p"
QT_MOC_LITERAL(1, 19, 9), // "clicked_1"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "Label_select_all_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_select_all_p[] = {

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

void Label_select_all_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_select_all_p *_t = static_cast<Label_select_all_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_select_all_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_select_all_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_select_all_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_select_all_p.data,
    qt_meta_data_Label_select_all_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_select_all_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_select_all_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_select_all_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_select_all_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_select_all_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_deselect_all_p_t {
    QByteArrayData data[3];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_deselect_all_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_deselect_all_p_t qt_meta_stringdata_Label_deselect_all_p = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Label_deselect_all_p"
QT_MOC_LITERAL(1, 21, 9), // "clicked_1"
QT_MOC_LITERAL(2, 31, 0) // ""

    },
    "Label_deselect_all_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_deselect_all_p[] = {

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

void Label_deselect_all_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_deselect_all_p *_t = static_cast<Label_deselect_all_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_deselect_all_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_deselect_all_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_deselect_all_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_deselect_all_p.data,
    qt_meta_data_Label_deselect_all_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_deselect_all_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_deselect_all_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_deselect_all_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_deselect_all_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_deselect_all_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_left_p_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_left_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_left_p_t qt_meta_stringdata_Label_left_p = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Label_left_p"
QT_MOC_LITERAL(1, 13, 9), // "clicked_1"
QT_MOC_LITERAL(2, 23, 0) // ""

    },
    "Label_left_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_left_p[] = {

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

void Label_left_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_left_p *_t = static_cast<Label_left_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_left_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_left_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_left_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_left_p.data,
    qt_meta_data_Label_left_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_left_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_left_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_left_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_left_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_left_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_right_p_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_right_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_right_p_t qt_meta_stringdata_Label_right_p = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_right_p"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_right_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_right_p[] = {

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

void Label_right_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_right_p *_t = static_cast<Label_right_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_right_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_right_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_right_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_right_p.data,
    qt_meta_data_Label_right_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_right_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_right_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_right_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_right_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_right_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_delete_p_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_delete_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_delete_p_t qt_meta_stringdata_Label_delete_p = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_delete_p"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_delete_p\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_delete_p[] = {

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

void Label_delete_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_delete_p *_t = static_cast<Label_delete_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_delete_p::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_delete_p::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_delete_p::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_delete_p.data,
    qt_meta_data_Label_delete_p,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_delete_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_delete_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_delete_p.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_delete_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_delete_p::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_photo_1_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_photo_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_photo_1_t qt_meta_stringdata_Label_photo_1 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_photo_1"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_photo_1\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_photo_1[] = {

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

void Label_photo_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_photo_1 *_t = static_cast<Label_photo_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_photo_1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_photo_1::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_photo_1::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_photo_1.data,
    qt_meta_data_Label_photo_1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_photo_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_photo_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_photo_1.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_photo_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_photo_1::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_photo_2_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_photo_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_photo_2_t qt_meta_stringdata_Label_photo_2 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_photo_2"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_photo_2\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_photo_2[] = {

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

void Label_photo_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_photo_2 *_t = static_cast<Label_photo_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_photo_2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_photo_2::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_photo_2::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_photo_2.data,
    qt_meta_data_Label_photo_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_photo_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_photo_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_photo_2.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_photo_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_photo_2::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_photo_3_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_photo_3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_photo_3_t qt_meta_stringdata_Label_photo_3 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_photo_3"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_photo_3\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_photo_3[] = {

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

void Label_photo_3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_photo_3 *_t = static_cast<Label_photo_3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_photo_3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_photo_3::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_photo_3::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_photo_3.data,
    qt_meta_data_Label_photo_3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_photo_3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_photo_3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_photo_3.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_photo_3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_photo_3::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_photo_4_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_photo_4_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_photo_4_t qt_meta_stringdata_Label_photo_4 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_photo_4"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_photo_4\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_photo_4[] = {

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

void Label_photo_4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_photo_4 *_t = static_cast<Label_photo_4 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_photo_4::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_photo_4::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_photo_4::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_photo_4.data,
    qt_meta_data_Label_photo_4,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_photo_4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_photo_4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_photo_4.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_photo_4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_photo_4::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_photo_5_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_photo_5_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_photo_5_t qt_meta_stringdata_Label_photo_5 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_photo_5"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_photo_5\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_photo_5[] = {

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

void Label_photo_5::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_photo_5 *_t = static_cast<Label_photo_5 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_photo_5::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_photo_5::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_photo_5::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_photo_5.data,
    qt_meta_data_Label_photo_5,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_photo_5::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_photo_5::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_photo_5.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_photo_5::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_photo_5::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_photo_6_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_photo_6_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_photo_6_t qt_meta_stringdata_Label_photo_6 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_photo_6"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_photo_6\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_photo_6[] = {

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

void Label_photo_6::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_photo_6 *_t = static_cast<Label_photo_6 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_photo_6::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_photo_6::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_photo_6::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_photo_6.data,
    qt_meta_data_Label_photo_6,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_photo_6::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_photo_6::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_photo_6.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_photo_6::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_photo_6::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
