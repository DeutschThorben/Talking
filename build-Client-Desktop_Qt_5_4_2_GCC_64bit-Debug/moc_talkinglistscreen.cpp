/****************************************************************************
** Meta object code from reading C++ file 'talkinglistscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/screen/talkinglistscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'talkinglistscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TalkingListScreen_t {
    QByteArrayData data[7];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TalkingListScreen_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TalkingListScreen_t qt_meta_stringdata_TalkingListScreen = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TalkingListScreen"
QT_MOC_LITERAL(1, 18, 17), // "onFreshFriendList"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "onAddNewFriendClicked"
QT_MOC_LITERAL(4, 59, 19), // "onMakeMassesClicked"
QT_MOC_LITERAL(5, 79, 25), // "onTalkingWithOtherClicked"
QT_MOC_LITERAL(6, 105, 16) // "QListWidgetItem*"

    },
    "TalkingListScreen\0onFreshFriendList\0"
    "\0onAddNewFriendClicked\0onMakeMassesClicked\0"
    "onTalkingWithOtherClicked\0QListWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TalkingListScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void TalkingListScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TalkingListScreen *_t = static_cast<TalkingListScreen *>(_o);
        switch (_id) {
        case 0: _t->onFreshFriendList(); break;
        case 1: _t->onAddNewFriendClicked(); break;
        case 2: _t->onMakeMassesClicked(); break;
        case 3: _t->onTalkingWithOtherClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TalkingListScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TalkingListScreen.data,
      qt_meta_data_TalkingListScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TalkingListScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TalkingListScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TalkingListScreen.stringdata))
        return static_cast<void*>(const_cast< TalkingListScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int TalkingListScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
