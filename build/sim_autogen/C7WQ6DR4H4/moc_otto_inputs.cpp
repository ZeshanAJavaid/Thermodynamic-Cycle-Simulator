/****************************************************************************
** Meta object code from reading C++ file 'otto_inputs.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../gui/src/headers/otto_inputs.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'otto_inputs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_OttoInputWindow_t {
    uint offsetsAndSizes[10];
    char stringdata0[16];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_OttoInputWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_OttoInputWindow_t qt_meta_stringdata_OttoInputWindow = {
    {
        QT_MOC_LITERAL(0, 15),  // "OttoInputWindow"
        QT_MOC_LITERAL(16, 21),  // "OpenPerformanceWindow"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 14),  // "OpenHelpWindow"
        QT_MOC_LITERAL(54, 19)   // "OpenSelectionWindow"
    },
    "OttoInputWindow",
    "OpenPerformanceWindow",
    "",
    "OpenHelpWindow",
    "OpenSelectionWindow"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_OttoInputWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject OttoInputWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_OttoInputWindow.offsetsAndSizes,
    qt_meta_data_OttoInputWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_OttoInputWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OttoInputWindow, std::true_type>,
        // method 'OpenPerformanceWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OpenHelpWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OpenSelectionWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void OttoInputWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OttoInputWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OpenPerformanceWindow(); break;
        case 1: _t->OpenHelpWindow(); break;
        case 2: _t->OpenSelectionWindow(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *OttoInputWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OttoInputWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OttoInputWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int OttoInputWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
