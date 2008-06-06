/****************************************************************************
** Form implementation generated from reading ui file 'stepsequencerwidgetbase.ui'
**
** Created: Sat Jun 7 11:02:13 2008
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "stepsequencerwidgetbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qtoolbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qdial.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a stepsequencerWidgetBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
stepsequencerWidgetBase::stepsequencerWidgetBase( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "stepsequencerwidgetbase" );
    stepsequencerwidgetbaseLayout = new QVBoxLayout( this, 11, 6, "stepsequencerwidgetbaseLayout"); 

    frame4 = new QFrame( this, "frame4" );
    frame4->setFrameShape( QFrame::StyledPanel );
    frame4->setFrameShadow( QFrame::Raised );
    frame4Layout = new QHBoxLayout( frame4, 11, 6, "frame4Layout"); 

    frame5_2 = new QFrame( frame4, "frame5_2" );
    frame5_2->setFrameShape( QFrame::StyledPanel );
    frame5_2->setFrameShadow( QFrame::Raised );
    frame5_2Layout = new QVBoxLayout( frame5_2, 11, 6, "frame5_2Layout"); 

    frame12_2 = new QFrame( frame5_2, "frame12_2" );
    frame12_2->setFrameShape( QFrame::StyledPanel );
    frame12_2->setFrameShadow( QFrame::Raised );
    frame12_2Layout = new QHBoxLayout( frame12_2, 11, 6, "frame12_2Layout"); 

    textLabel1 = new QLabel( frame12_2, "textLabel1" );
    frame12_2Layout->addWidget( textLabel1 );

    bpm = new QSpinBox( frame12_2, "bpm" );
    bpm->setMaxValue( 300 );
    bpm->setValue( 120 );
    frame12_2Layout->addWidget( bpm );
    frame5_2Layout->addWidget( frame12_2 );

    writeButton = new QToolButton( frame5_2, "writeButton" );
    QFont writeButton_font(  writeButton->font() );
    writeButton->setFont( writeButton_font ); 
    frame5_2Layout->addWidget( writeButton );
    frame4Layout->addWidget( frame5_2 );

    frame7 = new QFrame( frame4, "frame7" );
    frame7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, frame7->sizePolicy().hasHeightForWidth() ) );
    frame7->setFrameShape( QFrame::StyledPanel );
    frame7->setFrameShadow( QFrame::Raised );
    frame7Layout = new QVBoxLayout( frame7, 11, 6, "frame7Layout"); 

    play = new QToolButton( frame7, "play" );
    play->setToggleButton( TRUE );
    frame7Layout->addWidget( play );

    frame6 = new QFrame( frame7, "frame6" );
    frame6->setFrameShape( QFrame::StyledPanel );
    frame6->setFrameShadow( QFrame::Raised );
    frame6Layout = new QHBoxLayout( frame6, 11, 6, "frame6Layout"); 

    patternModeGroup = new QButtonGroup( frame6, "patternModeGroup" );
    patternModeGroup->setExclusive( TRUE );
    patternModeGroup->setProperty( "selectedId", 2 );
    patternModeGroup->setColumnLayout(0, Qt::Vertical );
    patternModeGroup->layout()->setSpacing( 6 );
    patternModeGroup->layout()->setMargin( 11 );
    patternModeGroupLayout = new QVBoxLayout( patternModeGroup->layout() );
    patternModeGroupLayout->setAlignment( Qt::AlignTop );

    radioButton3 = new QRadioButton( patternModeGroup, "radioButton3" );
    patternModeGroup->insert( radioButton3, 0 );
    patternModeGroupLayout->addWidget( radioButton3 );

    radioButton4 = new QRadioButton( patternModeGroup, "radioButton4" );
    patternModeGroupLayout->addWidget( radioButton4 );

    radioButton22 = new QRadioButton( patternModeGroup, "radioButton22" );
    radioButton22->setChecked( TRUE );
    patternModeGroupLayout->addWidget( radioButton22 );
    frame6Layout->addWidget( patternModeGroup );

    stepModeGroup = new QButtonGroup( frame6, "stepModeGroup" );
    stepModeGroup->setEnabled( TRUE );
    stepModeGroup->setExclusive( TRUE );
    stepModeGroup->setProperty( "selectedId", 0 );
    stepModeGroup->setColumnLayout(0, Qt::Vertical );
    stepModeGroup->layout()->setSpacing( 6 );
    stepModeGroup->layout()->setMargin( 11 );
    stepModeGroupLayout = new QVBoxLayout( stepModeGroup->layout() );
    stepModeGroupLayout->setAlignment( Qt::AlignTop );

    note = new QRadioButton( stepModeGroup, "note" );
    note->setChecked( TRUE );
    stepModeGroupLayout->addWidget( note );

    length = new QRadioButton( stepModeGroup, "length" );
    stepModeGroupLayout->addWidget( length );

    radioButton61 = new QRadioButton( stepModeGroup, "radioButton61" );
    stepModeGroupLayout->addWidget( radioButton61 );

    radioButton24 = new QRadioButton( stepModeGroup, "radioButton24" );
    stepModeGroupLayout->addWidget( radioButton24 );
    frame6Layout->addWidget( stepModeGroup );

    dataDisplay = new QLabel( frame6, "dataDisplay" );
    dataDisplay->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, dataDisplay->sizePolicy().hasHeightForWidth() ) );
    dataDisplay->setMinimumSize( QSize( 200, 100 ) );
    dataDisplay->setMaximumSize( QSize( 200, 100 ) );
    dataDisplay->setPaletteForegroundColor( QColor( 200, 255, 89 ) );
    dataDisplay->setPaletteBackgroundColor( QColor( 20, 42, 0 ) );
    QFont dataDisplay_font(  dataDisplay->font() );
    dataDisplay_font.setFamily( "Bitstream Vera Sans" );
    dataDisplay_font.setPointSize( 36 );
    dataDisplay_font.setBold( TRUE );
    dataDisplay_font.setItalic( TRUE );
    dataDisplay->setFont( dataDisplay_font ); 
    dataDisplay->setFrameShape( QLabel::Box );
    dataDisplay->setFrameShadow( QLabel::Raised );
    frame6Layout->addWidget( dataDisplay );

    dataDial = new QDial( frame6, "dataDial" );
    dataDial->setWrapping( TRUE );
    dataDial->setNotchTarget( 12 );
    dataDial->setNotchesVisible( TRUE );
    dataDial->setMaxValue( 127 );
    dataDial->setLineStep( 12 );
    dataDial->setPageStep( 36 );
    frame6Layout->addWidget( dataDial );
    frame7Layout->addWidget( frame6 );
    frame4Layout->addWidget( frame7 );
    stepsequencerwidgetbaseLayout->addWidget( frame4 );

    frame9 = new QFrame( this, "frame9" );
    frame9->setFrameShape( QFrame::StyledPanel );
    frame9->setFrameShadow( QFrame::Raised );
    frame9Layout = new QHBoxLayout( frame9, 11, 6, "frame9Layout"); 

    synthParts = new QButtonGroup( frame9, "synthParts" );
    synthParts->setExclusive( TRUE );
    synthParts->setColumnLayout(0, Qt::Vertical );
    synthParts->layout()->setSpacing( 6 );
    synthParts->layout()->setMargin( 11 );
    synthPartsLayout = new QHBoxLayout( synthParts->layout() );
    synthPartsLayout->setAlignment( Qt::AlignTop );

    synthPart1 = new QToolButton( synthParts, "synthPart1" );
    synthPart1->setMinimumSize( QSize( 0, 50 ) );
    synthPart1->setMaximumSize( QSize( 40, 32767 ) );
    synthPart1->setToggleButton( TRUE );
    synthPart1->setOn( TRUE );
    synthPartsLayout->addWidget( synthPart1 );

    synthPart2 = new QToolButton( synthParts, "synthPart2" );
    synthPart2->setMaximumSize( QSize( 40, 32767 ) );
    synthPart2->setToggleButton( TRUE );
    synthPartsLayout->addWidget( synthPart2 );

    synthPart3 = new QToolButton( synthParts, "synthPart3" );
    synthPart3->setMaximumSize( QSize( 40, 32767 ) );
    synthPart3->setToggleButton( TRUE );
    synthPartsLayout->addWidget( synthPart3 );

    synthPart4 = new QToolButton( synthParts, "synthPart4" );
    synthPart4->setMaximumSize( QSize( 40, 32767 ) );
    synthPart4->setToggleButton( TRUE );
    synthPartsLayout->addWidget( synthPart4 );
    frame9Layout->addWidget( synthParts );

    drumParts = new QButtonGroup( frame9, "drumParts" );
    drumParts->setExclusive( TRUE );
    drumParts->setColumnLayout(0, Qt::Vertical );
    drumParts->layout()->setSpacing( 6 );
    drumParts->layout()->setMargin( 11 );
    drumPartsLayout = new QHBoxLayout( drumParts->layout() );
    drumPartsLayout->setAlignment( Qt::AlignTop );

    toolButton59 = new QToolButton( drumParts, "toolButton59" );
    toolButton59->setMinimumSize( QSize( 0, 50 ) );
    toolButton59->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59 );

    toolButton59_2 = new QToolButton( drumParts, "toolButton59_2" );
    toolButton59_2->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_2->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_2 );

    toolButton59_3 = new QToolButton( drumParts, "toolButton59_3" );
    toolButton59_3->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3 );

    toolButton59_3_2 = new QToolButton( drumParts, "toolButton59_3_2" );
    toolButton59_3_2->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3_2->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3_2 );

    toolButton59_3_3 = new QToolButton( drumParts, "toolButton59_3_3" );
    toolButton59_3_3->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3_3->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3_3 );

    toolButton59_3_4 = new QToolButton( drumParts, "toolButton59_3_4" );
    toolButton59_3_4->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3_4->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3_4 );

    toolButton59_3_5 = new QToolButton( drumParts, "toolButton59_3_5" );
    toolButton59_3_5->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3_5->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3_5 );

    toolButton59_3_6 = new QToolButton( drumParts, "toolButton59_3_6" );
    toolButton59_3_6->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3_6->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3_6 );

    toolButton59_3_7 = new QToolButton( drumParts, "toolButton59_3_7" );
    toolButton59_3_7->setMaximumSize( QSize( 40, 32767 ) );
    toolButton59_3_7->setToggleButton( TRUE );
    drumPartsLayout->addWidget( toolButton59_3_7 );
    frame9Layout->addWidget( drumParts );
    stepsequencerwidgetbaseLayout->addWidget( frame9 );

    frame5 = new QFrame( this, "frame5" );
    frame5->setFrameShape( QFrame::StyledPanel );
    frame5->setFrameShadow( QFrame::Raised );
    frame5Layout = new QVBoxLayout( frame5, 11, 6, "frame5Layout"); 

    frame10 = new QFrame( frame5, "frame10" );
    frame10->setFrameShape( QFrame::StyledPanel );
    frame10->setFrameShadow( QFrame::Raised );
    frame10Layout = new QHBoxLayout( frame10, 11, 6, "frame10Layout"); 

    frame11 = new QFrame( frame10, "frame11" );
    frame11->setFrameShape( QFrame::MShape );
    frame11->setFrameShadow( QFrame::Plain );
    frame11Layout = new QVBoxLayout( frame11, 11, 6, "frame11Layout"); 

    playPositionGroup = new QButtonGroup( frame11, "playPositionGroup" );
    playPositionGroup->setLineWidth( 1 );
    playPositionGroup->setExclusive( TRUE );
    playPositionGroup->setColumnLayout(0, Qt::Vertical );
    playPositionGroup->layout()->setSpacing( 6 );
    playPositionGroup->layout()->setMargin( 11 );
    playPositionGroupLayout = new QHBoxLayout( playPositionGroup->layout() );
    playPositionGroupLayout->setAlignment( Qt::AlignTop );

    radioButton5_2 = new QRadioButton( playPositionGroup, "radioButton5_2" );
    radioButton5_2->setChecked( TRUE );
    playPositionGroupLayout->addWidget( radioButton5_2 );

    radioButton6_2 = new QRadioButton( playPositionGroup, "radioButton6_2" );
    playPositionGroupLayout->addWidget( radioButton6_2 );

    radioButton7_2 = new QRadioButton( playPositionGroup, "radioButton7_2" );
    playPositionGroupLayout->addWidget( radioButton7_2 );

    radioButton8_2 = new QRadioButton( playPositionGroup, "radioButton8_2" );
    playPositionGroupLayout->addWidget( radioButton8_2 );

    radioButton9_2 = new QRadioButton( playPositionGroup, "radioButton9_2" );
    playPositionGroupLayout->addWidget( radioButton9_2 );

    radioButton10_2 = new QRadioButton( playPositionGroup, "radioButton10_2" );
    playPositionGroupLayout->addWidget( radioButton10_2 );

    radioButton11_2 = new QRadioButton( playPositionGroup, "radioButton11_2" );
    playPositionGroupLayout->addWidget( radioButton11_2 );

    radioButton12_2 = new QRadioButton( playPositionGroup, "radioButton12_2" );
    playPositionGroupLayout->addWidget( radioButton12_2 );
    frame11Layout->addWidget( playPositionGroup );

    editPositionGroup = new QButtonGroup( frame11, "editPositionGroup" );
    editPositionGroup->setExclusive( TRUE );
    editPositionGroup->setColumnLayout(0, Qt::Vertical );
    editPositionGroup->layout()->setSpacing( 6 );
    editPositionGroup->layout()->setMargin( 11 );
    editPositionGroupLayout = new QHBoxLayout( editPositionGroup->layout() );
    editPositionGroupLayout->setAlignment( Qt::AlignTop );

    radioButton5 = new QRadioButton( editPositionGroup, "radioButton5" );
    radioButton5->setChecked( TRUE );
    editPositionGroupLayout->addWidget( radioButton5 );

    radioButton6 = new QRadioButton( editPositionGroup, "radioButton6" );
    editPositionGroupLayout->addWidget( radioButton6 );

    radioButton7 = new QRadioButton( editPositionGroup, "radioButton7" );
    editPositionGroupLayout->addWidget( radioButton7 );

    radioButton8 = new QRadioButton( editPositionGroup, "radioButton8" );
    editPositionGroupLayout->addWidget( radioButton8 );

    radioButton9 = new QRadioButton( editPositionGroup, "radioButton9" );
    editPositionGroupLayout->addWidget( radioButton9 );

    radioButton10 = new QRadioButton( editPositionGroup, "radioButton10" );
    editPositionGroupLayout->addWidget( radioButton10 );

    radioButton11 = new QRadioButton( editPositionGroup, "radioButton11" );
    editPositionGroupLayout->addWidget( radioButton11 );

    radioButton12 = new QRadioButton( editPositionGroup, "radioButton12" );
    editPositionGroupLayout->addWidget( radioButton12 );
    frame11Layout->addWidget( editPositionGroup );
    frame10Layout->addWidget( frame11 );

    frame12 = new QFrame( frame10, "frame12" );
    frame12->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, frame12->sizePolicy().hasHeightForWidth() ) );
    frame12->setFrameShape( QFrame::StyledPanel );
    frame12->setFrameShadow( QFrame::Raised );

    muteParts = new QCheckBox( frame12, "muteParts" );
    muteParts->setGeometry( QRect( 9, 13, 77, 20 ) );
    frame10Layout->addWidget( frame12 );
    frame5Layout->addWidget( frame10 );

    sequenceGroup = new QButtonGroup( frame5, "sequenceGroup" );
    sequenceGroup->setExclusive( TRUE );
    sequenceGroup->setColumnLayout(0, Qt::Vertical );
    sequenceGroup->layout()->setSpacing( 6 );
    sequenceGroup->layout()->setMargin( 11 );
    sequenceGroupLayout = new QHBoxLayout( sequenceGroup->layout() );
    sequenceGroupLayout->setAlignment( Qt::AlignTop );

    step01 = new QToolButton( sequenceGroup, "step01" );
    step01->setMinimumSize( QSize( 0, 50 ) );
    step01->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step01 );

    step02 = new QToolButton( sequenceGroup, "step02" );
    step02->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step02 );

    step03 = new QToolButton( sequenceGroup, "step03" );
    step03->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step03 );

    step04 = new QToolButton( sequenceGroup, "step04" );
    step04->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step04 );

    step05 = new QToolButton( sequenceGroup, "step05" );
    step05->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step05 );

    step06 = new QToolButton( sequenceGroup, "step06" );
    step06->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step06 );

    step07 = new QToolButton( sequenceGroup, "step07" );
    step07->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step07 );

    step08 = new QToolButton( sequenceGroup, "step08" );
    step08->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step08 );

    step09 = new QToolButton( sequenceGroup, "step09" );
    step09->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step09 );

    step10 = new QToolButton( sequenceGroup, "step10" );
    step10->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step10 );

    step11 = new QToolButton( sequenceGroup, "step11" );
    step11->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step11 );

    step12 = new QToolButton( sequenceGroup, "step12" );
    step12->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step12 );

    step13 = new QToolButton( sequenceGroup, "step13" );
    step13->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step13 );

    step14 = new QToolButton( sequenceGroup, "step14" );
    step14->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step14 );

    step15 = new QToolButton( sequenceGroup, "step15" );
    step15->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step15 );

    step16 = new QToolButton( sequenceGroup, "step16" );
    step16->setToggleButton( TRUE );
    sequenceGroupLayout->addWidget( step16 );
    frame5Layout->addWidget( sequenceGroup );
    stepsequencerwidgetbaseLayout->addWidget( frame5 );
    languageChange();
    resize( QSize(965, 609).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( bpm, SIGNAL( valueChanged(int) ), this, SLOT( bpm_valueChanged(int) ) );
    connect( play, SIGNAL( toggled(bool) ), this, SLOT( play_toggled(bool) ) );
    connect( sequenceGroup, SIGNAL( clicked(int) ), this, SLOT( sequence_clicked(int) ) );
    connect( dataDial, SIGNAL( valueChanged(int) ), this, SLOT( dataDial_valueChanged(int) ) );
    connect( stepModeGroup, SIGNAL( clicked(int) ), this, SLOT( stepModeGroup_clicked(int) ) );
    connect( muteParts, SIGNAL( toggled(bool) ), this, SLOT( muteParts_toggled(bool) ) );
    connect( editPositionGroup, SIGNAL( clicked(int) ), this, SLOT( editPositionGroup_clicked(int) ) );
    connect( patternModeGroup, SIGNAL( clicked(int) ), this, SLOT( patternModeGroup_clicked(int) ) );
    connect( drumParts, SIGNAL( clicked(int) ), this, SLOT( drumParts_clicked(int) ) );
    connect( synthParts, SIGNAL( clicked(int) ), this, SLOT( synthParts_clicked(int) ) );
    connect( writeButton, SIGNAL( clicked() ), this, SLOT( writeButton_clicked() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
stepsequencerWidgetBase::~stepsequencerWidgetBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void stepsequencerWidgetBase::languageChange()
{
    setCaption( tr( "stepsequencerwidgetbase" ) );
    textLabel1->setText( tr( "BPM" ) );
    writeButton->setText( tr( "write bank" ) );
    play->setText( tr( "Pl&ay" ) );
    play->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    patternModeGroup->setTitle( tr( "Pattern" ) );
    radioButton3->setText( tr( "p&atch" ) );
    radioButton3->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    radioButton4->setText( tr( "channel" ) );
    radioButton4->setAccel( QKeySequence( QString::null ) );
    radioButton22->setText( tr( "length" ) );
    radioButton22->setAccel( QKeySequence( QString::null ) );
    stepModeGroup->setTitle( tr( "Step" ) );
    note->setText( tr( "on/off" ) );
    note->setAccel( QKeySequence( QString::null ) );
    length->setText( tr( "note" ) );
    length->setAccel( QKeySequence( QString::null ) );
    radioButton61->setText( tr( "length" ) );
    radioButton24->setText( tr( "velocit&y" ) );
    dataDisplay->setText( tr( "kTribe" ) );
    synthParts->setTitle( tr( "synthParts" ) );
    synthPart1->setText( tr( "1" ) );
    synthPart2->setText( tr( "2" ) );
    synthPart3->setText( tr( "3" ) );
    synthPart4->setText( tr( "4" ) );
    drumParts->setTitle( tr( "drumParts" ) );
    toolButton59->setText( tr( "1" ) );
    toolButton59_2->setText( tr( "2" ) );
    toolButton59_3->setText( tr( "3" ) );
    toolButton59_3_2->setText( tr( "4" ) );
    toolButton59_3_3->setText( tr( "5" ) );
    toolButton59_3_4->setText( tr( "6" ) );
    toolButton59_3_5->setText( tr( "7" ) );
    toolButton59_3_6->setText( tr( "8" ) );
    toolButton59_3_7->setText( tr( "A" ) );
    playPositionGroup->setTitle( tr( "playPosition" ) );
    radioButton5_2->setText( tr( "&1" ) );
    radioButton5_2->setAccel( QKeySequence( tr( "Alt+1" ) ) );
    radioButton6_2->setText( tr( "&2" ) );
    radioButton6_2->setAccel( QKeySequence( tr( "Alt+2" ) ) );
    radioButton7_2->setText( tr( "&3" ) );
    radioButton7_2->setAccel( QKeySequence( tr( "Alt+3" ) ) );
    radioButton8_2->setText( tr( "&4" ) );
    radioButton8_2->setAccel( QKeySequence( tr( "Alt+4" ) ) );
    radioButton9_2->setText( tr( "&5" ) );
    radioButton9_2->setAccel( QKeySequence( tr( "Alt+5" ) ) );
    radioButton10_2->setText( tr( "&6" ) );
    radioButton10_2->setAccel( QKeySequence( tr( "Alt+6" ) ) );
    radioButton11_2->setText( tr( "&7" ) );
    radioButton11_2->setAccel( QKeySequence( tr( "Alt+7" ) ) );
    radioButton12_2->setText( tr( "&8" ) );
    radioButton12_2->setAccel( QKeySequence( tr( "Alt+8" ) ) );
    editPositionGroup->setTitle( tr( "editPosition" ) );
    radioButton5->setText( tr( "&1" ) );
    radioButton5->setAccel( QKeySequence( tr( "Alt+1" ) ) );
    radioButton6->setText( tr( "&2" ) );
    radioButton6->setAccel( QKeySequence( tr( "Alt+2" ) ) );
    radioButton7->setText( tr( "&3" ) );
    radioButton7->setAccel( QKeySequence( tr( "Alt+3" ) ) );
    radioButton8->setText( tr( "&4" ) );
    radioButton8->setAccel( QKeySequence( tr( "Alt+4" ) ) );
    radioButton9->setText( tr( "&5" ) );
    radioButton9->setAccel( QKeySequence( tr( "Alt+5" ) ) );
    radioButton10->setText( tr( "&6" ) );
    radioButton10->setAccel( QKeySequence( tr( "Alt+6" ) ) );
    radioButton11->setText( tr( "&7" ) );
    radioButton11->setAccel( QKeySequence( tr( "Alt+7" ) ) );
    radioButton12->setText( tr( "&8" ) );
    radioButton12->setAccel( QKeySequence( tr( "Alt+8" ) ) );
    muteParts->setText( tr( "mute" ) );
    sequenceGroup->setTitle( tr( "sequence" ) );
    step01->setText( tr( "01" ) );
    step02->setText( tr( "02" ) );
    step03->setText( tr( "03" ) );
    step04->setText( tr( "04" ) );
    step05->setText( tr( "05" ) );
    step06->setText( tr( "06" ) );
    step07->setText( tr( "07" ) );
    step08->setText( tr( "08" ) );
    step09->setText( tr( "09" ) );
    step10->setText( tr( "10" ) );
    step11->setText( tr( "11" ) );
    step12->setText( tr( "12" ) );
    step13->setText( tr( "13" ) );
    step14->setText( tr( "14" ) );
    step15->setText( tr( "15" ) );
    step16->setText( tr( "16" ) );
}

void stepsequencerWidgetBase::bpm_valueChanged(int)
{
    qWarning( "stepsequencerWidgetBase::bpm_valueChanged(int): Not implemented yet" );
}

void stepsequencerWidgetBase::play_toggled(bool)
{
    qWarning( "stepsequencerWidgetBase::play_toggled(bool): Not implemented yet" );
}

void stepsequencerWidgetBase::sequence_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::sequence_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::dial2_valueChanged(int)
{
    qWarning( "stepsequencerWidgetBase::dial2_valueChanged(int): Not implemented yet" );
}

void stepsequencerWidgetBase::dataDial_valueChanged(int)
{
    qWarning( "stepsequencerWidgetBase::dataDial_valueChanged(int): Not implemented yet" );
}

void stepsequencerWidgetBase::stepMode_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::stepMode_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::synthParts_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::synthParts_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::stepModeGroup_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::stepModeGroup_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::muteParts_toggled(bool)
{
    qWarning( "stepsequencerWidgetBase::muteParts_toggled(bool): Not implemented yet" );
}

void stepsequencerWidgetBase::updateGui()
{
    qWarning( "stepsequencerWidgetBase::updateGui(): Not implemented yet" );
}

void stepsequencerWidgetBase::editPositionGroup_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::editPositionGroup_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::patternModeGroup_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::patternModeGroup_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::drumPartGroup_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::drumPartGroup_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::drumParts_clicked(int)
{
    qWarning( "stepsequencerWidgetBase::drumParts_clicked(int): Not implemented yet" );
}

void stepsequencerWidgetBase::toolButton31_clicked()
{
    qWarning( "stepsequencerWidgetBase::toolButton31_clicked(): Not implemented yet" );
}

void stepsequencerWidgetBase::writeButton_clicked()
{
    qWarning( "stepsequencerWidgetBase::writeButton_clicked(): Not implemented yet" );
}

void stepsequencerWidgetBase::loadButton_clicked()
{
    qWarning( "stepsequencerWidgetBase::loadButton_clicked(): Not implemented yet" );
}

