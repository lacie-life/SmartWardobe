/****************************************************************************
** Meta object code from reading C++ file 'AppModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SmartWardrobeGUI/include/AppModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppModel_t {
    QByteArrayData data[37];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppModel_t qt_meta_stringdata_AppModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AppModel"
QT_MOC_LITERAL(1, 9, 10), // "slotUpdate"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "wardrobeUpdate"
QT_MOC_LITERAL(4, 36, 18), // "wardrobeUpdateDone"
QT_MOC_LITERAL(5, 55, 10), // "imageReady"
QT_MOC_LITERAL(6, 66, 6), // "pixmap"
QT_MOC_LITERAL(7, 73, 9), // "sendIndex"
QT_MOC_LITERAL(8, 83, 5), // "index"
QT_MOC_LITERAL(9, 89, 10), // "havePerson"
QT_MOC_LITERAL(10, 100, 8), // "noPerson"
QT_MOC_LITERAL(11, 109, 15), // "recognitionDone"
QT_MOC_LITERAL(12, 125, 12), // "slotNotifyUI"
QT_MOC_LITERAL(13, 138, 8), // "position"
QT_MOC_LITERAL(14, 147, 18), // "idRecognizedNotify"
QT_MOC_LITERAL(15, 166, 6), // "faceId"
QT_MOC_LITERAL(16, 173, 12), // "stateChanged"
QT_MOC_LITERAL(17, 186, 12), // "rfidReceived"
QT_MOC_LITERAL(18, 199, 4), // "rfid"
QT_MOC_LITERAL(19, 204, 12), // "processImage"
QT_MOC_LITERAL(20, 217, 7), // "cv::Mat"
QT_MOC_LITERAL(21, 225, 5), // "frame"
QT_MOC_LITERAL(22, 231, 11), // "extractData"
QT_MOC_LITERAL(23, 243, 8), // "QString&"
QT_MOC_LITERAL(24, 252, 4), // "data"
QT_MOC_LITERAL(25, 257, 9), // "checkFace"
QT_MOC_LITERAL(26, 267, 12), // "QStringList&"
QT_MOC_LITERAL(27, 280, 8), // "setState"
QT_MOC_LITERAL(28, 289, 9), // "APP_STATE"
QT_MOC_LITERAL(29, 299, 5), // "state"
QT_MOC_LITERAL(30, 305, 10), // "NONE_STATE"
QT_MOC_LITERAL(31, 316, 14), // "CHECKING_STATE"
QT_MOC_LITERAL(32, 331, 19), // "CHECKING_DONE_STATE"
QT_MOC_LITERAL(33, 351, 17), // "NO_CHEKCING_STATE"
QT_MOC_LITERAL(34, 369, 14), // "ADD_FACE_STATE"
QT_MOC_LITERAL(35, 384, 11), // "SLOT_UPDATE"
QT_MOC_LITERAL(36, 396, 9) // "END_STATE"

    },
    "AppModel\0slotUpdate\0\0wardrobeUpdate\0"
    "wardrobeUpdateDone\0imageReady\0pixmap\0"
    "sendIndex\0index\0havePerson\0noPerson\0"
    "recognitionDone\0slotNotifyUI\0position\0"
    "idRecognizedNotify\0faceId\0stateChanged\0"
    "rfidReceived\0rfid\0processImage\0cv::Mat\0"
    "frame\0extractData\0QString&\0data\0"
    "checkFace\0QStringList&\0setState\0"
    "APP_STATE\0state\0NONE_STATE\0CHECKING_STATE\0"
    "CHECKING_DONE_STATE\0NO_CHEKCING_STATE\0"
    "ADD_FACE_STATE\0SLOT_UPDATE\0END_STATE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       1,  128, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       7,    1,  100,    2, 0x06 /* Public */,
       9,    0,  103,    2, 0x06 /* Public */,
      10,    0,  104,    2, 0x06 /* Public */,
      11,    0,  105,    2, 0x06 /* Public */,
      12,    1,  106,    2, 0x06 /* Public */,
      14,    1,  109,    2, 0x06 /* Public */,
      16,    0,  112,    2, 0x06 /* Public */,
      17,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  116,    2, 0x0a /* Public */,
      22,    1,  119,    2, 0x0a /* Public */,
      25,    1,  122,    2, 0x0a /* Public */,
      27,    1,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 26,   15,
    QMetaType::Void, 0x80000000 | 28,   29,

 // enums: name, flags, count, data
      28, 0x0,    7,  132,

 // enum data: key, value
      30, uint(AppModel::NONE_STATE),
      31, uint(AppModel::CHECKING_STATE),
      32, uint(AppModel::CHECKING_DONE_STATE),
      33, uint(AppModel::NO_CHEKCING_STATE),
      34, uint(AppModel::ADD_FACE_STATE),
      35, uint(AppModel::SLOT_UPDATE),
      36, uint(AppModel::END_STATE),

       0        // eod
};

void AppModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppModel *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotUpdate(); break;
        case 1: _t->wardrobeUpdate(); break;
        case 2: _t->wardrobeUpdateDone(); break;
        case 3: _t->imageReady((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 4: _t->sendIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->havePerson(); break;
        case 6: _t->noPerson(); break;
        case 7: _t->recognitionDone(); break;
        case 8: _t->slotNotifyUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->idRecognizedNotify((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->stateChanged(); break;
        case 11: _t->rfidReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->processImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 13: _t->extractData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->checkFace((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 15: _t->setState((*reinterpret_cast< APP_STATE(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::slotUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::wardrobeUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::wardrobeUpdateDone)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::imageReady)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::sendIndex)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::havePerson)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::noPerson)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::recognitionDone)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::slotNotifyUI)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::idRecognizedNotify)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::stateChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::rfidReceived)) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject AppModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppModel.data,
      qt_meta_data_AppModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AppModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void AppModel::slotUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AppModel::wardrobeUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppModel::wardrobeUpdateDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppModel::imageReady(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AppModel::sendIndex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AppModel::havePerson()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void AppModel::noPerson()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void AppModel::recognitionDone()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void AppModel::slotNotifyUI(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void AppModel::idRecognizedNotify(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void AppModel::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void AppModel::rfidReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
