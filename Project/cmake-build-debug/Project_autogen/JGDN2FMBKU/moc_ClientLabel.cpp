/****************************************************************************
** Meta object code from reading C++ file 'ClientLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/ClientLabel/ClientLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UI__ClientLabel_t {
    QByteArrayData data[14];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UI__ClientLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UI__ClientLabel_t qt_meta_stringdata_UI__ClientLabel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "UI::ClientLabel"
QT_MOC_LITERAL(1, 16, 15), // "viewAllScooters"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "handleHeaderClicked"
QT_MOC_LITERAL(4, 53, 5), // "index"
QT_MOC_LITERAL(5, 59, 15), // "exitApplication"
QT_MOC_LITERAL(6, 75, 17), // "cellDoubleClicked"
QT_MOC_LITERAL(7, 93, 8), // "rowIndex"
QT_MOC_LITERAL(8, 102, 11), // "columnIndex"
QT_MOC_LITERAL(9, 114, 14), // "reserveScooter"
QT_MOC_LITERAL(10, 129, 10), // "useScooter"
QT_MOC_LITERAL(11, 140, 11), // "freeScooter"
QT_MOC_LITERAL(12, 152, 21), // "seeMyReservedScooters"
QT_MOC_LITERAL(13, 174, 18) // "seeAllFreeScooters"

    },
    "UI::ClientLabel\0viewAllScooters\0\0"
    "handleHeaderClicked\0index\0exitApplication\0"
    "cellDoubleClicked\0rowIndex\0columnIndex\0"
    "reserveScooter\0useScooter\0freeScooter\0"
    "seeMyReservedScooters\0seeAllFreeScooters"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UI__ClientLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    2,   64,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UI::ClientLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->viewAllScooters(); break;
        case 1: _t->handleHeaderClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->exitApplication(); break;
        case 3: _t->cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->reserveScooter(); break;
        case 5: _t->useScooter(); break;
        case 6: _t->freeScooter(); break;
        case 7: _t->seeMyReservedScooters(); break;
        case 8: _t->seeAllFreeScooters(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UI::ClientLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UI__ClientLabel.data,
    qt_meta_data_UI__ClientLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UI::ClientLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UI::ClientLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UI__ClientLabel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UI::ClientLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
