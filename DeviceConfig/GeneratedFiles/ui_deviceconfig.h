/********************************************************************************
** Form generated from reading UI file 'deviceconfig.ui'
**
** Created: Fri Dec 9 09:54:15 2022
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONFIG_H
#define UI_DEVICECONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIDevicesConfig
{
public:
    QTabWidget *tabWidget;
    QWidget *tabSysSet;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *comboBox_5;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_10;
    QComboBox *comboBox_6;
    QHBoxLayout *horizontalLayout_24;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_9;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_25;
    QCheckBox *cbtIOCard;
    QCheckBox *locklocation;
    QCheckBox *IsOldPlc;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QPushButton *btnAdd;
    QSpacerItem *verticalSpacer;
    QWidget *tabDevices;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label;
    QHBoxLayout *horizontalLayout_33;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *pushButton_2;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *pushButton_3;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *pushButton_4;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_15;
    QListWidget *listDevList;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *ledtID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *LE_RealID;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *LE_Station;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_17;
    QLineEdit *LE_Shuter;
    QHBoxLayout *horizontalLayout_29;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *LE_Roangle;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_20;
    QLineEdit *LE_ImageNum;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *LE_FirstTrigger;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QLineEdit *LE_SecondTrigger;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QComboBox *cbxCameraType;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QComboBox *Cb_CameraParm;
    QPushButton *pushButton;
    QPushButton *Pb_Sync;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QLineEdit *ledtDevMark;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_24;
    QComboBox *cbxCameraType_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnioSave;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRead;
    QPushButton *btnFalut;
    QPushButton *btnExport;

    void setupUi(QWidget *UIDevicesConfig)
    {
        if (UIDevicesConfig->objectName().isEmpty())
            UIDevicesConfig->setObjectName(QString::fromUtf8("UIDevicesConfig"));
        UIDevicesConfig->setWindowModality(Qt::ApplicationModal);
        UIDevicesConfig->setEnabled(true);
        UIDevicesConfig->resize(550, 550);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UIDevicesConfig->sizePolicy().hasHeightForWidth());
        UIDevicesConfig->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(UIDevicesConfig);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, 9, 532, 501));
        tabWidget->setMinimumSize(QSize(350, 350));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabSysSet = new QWidget();
        tabSysSet->setObjectName(QString::fromUtf8("tabSysSet"));
        verticalLayout_5 = new QVBoxLayout(tabSysSet);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_2 = new QLabel(tabSysSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);

        horizontalLayout_18->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_3);

        comboBox = new QComboBox(tabSysSet);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_18->addWidget(comboBox);

        horizontalLayout_18->setStretch(0, 2);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_3 = new QLabel(tabSysSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_19->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_4);

        comboBox_2 = new QComboBox(tabSysSet);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_19->addWidget(comboBox_2);

        horizontalLayout_19->setStretch(0, 2);
        horizontalLayout_19->setStretch(1, 1);
        horizontalLayout_19->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_4 = new QLabel(tabSysSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_20->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_5);

        comboBox_3 = new QComboBox(tabSysSet);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_20->addWidget(comboBox_3);

        horizontalLayout_20->setStretch(0, 2);
        horizontalLayout_20->setStretch(1, 1);
        horizontalLayout_20->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_5 = new QLabel(tabSysSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_21->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_6);

        spinBox = new QSpinBox(tabSysSet);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_21->addWidget(spinBox);

        horizontalLayout_21->setStretch(0, 2);
        horizontalLayout_21->setStretch(1, 1);
        horizontalLayout_21->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_6 = new QLabel(tabSysSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_22->addWidget(label_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_7);

        spinBox_2 = new QSpinBox(tabSysSet);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_22->addWidget(spinBox_2);

        horizontalLayout_22->setStretch(0, 2);
        horizontalLayout_22->setStretch(1, 1);
        horizontalLayout_22->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_16 = new QLabel(tabSysSet);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_23->addWidget(label_16);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_8);

        comboBox_5 = new QComboBox(tabSysSet);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        horizontalLayout_23->addWidget(comboBox_5);

        horizontalLayout_23->setStretch(0, 2);
        horizontalLayout_23->setStretch(1, 1);
        horizontalLayout_23->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_23);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        label_25 = new QLabel(tabSysSet);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_34->addWidget(label_25);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_10);

        comboBox_6 = new QComboBox(tabSysSet);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        horizontalLayout_34->addWidget(comboBox_6);

        horizontalLayout_34->setStretch(0, 2);
        horizontalLayout_34->setStretch(1, 1);
        horizontalLayout_34->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_34);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        checkBox = new QCheckBox(tabSysSet);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_24->addWidget(checkBox);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_9);

        comboBox_4 = new QComboBox(tabSysSet);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy1);
        comboBox_4->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_24->addWidget(comboBox_4);

        horizontalLayout_24->setStretch(0, 2);
        horizontalLayout_24->setStretch(1, 1);
        horizontalLayout_24->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        cbtIOCard = new QCheckBox(tabSysSet);
        cbtIOCard->setObjectName(QString::fromUtf8("cbtIOCard"));
        cbtIOCard->setEnabled(true);
        cbtIOCard->setFont(font);
        cbtIOCard->setTristate(false);

        horizontalLayout_25->addWidget(cbtIOCard);

        locklocation = new QCheckBox(tabSysSet);
        locklocation->setObjectName(QString::fromUtf8("locklocation"));
        locklocation->setEnabled(true);
        locklocation->setFont(font);
        locklocation->setTristate(false);

        horizontalLayout_25->addWidget(locklocation);

        IsOldPlc = new QCheckBox(tabSysSet);
        IsOldPlc->setObjectName(QString::fromUtf8("IsOldPlc"));

        horizontalLayout_25->addWidget(IsOldPlc);

        horizontalLayout_25->setStretch(0, 2);
        horizontalLayout_25->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_25);


        horizontalLayout_26->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        listWidget = new QListWidget(tabSysSet);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);
        listWidget->setMaximumSize(QSize(40, 300));

        verticalLayout_3->addWidget(listWidget);

        btnAdd = new QPushButton(tabSysSet);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        sizePolicy2.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy2);
        btnAdd->setMaximumSize(QSize(40, 20));

        verticalLayout_3->addWidget(btnAdd);


        horizontalLayout_26->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_26);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        tabWidget->addTab(tabSysSet, QString());
        tabDevices = new QWidget();
        tabDevices->setObjectName(QString::fromUtf8("tabDevices"));
        verticalLayout_2 = new QVBoxLayout(tabDevices);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label = new QLabel(tabDevices);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_16->addWidget(label);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(0);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(5);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        pushButton_2 = new QPushButton(tabDevices);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setMinimumSize(QSize(15, 15));
        pushButton_2->setMaximumSize(QSize(15, 15));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

        horizontalLayout_30->addWidget(pushButton_2);

        label_21 = new QLabel(tabDevices);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(50, 0));
        label_21->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setPointSize(9);
        label_21->setFont(font1);

        horizontalLayout_30->addWidget(label_21);


        horizontalLayout_33->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(5);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        pushButton_3 = new QPushButton(tabDevices);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setMinimumSize(QSize(15, 15));
        pushButton_3->setMaximumSize(QSize(15, 15));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));

        horizontalLayout_31->addWidget(pushButton_3);

        label_22 = new QLabel(tabDevices);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(50, 0));
        label_22->setMaximumSize(QSize(50, 16777215));
        label_22->setFont(font1);

        horizontalLayout_31->addWidget(label_22);


        horizontalLayout_33->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(5);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        pushButton_4 = new QPushButton(tabDevices);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setMinimumSize(QSize(15, 15));
        pushButton_4->setMaximumSize(QSize(15, 15));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout_32->addWidget(pushButton_4);

        label_23 = new QLabel(tabDevices);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(200, 0));
        label_23->setMaximumSize(QSize(200, 16777215));
        label_23->setFont(font1);

        horizontalLayout_32->addWidget(label_23);


        horizontalLayout_33->addLayout(horizontalLayout_32);


        horizontalLayout_16->addLayout(horizontalLayout_33);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_18 = new QLabel(tabDevices);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_17->addWidget(label_18);

        label_19 = new QLabel(tabDevices);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_17->addWidget(label_19);


        horizontalLayout_16->addLayout(horizontalLayout_17);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        listDevList = new QListWidget(tabDevices);
        listDevList->setObjectName(QString::fromUtf8("listDevList"));
        sizePolicy2.setHeightForWidth(listDevList->sizePolicy().hasHeightForWidth());
        listDevList->setSizePolicy(sizePolicy2);
        listDevList->setMinimumSize(QSize(80, 0));
        listDevList->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_15->addWidget(listDevList);

        frame = new QFrame(tabDevices);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 0));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_27 = new QHBoxLayout(frame);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_8);

        ledtID = new QLineEdit(frame);
        ledtID->setObjectName(QString::fromUtf8("ledtID"));

        horizontalLayout_3->addWidget(ledtID);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        LE_RealID = new QLineEdit(frame);
        LE_RealID->setObjectName(QString::fromUtf8("LE_RealID"));

        horizontalLayout_2->addWidget(LE_RealID);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        LE_Station = new QLineEdit(frame);
        LE_Station->setObjectName(QString::fromUtf8("LE_Station"));

        horizontalLayout_5->addWidget(LE_Station);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_6->addWidget(label_17);

        LE_Shuter = new QLineEdit(frame);
        LE_Shuter->setObjectName(QString::fromUtf8("LE_Shuter"));

        horizontalLayout_6->addWidget(LE_Shuter);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        LE_Roangle = new QLineEdit(frame);
        LE_Roangle->setObjectName(QString::fromUtf8("LE_Roangle"));

        horizontalLayout_13->addWidget(LE_Roangle);


        horizontalLayout_29->addLayout(horizontalLayout_13);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_28->addWidget(label_20);

        LE_ImageNum = new QLineEdit(frame);
        LE_ImageNum->setObjectName(QString::fromUtf8("LE_ImageNum"));

        horizontalLayout_28->addWidget(LE_ImageNum);


        horizontalLayout_29->addLayout(horizontalLayout_28);


        verticalLayout->addLayout(horizontalLayout_29);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_8->addWidget(label_13);

        LE_FirstTrigger = new QLineEdit(frame);
        LE_FirstTrigger->setObjectName(QString::fromUtf8("LE_FirstTrigger"));
        LE_FirstTrigger->setEnabled(true);

        horizontalLayout_8->addWidget(LE_FirstTrigger);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        LE_SecondTrigger = new QLineEdit(frame);
        LE_SecondTrigger->setObjectName(QString::fromUtf8("LE_SecondTrigger"));

        horizontalLayout_9->addWidget(LE_SecondTrigger);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_10->addWidget(label_7);

        cbxCameraType = new QComboBox(frame);
        cbxCameraType->setObjectName(QString::fromUtf8("cbxCameraType"));

        horizontalLayout_10->addWidget(cbxCameraType);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_11->addWidget(label_10);

        Cb_CameraParm = new QComboBox(frame);
        Cb_CameraParm->setObjectName(QString::fromUtf8("Cb_CameraParm"));

        horizontalLayout_11->addWidget(Cb_CameraParm);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 20));
        pushButton->setMaximumSize(QSize(40, 20));

        horizontalLayout_11->addWidget(pushButton);

        Pb_Sync = new QPushButton(frame);
        Pb_Sync->setObjectName(QString::fromUtf8("Pb_Sync"));
        Pb_Sync->setMinimumSize(QSize(40, 20));
        Pb_Sync->setMaximumSize(QSize(40, 20));

        horizontalLayout_11->addWidget(Pb_Sync);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        ledtDevMark = new QLineEdit(frame);
        ledtDevMark->setObjectName(QString::fromUtf8("ledtDevMark"));

        horizontalLayout_12->addWidget(ledtDevMark);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(80, 0));

        horizontalLayout_14->addWidget(label_24);

        cbxCameraType_2 = new QComboBox(frame);
        cbxCameraType_2->setObjectName(QString::fromUtf8("cbxCameraType_2"));
        cbxCameraType_2->setMinimumSize(QSize(100, 0));

        horizontalLayout_14->addWidget(cbxCameraType_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);

        btnioSave = new QPushButton(frame);
        btnioSave->setObjectName(QString::fromUtf8("btnioSave"));

        horizontalLayout_14->addWidget(btnioSave);


        verticalLayout->addLayout(horizontalLayout_14);


        horizontalLayout_27->addLayout(verticalLayout);


        horizontalLayout_15->addWidget(frame);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_15);

        tabWidget->addTab(tabDevices, QString());
        layoutWidget = new QWidget(UIDevicesConfig);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 516, 531, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnRead = new QPushButton(layoutWidget);
        btnRead->setObjectName(QString::fromUtf8("btnRead"));

        horizontalLayout->addWidget(btnRead);

        btnFalut = new QPushButton(layoutWidget);
        btnFalut->setObjectName(QString::fromUtf8("btnFalut"));

        horizontalLayout->addWidget(btnFalut);

        btnExport = new QPushButton(layoutWidget);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        btnExport->setEnabled(true);

        horizontalLayout->addWidget(btnExport);


        retranslateUi(UIDevicesConfig);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UIDevicesConfig);
    } // setupUi

    void retranslateUi(QWidget *UIDevicesConfig)
    {
        UIDevicesConfig->setWindowTitle(QApplication::translate("UIDevicesConfig", "Device Configuration", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UIDevicesConfig", "Sytem Name:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("UIDevicesConfig", "front", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "clamp", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "back", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("UIDevicesConfig", "IO Card Count:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("UIDevicesConfig", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "2", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("UIDevicesConfig", "Camera Count:", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("UIDevicesConfig", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "18", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("UIDevicesConfig", "Card Continue Kick\357\274\232 ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UIDevicesConfig", "Card Cumulative Kick\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("UIDevicesConfig", "Mode Name:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("UIDevicesConfig", "Light Source Type:", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("UIDevicesConfig", "Ruishi", 0, QApplication::UnicodeUTF8)
        );
        checkBox->setText(QApplication::translate("UIDevicesConfig", "Kick if roi fail", 0, QApplication::UnicodeUTF8));
        cbtIOCard->setText(QApplication::translate("UIDevicesConfig", "IO Card Enable", 0, QApplication::UnicodeUTF8));
        locklocation->setText(QApplication::translate("UIDevicesConfig", "Self localization of stress", 0, QApplication::UnicodeUTF8));
        IsOldPlc->setText(QApplication::translate("UIDevicesConfig", "isOldPlc", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("UIDevicesConfig", "PushButton", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSysSet), QApplication::translate("UIDevicesConfig", "System Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UIDevicesConfig", "Device List:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
        label_21->setText(QApplication::translate("UIDevicesConfig", "Normal", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QString());
        label_22->setText(QApplication::translate("UIDevicesConfig", "Stress", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QString());
        label_23->setText(QApplication::translate("UIDevicesConfig", "Striola", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("UIDevicesConfig", "Current Device", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("UIDevicesConfig", "10", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UIDevicesConfig", "Device ID:", 0, QApplication::UnicodeUTF8));
        ledtID->setText(QString());
        label_11->setText(QApplication::translate("UIDevicesConfig", "RealLine ID:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("UIDevicesConfig", "Station:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("UIDevicesConfig", "Camera Shuter:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("UIDevicesConfig", "Roangle:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("UIDevicesConfig", "Camera Number", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("UIDevicesConfig", "FristTrigger:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("UIDevicesConfig", "SecondTrigger:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UIDevicesConfig", "Camera Type Name:", 0, QApplication::UnicodeUTF8));
        cbxCameraType->clear();
        cbxCameraType->insertItems(0, QStringList()
         << QApplication::translate("UIDevicesConfig", "MER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "AVT", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("UIDevicesConfig", "Init File:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("UIDevicesConfig", "...", 0, QApplication::UnicodeUTF8));
        Pb_Sync->setText(QApplication::translate("UIDevicesConfig", "Sync", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("UIDevicesConfig", "Device Mark:", 0, QApplication::UnicodeUTF8));
        ledtDevMark->setText(QString());
        label_24->setText(QApplication::translate("UIDevicesConfig", "Iamge Type:", 0, QApplication::UnicodeUTF8));
        cbxCameraType_2->clear();
        cbxCameraType_2->insertItems(0, QStringList()
         << QApplication::translate("UIDevicesConfig", "Neck", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIDevicesConfig", "Bottom", 0, QApplication::UnicodeUTF8)
        );
        btnioSave->setText(QApplication::translate("UIDevicesConfig", "Save", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDevices), QApplication::translate("UIDevicesConfig", "Camera Settings", 0, QApplication::UnicodeUTF8));
        btnRead->setText(QApplication::translate("UIDevicesConfig", "Read", 0, QApplication::UnicodeUTF8));
        btnFalut->setText(QApplication::translate("UIDevicesConfig", "defalut", 0, QApplication::UnicodeUTF8));
        btnExport->setText(QApplication::translate("UIDevicesConfig", "Export", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UIDevicesConfig: public Ui_UIDevicesConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONFIG_H
