/****************************************************************************
** stepsequencerWidget meta object code from reading C++ file 'stepsequencerwidget.h'
**
** Created: Sat Jun 7 11:02:18 2008
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "stepsequencerwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *stepsequencerWidget::className() const
{
    return "stepsequencerWidget";
}

QMetaObject *stepsequencerWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_stepsequencerWidget( "stepsequencerWidget", &stepsequencerWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString stepsequencerWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "stepsequencerWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString stepsequencerWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "stepsequencerWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* stepsequencerWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = stepsequencerWidgetBase::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"muteParts_toggled", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"stepModeGroup_clicked", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"synthParts_clicked", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"dataDial_valueChanged", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"sequence_clicked", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"drumParts_clicked", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"play_toggled", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"patternModeGroup_clicked", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"editPositionGroup_clicked", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"bpm_valueChanged", 1, param_slot_9 };
    static const QUMethod slot_10 = {"updateGui", 0, 0 };
    static const QUMethod slot_11 = {"writeButton_clicked", 0, 0 };
    static const QUMethod slot_12 = {"loadButton_clicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "muteParts_toggled(bool)", &slot_0, QMetaData::Public },
	{ "stepModeGroup_clicked(int)", &slot_1, QMetaData::Public },
	{ "synthParts_clicked(int)", &slot_2, QMetaData::Public },
	{ "dataDial_valueChanged(int)", &slot_3, QMetaData::Public },
	{ "sequence_clicked(int)", &slot_4, QMetaData::Public },
	{ "drumParts_clicked(int)", &slot_5, QMetaData::Public },
	{ "play_toggled(bool)", &slot_6, QMetaData::Public },
	{ "patternModeGroup_clicked(int)", &slot_7, QMetaData::Public },
	{ "editPositionGroup_clicked(int)", &slot_8, QMetaData::Public },
	{ "bpm_valueChanged(int)", &slot_9, QMetaData::Public },
	{ "updateGui()", &slot_10, QMetaData::Public },
	{ "writeButton_clicked()", &slot_11, QMetaData::Public },
	{ "loadButton_clicked()", &slot_12, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"stepsequencerWidget", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_stepsequencerWidget.setMetaObject( metaObj );
    return metaObj;
}

void* stepsequencerWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "stepsequencerWidget" ) )
	return this;
    return stepsequencerWidgetBase::qt_cast( clname );
}

bool stepsequencerWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: muteParts_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 1: stepModeGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 2: synthParts_clicked((int)static_QUType_int.get(_o+1)); break;
    case 3: dataDial_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 4: sequence_clicked((int)static_QUType_int.get(_o+1)); break;
    case 5: drumParts_clicked((int)static_QUType_int.get(_o+1)); break;
    case 6: play_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 7: patternModeGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 8: editPositionGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 9: bpm_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 10: updateGui(); break;
    case 11: writeButton_clicked(); break;
    case 12: loadButton_clicked(); break;
    default:
	return stepsequencerWidgetBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool stepsequencerWidget::qt_emit( int _id, QUObject* _o )
{
    return stepsequencerWidgetBase::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool stepsequencerWidget::qt_property( int id, int f, QVariant* v)
{
    return stepsequencerWidgetBase::qt_property( id, f, v);
}

bool stepsequencerWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
