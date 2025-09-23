/****************************************************************************
** Meta object code from reading C++ file 'videoshow_sel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/videoshow_sel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoshow_sel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_videoshow_sel_t {
    QByteArrayData data[9];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_videoshow_sel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_videoshow_sel_t qt_meta_stringdata_videoshow_sel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "videoshow_sel"
QT_MOC_LITERAL(1, 14, 20), // "sigReturnToVideoShow"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18), // "onDelayPlayTimeout"
QT_MOC_LITERAL(4, 55, 31), // "On_Btn_PlayPause_Toggle_Clicked"
QT_MOC_LITERAL(5, 87, 35), // "On_Btn_VideoPlayerPlay_Stop_C..."
QT_MOC_LITERAL(6, 123, 21), // "On_Btn_Return_Clicked"
QT_MOC_LITERAL(7, 145, 35), // "On_Btn_VideoPlayerPlay_Play_C..."
QT_MOC_LITERAL(8, 181, 36) // "On_Btn_VideoPlayerPlay_Pause_..."

    },
    "videoshow_sel\0sigReturnToVideoShow\0\0"
    "onDelayPlayTimeout\0On_Btn_PlayPause_Toggle_Clicked\0"
    "On_Btn_VideoPlayerPlay_Stop_Clicked\0"
    "On_Btn_Return_Clicked\0"
    "On_Btn_VideoPlayerPlay_Play_Clicked\0"
    "On_Btn_VideoPlayerPlay_Pause_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_videoshow_sel[] = {

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
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

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

void videoshow_sel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        videoshow_sel *_t = static_cast<videoshow_sel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReturnToVideoShow(); break;
        case 1: _t->onDelayPlayTimeout(); break;
        case 2: _t->On_Btn_PlayPause_Toggle_Clicked(); break;
        case 3: _t->On_Btn_VideoPlayerPlay_Stop_Clicked(); break;
        case 4: _t->On_Btn_Return_Clicked(); break;
        case 5: _t->On_Btn_VideoPlayerPlay_Play_Clicked(); break;
        case 6: _t->On_Btn_VideoPlayerPlay_Pause_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (videoshow_sel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoshow_sel::sigReturnToVideoShow)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject videoshow_sel::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_videoshow_sel.data,
    qt_meta_data_videoshow_sel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *videoshow_sel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videoshow_sel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_videoshow_sel.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int videoshow_sel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void videoshow_sel::sigReturnToVideoShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
