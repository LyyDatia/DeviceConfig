/****************************************************************************
** Meta object code from reading C++ file 'deviceconfig.h'
**
** Created: Thu Sep 22 14:11:28 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../deviceconfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deviceconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeviceConfig[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      42,   13,   13,   13, 0x0a,
      62,   13,   13,   13, 0x0a,
      78,   13,   13,   13, 0x0a,
      93,   13,   13,   13, 0x0a,
     121,   13,   13,   13, 0x0a,
     151,   13,   13,   13, 0x0a,
     172,   13,   13,   13, 0x0a,
     191,   13,   13,   13, 0x0a,
     210,   13,   13,   13, 0x0a,
     225,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeviceConfig[] = {
    "DeviceConfig\0\0slots_SaveMode3Changed(int)\0"
    "slots_addKicklist()\0slots_defalut()\0"
    "slots_Export()\0slots_showCameraIOInfo(int)\0"
    "slots_ChangeCameraIOData(int)\0"
    "slots_CameraioSave()\0slots_ReadConfig()\0"
    "slots_GetIniPath()\0slots_SetAll()\0"
    "slots_Lock(int)\0"
};

void DeviceConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeviceConfig *_t = static_cast<DeviceConfig *>(_o);
        switch (_id) {
        case 0: _t->slots_SaveMode3Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slots_addKicklist(); break;
        case 2: _t->slots_defalut(); break;
        case 3: _t->slots_Export(); break;
        case 4: _t->slots_showCameraIOInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slots_ChangeCameraIOData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slots_CameraioSave(); break;
        case 7: _t->slots_ReadConfig(); break;
        case 8: _t->slots_GetIniPath(); break;
        case 9: _t->slots_SetAll(); break;
        case 10: _t->slots_Lock((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DeviceConfig::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeviceConfig::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DeviceConfig,
      qt_meta_data_DeviceConfig, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeviceConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeviceConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeviceConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceConfig))
        return static_cast<void*>(const_cast< DeviceConfig*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DeviceConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
