/****************************************************************************
** Meta object code from reading C++ file 'ComfirmDelete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/ComfirmDelete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComfirmDelete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComfirmDelete_t {
    QByteArrayData data[7];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComfirmDelete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComfirmDelete_t qt_meta_stringdata_ComfirmDelete = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ComfirmDelete"
QT_MOC_LITERAL(1, 14, 16), // "deleteBtnClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "cancelBtnClicked"
QT_MOC_LITERAL(4, 49, 4), // "back"
QT_MOC_LITERAL(5, 54, 20), // "on_deleteBtn_clicked"
QT_MOC_LITERAL(6, 75, 20) // "on_cancelBtn_clicked"

    },
    "ComfirmDelete\0deleteBtnClicked\0\0"
    "cancelBtnClicked\0back\0on_deleteBtn_clicked\0"
    "on_cancelBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComfirmDelete[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ComfirmDelete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ComfirmDelete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteBtnClicked(); break;
        case 1: _t->cancelBtnClicked(); break;
        case 2: _t->back(); break;
        case 3: _t->on_deleteBtn_clicked(); break;
        case 4: _t->on_cancelBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComfirmDelete::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfirmDelete::deleteBtnClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComfirmDelete::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfirmDelete::cancelBtnClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ComfirmDelete::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfirmDelete::back)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ComfirmDelete::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ComfirmDelete.data,
    qt_meta_data_ComfirmDelete,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ComfirmDelete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComfirmDelete::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComfirmDelete.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ComfirmDelete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ComfirmDelete::deleteBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ComfirmDelete::cancelBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ComfirmDelete::back()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
