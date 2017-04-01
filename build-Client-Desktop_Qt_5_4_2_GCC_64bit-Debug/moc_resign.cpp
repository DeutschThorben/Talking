/****************************************************************************
** Meta object code from reading C++ file 'resign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/screen/resign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Resign_t {
    QByteArrayData data[8];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Resign_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Resign_t qt_meta_stringdata_Resign = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Resign"
QT_MOC_LITERAL(1, 7, 14), // "onBtnOkClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "onBtnEmptyClicked"
QT_MOC_LITERAL(4, 41, 16), // "onFeedBackRegist"
QT_MOC_LITERAL(5, 58, 17), // "onLabelNameChange"
QT_MOC_LITERAL(6, 76, 15), // "onLabelKWChange"
QT_MOC_LITERAL(7, 92, 20) // "onLabelKWAgainChange"

    },
    "Resign\0onBtnOkClicked\0\0onBtnEmptyClicked\0"
    "onFeedBackRegist\0onLabelNameChange\0"
    "onLabelKWChange\0onLabelKWAgainChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Resign[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Resign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Resign *_t = static_cast<Resign *>(_o);
        switch (_id) {
        case 0: _t->onBtnOkClicked(); break;
        case 1: _t->onBtnEmptyClicked(); break;
        case 2: _t->onFeedBackRegist(); break;
        case 3: _t->onLabelNameChange(); break;
        case 4: _t->onLabelKWChange(); break;
        case 5: _t->onLabelKWAgainChange(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Resign::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Resign.data,
      qt_meta_data_Resign,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Resign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Resign::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Resign.stringdata))
        return static_cast<void*>(const_cast< Resign*>(this));
    return QWidget::qt_metacast(_clname);
}

int Resign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
