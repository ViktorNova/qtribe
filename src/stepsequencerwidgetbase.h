#ifndef STEPSEQUENCERWIDGETBASE_H
#define STEPSEQUENCERWIDGETBASE_H

#include <qvariant.h>


#include <Qt3Support/Q3ButtonGroup>
#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDial>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stepsequencerWidgetBase
{
public:
    QVBoxLayout *vboxLayout;
    Q3Frame *frame4;
    QHBoxLayout *hboxLayout;
    Q3Frame *frame5_2;
    QVBoxLayout *vboxLayout1;
    Q3Frame *frame7;
    QVBoxLayout *vboxLayout2;
    Q3Frame *frame13;
    QHBoxLayout *hboxLayout1;
    QToolButton *writeButton;
    Q3Frame *frame14;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel1;
    QSpinBox *bpm;
    QToolButton *record;
    QToolButton *play;
    Q3Frame *frame6;
    QHBoxLayout *hboxLayout3;
    Q3ButtonGroup *patternModeGroup;
    QVBoxLayout *vboxLayout3;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QRadioButton *radioButton22;
    Q3ButtonGroup *stepModeGroup;
    QVBoxLayout *vboxLayout4;
    QRadioButton *note;
    QRadioButton *length;
    QRadioButton *radioButton61;
    QRadioButton *radioButton24;
    QRadioButton *radioButton26;
    Q3ButtonGroup *chainGroup;
    QVBoxLayout *vboxLayout5;
    QRadioButton *radioButton24_2;
    QCheckBox *checkBox2;
    QLabel *dataDisplay;
    QDial *dataDial;
    Q3Frame *frame9;
    QHBoxLayout *hboxLayout4;
    Q3ButtonGroup *synthParts;
    QToolButton *synthPart1;
    QToolButton *synthPart2;
    QToolButton *synthPart3;
    QToolButton *synthPart4;
    Q3ButtonGroup *drumParts;
    QHBoxLayout *hboxLayout5;
    QToolButton *toolButton59;
    QToolButton *toolButton59_2;
    QToolButton *toolButton59_3;
    QToolButton *toolButton59_3_2;
    QToolButton *toolButton59_3_3;
    QToolButton *toolButton59_3_4;
    QToolButton *toolButton59_3_5;
    QToolButton *toolButton59_3_6;
    QToolButton *toolButton59_3_7;
    Q3Frame *frame5;
    QVBoxLayout *vboxLayout6;
    Q3Frame *frame10;
    QHBoxLayout *hboxLayout6;
    Q3Frame *frame11;
    QVBoxLayout *vboxLayout7;
    Q3ButtonGroup *playPositionGroup;
    QHBoxLayout *hboxLayout7;
    QRadioButton *radioButton5_2;
    QRadioButton *radioButton6_2;
    QRadioButton *radioButton7_2;
    QRadioButton *radioButton8_2;
    QRadioButton *radioButton9_2;
    QRadioButton *radioButton10_2;
    QRadioButton *radioButton11_2;
    QRadioButton *radioButton12_2;
    Q3ButtonGroup *editPositionGroup;
    QHBoxLayout *hboxLayout8;
    QRadioButton *radioButton5;
    QRadioButton *radioButton6;
    QRadioButton *radioButton7;
    QRadioButton *radioButton8;
    QRadioButton *radioButton9;
    QRadioButton *radioButton10;
    QRadioButton *radioButton11;
    QRadioButton *radioButton12;
    Q3Frame *frame12;
    QCheckBox *muteParts;
    QCheckBox *triggerOnSelect;
    QCheckBox *checkBox6;
    QCheckBox *arpOn;
    QLabel *statusline;
    Q3ButtonGroup *sequenceGroup;
    QHBoxLayout *hboxLayout9;
    QToolButton *step01;
    QToolButton *step02;
    QToolButton *step03;
    QToolButton *step04;
    QToolButton *step05;
    QToolButton *step06;
    QToolButton *step07;
    QToolButton *step08;
    QToolButton *step09;
    QToolButton *step10;
    QToolButton *step11;
    QToolButton *step12;
    QToolButton *step13;
    QToolButton *step14;
    QToolButton *step15;
    QToolButton *step16;

    void setupUi(QWidget *stepsequencerwidgetbase)
    {
        if (stepsequencerwidgetbase->objectName().isEmpty())
            stepsequencerwidgetbase->setObjectName(QString::fromUtf8("stepsequencerwidgetbase"));
        stepsequencerwidgetbase->resize(907, 512);
        vboxLayout = new QVBoxLayout(stepsequencerwidgetbase);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        frame4 = new Q3Frame(stepsequencerwidgetbase);
        frame4->setObjectName(QString::fromUtf8("frame4"));
        frame4->setFrameShape(QFrame::NoFrame);
        frame4->setFrameShadow(QFrame::Raised);
        hboxLayout = new QHBoxLayout(frame4);
        hboxLayout->setSpacing(0);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        frame5_2 = new Q3Frame(frame4);
        frame5_2->setObjectName(QString::fromUtf8("frame5_2"));
        frame5_2->setFrameShape(QFrame::NoFrame);
        frame5_2->setFrameShadow(QFrame::Raised);
        vboxLayout1 = new QVBoxLayout(frame5_2);
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));

        hboxLayout->addWidget(frame5_2);

        frame7 = new Q3Frame(frame4);
        frame7->setObjectName(QString::fromUtf8("frame7"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame7->sizePolicy().hasHeightForWidth());
        frame7->setSizePolicy(sizePolicy);
        frame7->setFrameShape(QFrame::NoFrame);
        frame7->setFrameShadow(QFrame::Raised);
        vboxLayout2 = new QVBoxLayout(frame7);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(11, 11, 11, 11);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        frame13 = new Q3Frame(frame7);
        frame13->setObjectName(QString::fromUtf8("frame13"));
        frame13->setFrameShape(QFrame::StyledPanel);
        frame13->setFrameShadow(QFrame::Raised);
        hboxLayout1 = new QHBoxLayout(frame13);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(11, 11, 11, 11);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        writeButton = new QToolButton(frame13);
        writeButton->setObjectName(QString::fromUtf8("writeButton"));
        writeButton->setMaximumSize(QSize(100, 32767));
        QFont font;
        writeButton->setFont(font);

        hboxLayout1->addWidget(writeButton);

        frame14 = new Q3Frame(frame13);
        frame14->setObjectName(QString::fromUtf8("frame14"));
        frame14->setFrameShape(QFrame::StyledPanel);
        frame14->setFrameShadow(QFrame::Raised);
        hboxLayout2 = new QHBoxLayout(frame14);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel1 = new QLabel(frame14);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1);

        bpm = new QSpinBox(frame14);
        bpm->setObjectName(QString::fromUtf8("bpm"));
        bpm->setMaximum(300);
        bpm->setValue(120);

        hboxLayout2->addWidget(bpm);


        hboxLayout1->addWidget(frame14);

        record = new QToolButton(frame13);
        record->setObjectName(QString::fromUtf8("record"));
        record->setEnabled(false);
        record->setMinimumSize(QSize(100, 40));
        record->setMaximumSize(QSize(100, 32767));

        hboxLayout1->addWidget(record);

        play = new QToolButton(frame13);
        play->setObjectName(QString::fromUtf8("play"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(1));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy1);
        play->setCheckable(true);

        hboxLayout1->addWidget(play);


        vboxLayout2->addWidget(frame13);

        frame6 = new Q3Frame(frame7);
        frame6->setObjectName(QString::fromUtf8("frame6"));
        frame6->setFrameShape(QFrame::StyledPanel);
        frame6->setFrameShadow(QFrame::Raised);
        hboxLayout3 = new QHBoxLayout(frame6);
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        patternModeGroup = new Q3ButtonGroup(frame6);
        patternModeGroup->setObjectName(QString::fromUtf8("patternModeGroup"));
        patternModeGroup->setExclusive(true);
        patternModeGroup->setProperty("selectedId", QVariant(2));
        patternModeGroup->setColumnLayout(0, Qt::Vertical);
        patternModeGroup->layout()->setSpacing(0);
        patternModeGroup->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout3 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(patternModeGroup->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout3);
        vboxLayout3->setAlignment(Qt::AlignTop);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        radioButton3 = new QRadioButton(patternModeGroup);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));
        patternModeGroup->insert(radioButton3, 0);

        vboxLayout3->addWidget(radioButton3);

        radioButton4 = new QRadioButton(patternModeGroup);
        radioButton4->setObjectName(QString::fromUtf8("radioButton4"));

        vboxLayout3->addWidget(radioButton4);

        radioButton22 = new QRadioButton(patternModeGroup);
        radioButton22->setObjectName(QString::fromUtf8("radioButton22"));
        radioButton22->setChecked(true);

        vboxLayout3->addWidget(radioButton22);


        hboxLayout3->addWidget(patternModeGroup);

        stepModeGroup = new Q3ButtonGroup(frame6);
        stepModeGroup->setObjectName(QString::fromUtf8("stepModeGroup"));
        stepModeGroup->setEnabled(true);
        stepModeGroup->setExclusive(true);
        stepModeGroup->setProperty("selectedId", QVariant(0));
        stepModeGroup->setColumnLayout(0, Qt::Vertical);
        stepModeGroup->layout()->setSpacing(0);
        stepModeGroup->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout4 = new QVBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(stepModeGroup->layout());
        if (boxlayout1)
            boxlayout1->addLayout(vboxLayout4);
        vboxLayout4->setAlignment(Qt::AlignTop);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        note = new QRadioButton(stepModeGroup);
        note->setObjectName(QString::fromUtf8("note"));
        note->setChecked(true);

        vboxLayout4->addWidget(note);

        length = new QRadioButton(stepModeGroup);
        length->setObjectName(QString::fromUtf8("length"));

        vboxLayout4->addWidget(length);

        radioButton61 = new QRadioButton(stepModeGroup);
        radioButton61->setObjectName(QString::fromUtf8("radioButton61"));

        vboxLayout4->addWidget(radioButton61);

        radioButton24 = new QRadioButton(stepModeGroup);
        radioButton24->setObjectName(QString::fromUtf8("radioButton24"));

        vboxLayout4->addWidget(radioButton24);

        radioButton26 = new QRadioButton(stepModeGroup);
        radioButton26->setObjectName(QString::fromUtf8("radioButton26"));

        vboxLayout4->addWidget(radioButton26);


        hboxLayout3->addWidget(stepModeGroup);

        chainGroup = new Q3ButtonGroup(frame6);
        chainGroup->setObjectName(QString::fromUtf8("chainGroup"));
        chainGroup->setEnabled(true);
        chainGroup->setColumnLayout(0, Qt::Vertical);
        chainGroup->layout()->setSpacing(6);
        chainGroup->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout5 = new QVBoxLayout();
        QBoxLayout *boxlayout2 = qobject_cast<QBoxLayout *>(chainGroup->layout());
        if (boxlayout2)
            boxlayout2->addLayout(vboxLayout5);
        vboxLayout5->setAlignment(Qt::AlignTop);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        radioButton24_2 = new QRadioButton(chainGroup);
        radioButton24_2->setObjectName(QString::fromUtf8("radioButton24_2"));
        radioButton24_2->setEnabled(true);

        vboxLayout5->addWidget(radioButton24_2);

        checkBox2 = new QCheckBox(chainGroup);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));

        vboxLayout5->addWidget(checkBox2);


        hboxLayout3->addWidget(chainGroup);

        dataDisplay = new QLabel(frame6);
        dataDisplay->setObjectName(QString::fromUtf8("dataDisplay"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(5));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dataDisplay->sizePolicy().hasHeightForWidth());
        dataDisplay->setSizePolicy(sizePolicy2);
        dataDisplay->setMinimumSize(QSize(200, 100));
        dataDisplay->setMaximumSize(QSize(200, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Vera Sans"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setItalic(true);
        dataDisplay->setFont(font1);
        dataDisplay->setFrameShape(QFrame::Box);
        dataDisplay->setFrameShadow(QFrame::Raised);
        dataDisplay->setWordWrap(false);

        hboxLayout3->addWidget(dataDisplay);

        dataDial = new QDial(frame6);
        dataDial->setObjectName(QString::fromUtf8("dataDial"));
        dataDial->setMinimumSize(QSize(100, 100));
        dataDial->setWrapping(true);
        dataDial->setNotchTarget(12);
        dataDial->setNotchesVisible(true);
        dataDial->setMaximum(127);
        dataDial->setSingleStep(12);
        dataDial->setPageStep(36);

        hboxLayout3->addWidget(dataDial);


        vboxLayout2->addWidget(frame6);


        hboxLayout->addWidget(frame7);


        vboxLayout->addWidget(frame4);

        frame9 = new Q3Frame(stepsequencerwidgetbase);
        frame9->setObjectName(QString::fromUtf8("frame9"));
        frame9->setFrameShape(QFrame::NoFrame);
        frame9->setFrameShadow(QFrame::Raised);
        hboxLayout4 = new QHBoxLayout(frame9);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        synthParts = new Q3ButtonGroup(frame9);
        synthParts->setObjectName(QString::fromUtf8("synthParts"));
        synthParts->setExclusive(true);
        synthPart1 = new QToolButton(synthParts);
        synthPart1->setObjectName(QString::fromUtf8("synthPart1"));
        synthPart1->setGeometry(QRect(11, 21, 40, 50));
        synthPart1->setMinimumSize(QSize(0, 50));
        synthPart1->setMaximumSize(QSize(40, 32767));
        synthPart1->setCheckable(true);
        synthPart1->setChecked(true);
        synthPart2 = new QToolButton(synthParts);
        synthPart2->setObjectName(QString::fromUtf8("synthPart2"));
        synthPart2->setGeometry(QRect(57, 21, 40, 50));
        synthPart2->setMaximumSize(QSize(40, 32767));
        synthPart2->setCheckable(true);
        synthPart3 = new QToolButton(synthParts);
        synthPart3->setObjectName(QString::fromUtf8("synthPart3"));
        synthPart3->setGeometry(QRect(103, 21, 40, 50));
        synthPart3->setMaximumSize(QSize(40, 32767));
        synthPart3->setCheckable(true);
        synthPart4 = new QToolButton(synthParts);
        synthPart4->setObjectName(QString::fromUtf8("synthPart4"));
        synthPart4->setGeometry(QRect(149, 21, 40, 50));
        synthPart4->setMaximumSize(QSize(40, 32767));
        synthPart4->setCheckable(true);

        hboxLayout4->addWidget(synthParts);

        drumParts = new Q3ButtonGroup(frame9);
        drumParts->setObjectName(QString::fromUtf8("drumParts"));
        drumParts->setExclusive(true);
        drumParts->setColumnLayout(0, Qt::Vertical);
        drumParts->layout()->setSpacing(6);
        drumParts->layout()->setContentsMargins(11, 11, 11, 11);
        hboxLayout5 = new QHBoxLayout();
        QBoxLayout *boxlayout3 = qobject_cast<QBoxLayout *>(drumParts->layout());
        if (boxlayout3)
            boxlayout3->addLayout(hboxLayout5);
        hboxLayout5->setAlignment(Qt::AlignTop);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        toolButton59 = new QToolButton(drumParts);
        toolButton59->setObjectName(QString::fromUtf8("toolButton59"));
        toolButton59->setMinimumSize(QSize(0, 50));
        toolButton59->setMaximumSize(QSize(40, 32767));
        toolButton59->setCheckable(true);

        hboxLayout5->addWidget(toolButton59);

        toolButton59_2 = new QToolButton(drumParts);
        toolButton59_2->setObjectName(QString::fromUtf8("toolButton59_2"));
        toolButton59_2->setMaximumSize(QSize(40, 32767));
        toolButton59_2->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_2);

        toolButton59_3 = new QToolButton(drumParts);
        toolButton59_3->setObjectName(QString::fromUtf8("toolButton59_3"));
        toolButton59_3->setMaximumSize(QSize(40, 32767));
        toolButton59_3->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3);

        toolButton59_3_2 = new QToolButton(drumParts);
        toolButton59_3_2->setObjectName(QString::fromUtf8("toolButton59_3_2"));
        toolButton59_3_2->setMaximumSize(QSize(40, 32767));
        toolButton59_3_2->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3_2);

        toolButton59_3_3 = new QToolButton(drumParts);
        toolButton59_3_3->setObjectName(QString::fromUtf8("toolButton59_3_3"));
        toolButton59_3_3->setMaximumSize(QSize(40, 32767));
        toolButton59_3_3->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3_3);

        toolButton59_3_4 = new QToolButton(drumParts);
        toolButton59_3_4->setObjectName(QString::fromUtf8("toolButton59_3_4"));
        toolButton59_3_4->setMaximumSize(QSize(40, 32767));
        toolButton59_3_4->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3_4);

        toolButton59_3_5 = new QToolButton(drumParts);
        toolButton59_3_5->setObjectName(QString::fromUtf8("toolButton59_3_5"));
        toolButton59_3_5->setMaximumSize(QSize(40, 32767));
        toolButton59_3_5->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3_5);

        toolButton59_3_6 = new QToolButton(drumParts);
        toolButton59_3_6->setObjectName(QString::fromUtf8("toolButton59_3_6"));
        toolButton59_3_6->setMaximumSize(QSize(40, 32767));
        toolButton59_3_6->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3_6);

        toolButton59_3_7 = new QToolButton(drumParts);
        toolButton59_3_7->setObjectName(QString::fromUtf8("toolButton59_3_7"));
        toolButton59_3_7->setMaximumSize(QSize(40, 32767));
        toolButton59_3_7->setCheckable(true);

        hboxLayout5->addWidget(toolButton59_3_7);


        hboxLayout4->addWidget(drumParts);


        vboxLayout->addWidget(frame9);

        frame5 = new Q3Frame(stepsequencerwidgetbase);
        frame5->setObjectName(QString::fromUtf8("frame5"));
        frame5->setFrameShape(QFrame::NoFrame);
        frame5->setFrameShadow(QFrame::Raised);
        vboxLayout6 = new QVBoxLayout(frame5);
        vboxLayout6->setSpacing(0);
        vboxLayout6->setContentsMargins(0, 0, 0, 0);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        frame10 = new Q3Frame(frame5);
        frame10->setObjectName(QString::fromUtf8("frame10"));
        frame10->setFrameShape(QFrame::NoFrame);
        frame10->setFrameShadow(QFrame::Plain);
        hboxLayout6 = new QHBoxLayout(frame10);
        hboxLayout6->setSpacing(6);
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        frame11 = new Q3Frame(frame10);
        frame11->setObjectName(QString::fromUtf8("frame11"));
        frame11->setFrameShadow(QFrame::Plain);
        vboxLayout7 = new QVBoxLayout(frame11);
        vboxLayout7->setSpacing(6);
        vboxLayout7->setContentsMargins(11, 11, 11, 11);
        vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
        playPositionGroup = new Q3ButtonGroup(frame11);
        playPositionGroup->setObjectName(QString::fromUtf8("playPositionGroup"));
        playPositionGroup->setFrameShape(Q3GroupBox::NoFrame);
        playPositionGroup->setLineWidth(1);
        playPositionGroup->setExclusive(true);
        playPositionGroup->setColumnLayout(0, Qt::Vertical);
        playPositionGroup->layout()->setSpacing(0);
        playPositionGroup->layout()->setContentsMargins(0, 0, 0, 0);
        hboxLayout7 = new QHBoxLayout();
        QBoxLayout *boxlayout4 = qobject_cast<QBoxLayout *>(playPositionGroup->layout());
        if (boxlayout4)
            boxlayout4->addLayout(hboxLayout7);
        hboxLayout7->setAlignment(Qt::AlignTop);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        radioButton5_2 = new QRadioButton(playPositionGroup);
        radioButton5_2->setObjectName(QString::fromUtf8("radioButton5_2"));
        radioButton5_2->setChecked(true);

        hboxLayout7->addWidget(radioButton5_2);

        radioButton6_2 = new QRadioButton(playPositionGroup);
        radioButton6_2->setObjectName(QString::fromUtf8("radioButton6_2"));

        hboxLayout7->addWidget(radioButton6_2);

        radioButton7_2 = new QRadioButton(playPositionGroup);
        radioButton7_2->setObjectName(QString::fromUtf8("radioButton7_2"));

        hboxLayout7->addWidget(radioButton7_2);

        radioButton8_2 = new QRadioButton(playPositionGroup);
        radioButton8_2->setObjectName(QString::fromUtf8("radioButton8_2"));

        hboxLayout7->addWidget(radioButton8_2);

        radioButton9_2 = new QRadioButton(playPositionGroup);
        radioButton9_2->setObjectName(QString::fromUtf8("radioButton9_2"));

        hboxLayout7->addWidget(radioButton9_2);

        radioButton10_2 = new QRadioButton(playPositionGroup);
        radioButton10_2->setObjectName(QString::fromUtf8("radioButton10_2"));

        hboxLayout7->addWidget(radioButton10_2);

        radioButton11_2 = new QRadioButton(playPositionGroup);
        radioButton11_2->setObjectName(QString::fromUtf8("radioButton11_2"));

        hboxLayout7->addWidget(radioButton11_2);

        radioButton12_2 = new QRadioButton(playPositionGroup);
        radioButton12_2->setObjectName(QString::fromUtf8("radioButton12_2"));

        hboxLayout7->addWidget(radioButton12_2);


        vboxLayout7->addWidget(playPositionGroup);

        editPositionGroup = new Q3ButtonGroup(frame11);
        editPositionGroup->setObjectName(QString::fromUtf8("editPositionGroup"));
        editPositionGroup->setFrameShape(Q3GroupBox::NoFrame);
        editPositionGroup->setExclusive(true);
        editPositionGroup->setColumnLayout(0, Qt::Vertical);
        editPositionGroup->layout()->setSpacing(0);
        editPositionGroup->layout()->setContentsMargins(0, 0, 0, 0);
        hboxLayout8 = new QHBoxLayout();
        QBoxLayout *boxlayout5 = qobject_cast<QBoxLayout *>(editPositionGroup->layout());
        if (boxlayout5)
            boxlayout5->addLayout(hboxLayout8);
        hboxLayout8->setAlignment(Qt::AlignTop);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        radioButton5 = new QRadioButton(editPositionGroup);
        radioButton5->setObjectName(QString::fromUtf8("radioButton5"));
        radioButton5->setChecked(true);

        hboxLayout8->addWidget(radioButton5);

        radioButton6 = new QRadioButton(editPositionGroup);
        radioButton6->setObjectName(QString::fromUtf8("radioButton6"));

        hboxLayout8->addWidget(radioButton6);

        radioButton7 = new QRadioButton(editPositionGroup);
        radioButton7->setObjectName(QString::fromUtf8("radioButton7"));

        hboxLayout8->addWidget(radioButton7);

        radioButton8 = new QRadioButton(editPositionGroup);
        radioButton8->setObjectName(QString::fromUtf8("radioButton8"));

        hboxLayout8->addWidget(radioButton8);

        radioButton9 = new QRadioButton(editPositionGroup);
        radioButton9->setObjectName(QString::fromUtf8("radioButton9"));

        hboxLayout8->addWidget(radioButton9);

        radioButton10 = new QRadioButton(editPositionGroup);
        radioButton10->setObjectName(QString::fromUtf8("radioButton10"));

        hboxLayout8->addWidget(radioButton10);

        radioButton11 = new QRadioButton(editPositionGroup);
        radioButton11->setObjectName(QString::fromUtf8("radioButton11"));

        hboxLayout8->addWidget(radioButton11);

        radioButton12 = new QRadioButton(editPositionGroup);
        radioButton12->setObjectName(QString::fromUtf8("radioButton12"));

        hboxLayout8->addWidget(radioButton12);


        vboxLayout7->addWidget(editPositionGroup);


        hboxLayout6->addWidget(frame11);

        frame12 = new Q3Frame(frame10);
        frame12->setObjectName(QString::fromUtf8("frame12"));
        sizePolicy.setHeightForWidth(frame12->sizePolicy().hasHeightForWidth());
        frame12->setSizePolicy(sizePolicy);
        frame12->setFrameShape(QFrame::NoFrame);
        frame12->setFrameShadow(QFrame::Raised);
        muteParts = new QCheckBox(frame12);
        muteParts->setObjectName(QString::fromUtf8("muteParts"));
        muteParts->setGeometry(QRect(10, 0, 100, 20));
        triggerOnSelect = new QCheckBox(frame12);
        triggerOnSelect->setObjectName(QString::fromUtf8("triggerOnSelect"));
        triggerOnSelect->setEnabled(false);
        triggerOnSelect->setGeometry(QRect(10, 30, 91, 21));
        checkBox6 = new QCheckBox(frame12);
        checkBox6->setObjectName(QString::fromUtf8("checkBox6"));
        checkBox6->setGeometry(QRect(110, 0, 136, 20));
        arpOn = new QCheckBox(frame12);
        arpOn->setObjectName(QString::fromUtf8("arpOn"));
        arpOn->setGeometry(QRect(110, 30, 100, 31));
        statusline = new QLabel(frame12);
        statusline->setObjectName(QString::fromUtf8("statusline"));
        statusline->setGeometry(QRect(10, 60, 550, 31));
        statusline->setWordWrap(false);

        hboxLayout6->addWidget(frame12);


        vboxLayout6->addWidget(frame10);

        sequenceGroup = new Q3ButtonGroup(frame5);
        sequenceGroup->setObjectName(QString::fromUtf8("sequenceGroup"));
        sequenceGroup->setFrameShape(Q3GroupBox::GroupBoxPanel);
        sequenceGroup->setExclusive(true);
        sequenceGroup->setColumnLayout(0, Qt::Vertical);
        sequenceGroup->layout()->setSpacing(6);
        sequenceGroup->layout()->setContentsMargins(11, 11, 11, 11);
        hboxLayout9 = new QHBoxLayout();
        QBoxLayout *boxlayout6 = qobject_cast<QBoxLayout *>(sequenceGroup->layout());
        if (boxlayout6)
            boxlayout6->addLayout(hboxLayout9);
        hboxLayout9->setAlignment(Qt::AlignTop);
        hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
        step01 = new QToolButton(sequenceGroup);
        step01->setObjectName(QString::fromUtf8("step01"));
        step01->setMinimumSize(QSize(0, 50));
        step01->setCheckable(true);

        hboxLayout9->addWidget(step01);

        step02 = new QToolButton(sequenceGroup);
        step02->setObjectName(QString::fromUtf8("step02"));
        step02->setCheckable(true);

        hboxLayout9->addWidget(step02);

        step03 = new QToolButton(sequenceGroup);
        step03->setObjectName(QString::fromUtf8("step03"));
        step03->setCheckable(true);

        hboxLayout9->addWidget(step03);

        step04 = new QToolButton(sequenceGroup);
        step04->setObjectName(QString::fromUtf8("step04"));
        step04->setCheckable(true);

        hboxLayout9->addWidget(step04);

        step05 = new QToolButton(sequenceGroup);
        step05->setObjectName(QString::fromUtf8("step05"));
        step05->setCheckable(true);

        hboxLayout9->addWidget(step05);

        step06 = new QToolButton(sequenceGroup);
        step06->setObjectName(QString::fromUtf8("step06"));
        step06->setCheckable(true);

        hboxLayout9->addWidget(step06);

        step07 = new QToolButton(sequenceGroup);
        step07->setObjectName(QString::fromUtf8("step07"));
        step07->setCheckable(true);

        hboxLayout9->addWidget(step07);

        step08 = new QToolButton(sequenceGroup);
        step08->setObjectName(QString::fromUtf8("step08"));
        step08->setCheckable(true);

        hboxLayout9->addWidget(step08);

        step09 = new QToolButton(sequenceGroup);
        step09->setObjectName(QString::fromUtf8("step09"));
        step09->setCheckable(true);

        hboxLayout9->addWidget(step09);

        step10 = new QToolButton(sequenceGroup);
        step10->setObjectName(QString::fromUtf8("step10"));
        step10->setCheckable(true);

        hboxLayout9->addWidget(step10);

        step11 = new QToolButton(sequenceGroup);
        step11->setObjectName(QString::fromUtf8("step11"));
        step11->setCheckable(true);

        hboxLayout9->addWidget(step11);

        step12 = new QToolButton(sequenceGroup);
        step12->setObjectName(QString::fromUtf8("step12"));
        step12->setCheckable(true);

        hboxLayout9->addWidget(step12);

        step13 = new QToolButton(sequenceGroup);
        step13->setObjectName(QString::fromUtf8("step13"));
        step13->setCheckable(true);

        hboxLayout9->addWidget(step13);

        step14 = new QToolButton(sequenceGroup);
        step14->setObjectName(QString::fromUtf8("step14"));
        step14->setCheckable(true);

        hboxLayout9->addWidget(step14);

        step15 = new QToolButton(sequenceGroup);
        step15->setObjectName(QString::fromUtf8("step15"));
        step15->setCheckable(true);

        hboxLayout9->addWidget(step15);

        step16 = new QToolButton(sequenceGroup);
        step16->setObjectName(QString::fromUtf8("step16"));
        step16->setCheckable(true);

        hboxLayout9->addWidget(step16);


        vboxLayout6->addWidget(sequenceGroup);


        vboxLayout->addWidget(frame5);


        retranslateUi(stepsequencerwidgetbase);
        QObject::connect(play, SIGNAL(toggled(bool)), stepsequencerwidgetbase, SLOT(play_toggled(bool)));
        QObject::connect(sequenceGroup, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(sequence_clicked(int)));
        QObject::connect(dataDial, SIGNAL(valueChanged(int)), stepsequencerwidgetbase, SLOT(dataDial_valueChanged(int)));
        QObject::connect(stepModeGroup, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(stepModeGroup_clicked(int)));
        QObject::connect(muteParts, SIGNAL(toggled(bool)), stepsequencerwidgetbase, SLOT(muteParts_toggled(bool)));
        QObject::connect(editPositionGroup, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(editPositionGroup_clicked(int)));
        QObject::connect(patternModeGroup, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(patternModeGroup_clicked(int)));
        QObject::connect(drumParts, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(drumParts_clicked(int)));
        QObject::connect(synthParts, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(synthParts_clicked(int)));
        QObject::connect(writeButton, SIGNAL(clicked()), stepsequencerwidgetbase, SLOT(writeButton_clicked()));
        QObject::connect(bpm, SIGNAL(valueChanged(int)), stepsequencerwidgetbase, SLOT(bpm_valueChanged(int)));
        QObject::connect(chainGroup, SIGNAL(clicked(int)), stepsequencerwidgetbase, SLOT(chainGroup_clicked(int)));
        QObject::connect(arpOn, SIGNAL(toggled(bool)), stepsequencerwidgetbase, SLOT(arpOn_stateChanged(bool)));

        QMetaObject::connectSlotsByName(stepsequencerwidgetbase);
    } // setupUi

    void retranslateUi(QWidget *stepsequencerwidgetbase)
    {
        stepsequencerwidgetbase->setWindowTitle(QApplication::translate("stepsequencerWidgetBase", "stepsequencerwidgetbase", 0, QApplication::UnicodeUTF8));
        writeButton->setText(QApplication::translate("stepsequencerWidgetBase", "write bank", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("stepsequencerWidgetBase", "BPM", 0, QApplication::UnicodeUTF8));
        record->setText(QApplication::translate("stepsequencerWidgetBase", "record", 0, QApplication::UnicodeUTF8));
        play->setText(QApplication::translate("stepsequencerWidgetBase", "play", 0, QApplication::UnicodeUTF8));
        play->setShortcut(QString());
        patternModeGroup->setTitle(QApplication::translate("stepsequencerWidgetBase", "Pattern", 0, QApplication::UnicodeUTF8));
        radioButton3->setText(QApplication::translate("stepsequencerWidgetBase", "p&atch", 0, QApplication::UnicodeUTF8));
        radioButton3->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+A", 0, QApplication::UnicodeUTF8));
        radioButton4->setText(QApplication::translate("stepsequencerWidgetBase", "channel", 0, QApplication::UnicodeUTF8));
        radioButton4->setShortcut(QString());
        radioButton22->setText(QApplication::translate("stepsequencerWidgetBase", "&length", 0, QApplication::UnicodeUTF8));
        radioButton22->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+L", 0, QApplication::UnicodeUTF8));
        stepModeGroup->setTitle(QApplication::translate("stepsequencerWidgetBase", "Step", 0, QApplication::UnicodeUTF8));
        note->setText(QApplication::translate("stepsequencerWidgetBase", "&on/off", 0, QApplication::UnicodeUTF8));
        note->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+O", 0, QApplication::UnicodeUTF8));
        length->setText(QApplication::translate("stepsequencerWidgetBase", "&note", 0, QApplication::UnicodeUTF8));
        length->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+N", 0, QApplication::UnicodeUTF8));
        radioButton61->setText(QApplication::translate("stepsequencerWidgetBase", "length", 0, QApplication::UnicodeUTF8));
        radioButton24->setText(QApplication::translate("stepsequencerWidgetBase", "velocit&y", 0, QApplication::UnicodeUTF8));
        radioButton26->setText(QApplication::translate("stepsequencerWidgetBase", "tonality", 0, QApplication::UnicodeUTF8));
        chainGroup->setTitle(QApplication::translate("stepsequencerWidgetBase", "Chain", 0, QApplication::UnicodeUTF8));
        radioButton24_2->setText(QApplication::translate("stepsequencerWidgetBase", "chain", 0, QApplication::UnicodeUTF8));
        checkBox2->setText(QApplication::translate("stepsequencerWidgetBase", "chain loop", 0, QApplication::UnicodeUTF8));
        dataDisplay->setText(QApplication::translate("stepsequencerWidgetBase", "qTribe", 0, QApplication::UnicodeUTF8));
        synthParts->setTitle(QApplication::translate("stepsequencerWidgetBase", "synthParts", 0, QApplication::UnicodeUTF8));
        synthPart1->setText(QApplication::translate("stepsequencerWidgetBase", "1", 0, QApplication::UnicodeUTF8));
        synthPart2->setText(QApplication::translate("stepsequencerWidgetBase", "2", 0, QApplication::UnicodeUTF8));
        synthPart3->setText(QApplication::translate("stepsequencerWidgetBase", "3", 0, QApplication::UnicodeUTF8));
        synthPart4->setText(QApplication::translate("stepsequencerWidgetBase", "4", 0, QApplication::UnicodeUTF8));
        drumParts->setTitle(QApplication::translate("stepsequencerWidgetBase", "drumParts", 0, QApplication::UnicodeUTF8));
        toolButton59->setText(QApplication::translate("stepsequencerWidgetBase", "1", 0, QApplication::UnicodeUTF8));
        toolButton59_2->setText(QApplication::translate("stepsequencerWidgetBase", "2", 0, QApplication::UnicodeUTF8));
        toolButton59_3->setText(QApplication::translate("stepsequencerWidgetBase", "3", 0, QApplication::UnicodeUTF8));
        toolButton59_3_2->setText(QApplication::translate("stepsequencerWidgetBase", "4", 0, QApplication::UnicodeUTF8));
        toolButton59_3_3->setText(QApplication::translate("stepsequencerWidgetBase", "5", 0, QApplication::UnicodeUTF8));
        toolButton59_3_4->setText(QApplication::translate("stepsequencerWidgetBase", "6", 0, QApplication::UnicodeUTF8));
        toolButton59_3_5->setText(QApplication::translate("stepsequencerWidgetBase", "7", 0, QApplication::UnicodeUTF8));
        toolButton59_3_6->setText(QApplication::translate("stepsequencerWidgetBase", "8", 0, QApplication::UnicodeUTF8));
        toolButton59_3_7->setText(QApplication::translate("stepsequencerWidgetBase", "A", 0, QApplication::UnicodeUTF8));
        playPositionGroup->setTitle(QApplication::translate("stepsequencerWidgetBase", "playPosition", 0, QApplication::UnicodeUTF8));
        radioButton5_2->setText(QApplication::translate("stepsequencerWidgetBase", "&1", 0, QApplication::UnicodeUTF8));
        radioButton5_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+1", 0, QApplication::UnicodeUTF8));
        radioButton6_2->setText(QApplication::translate("stepsequencerWidgetBase", "&2", 0, QApplication::UnicodeUTF8));
        radioButton6_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+2", 0, QApplication::UnicodeUTF8));
        radioButton7_2->setText(QApplication::translate("stepsequencerWidgetBase", "&3", 0, QApplication::UnicodeUTF8));
        radioButton7_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+3", 0, QApplication::UnicodeUTF8));
        radioButton8_2->setText(QApplication::translate("stepsequencerWidgetBase", "&4", 0, QApplication::UnicodeUTF8));
        radioButton8_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+4", 0, QApplication::UnicodeUTF8));
        radioButton9_2->setText(QApplication::translate("stepsequencerWidgetBase", "&5", 0, QApplication::UnicodeUTF8));
        radioButton9_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+5", 0, QApplication::UnicodeUTF8));
        radioButton10_2->setText(QApplication::translate("stepsequencerWidgetBase", "&6", 0, QApplication::UnicodeUTF8));
        radioButton10_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+6", 0, QApplication::UnicodeUTF8));
        radioButton11_2->setText(QApplication::translate("stepsequencerWidgetBase", "&7", 0, QApplication::UnicodeUTF8));
        radioButton11_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+7", 0, QApplication::UnicodeUTF8));
        radioButton12_2->setText(QApplication::translate("stepsequencerWidgetBase", "&8", 0, QApplication::UnicodeUTF8));
        radioButton12_2->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+8", 0, QApplication::UnicodeUTF8));
        editPositionGroup->setTitle(QApplication::translate("stepsequencerWidgetBase", "editPosition", 0, QApplication::UnicodeUTF8));
        radioButton5->setText(QApplication::translate("stepsequencerWidgetBase", "&1", 0, QApplication::UnicodeUTF8));
        radioButton5->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+1", 0, QApplication::UnicodeUTF8));
        radioButton6->setText(QApplication::translate("stepsequencerWidgetBase", "&2", 0, QApplication::UnicodeUTF8));
        radioButton6->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+2", 0, QApplication::UnicodeUTF8));
        radioButton7->setText(QApplication::translate("stepsequencerWidgetBase", "&3", 0, QApplication::UnicodeUTF8));
        radioButton7->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+3", 0, QApplication::UnicodeUTF8));
        radioButton8->setText(QApplication::translate("stepsequencerWidgetBase", "&4", 0, QApplication::UnicodeUTF8));
        radioButton8->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+4", 0, QApplication::UnicodeUTF8));
        radioButton9->setText(QApplication::translate("stepsequencerWidgetBase", "&5", 0, QApplication::UnicodeUTF8));
        radioButton9->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+5", 0, QApplication::UnicodeUTF8));
        radioButton10->setText(QApplication::translate("stepsequencerWidgetBase", "&6", 0, QApplication::UnicodeUTF8));
        radioButton10->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+6", 0, QApplication::UnicodeUTF8));
        radioButton11->setText(QApplication::translate("stepsequencerWidgetBase", "&7", 0, QApplication::UnicodeUTF8));
        radioButton11->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+7", 0, QApplication::UnicodeUTF8));
        radioButton12->setText(QApplication::translate("stepsequencerWidgetBase", "&8", 0, QApplication::UnicodeUTF8));
        radioButton12->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+8", 0, QApplication::UnicodeUTF8));
        muteParts->setText(QApplication::translate("stepsequencerWidgetBase", "part &mute", 0, QApplication::UnicodeUTF8));
        muteParts->setShortcut(QApplication::translate("stepsequencerWidgetBase", "Alt+M", 0, QApplication::UnicodeUTF8));
        triggerOnSelect->setText(QApplication::translate("stepsequencerWidgetBase", "select trig.", 0, QApplication::UnicodeUTF8));
        checkBox6->setText(QApplication::translate("stepsequencerWidgetBase", "global mute", 0, QApplication::UnicodeUTF8));
        arpOn->setText(QApplication::translate("stepsequencerWidgetBase", "arpeggiate", 0, QApplication::UnicodeUTF8));
        arpOn->setShortcut(QString());
        statusline->setText(QApplication::translate("stepsequencerWidgetBase", "Status", 0, QApplication::UnicodeUTF8));
        sequenceGroup->setTitle(QApplication::translate("stepsequencerWidgetBase", "sequence", 0, QApplication::UnicodeUTF8));
        step01->setText(QApplication::translate("stepsequencerWidgetBase", "01", 0, QApplication::UnicodeUTF8));
        step02->setText(QApplication::translate("stepsequencerWidgetBase", "02", 0, QApplication::UnicodeUTF8));
        step03->setText(QApplication::translate("stepsequencerWidgetBase", "03", 0, QApplication::UnicodeUTF8));
        step04->setText(QApplication::translate("stepsequencerWidgetBase", "04", 0, QApplication::UnicodeUTF8));
        step05->setText(QApplication::translate("stepsequencerWidgetBase", "05", 0, QApplication::UnicodeUTF8));
        step06->setText(QApplication::translate("stepsequencerWidgetBase", "06", 0, QApplication::UnicodeUTF8));
        step07->setText(QApplication::translate("stepsequencerWidgetBase", "07", 0, QApplication::UnicodeUTF8));
        step08->setText(QApplication::translate("stepsequencerWidgetBase", "08", 0, QApplication::UnicodeUTF8));
        step09->setText(QApplication::translate("stepsequencerWidgetBase", "09", 0, QApplication::UnicodeUTF8));
        step10->setText(QApplication::translate("stepsequencerWidgetBase", "10", 0, QApplication::UnicodeUTF8));
        step11->setText(QApplication::translate("stepsequencerWidgetBase", "11", 0, QApplication::UnicodeUTF8));
        step12->setText(QApplication::translate("stepsequencerWidgetBase", "12", 0, QApplication::UnicodeUTF8));
        step13->setText(QApplication::translate("stepsequencerWidgetBase", "13", 0, QApplication::UnicodeUTF8));
        step14->setText(QApplication::translate("stepsequencerWidgetBase", "14", 0, QApplication::UnicodeUTF8));
        step15->setText(QApplication::translate("stepsequencerWidgetBase", "15", 0, QApplication::UnicodeUTF8));
        step16->setText(QApplication::translate("stepsequencerWidgetBase", "16", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class stepsequencerWidgetBase: public Ui_stepsequencerWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

class stepsequencerWidgetBase : public QWidget, public Ui::stepsequencerWidgetBase
{
    Q_OBJECT

public:
    stepsequencerWidgetBase(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
    ~stepsequencerWidgetBase();

public slots:
    virtual void bpm_valueChanged(int);
    virtual void play_toggled(bool);
    virtual void sequence_clicked(int);
    virtual void dial2_valueChanged(int);
    virtual void dataDial_valueChanged(int);
    virtual void stepMode_clicked(int);
    virtual void synthParts_clicked(int);
    virtual void stepModeGroup_clicked(int);
    virtual void muteParts_toggled(bool);
    virtual void updateGui();
    virtual void editPositionGroup_clicked(int);
    virtual void patternModeGroup_clicked(int);
    virtual void drumPartGroup_clicked(int);
    virtual void drumParts_clicked(int);
    virtual void toolButton31_clicked();
    virtual void writeButton_clicked();
    virtual void loadButton_clicked();
    virtual void setMutes_clicked();
    virtual void clearMutes_clicked();
    virtual void chainGroup_clicked(int);
    virtual void arpOn_stateChanged(int);
    virtual void arpOn_stateChanged(bool);

protected slots:
    virtual void languageChange();

};

#endif // STEPSEQUENCERWIDGETBASE_H
