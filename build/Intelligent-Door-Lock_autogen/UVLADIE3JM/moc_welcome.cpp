/****************************************************************************
** Meta object code from reading C++ file 'welcome.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/welcome.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Welcome_t {
    QByteArrayData data[15];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Welcome_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Welcome_t qt_meta_stringdata_Welcome = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Welcome"
QT_MOC_LITERAL(1, 8, 11), // "face_unlock"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "code_unlock"
QT_MOC_LITERAL(4, 33, 9), // "start_new"
QT_MOC_LITERAL(5, 43, 12), // "start_delete"
QT_MOC_LITERAL(6, 56, 19), // "check_camera_thread"
QT_MOC_LITERAL(7, 76, 24), // "check_camera_thread_save"
QT_MOC_LITERAL(8, 101, 14), // "check_function"
QT_MOC_LITERAL(9, 116, 10), // "func_index"
QT_MOC_LITERAL(10, 127, 15), // "displaySavedImg"
QT_MOC_LITERAL(11, 143, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 160, 4), // "item"
QT_MOC_LITERAL(13, 165, 8), // "lock_now"
QT_MOC_LITERAL(14, 174, 11) // "change_code"

    },
    "Welcome\0face_unlock\0\0code_unlock\0"
    "start_new\0start_delete\0check_camera_thread\0"
    "check_camera_thread_save\0check_function\0"
    "func_index\0displaySavedImg\0QListWidgetItem*\0"
    "item\0lock_now\0change_code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Welcome[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Welcome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Welcome *_t = static_cast<Welcome *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->face_unlock(); break;
        case 1: _t->code_unlock(); break;
        case 2: _t->start_new(); break;
        case 3: _t->start_delete(); break;
        case 4: _t->check_camera_thread(); break;
        case 5: _t->check_camera_thread_save(); break;
        case 6: _t->check_function((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->displaySavedImg((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->lock_now(); break;
        case 9: _t->change_code(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Welcome::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Welcome.data,
      qt_meta_data_Welcome,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Welcome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Welcome::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Welcome.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Welcome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
