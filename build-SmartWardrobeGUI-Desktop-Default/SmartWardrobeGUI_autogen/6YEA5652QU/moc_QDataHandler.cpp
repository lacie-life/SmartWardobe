/****************************************************************************
** Meta object code from reading C++ file 'QDataHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SmartWardrobeGUI/include/QDataHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDataHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDataHandler_t {
    QByteArrayData data[12];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDataHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDataHandler_t qt_meta_stringdata_QDataHandler = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QDataHandler"
QT_MOC_LITERAL(1, 13, 9), // "dataReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QString&"
QT_MOC_LITERAL(4, 33, 4), // "data"
QT_MOC_LITERAL(5, 38, 14), // "openSerialPort"
QT_MOC_LITERAL(6, 53, 15), // "closeSerialPort"
QT_MOC_LITERAL(7, 69, 9), // "writeData"
QT_MOC_LITERAL(8, 79, 8), // "readData"
QT_MOC_LITERAL(9, 88, 11), // "handleError"
QT_MOC_LITERAL(10, 100, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(11, 129, 5) // "error"

    },
    "QDataHandler\0dataReady\0\0QString&\0data\0"
    "openSerialPort\0closeSerialPort\0writeData\0"
    "readData\0handleError\0QSerialPort::SerialPortError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDataHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void QDataHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDataHandler *_t = static_cast<QDataHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReady((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->openSerialPort(); break;
        case 2: _t->closeSerialPort(); break;
        case 3: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->readData(); break;
        case 5: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QDataHandler::*_t)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QDataHandler::dataReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QDataHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDataHandler.data,
      qt_meta_data_QDataHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDataHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDataHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDataHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDataHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QDataHandler::dataReady(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
