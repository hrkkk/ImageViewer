/****************************************************************************
** Meta object code from reading C++ file 'CustomOpenGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CustomOpenGLWidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomOpenGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS = QtMocHelpers::stringData(
    "CustomOpenGLWidget",
    "sign_mouseClicked",
    "",
    "x",
    "y",
    "sign_scaleChanged",
    "scale",
    "slot_showImage",
    "uint8_t*",
    "data",
    "width",
    "height",
    "channels",
    "slot_resizeViewport",
    "slot_changeScale",
    "flag"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[19];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[2];
    char stringdata5[18];
    char stringdata6[6];
    char stringdata7[15];
    char stringdata8[9];
    char stringdata9[5];
    char stringdata10[6];
    char stringdata11[7];
    char stringdata12[9];
    char stringdata13[20];
    char stringdata14[17];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "CustomOpenGLWidget"
        QT_MOC_LITERAL(19, 17),  // "sign_mouseClicked"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 1),  // "x"
        QT_MOC_LITERAL(40, 1),  // "y"
        QT_MOC_LITERAL(42, 17),  // "sign_scaleChanged"
        QT_MOC_LITERAL(60, 5),  // "scale"
        QT_MOC_LITERAL(66, 14),  // "slot_showImage"
        QT_MOC_LITERAL(81, 8),  // "uint8_t*"
        QT_MOC_LITERAL(90, 4),  // "data"
        QT_MOC_LITERAL(95, 5),  // "width"
        QT_MOC_LITERAL(101, 6),  // "height"
        QT_MOC_LITERAL(108, 8),  // "channels"
        QT_MOC_LITERAL(117, 19),  // "slot_resizeViewport"
        QT_MOC_LITERAL(137, 16),  // "slot_changeScale"
        QT_MOC_LITERAL(154, 4)   // "flag"
    },
    "CustomOpenGLWidget",
    "sign_mouseClicked",
    "",
    "x",
    "y",
    "sign_scaleChanged",
    "scale",
    "slot_showImage",
    "uint8_t*",
    "data",
    "width",
    "height",
    "channels",
    "slot_resizeViewport",
    "slot_changeScale",
    "flag"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCustomOpenGLWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,
       5,    1,   49,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    4,   52,    2, 0x0a,    6 /* Public */,
      13,    0,   61,    2, 0x0a,   11 /* Public */,
      14,    1,   62,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Double,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject CustomOpenGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCustomOpenGLWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CustomOpenGLWidget, std::true_type>,
        // method 'sign_mouseClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sign_scaleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'slot_showImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t *, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'slot_resizeViewport'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_changeScale'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void CustomOpenGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomOpenGLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sign_mouseClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->sign_scaleChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->slot_showImage((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[4]))); break;
        case 3: _t->slot_resizeViewport(); break;
        case 4: _t->slot_changeScale((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CustomOpenGLWidget::*)(int , int );
            if (_t _q_method = &CustomOpenGLWidget::sign_mouseClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CustomOpenGLWidget::*)(double );
            if (_t _q_method = &CustomOpenGLWidget::sign_scaleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *CustomOpenGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomOpenGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int CustomOpenGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CustomOpenGLWidget::sign_mouseClicked(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CustomOpenGLWidget::sign_scaleChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
