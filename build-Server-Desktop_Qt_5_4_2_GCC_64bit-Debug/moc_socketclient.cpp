/****************************************************************************
** Meta object code from reading C++ file 'socketclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Server/control/socketclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SocketClient_t {
    QByteArrayData data[7];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketClient_t qt_meta_stringdata_SocketClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SocketClient"
QT_MOC_LITERAL(1, 13, 15), // "UserStateChange"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "onReadyRead"
QT_MOC_LITERAL(4, 42, 21), // "sendOnlineUserToEvery"
QT_MOC_LITERAL(5, 64, 11), // "PackageType"
QT_MOC_LITERAL(6, 76, 11) // "QTcpSocket*"

    },
    "SocketClient\0UserStateChange\0\0onReadyRead\0"
    "sendOnlineUserToEvery\0PackageType\0"
    "QTcpSocket*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   34,    2, 0x0a /* Public */,
       4,    4,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, 0x80000000 | 6, QMetaType::Int,    2,    2,    2,    2,

       0        // eod
};

void SocketClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketClient *_t = static_cast<SocketClient *>(_o);
        switch (_id) {
        case 0: _t->UserStateChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->onReadyRead(); break;
        case 2: _t->sendOnlineUserToEvery((*reinterpret_cast< PackageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QTcpSocket*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SocketClient::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketClient::UserStateChange)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SocketClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocketClient.data,
      qt_meta_data_SocketClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SocketClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SocketClient.stringdata))
        return static_cast<void*>(const_cast< SocketClient*>(this));
    return QObject::qt_metacast(_clname);
}

int SocketClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SocketClient::UserStateChange(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
