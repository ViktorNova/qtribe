/****************************************************************************
** stepsequencerWidgetBase meta object code from reading C++ file 'stepsequencerwidgetbase.h'
**
** Created: Sat Jun 7 11:02:18 2008
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "stepsequencerwidgetbase.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *stepsequencerWidgetBase::className() const
{
    return "stepsequencerWidgetBase";
}

QMetaObject *stepsequencerWidgetBase::metaObj = 0;
static QMetaObjectCleanUp cleanUp_stepsequencerWidgetBase( "stepsequencerWidgetBase", &stepsequencerWidgetBase::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString stepsequencerWidgetBase::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "stepsequencerWidgetBase", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString stepsequencerWidgetBase::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "stepsequencerWidgetBase", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* stepsequencerWidgetBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"bpm_valueChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"play_toggled", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"sequence_clicked", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"dial2_valueChanged", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"dataDial_valueChanged", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"stepMode_clicked", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"synthParts_clicked", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"stepModeGroup_clicked", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"muteParts_toggled", 1, param_slot_8 };
    static const QUMethod slot_9 = {"updateGui", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"editPositionGroup_clicked", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"patternModeGroup_clicked", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"drumPartGroup_clicked", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"drumParts_clicked", 1, param_slot_13 };
    static const QUMethod slot_14 = {"toolButton31_clicked", 0, 0 };
    static const QUMethod slot_15 = {"writeButton_clicked", 0, 0 };
    static const QUMethod slot_16 = {"loadButton_clicked", 0, 0 };
    static const QUMethod slot_17 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "bpm_valueChanged(int)", &slot_0, QMetaData::Public },
	{ "play_toggled(bool)", &slot_1, QMetaData::Public },
	{ "sequence_clicked(int)", &slot_2, QMetaData::Public },
	{ "dial2_valueChanged(int)", &slot_3, QMetaData::Public },
	{ "dataDial_valueChanged(int)", &slot_4, QMetaData::Public },
	{ "stepMode_clicked(int)", &slot_5, QMetaData::Public },
	{ "synthParts_clicked(int)", &slot_6, QMetaData::Public },
	{ "stepModeGroup_clicked(int)", &slot_7, QMetaData::Public },
	{ "muteParts_toggled(bool)", &slot_8, QMetaData::Public },
	{ "updateGui()", &slot_9, QMetaData::Public },
	{ "editPositionGroup_clicked(int)", &slot_10, QMetaData::Public },
	{ "patternModeGroup_clicked(int)", &slot_11, QMetaData::Public },
	{ "drumPartGroup_clicked(int)", &slot_12, QMetaData::Public },
	{ "drumParts_clicked(int)", &slot_13, QMetaData::Public },
	{ "toolButton31_clicked()", &slot_14, QMetaData::Public },
	{ "writeButton_clicked()", &slot_15, QMetaData::Public },
	{ "loadButton_clicked()", &slot_16, QMetaData::Public },
	{ "languageChange()", &slot_17, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"stepsequencerWidgetBase", parentObject,
	slot_tbl, 18,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_stepsequencerWidgetBase.setMetaObject( metaObj );
    return metaObj;
}

void* stepsequencerWidgetBase::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "stepsequencerWidgetBase" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool stepsequencerWidgetBase::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: bpm_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: play_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 2: sequence_clicked((int)static_QUType_int.get(_o+1)); break;
    case 3: dial2_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 4: dataDial_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 5: stepMode_clicked((int)static_QUType_int.get(_o+1)); break;
    case 6: synthParts_clicked((int)static_QUType_int.get(_o+1)); break;
    case 7: stepModeGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 8: muteParts_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 9: updateGui(); break;
    case 10: editPositionGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 11: patternModeGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 12: drumPartGroup_clicked((int)static_QUType_int.get(_o+1)); break;
    case 13: drumParts_clicked((int)static_QUType_int.get(_o+1)); break;
    case 14: toolButton31_clicked(); break;
    case 15: writeButton_clicked(); break;
    case 16: loadButton_clicked(); break;
    case 17: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool stepsequencerWidgetBase::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool stepsequencerWidgetBase::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool stepsequencerWidgetBase::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
