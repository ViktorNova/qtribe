/****************************************************************************
** qTribe meta object code from reading C++ file 'qtribe.h'
**
** Created: Sat Jun 7 11:07:39 2008
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "qtribe.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *qTribe::className() const
{
    return "qTribe";
}

QMetaObject *qTribe::metaObj = 0;
static QMetaObjectCleanUp cleanUp_qTribe( "qTribe", &qTribe::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString qTribe::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "qTribe", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString qTribe::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "qTribe", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* qTribe::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"qTribe", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_qTribe.setMetaObject( metaObj );
    return metaObj;
}

void* qTribe::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "qTribe" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool qTribe::qt_invoke( int _id, QUObject* _o )
{
    return QMainWindow::qt_invoke(_id,_o);
}

bool qTribe::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool qTribe::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool qTribe::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
