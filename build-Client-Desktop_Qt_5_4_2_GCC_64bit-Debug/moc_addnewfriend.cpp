/****************************************************************************
** Meta object code from reading C++ file 'addnewfriend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/screen/addnewfriend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewfriend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddNewFriend_t {
    QByteArrayData data[6];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddNewFriend_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddNewFriend_t qt_meta_stringdata_AddNewFriend = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AddNewFriend"
QT_MOC_LITERAL(1, 13, 16), // "addFriendSuccess"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "onFindThisNameClicked"
QT_MOC_LITERAL(4, 53, 19), // "onExitScreenClicked"
QT_MOC_LITERAL(5, 73, 14) // "onFeedBackFind"

    },
    "AddNewFriend\0addFriendSuccess\0\0"
    "onFindThisNameClicked\0onExitScreenClicked\0"
    "onFeedBackFind"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddNewFriend[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddNewFriend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddNewFriend *_t = static_cast<AddNewFriend *>(_o);
        switch (_id) {
        case 0: _t->addFriendSuccess(); break;
        case 1: _t->onFindThisNameClicked(); break;
        case 2: _t->onExitScreenClicked(); break;
        case 3: _t->onFeedBackFind(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddNewFriend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddNewFriend::addFriendSuccess)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddNewFriend::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddNewFriend.data,
      qt_meta_data_AddNewFriend,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddNewFriend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddNewFriend::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddNewFriend.stringdata))
        return static_cast<void*>(const_cast< AddNewFriend*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddNewFriend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AddNewFriend::addFriendSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE