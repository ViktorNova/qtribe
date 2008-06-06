/****************************************************************************
** Form interface generated from reading ui file 'stepsequencerwidgetbase.ui'
**
** Created: Sat Jun 7 11:02:08 2008
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef STEPSEQUENCERWIDGETBASE_H
#define STEPSEQUENCERWIDGETBASE_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QSpinBox;
class QToolButton;
class QButtonGroup;
class QRadioButton;
class QDial;
class QCheckBox;

class stepsequencerWidgetBase : public QWidget
{
    Q_OBJECT

public:
    stepsequencerWidgetBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~stepsequencerWidgetBase();

    QFrame* frame4;
    QFrame* frame5_2;
    QFrame* frame12_2;
    QLabel* textLabel1;
    QSpinBox* bpm;
    QToolButton* writeButton;
    QFrame* frame7;
    QToolButton* play;
    QFrame* frame6;
    QButtonGroup* patternModeGroup;
    QRadioButton* radioButton3;
    QRadioButton* radioButton4;
    QRadioButton* radioButton22;
    QButtonGroup* stepModeGroup;
    QRadioButton* note;
    QRadioButton* length;
    QRadioButton* radioButton61;
    QRadioButton* radioButton24;
    QLabel* dataDisplay;
    QDial* dataDial;
    QFrame* frame9;
    QButtonGroup* synthParts;
    QToolButton* synthPart1;
    QToolButton* synthPart2;
    QToolButton* synthPart3;
    QToolButton* synthPart4;
    QButtonGroup* drumParts;
    QToolButton* toolButton59;
    QToolButton* toolButton59_2;
    QToolButton* toolButton59_3;
    QToolButton* toolButton59_3_2;
    QToolButton* toolButton59_3_3;
    QToolButton* toolButton59_3_4;
    QToolButton* toolButton59_3_5;
    QToolButton* toolButton59_3_6;
    QToolButton* toolButton59_3_7;
    QFrame* frame5;
    QFrame* frame10;
    QFrame* frame11;
    QButtonGroup* playPositionGroup;
    QRadioButton* radioButton5_2;
    QRadioButton* radioButton6_2;
    QRadioButton* radioButton7_2;
    QRadioButton* radioButton8_2;
    QRadioButton* radioButton9_2;
    QRadioButton* radioButton10_2;
    QRadioButton* radioButton11_2;
    QRadioButton* radioButton12_2;
    QButtonGroup* editPositionGroup;
    QRadioButton* radioButton5;
    QRadioButton* radioButton6;
    QRadioButton* radioButton7;
    QRadioButton* radioButton8;
    QRadioButton* radioButton9;
    QRadioButton* radioButton10;
    QRadioButton* radioButton11;
    QRadioButton* radioButton12;
    QFrame* frame12;
    QCheckBox* muteParts;
    QButtonGroup* sequenceGroup;
    QToolButton* step01;
    QToolButton* step02;
    QToolButton* step03;
    QToolButton* step04;
    QToolButton* step05;
    QToolButton* step06;
    QToolButton* step07;
    QToolButton* step08;
    QToolButton* step09;
    QToolButton* step10;
    QToolButton* step11;
    QToolButton* step12;
    QToolButton* step13;
    QToolButton* step14;
    QToolButton* step15;
    QToolButton* step16;

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

protected:
    QVBoxLayout* stepsequencerwidgetbaseLayout;
    QHBoxLayout* frame4Layout;
    QVBoxLayout* frame5_2Layout;
    QHBoxLayout* frame12_2Layout;
    QVBoxLayout* frame7Layout;
    QHBoxLayout* frame6Layout;
    QVBoxLayout* patternModeGroupLayout;
    QVBoxLayout* stepModeGroupLayout;
    QHBoxLayout* frame9Layout;
    QHBoxLayout* synthPartsLayout;
    QHBoxLayout* drumPartsLayout;
    QVBoxLayout* frame5Layout;
    QHBoxLayout* frame10Layout;
    QVBoxLayout* frame11Layout;
    QHBoxLayout* playPositionGroupLayout;
    QHBoxLayout* editPositionGroupLayout;
    QHBoxLayout* sequenceGroupLayout;

protected slots:
    virtual void languageChange();

};

#endif // STEPSEQUENCERWIDGETBASE_H
