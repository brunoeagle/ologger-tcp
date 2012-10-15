/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created: Thu 11. Oct 19:29:56 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TCPServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x08,
      53,   10,   10,   10, 0x08,
      72,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TCPServer[] = {
    "TCPServer\0\0checked\0on_listenPushButton_toggled(bool)\0"
    "acceptConnection()\0startRead()\0"
};

void TCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TCPServer *_t = static_cast<TCPServer *>(_o);
        switch (_id) {
        case 0: _t->on_listenPushButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->acceptConnection(); break;
        case 2: _t->startRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TCPServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TCPServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TCPServer,
      qt_meta_data_TCPServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TCPServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer))
        return static_cast<void*>(const_cast< TCPServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
