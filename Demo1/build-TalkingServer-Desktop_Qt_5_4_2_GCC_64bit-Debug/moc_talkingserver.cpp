/****************************************************************************
** Meta object code from reading C++ file 'talkingserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TalkingServer/talkingserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'talkingserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TalkingServer_t {
    QByteArrayData data[9];
    char stringdata[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TalkingServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TalkingServer_t qt_meta_stringdata_TalkingServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TalkingServer"
QT_MOC_LITERAL(1, 14, 12), // "onConnection"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "onDeleteUserClicked"
QT_MOC_LITERAL(4, 48, 15), // "onClearListWork"
QT_MOC_LITERAL(5, 64, 13), // "onExitClicked"
QT_MOC_LITERAL(6, 78, 17), // "onGetListUserName"
QT_MOC_LITERAL(7, 96, 17), // "onUserStateChange"
QT_MOC_LITERAL(8, 114, 14) // "onUserAddOther"

    },
    "TalkingServer\0onConnection\0\0"
    "onDeleteUserClicked\0onClearListWork\0"
    "onExitClicked\0onGetListUserName\0"
    "onUserStateChange\0onUserAddOther"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TalkingServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    3,   56,    2, 0x08 /* Private */,
       8,    2,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

       0        // eod
};

void TalkingServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TalkingServer *_t = static_cast<TalkingServer *>(_o);
        switch (_id) {
        case 0: _t->onConnection(); break;
        case 1: _t->onDeleteUserClicked(); break;
        case 2: _t->onClearListWork(); break;
        case 3: _t->onExitClicked(); break;
        case 4: _t->onGetListUserName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onUserStateChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->onUserAddOther((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TalkingServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TalkingServer.data,
      qt_meta_data_TalkingServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TalkingServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TalkingServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TalkingServer.stringdata))
        return static_cast<void*>(const_cast< TalkingServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TalkingServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
