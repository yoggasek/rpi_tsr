/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "E:/Programy/qtcreatorx64/bin/nienazwany/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[16];
    char stringdata[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 12), // "Mat3b2QImage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "Mat3b"
QT_MOC_LITERAL(4, 27, 3), // "src"
QT_MOC_LITERAL(5, 31, 22), // "on_stop_Button_clicked"
QT_MOC_LITERAL(6, 54, 25), // "on_zdjecie_Button_clicked"
QT_MOC_LITERAL(7, 80, 24), // "on_kamera_Button_clicked"
QT_MOC_LITERAL(8, 105, 22), // "on_film_Button_clicked"
QT_MOC_LITERAL(9, 128, 28), // "on_wykrywanie_Button_clicked"
QT_MOC_LITERAL(10, 157, 24), // "processFrameAndUpdateGUI"
QT_MOC_LITERAL(11, 182, 14), // "numberofframes"
QT_MOC_LITERAL(12, 197, 7), // "kamerka"
QT_MOC_LITERAL(13, 205, 11), // "svm_predict"
QT_MOC_LITERAL(14, 217, 4), // "Mat&"
QT_MOC_LITERAL(15, 222, 5) // "image"

    },
    "Dialog\0Mat3b2QImage\0\0Mat3b\0src\0"
    "on_stop_Button_clicked\0on_zdjecie_Button_clicked\0"
    "on_kamera_Button_clicked\0"
    "on_film_Button_clicked\0"
    "on_wykrywanie_Button_clicked\0"
    "processFrameAndUpdateGUI\0numberofframes\0"
    "kamerka\0svm_predict\0Mat&\0image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

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
       1,    1,   64,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QImage, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 14,   15,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        switch (_id) {
        case 0: { QImage _r = _t->Mat3b2QImage((*reinterpret_cast< Mat3b(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 1: _t->on_stop_Button_clicked(); break;
        case 2: _t->on_zdjecie_Button_clicked(); break;
        case 3: _t->on_kamera_Button_clicked(); break;
        case 4: _t->on_film_Button_clicked(); break;
        case 5: _t->on_wykrywanie_Button_clicked(); break;
        case 6: _t->processFrameAndUpdateGUI(); break;
        case 7: _t->numberofframes(); break;
        case 8: _t->kamerka(); break;
        case 9: { int _r = _t->svm_predict((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
