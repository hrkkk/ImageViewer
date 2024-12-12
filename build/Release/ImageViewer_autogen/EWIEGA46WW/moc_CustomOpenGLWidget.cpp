/****************************************************************************
** Meta object code from reading C++ file 'CustomOpenGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../CustomOpenGLWidget.h"
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
#error "This file was generated using the moc from 6.6.3. It"
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
constexpr auto qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS = QtMocHelpers::stringData(
    "CustomOpenGLWidget",
    "sig_scaleChanged",
    "",
    "scale",
    "slot_showImage",
    "std::shared_ptr<ImageData>&",
    "data",
    "orientation",
    "slot_resizeViewport",
    "slot_changeScale",
    "flag",
    "slot_rotateImage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[19];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[15];
    char stringdata5[28];
    char stringdata6[5];
    char stringdata7[12];
    char stringdata8[20];
    char stringdata9[17];
    char stringdata10[5];
    char stringdata11[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS_t qt_meta_stringdata_CLASSCustomOpenGLWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "CustomOpenGLWidget"
        QT_MOC_LITERAL(19, 16),  // "sig_scaleChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 5),  // "scale"
        QT_MOC_LITERAL(43, 14),  // "slot_showImage"
        QT_MOC_LITERAL(58, 27),  // "std::shared_ptr<ImageData>&"
        QT_MOC_LITERAL(86, 4),  // "data"
        QT_MOC_LITERAL(91, 11),  // "orientation"
        QT_MOC_LITERAL(103, 19),  // "slot_resizeViewport"
        QT_MOC_LITERAL(123, 16),  // "slot_changeScale"
        QT_MOC_LITERAL(140, 4),  // "flag"
        QT_MOC_LITERAL(145, 16)   // "slot_rotateImage"
    },
    "CustomOpenGLWidget",
    "sig_scaleChanged",
    "",
    "scale",
    "slot_showImage",
    "std::shared_ptr<ImageData>&",
    "data",
    "orientation",
    "slot_resizeViewport",
    "slot_changeScale",
    "flag",
    "slot_rotateImage"
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
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   47,    2, 0x0a,    3 /* Public */,
       8,    0,   52,    2, 0x0a,    6 /* Public */,
       9,    1,   53,    2, 0x0a,    7 /* Public */,
      11,    0,   56,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

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
        // method 'sig_scaleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'slot_showImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<ImageData> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_resizeViewport'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_changeScale'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_rotateImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CustomOpenGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomOpenGLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_scaleChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->slot_showImage((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<ImageData>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->slot_resizeViewport(); break;
        case 3: _t->slot_changeScale((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->slot_rotateImage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CustomOpenGLWidget::*)(double );
            if (_t _q_method = &CustomOpenGLWidget::sig_scaleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
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
void CustomOpenGLWidget::sig_scaleChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
