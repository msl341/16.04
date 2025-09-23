/****************************************************************************
** Meta object code from reading C++ file 'photoshow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/photoshow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photoshow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_photoshow_t {
    QByteArrayData data[8];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_photoshow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_photoshow_t qt_meta_stringdata_photoshow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "photoshow"
QT_MOC_LITERAL(1, 10, 17), // "sigReturnTowidget"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 24), // "On_Btn_Pre_Photo_Clicked"
QT_MOC_LITERAL(4, 54, 25), // "On_Btn_Next_Photo_Clicked"
QT_MOC_LITERAL(5, 80, 23), // "On_Btn_Del_File_Clicked"
QT_MOC_LITERAL(6, 104, 21), // "On_Btn_Return_Clicked"
QT_MOC_LITERAL(7, 126, 13) // "refreshPhotos"

    },
    "photoshow\0sigReturnTowidget\0\0"
    "On_Btn_Pre_Photo_Clicked\0"
    "On_Btn_Next_Photo_Clicked\0"
    "On_Btn_Del_File_Clicked\0On_Btn_Return_Clicked\0"
    "refreshPhotos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_photoshow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void photoshow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<photoshow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReturnTowidget(); break;
        case 1: _t->On_Btn_Pre_Photo_Clicked(); break;
        case 2: _t->On_Btn_Next_Photo_Clicked(); break;
        case 3: _t->On_Btn_Del_File_Clicked(); break;
        case 4: _t->On_Btn_Return_Clicked(); break;
        case 5: _t->refreshPhotos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (photoshow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&photoshow::sigReturnTowidget)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject photoshow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_photoshow.data,
    qt_meta_data_photoshow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *photoshow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *photoshow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_photoshow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int photoshow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void photoshow::sigReturnTowidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
