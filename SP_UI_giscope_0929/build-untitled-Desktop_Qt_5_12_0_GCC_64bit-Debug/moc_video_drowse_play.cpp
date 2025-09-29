/****************************************************************************
** Meta object code from reading C++ file 'video_drowse_play.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/video_drowse_play.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_drowse_play.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_video_drowse_play_t {
    QByteArrayData data[12];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_video_drowse_play_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_video_drowse_play_t qt_meta_stringdata_video_drowse_play = {
    {
QT_MOC_LITERAL(0, 0, 17), // "video_drowse_play"
QT_MOC_LITERAL(1, 18, 12), // "socket_pause"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "socket_play_on"
QT_MOC_LITERAL(4, 47, 17), // "socket_play_video"
QT_MOC_LITERAL(5, 65, 21), // "socket_play_video_one"
QT_MOC_LITERAL(6, 87, 17), // "socket_close_play"
QT_MOC_LITERAL(7, 105, 24), // "socket_close_play_return"
QT_MOC_LITERAL(8, 130, 19), // "socket_fast_forward"
QT_MOC_LITERAL(9, 150, 20), // "socket_fast_backward"
QT_MOC_LITERAL(10, 171, 12), // "return_video"
QT_MOC_LITERAL(11, 184, 17) // "update_video_name"

    },
    "video_drowse_play\0socket_pause\0\0"
    "socket_play_on\0socket_play_video\0"
    "socket_play_video_one\0socket_close_play\0"
    "socket_close_play_return\0socket_fast_forward\0"
    "socket_fast_backward\0return_video\0"
    "update_video_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_video_drowse_play[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

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
      11,    0,   73,    2, 0x06 /* Public */,

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
    QMetaType::Void,

       0        // eod
};

void video_drowse_play::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        video_drowse_play *_t = static_cast<video_drowse_play *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->socket_pause(); break;
        case 1: _t->socket_play_on(); break;
        case 2: _t->socket_play_video(); break;
        case 3: _t->socket_play_video_one(); break;
        case 4: _t->socket_close_play(); break;
        case 5: _t->socket_close_play_return(); break;
        case 6: _t->socket_fast_forward(); break;
        case 7: _t->socket_fast_backward(); break;
        case 8: _t->return_video(); break;
        case 9: _t->update_video_name(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_pause)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_play_on)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_play_video)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_play_video_one)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_close_play)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_close_play_return)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_fast_forward)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::socket_fast_backward)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::return_video)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (video_drowse_play::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_drowse_play::update_video_name)) {
                *result = 9;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject video_drowse_play::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_video_drowse_play.data,
    qt_meta_data_video_drowse_play,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *video_drowse_play::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *video_drowse_play::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_video_drowse_play.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int video_drowse_play::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void video_drowse_play::socket_pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void video_drowse_play::socket_play_on()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void video_drowse_play::socket_play_video()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void video_drowse_play::socket_play_video_one()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void video_drowse_play::socket_close_play()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void video_drowse_play::socket_close_play_return()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void video_drowse_play::socket_fast_forward()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void video_drowse_play::socket_fast_backward()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void video_drowse_play::return_video()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void video_drowse_play::update_video_name()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
struct qt_meta_stringdata_Label_return_vs_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_return_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_return_vs_t qt_meta_stringdata_Label_return_vs = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Label_return_vs"
QT_MOC_LITERAL(1, 16, 9), // "clicked_1"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "Label_return_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_return_vs[] = {

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

void Label_return_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_return_vs *_t = static_cast<Label_return_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_return_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_return_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_return_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_return_vs.data,
    qt_meta_data_Label_return_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_return_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_return_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_return_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_return_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_return_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_left_vs_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_left_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_left_vs_t qt_meta_stringdata_Label_left_vs = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Label_left_vs"
QT_MOC_LITERAL(1, 14, 9), // "clicked_1"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "Label_left_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_left_vs[] = {

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

void Label_left_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_left_vs *_t = static_cast<Label_left_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_left_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_left_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_left_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_left_vs.data,
    qt_meta_data_Label_left_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_left_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_left_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_left_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_left_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_left_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_right_vs_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_right_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_right_vs_t qt_meta_stringdata_Label_right_vs = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_right_vs"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_right_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_right_vs[] = {

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

void Label_right_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_right_vs *_t = static_cast<Label_right_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_right_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_right_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_right_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_right_vs.data,
    qt_meta_data_Label_right_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_right_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_right_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_right_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_right_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_right_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_recoil_vs_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_recoil_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_recoil_vs_t qt_meta_stringdata_Label_recoil_vs = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Label_recoil_vs"
QT_MOC_LITERAL(1, 16, 9), // "clicked_1"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "Label_recoil_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_recoil_vs[] = {

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

void Label_recoil_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_recoil_vs *_t = static_cast<Label_recoil_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_recoil_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_recoil_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_recoil_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_recoil_vs.data,
    qt_meta_data_Label_recoil_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_recoil_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_recoil_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_recoil_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_recoil_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_recoil_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_pause_vs_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_pause_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_pause_vs_t qt_meta_stringdata_Label_pause_vs = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Label_pause_vs"
QT_MOC_LITERAL(1, 15, 9), // "clicked_1"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "Label_pause_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_pause_vs[] = {

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

void Label_pause_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_pause_vs *_t = static_cast<Label_pause_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_pause_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_pause_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_pause_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_pause_vs.data,
    qt_meta_data_Label_pause_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_pause_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_pause_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_pause_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_pause_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_pause_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_advance_vs_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_advance_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_advance_vs_t qt_meta_stringdata_Label_advance_vs = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Label_advance_vs"
QT_MOC_LITERAL(1, 17, 9), // "clicked_1"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "Label_advance_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_advance_vs[] = {

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

void Label_advance_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_advance_vs *_t = static_cast<Label_advance_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_advance_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_advance_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_advance_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_advance_vs.data,
    qt_meta_data_Label_advance_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_advance_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_advance_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_advance_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_advance_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_advance_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Label_delete_vs_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Label_delete_vs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Label_delete_vs_t qt_meta_stringdata_Label_delete_vs = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Label_delete_vs"
QT_MOC_LITERAL(1, 16, 9), // "clicked_1"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "Label_delete_vs\0clicked_1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Label_delete_vs[] = {

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

void Label_delete_vs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Label_delete_vs *_t = static_cast<Label_delete_vs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked_1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Label_delete_vs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Label_delete_vs::clicked_1)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Label_delete_vs::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_Label_delete_vs.data,
    qt_meta_data_Label_delete_vs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Label_delete_vs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Label_delete_vs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Label_delete_vs.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int Label_delete_vs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Label_delete_vs::clicked_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
