/****************************************************************************
** Meta object code from reading C++ file 'Character.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Character.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Character.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Character_t {
    QByteArrayData data[17];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Character_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Character_t qt_meta_stringdata_Character = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Character"
QT_MOC_LITERAL(1, 10, 12), // "signalBullet"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "start"
QT_MOC_LITERAL(4, 30, 3), // "end"
QT_MOC_LITERAL(5, 34, 12), // "signalScroll"
QT_MOC_LITERAL(6, 47, 1), // "x"
QT_MOC_LITERAL(7, 49, 1), // "y"
QT_MOC_LITERAL(8, 51, 14), // "signalTakeItem"
QT_MOC_LITERAL(9, 66, 10), // "slotTarget"
QT_MOC_LITERAL(10, 77, 5), // "point"
QT_MOC_LITERAL(11, 83, 8), // "slotShot"
QT_MOC_LITERAL(12, 92, 4), // "shot"
QT_MOC_LITERAL(13, 97, 8), // "slotTick"
QT_MOC_LITERAL(14, 106, 17), // "slotReceiveDamage"
QT_MOC_LITERAL(15, 124, 3), // "dmg"
QT_MOC_LITERAL(16, 128, 15) // "slotBulletTimer"

    },
    "Character\0signalBullet\0\0start\0end\0"
    "signalScroll\0x\0y\0signalTakeItem\0"
    "slotTarget\0point\0slotShot\0shot\0slotTick\0"
    "slotReceiveDamage\0dmg\0slotBulletTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Character[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    2,   59,    2, 0x06 /* Public */,
       8,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,
      14,    1,   72,    2, 0x0a /* Public */,
      16,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void Character::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Character *_t = static_cast<Character *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalBullet((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 1: _t->signalScroll((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->signalTakeItem(); break;
        case 3: _t->slotTarget((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->slotShot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotTick(); break;
        case 6: _t->slotReceiveDamage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotBulletTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Character::*)(QPointF , QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Character::signalBullet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Character::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Character::signalScroll)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Character::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Character::signalTakeItem)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Character::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Character.data,
      qt_meta_data_Character,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Character::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Character::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Character.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Character::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Character::signalBullet(QPointF _t1, QPointF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Character::signalScroll(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Character::signalTakeItem()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
