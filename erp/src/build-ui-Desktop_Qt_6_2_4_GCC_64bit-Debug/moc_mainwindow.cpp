/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 29), // "on_btnEscribirArchivo_clicked"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 25), // "on_btnLeerArchivo_clicked"
QT_MOC_LITERAL(68, 35), // "on_editNombreTienda_editingFi..."
QT_MOC_LITERAL(104, 32), // "on_editWebTienda_editingFinished"
QT_MOC_LITERAL(137, 38), // "on_editDireccionTienda_editin..."
QT_MOC_LITERAL(176, 37), // "on_editTelefonoTienda_editing..."
QT_MOC_LITERAL(214, 29), // "on_btnAgregarProducto_clicked"
QT_MOC_LITERAL(244, 28), // "on_btnEditarProducto_clicked"
QT_MOC_LITERAL(273, 30), // "on_btnEliminarProdcuto_clicked"
QT_MOC_LITERAL(304, 19), // "ObtenerNombreTienda"
QT_MOC_LITERAL(324, 6), // "string"
QT_MOC_LITERAL(331, 16), // "ObtenerWebTienda"
QT_MOC_LITERAL(348, 22), // "ObtenerDireccionTienda"
QT_MOC_LITERAL(371, 21) // "ObtenerTelefonoTienda"

    },
    "MainWindow\0on_btnEscribirArchivo_clicked\0"
    "\0on_btnLeerArchivo_clicked\0"
    "on_editNombreTienda_editingFinished\0"
    "on_editWebTienda_editingFinished\0"
    "on_editDireccionTienda_editingFinished\0"
    "on_editTelefonoTienda_editingFinished\0"
    "on_btnAgregarProducto_clicked\0"
    "on_btnEditarProducto_clicked\0"
    "on_btnEliminarProdcuto_clicked\0"
    "ObtenerNombreTienda\0string\0ObtenerWebTienda\0"
    "ObtenerDireccionTienda\0ObtenerTelefonoTienda"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    0,  100,    2, 0x08,    9 /* Private */,
      11,    0,  101,    2, 0x08,   10 /* Private */,
      13,    0,  102,    2, 0x08,   11 /* Private */,
      14,    0,  103,    2, 0x08,   12 /* Private */,
      15,    0,  104,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12,
    0x80000000 | 12,
    0x80000000 | 12,
    0x80000000 | 12,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnEscribirArchivo_clicked(); break;
        case 1: _t->on_btnLeerArchivo_clicked(); break;
        case 2: _t->on_editNombreTienda_editingFinished(); break;
        case 3: _t->on_editWebTienda_editingFinished(); break;
        case 4: _t->on_editDireccionTienda_editingFinished(); break;
        case 5: _t->on_editTelefonoTienda_editingFinished(); break;
        case 6: _t->on_btnAgregarProducto_clicked(); break;
        case 7: _t->on_btnEditarProducto_clicked(); break;
        case 8: _t->on_btnEliminarProdcuto_clicked(); break;
        case 9: { string _r = _t->ObtenerNombreTienda();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 10: { string _r = _t->ObtenerWebTienda();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 11: { string _r = _t->ObtenerDireccionTienda();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 12: { string _r = _t->ObtenerTelefonoTienda();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
