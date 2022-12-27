#include "DeviceConfig.h"

DeviceConfig::DeviceConfig(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//nCurrentCamIO=0;
	//qDebug()<<QCoreApplication::applicationDirPath();
	ui.tabWidget->setCurrentIndex(0);
	this->setFixedSize(550,550);
	this->setWindowIcon(QIcon(":/DeviceConfig/Resources/LOGO.ico"));
	lastWidget=0;
	initMarkAddress();
	initUIParam();
	initConnect();
	initConfig();
	insertDevList();
	AddList();
	initCameraParm();
	initRead();
}


DeviceConfig::~DeviceConfig()
{
	//initSave();
}

void DeviceConfig::initUIParam()
{
	ui.spinBox->setMinimum(2);
	ui.spinBox->setValue(2);
	ui.spinBox_2->setMinimum(1000);
	ui.spinBox_2->setValue(1000);
	ui.comboBox_3->setCurrentIndex(1);

	ui.checkBox->setChecked(true);
	ui.cbtIOCard->setChecked(true);
	ui.locklocation->setChecked(true);
}
void DeviceConfig::initConfig()
{
	m_sConfigPathInfo.m_strConfigPath = "Config/Config.ini";
	m_sConfigPathInfo.m_strModeInfoPath = "ModelInfo";
	nFictitiouCamCount = 0;
	FindModeInfo();
}
void DeviceConfig::initConnect()
{
	connect(ui.comboBox_3, SIGNAL(currentIndexChanged(int)), this, SLOT(slots_SaveMode3Changed(int)));
	connect(ui.btnAdd, SIGNAL(clicked()), this, SLOT(slots_addKicklist()));
	connect(ui.btnFalut, SIGNAL(clicked()), this, SLOT(slots_defalut()));
	connect(ui.btnExport, SIGNAL(clicked()), this, SLOT(slots_Export()));
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(slots_showCameraIOInfo(int)));
	connect(ui.listDevList, SIGNAL(currentRowChanged(int)), this, SLOT(slots_ChangeCamera(int)));
	connect(ui.btnioSave, SIGNAL(clicked()), this, SLOT(slots_CameraSave()));

	connect(ui.btnRead,SIGNAL(clicked()),this,SLOT(slots_ReadConfig()));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(slots_GetIniPath()));
	connect(ui.Pb_Sync,SIGNAL(clicked()),this,SLOT(slots_SetAll()));
	connect(ui.locklocation,SIGNAL(stateChanged(int)),this,SLOT(slots_Lock(int)));

}
//读取Mark地址
void DeviceConfig::initMarkAddress()
{
	QFile file("Config/MarkAddress.ini");
	if(!file.exists())
	{
		QMessageBox::warning(this,"Warning","Config/MarkAddress.ini not found");
		return;
	}
	QSettings m_psetting("Config/MarkAddress.ini",QSettings::IniFormat);//设置路径
	m_psetting.setIniCodec(QTextCodec::codecForName("UTF-8"));
	MarkAddress.clear();
	m_psetting.beginGroup("Mark");
	for(int i=1;1;i++)
	{
			QString key=QString("MarkAdd%1").arg(i);
			if(m_psetting.contains(key))
				MarkAddress.push_back(m_psetting.value(key).toString());
			else
				break;
	}
	m_psetting.endGroup();
}

void DeviceConfig::initRead()
{
	ReadInit("Config/Config.ini");
}


void DeviceConfig::initCameraParm()
{
	QDir dir("config/");
	QStringList list=dir.entryList();
	ui.Cb_CameraParm->clear();
	for( int i = 0; i < list.length(); i++ )    //打印目录文件
	{
		if(list[i].contains("CameraParm"))
		{
			ui.Cb_CameraParm->addItem(list[i]);
		}
	}
}

//切换设备配置
void DeviceConfig::slots_ChangeCamera(int temp)
{
	if (temp >= 0)
	{
		nCurrentCamIO = temp;
		ui.label_19->setText(QString::number(temp+1));
		ui.ledtID->setText(QString::number(nCameraIOInfo[temp].DeviceID));
		ui.LE_RealID->setText(QString::number(nCameraIOInfo[temp].RealLineID));
		ui.LE_Station->setText(QString::number(nCameraIOInfo[temp].DeviceStation));
		ui.LE_FirstTrigger->setText(QString::number(nCameraIOInfo[temp].DeviceFristTrigger));
		ui.LE_SecondTrigger->setText(QString::number(nCameraIOInfo[temp].DeviceSecondTrigger));
		for(int i=0;i<ui.Cb_CameraParm->count();i++)
		{
			if(nCameraIOInfo[temp].DeviceInitFile==ui.Cb_CameraParm->itemText(i))
			{
				ui.Cb_CameraParm->setCurrentIndex(i);
				break;
			}
		}
		//ui.ledtInitFileName->setText(nCameraIOInfo[temp].DeviceInitFile);
		ui.ledtDevMark->setText(nCameraIOInfo[temp].DeviceMark);
		ui.LE_Shuter->setText(QString::number(nCameraIOInfo[temp].DeviceShotTime));
		ui.LE_Roangle->setText(QString::number(nCameraIOInfo[temp].DeviceRoAngle));
		ui.LE_ImageNum->setText(QString::number(nCameraIOInfo[temp].DeviceImageNumber));
		nCameraIOInfo[temp].DeviceName=="AVT"?ui.cbxCameraType->setCurrentIndex(1):ui.cbxCameraType->setCurrentIndex(0);
		if(ui.comboBox_3->currentText().toInt()==4)
			nCameraIOInfo[temp].ImageType==1?ui.cbxCameraType_2->setCurrentIndex(0):ui.cbxCameraType_2->setCurrentIndex(1);
		Labels[temp]->setStyleSheet("color: rgb(255, 170, 0);");
		Labels[lastWidget]->setStyleSheet("color: rgb(0, 0, 0);");
		lastWidget=temp;
		if(nCameraIOInfo[temp].DeviceType!=2)//细条纹相机配置不可变
		{
			ui.LE_FirstTrigger->setEnabled(true);
			ui.LE_SecondTrigger->setEnabled(true);
			ui.LE_Roangle->setEnabled(true);
			ui.LE_Shuter->setEnabled(true);
			ui.LE_Station->setEnabled(true);
			ui.Cb_CameraParm->setEnabled(true);
			ui.ledtDevMark->setEnabled(true);
			ui.cbxCameraType->setEnabled(true);
			//ui.LE_RealID->setEnabled(true);
			ui.pushButton->setEnabled(true);
			ui.Pb_Sync->setEnabled(true);
			if(nCameraIOInfo[temp].DeviceType==1&&!ui.locklocation->checkState())
				ui.LE_ImageNum->setEnabled(true);
			else
				ui.LE_ImageNum->setEnabled(false);
		}
		else
		{
			ui.LE_FirstTrigger->setEnabled(false);
			ui.LE_SecondTrigger->setEnabled(false);
			ui.LE_Roangle->setEnabled(false);
			ui.LE_Shuter->setEnabled(false);
			ui.LE_Station->setEnabled(false);
			ui.Cb_CameraParm->setEnabled(false);
			ui.ledtDevMark->setEnabled(false);
			ui.cbxCameraType->setEnabled(false);
			//ui.LE_RealID->setEnabled(false);
			ui.pushButton->setEnabled(false);
			ui.Pb_Sync->setEnabled(false);
			ui.LE_ImageNum->setEnabled(false);
		}
		/*都不要啦*/
		ui.ledtID->setEnabled(false);
		ui.LE_RealID->setEnabled(false);
		ui.LE_Station->setEnabled(false);
	}
}
//保存当前设备配置
void DeviceConfig::slots_CameraSave()
{
	int temp=ui.comboBox_3->currentText().toInt();
	int diff=0;
	switch(temp)
	{
	case 12:nCurrentCamIO<6?diff=12:1;break;
	case 15:nCurrentCamIO<9?diff=15:1;break;
	case 18:nCurrentCamIO<9?diff=18:1;break;
	}
	nCameraIOInfo[nCurrentCamIO].DeviceID = ui.ledtID->text().toInt();
	nCameraIOInfo[nCurrentCamIO].RealLineID = ui.LE_RealID->text().toInt();
	nCameraIOInfo[nCurrentCamIO].DeviceStation = ui.LE_Station->text().toInt();
	nCameraIOInfo[nCurrentCamIO].DeviceFristTrigger = ui.LE_FirstTrigger->text().toInt();
	nCameraIOInfo[nCurrentCamIO].DeviceSecondTrigger = ui.LE_SecondTrigger->text().toInt();
	nCameraIOInfo[nCurrentCamIO].DeviceRoAngle = ui.LE_Roangle->text().toInt();
	nCameraIOInfo[nCurrentCamIO].DeviceInitFile = ui.Cb_CameraParm->currentText();
	nCameraIOInfo[nCurrentCamIO].DeviceMark = ui.ledtDevMark->text();
	nCameraIOInfo[nCurrentCamIO].DeviceShotTime = ui.LE_Shuter->text().toInt();
	nCameraIOInfo[nCurrentCamIO].DeviceName =ui.cbxCameraType->currentIndex()==0?"MER":"AVT";
	if(ui.comboBox_3->currentText().toInt()==4)
		nCameraIOInfo[nCurrentCamIO].ImageType =ui.cbxCameraType_2->currentIndex()==0?1:2;
	else
		nCameraIOInfo[nCurrentCamIO].ImageType=0;
	nCameraIOInfo[nCurrentCamIO].DeviceImageNumber =ui.LE_ImageNum->text().toInt();
	if(temp==4)
		return;
	//对应细条纹相机也要保存配置
	//nCameraIOInfo[nCurrentCamIO+diff].DeviceID = ui.ledtID->text().toInt();相机序号独立
	//nCameraIOInfo[nCurrentCamIO+diff].RealLineID = ui.LE_RealID->text().toInt();真实序号独立
	nCameraIOInfo[nCurrentCamIO+diff].DeviceStation = ui.LE_Station->text().toInt();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceFristTrigger = ui.LE_FirstTrigger->text().toInt();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceSecondTrigger = ui.LE_SecondTrigger->text().toInt();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceRoAngle = ui.LE_Roangle->text().toInt();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceInitFile = ui.Cb_CameraParm->currentText();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceMark = ui.ledtDevMark->text();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceShotTime = ui.LE_Shuter->text().toInt();
	nCameraIOInfo[nCurrentCamIO+diff].DeviceName =ui.cbxCameraType->currentIndex()==0?"MER":"AVT";
	//nCameraIOInfo[nCurrentCamIO].DeviceImageNumber =ui.LE_ImageNum->text().toInt();对应图像号独立
}
//读取功能
void DeviceConfig::slots_ReadConfig()
{
	QString path=QFileDialog::getOpenFileName(this,"Open","Config/");
	ReadInit(path);
}
//获取配置文件路径
void DeviceConfig::slots_GetIniPath()
{
	//QFileInfo path=QFileDialog::getOpenFileName(this,"Open","Config");
	//ui.ledtInitFileName->setText(path.fileName());
	initCameraParm();
}
//同步文件配置路径
void DeviceConfig::slots_SetAll()
{
	for(int i=0;i<nCameraIOInfo.size();i++)
	{
		nCameraIOInfo[i].DeviceInitFile=ui.Cb_CameraParm->currentText();
	}
}
//应力自定位
void DeviceConfig::slots_Lock(int state)
{
	if(state)
	{
		switch(ui.comboBox_3->currentText().toInt())
		{
		case 12:
			{
				for(int i=6;i<nCameraIOInfo.size()&&i<12;i++)
					nCameraIOInfo[i].DeviceImageNumber=nCameraIOInfo[i].DeviceID;
				break;
			}
		case 15:
			{
				for(int i=9;i<nCameraIOInfo.size()&&i<15;i++)
					nCameraIOInfo[i].DeviceImageNumber=nCameraIOInfo[i].DeviceID;
				break;
			}
		case 18:
			{
				for(int i=9;i<nCameraIOInfo.size()&&i<18;i++)
					nCameraIOInfo[i].DeviceImageNumber=nCameraIOInfo[i].DeviceID;
				break;
			}
		}
	}
	else
	{
		switch(ui.comboBox_3->currentText().toInt())
		{
		case 12:
			{
				for(int i=6;i<nCameraIOInfo.size()&&i<12;i++)
					nCameraIOInfo[i].DeviceImageNumber=i-5;
				break;
			}
		case 15:
			{
				for(int i=9;i<nCameraIOInfo.size()&&i<15;i++)
					nCameraIOInfo[i].DeviceImageNumber=i-8;
				break;
			}
		case 18:
			{
				for(int i=9;i<nCameraIOInfo.size()&&i<18;i++)
					nCameraIOInfo[i].DeviceImageNumber=i-8;
				break;
			}
		}
	}
}

void DeviceConfig::slots_showCameraIOInfo(int nSheet)
{
	if(nSheet == 0){
		ui.btnFalut->setVisible(true);
	}
	else if (nSheet == 1)
	{
		ui.btnFalut->setVisible(false);
		ui.listDevList->setCurrentRow(0);
	}
}
void DeviceConfig::FindModeInfo()
{
	ui.comboBox_5->clear();
	//TEST
	QStringList nList;
	QDir dir(m_sConfigPathInfo.m_strModeInfoPath);
	QFileInfoList dirList = dir.entryInfoList(QDir::AllDirs | QDir::Hidden | QDir::NoDotAndDotDot);
	if(dirList.size()==0)
	{
		QMessageBox::warning(this,"Warning","ModeInfo not found");
		return;
	}
	for (int i = 0; i < dirList.size(); i++)
	{
		QFileInfo dirInfo = dirList.at(i);
		nList.append(dirInfo.completeBaseName());
	}
	ui.comboBox_5->addItems(nList);
}
//更新设备列表
void DeviceConfig::insertDevList()
{
	ui.listDevList->clear();
	ui.listDevList->setSpacing(1);
	nCameraIOInfo.clear();
	int temp = ui.comboBox_3->currentText().toInt();
	int CameraNum;
	switch(temp)
	{
		case 4:CameraNum=4;break;
		case 12:CameraNum=18;break;
		case 15:CameraNum=24;break;
		case 18:CameraNum=27;break;
	}
	if(CameraNum==4)
	{

		ui.label_24->show();
		ui.cbxCameraType_2->show();
		ui.cbxCameraType_2->setCurrentIndex(0);
		ui.label_14->hide();
		ui.LE_SecondTrigger->hide();
	}
	else
	{
		ui.label_24->hide();
		ui.cbxCameraType_2->hide();
		ui.label_14->show();
		ui.LE_SecondTrigger->show();
	}
	for(int i=0;i<Widgets.size();i++)
	{
		auto w=Widgets[i];
		auto l=Labels[i];
		delete l;
		delete w;
	}
	Widgets.clear();
	Labels.clear();
	lastWidget=0;
	for (int i = 0; i < CameraNum; i++)
	{
		/*1:列表*/
		s_CameraIOInfo ntemp;
		if(CameraNum!=4)
		{
			ntemp.ImageType=0;
		}
		else
		{
			ntemp.ImageType=1;
		}
		QWidget *widget1 = new QWidget(ui.listDevList);
		Widgets.push_back(widget1);
		QLabel *lab1 = new QLabel(widget1);
		Labels.push_back(lab1);

		lab1->setGeometry(0,0,widget1->width(),widget1->height()-5);
		lab1->setAlignment(Qt::AlignVCenter);
		lab1->setText(tr("Camera")+QString::number(i + 1));
		switch(temp)//添加颜色
		{
		case 4:widget1->setStyleSheet("QWidget{""background-color:yellow;""}");break;
		case 12:i<6?widget1->setStyleSheet("QWidget{""background-color:yellow;""}"):i<12?widget1->setStyleSheet("QWidget{""background-color:rgb(0,255,0);""}"):widget1->setStyleSheet("QWidget{""background-color:red;""}");break;
		case 15:i<9?widget1->setStyleSheet("QWidget{""background-color:yellow;""}"):i<15?widget1->setStyleSheet("QWidget{""background-color:rgb(0,255,0);""}"):widget1->setStyleSheet("QWidget{""background-color:red;""}");break;
		case 18:i<9?widget1->setStyleSheet("QWidget{""background-color:yellow;""}"):i<18?widget1->setStyleSheet("QWidget{""background-color:rgb(0,255,0);""}"):widget1->setStyleSheet("QWidget{""background-color:red;""}");break;
		}
		QListWidgetItem *aItem = new QListWidgetItem(ui.listDevList);
		ui.listDevList->addItem(aItem);
		ui.listDevList->setItemWidget(aItem, widget1);
		/*2:是否为细条纹相机*/
		switch(temp)
		{
		case 12:i>=12?ntemp.DeviceType=2:i>=6?ntemp.DeviceType=1:ntemp.DeviceType=0;break;
		case 15:i>=15?ntemp.DeviceType=2:i>=9?ntemp.DeviceType=1:ntemp.DeviceType=0;break;
		case 18:i>=18?ntemp.DeviceType=2:i>=9?ntemp.DeviceType=1:ntemp.DeviceType=0;break;
		}
		/*3:相机序列号*/

		ntemp.DeviceID=i+1;

		/*4:分情况讨论参数
		1:真实序列号、Mark地址
		2:第一、第二触发口
		3:对应图像位
		4:所在工位（柱子）
		*/
		switch(temp)
		{
		case 4:
			{
				ntemp.RealLineID=i+1;
				ntemp.RealLineID_=i+1;
				switch(i+1)
				{
				case 1:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=0;ntemp.DeviceImageNumber=1;break;
				case 2:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=0;ntemp.DeviceImageNumber=2;break;
				case 3:ntemp.DeviceFristTrigger=4;ntemp.DeviceSecondTrigger=0;ntemp.DeviceImageNumber=3;break;
				case 4:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=0;ntemp.DeviceImageNumber=4;break;
				}
				if(i<MarkAddress.size())
					ntemp.DeviceMark=MarkAddress[i];
				break;
			}
		case 12:
			{
				//真实序列号、Mark地址
				if(i<12)
				{
					ntemp.RealLineID=i+1;
					ntemp.RealLineID_=i+1;
					if(i<MarkAddress.size())
						ntemp.DeviceMark=MarkAddress[i];
				}
				else
				{
					ntemp.RealLineID=i-11;
					ntemp.RealLineID_=i-11;
					if(i-12<MarkAddress.size())
						ntemp.DeviceMark=MarkAddress[i-12];
				}
				switch((i+1)%6)//第一、第二触发口、工位、对应图像号
				{
				case 1:
					{
						ntemp.DeviceFristTrigger=1;
						ntemp.DeviceSecondTrigger=2;
						ntemp.DeviceStation=1;
						//细条纹对应图像号等于普通相机2022.9.22-15:10
						i>=12?ntemp.DeviceImageNumber=1:ntemp.DeviceImageNumber=1;
						break;
					}
				case 2:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;i>=12?ntemp.DeviceImageNumber=2:ntemp.DeviceImageNumber=2;break;
				case 3:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=12?ntemp.DeviceImageNumber=3:ntemp.DeviceImageNumber=3;break;
				case 4:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=12?ntemp.DeviceImageNumber=4:ntemp.DeviceImageNumber=4;break;
				case 5:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=12?ntemp.DeviceImageNumber=5:ntemp.DeviceImageNumber=5;break;
				case 0:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=12?ntemp.DeviceImageNumber=6:ntemp.DeviceImageNumber=6;break;
				default:break;
				}
			}break;
		case 15:
			{
				//真实序列号、Mark地址
				if(i<15)
				{
					ntemp.RealLineID=i+1;
					ntemp.RealLineID_=i+1;
					if(i<MarkAddress.size())
						ntemp.DeviceMark=MarkAddress[i];
				}
				else
				{
					ntemp.RealLineID=i-14;
					ntemp.RealLineID_=i-14;
					if(i-15<MarkAddress.size())
						ntemp.DeviceMark=MarkAddress[i-15];
				}
				switch((i+1)%15)//第一、第二触发口、工位、对应图像号
				{
				case 1:
					{
						ntemp.DeviceFristTrigger=1;
						ntemp.DeviceSecondTrigger=2;
						ntemp.DeviceStation=1;
						i>=15?ntemp.DeviceImageNumber=1:ntemp.DeviceImageNumber=1;
						break;
					}
				case 2:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;i>=15?ntemp.DeviceImageNumber=2:ntemp.DeviceImageNumber=2;break;
				case 3:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;i>=15?ntemp.DeviceImageNumber=3:ntemp.DeviceImageNumber=3;break;
				case 10:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;ntemp.DeviceImageNumber=2;break;
				case 11:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;ntemp.DeviceImageNumber=3;break;
				case 4:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=15?ntemp.DeviceImageNumber=4:ntemp.DeviceImageNumber=4;break;
				case 5:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=15?ntemp.DeviceImageNumber=5:ntemp.DeviceImageNumber=5;break;
				case 6:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=15?ntemp.DeviceImageNumber=6:ntemp.DeviceImageNumber=6;break;
				case 12:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;ntemp.DeviceImageNumber=5;break;
				case 13:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;ntemp.DeviceImageNumber=6;break;
				case 7:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=15?ntemp.DeviceImageNumber=7:ntemp.DeviceImageNumber=7;break;
				case 8:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=15?ntemp.DeviceImageNumber=8:ntemp.DeviceImageNumber=8;break;
				case 9:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=15?ntemp.DeviceImageNumber=9:ntemp.DeviceImageNumber=9;break;
				case 14:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;ntemp.DeviceImageNumber=8;break;
				case 0:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;ntemp.DeviceImageNumber=9;break;
				default:break;
				}
			}break;
		case 18:
			{
				//真实序列号、Mark地址
				if(i<18)
				{
					ntemp.RealLineID=i+1;
					ntemp.RealLineID_=i+1;
					if(i<MarkAddress.size())
						ntemp.DeviceMark=MarkAddress[i];
				}
				else
				{
					ntemp.RealLineID=i-17;
					ntemp.RealLineID_=i-17;
					if(i-18<MarkAddress.size())
						ntemp.DeviceMark=MarkAddress[i-18];
				}
				switch((i+1)%9)//第一、第二触发口、工位、对应图像号
				{
				case 1:
					{
						ntemp.DeviceFristTrigger=1;
						ntemp.DeviceSecondTrigger=2;
						ntemp.DeviceStation=1;
						i>=18?ntemp.DeviceImageNumber=1:ntemp.DeviceImageNumber=1;
						break;
					}
				case 2:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;i>=18?ntemp.DeviceImageNumber=2:ntemp.DeviceImageNumber=2;break;
				case 3:ntemp.DeviceFristTrigger=1;ntemp.DeviceSecondTrigger=2;ntemp.DeviceStation=1;i>=18?ntemp.DeviceImageNumber=3:ntemp.DeviceImageNumber=3;break;
				case 4:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=18?ntemp.DeviceImageNumber=4:ntemp.DeviceImageNumber=4;break;
				case 5:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=18?ntemp.DeviceImageNumber=5:ntemp.DeviceImageNumber=5;break;													   
				case 6:ntemp.DeviceFristTrigger=3;ntemp.DeviceSecondTrigger=4;ntemp.DeviceStation=2;i>=18?ntemp.DeviceImageNumber=6:ntemp.DeviceImageNumber=6;break;
				case 7:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=18?ntemp.DeviceImageNumber=7:ntemp.DeviceImageNumber=7;break;													   
				case 8:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=18?ntemp.DeviceImageNumber=8:ntemp.DeviceImageNumber=8;break;
				case 0:ntemp.DeviceFristTrigger=5;ntemp.DeviceSecondTrigger=6;ntemp.DeviceStation=3;i>=18?ntemp.DeviceImageNumber=9:ntemp.DeviceImageNumber=9;break;
				default:break;
				}
			}break;
		default:break;
		}
		ntemp.DeviceInitFile=ui.Cb_CameraParm->count()?ui.Cb_CameraParm->currentText():"";
		/*6:添加*/
		nCameraIOInfo << ntemp;
	}
	slots_Lock(ui.locklocation->isChecked());
}
//改变相机数量
void DeviceConfig::slots_SaveMode3Changed(int temp)
{
	ui.comboBox_4->clear();
	insertDevList();
	AddList();
}
void DeviceConfig::AddList()
{
	int temp = ui.comboBox_3->currentText().toInt();
	if (temp > 4)
	{
		if (temp % 2 != 0)
		{
			temp++;
		}
		temp = temp + temp / 2;
	}
	nFictitiouCamCount = temp;
	QStringList nList;
	for (int i = 0; i < temp; i++)
	{
		nList.append(QString::number(i+1));
	}
	ui.comboBox_4->addItems(nList);
}

void DeviceConfig::ReadInit(QString path)
{
	//QString path=QFileDialog::getOpenFileName(this,"Open","Config/");
	QSettings m_psetting(path,QSettings::IniFormat);//设置路径
	m_psetting.setIniCodec(QTextCodec::codecForName("UTF-8"));

	//system
	m_psetting.beginGroup("system");
	if(m_psetting.contains("systemType"))//软件类型
		ui.comboBox->setCurrentIndex(m_psetting.value("systemType").toInt()-1);
	if(m_psetting.contains("iIOCardCount"))//IO卡数量
		ui.comboBox_2->setCurrentIndex(m_psetting.value("iIOCardCount").toInt()-1);
	if(m_psetting.contains("MinKickNumber"))//连续补踢报警
		ui.spinBox->setValue(m_psetting.value("MinKickNumber").toInt());
	if(m_psetting.contains("MaxKickNumber"))//连续累计报警
		ui.spinBox_2->setValue(m_psetting.value("MaxKickNumber").toInt());
	if(m_psetting.contains("isOLdPLC"))//一代机PLC
		ui.IsOldPlc->setChecked(m_psetting.value("isOLdPLC").toInt());
	if(m_psetting.contains("isUseIOCard"))//IO卡使能
		ui.cbtIOCard->setChecked(m_psetting.value("isUseIOCard").toInt());
	if(m_psetting.contains("NoKickIfNoFind"))//定位失败不剔除
		ui.checkBox->setChecked(m_psetting.value("NoKickIfNoFind").toInt());
	//if(m_psetting.contains("LastModelName"))
	//{
	//	QSettings m_psetting(QString("ModeInfo/%1/GrabInfo.ini").arg(m_psetting.value("NoKickIfNoFind").toString()),QSettings::IniFormat);//设置路径
	//	m_psetting.setIniCodec(QTextCodec::codecForName("UTF-8"));
	//	for(int i=0;i<nCameraIOInfo.size();i++)
	//	{

	//	}
	//}
	m_psetting.endGroup();

	//GarbCardParameter
	m_psetting.beginGroup("GarbCardParameter");
	if(m_psetting.contains("DeviceNum"))//相机数量
	{
		int DeviceNum=m_psetting.value("DeviceNum").toInt();
		bool DeviceNumError=false;
		switch(DeviceNum)
		{
		case 4:ui.comboBox_3->setCurrentIndex(0);break;
		case 12:ui.comboBox_3->setCurrentIndex(1);break;
		case 15:ui.comboBox_3->setCurrentIndex(2);break;
		case 18:ui.comboBox_3->setCurrentIndex(3);break;
		default:DeviceNumError=true;break;
		}
		if(DeviceNumError)
			return ;
		for(int i=0;i<nCameraIOInfo.size();i++)
		{
			QString key=QString("Device%1").arg(i+1);
			nCameraIOInfo[i].RealLineID=m_psetting.value(key+"RealLine").toInt();//相机真实序号
			nCameraIOInfo[i].DeviceID=m_psetting.value(key+"ID").toInt()+1;//相机序号
			nCameraIOInfo[i].DeviceStation=m_psetting.value(key+"Station").toInt();//相机工位
			nCameraIOInfo[i].DeviceFristTrigger=m_psetting.value(key+"FristTrigger").toInt();//第一次触发out口
			nCameraIOInfo[i].DeviceSecondTrigger=m_psetting.value(key+"SecondTrigger").toInt();//第二次触发out口
			nCameraIOInfo[i].DeviceMark=m_psetting.value(key+"Mark").toString();//MARK地址
			nCameraIOInfo[i].DeviceInitFile=m_psetting.value(key+"InitFile").toString();//配置文件
			nCameraIOInfo[i].DeviceName=m_psetting.value(key+"Name").toString();//相机名
			//nCameraIOInfo[i].DeviceImageNumber=m_psetting.value(key+"ImageNumber").toString().toInt();//对应图像号
		}
		m_psetting.endGroup();
		if(DeviceNum==4)
		{
			for(int i=0;i<4;i++)
			{
				QString key=QString("ImageType/Device_%1").arg(i);
				nCameraIOInfo[i].ImageType=m_psetting.value(key).toInt();
			}
		}
	}
	else
	{
		m_psetting.endGroup();
		return;
	}

	//RoAngle
	m_psetting.beginGroup("RoAngle");
	for(int i=0;i<nCameraIOInfo.size();i++)
	{
		QString key=QString("Device_%1").arg(i+1);
		nCameraIOInfo[i].DeviceRoAngle=m_psetting.value(key).toInt();//旋转角度
	}
	m_psetting.endGroup();
	

	slots_ChangeCamera(0);
}

void DeviceConfig::ClippingFrame(QSettings &ModeInfoConfig)//1209
{
	QString path;
	int width,height;
	for(int i=0;i<nCameraIOInfo.size();i++)
	{
		path="Config/"+nCameraIOInfo[i].DeviceInitFile;
		QSettings m_psetting(path,QSettings::IniFormat);//设置路径
		if(m_psetting.contains("Camera/Width"))
		{
			width=m_psetting.value("Camera/Width").toInt();
			ModeInfoConfig.setValue(QString("pointx/Grab_%1").arg(i),width-200);
		}
		else
		{
			ModeInfoConfig.setValue(QString("pointx/Grab_%1").arg(i),width-200);
		}

		if(m_psetting.contains("Camera/Height"))
		{
			height=m_psetting.value("Camera/Height").toInt();
			ModeInfoConfig.setValue(QString("pointy/Grab_%1").arg(i),height-200);
		}
		else
		{
			ModeInfoConfig.setValue(QString("pointy/Grab_%1").arg(i),height-200);
		}
	}
}

void DeviceConfig::slots_addKicklist()
{
	if (ui.checkBox->isChecked())
	{
		QString temp = ui.comboBox_4->currentText();
		QList<QLabel*> labelList = ui.listWidget->findChildren<QLabel*>();
		foreach(QLabel *label, labelList)
		{
			if (label->text() == temp)
			{
				return;
			}
		}
		QWidget *widget1 = new QWidget(ui.listWidget);
		QLabel *lab1 = new QLabel(widget1);
		lab1->setText(temp);
		QListWidgetItem *aItem = new QListWidgetItem(ui.listWidget);
		ui.listWidget->addItem(aItem);
		ui.listWidget->setItemWidget(aItem, widget1);
	}
}
void DeviceConfig::CameraClampSet(int nCount)
{
	nCameraIOInfo[0].DeviceStation = 1;
	nCameraIOInfo[0].DeviceFristTrigger = 1;
	nCameraIOInfo[0].DeviceSecondTrigger = 1;
	for (int i = 1; i < nCount; i++)
	{
		nCameraIOInfo[i].DeviceStation = i + 2;
		nCameraIOInfo[i].DeviceFristTrigger = i + 1;
		nCameraIOInfo[i].DeviceSecondTrigger = i + 1;
	}
	ui.label_14->setVisible(false);
	ui.LE_SecondTrigger->setVisible(false);
}
void DeviceConfig::CameraOtherSet(int nCount)
{
	ui.label_14->setVisible(true);
	ui.LE_SecondTrigger->setVisible(true);
	QList<int> ArrayFir;
	QList<int> ArraySec;
	QList<int> ArrayThr;
	if (nCount == 12)
	{
		ArrayFir << 0 << 1 << 6 << 7;
		ArraySec << 2 << 3 << 8 << 9;
		ArrayThr << 4 << 5 << 10 << 11;
	}
	if (nCount == 15)
	{
		ArrayFir << 0 << 1 << 2 << 9 << 10;
		ArraySec << 3 << 4 << 5 << 11 << 12;
		ArrayThr << 6 << 7 << 8 << 13 << 14;
	}
	if (nCount == 18)
	{
		ArrayFir << 0 << 1 << 2 << 9 << 10 << 11;
		ArraySec << 3 << 4 << 5 << 12 << 13 << 14;
		ArrayThr << 6 << 7 << 8 << 15 << 16 << 17;
	}
	foreach(int i, ArrayFir)
	{
		nCameraIOInfo[i].DeviceStation = 1;
		nCameraIOInfo[i].DeviceFristTrigger = 1;
		nCameraIOInfo[i].DeviceSecondTrigger = 2;
	}
	foreach(int i, ArraySec)
	{
		nCameraIOInfo[i].DeviceStation = 2;
		nCameraIOInfo[i].DeviceFristTrigger = 3;
		nCameraIOInfo[i].DeviceSecondTrigger = 4;
	}
	foreach(int i, ArrayThr)
	{
		nCameraIOInfo[i].DeviceStation = 3;
		nCameraIOInfo[i].DeviceFristTrigger = 5;
		nCameraIOInfo[i].DeviceSecondTrigger = 6;
	}
	//
}

void DeviceConfig::slots_defalut()
{
	if (ui.comboBox_5->count() == 0)
	{
		QMessageBox::information(this, tr("message"), tr("No Check Mode!"));
	}
	ui.listWidget->clear();
	ui.spinBox->setValue(2);
	ui.spinBox_2->setValue(1000);
	ui.checkBox->setChecked(false);
	ui.cbtIOCard->setChecked(true);
	ui.locklocation->setChecked(true);
	int nCount = nCameraIOInfo.count();
	int page;
	switch(ui.comboBox_3->currentText().toInt())
	{
	case 4:ui.comboBox_3->setCurrentIndex(0);break;
	case 12:ui.comboBox_3->setCurrentIndex(1);break;
	case 15:ui.comboBox_3->setCurrentIndex(2);break;
	case 18:ui.comboBox_3->setCurrentIndex(3);break;
	}
	for (int i = 0 ; i < nCount; i++)
	{
		//nCameraIOInfo[i].DeviceID = i+1;
		//nCameraIOInfo[i].RealLineID = i+1;
		//nCameraIOInfo[i].DeviceName = QString("MER");
		nCameraIOInfo[i].DeviceInitFile = QString("CameraParm1.ini");
		//nCameraIOInfo[i].DeviceShotTime = 200;
	}
	slots_ChangeCamera(0);
	//if (nCount <= 4)
	//{
	//	CameraClampSet(nCount);
	//}
	//else
	//{
	//	CameraOtherSet(nCount);
	//}
}
void DeviceConfig::slots_Export()
{
	int nSystemType = ui.comboBox->currentIndex();
	int nIOCount = ui.comboBox_2->currentText().toInt();
	int nCameraCount = ui.comboBox_3->currentText().toInt();
	int CameraNum;
	int CameraNumTrue;
	switch(nCameraCount)
	{
	case 4:CameraNum=4;CameraNumTrue=4;break;
	case 12:CameraNum=18;CameraNumTrue=12;break;
	case 15:CameraNum=24;CameraNumTrue=15;break;
	case 18:CameraNum=27;CameraNumTrue=18;break;
	}
	if ((nSystemType == 0 && (nCameraCount == 4 || nIOCount == 2)) || (nSystemType == 1 && (nCameraCount > 4 || nIOCount == 1)) || (nSystemType == 2 && (nCameraCount == 4 || nIOCount == 2)))
	{
		QMessageBox::information(this, tr("message"), tr("IO or Camera Count: failed!"));
		return;
	}
	QFile file("Config/Config.ini");
	if(file.exists())
	{
		file.remove("Config/Config.ini");
	}
	QSettings PathConfig(m_sConfigPathInfo.m_strConfigPath, QSettings::IniFormat);
	PathConfig.setIniCodec(QTextCodec::codecForName("GBK"));


	PathConfig.setValue("/system/systemType", nSystemType +1);
	PathConfig.setValue("/system/iIOCardCount", ui.comboBox_2->currentText().toInt());
	if (ui.cbtIOCard->isChecked())
	{
		PathConfig.setValue("/system/isUseIOCard", 1);
	}
	else {
		PathConfig.setValue("/system/isUseIOCard", 0);
	}
	if(ui.IsOldPlc->isChecked())
	{
		PathConfig.setValue("/system/IsOLdPLC", 1);
	}else{
		PathConfig.setValue("/system/IsOLdPLC", 0);
	}
	PathConfig.setValue("/system/CarveDeviceCount", nCameraCount *2);
	PathConfig.setValue("/system/MinKickNumber", ui.spinBox->text().toInt());
	PathConfig.setValue("/system/MaxKickNumber", ui.spinBox_2->text().toInt());
	PathConfig.setValue("/system/bCreateApp", 0);

	PathConfig.setValue("/system/Test", 0);
	PathConfig.setValue("/system/SaveNormalErrorImageByTime", 0);
	PathConfig.setValue("/system/SaveStressErrorImageByTime", 0);
	PathConfig.setValue("/system/LastModelName", ui.comboBox_5->currentText());
	PathConfig.setValue("/GarbCardParameter/DeviceNum", nCameraCount);
	if(ui.comboBox_6->currentIndex()==0)
	{
		if(ui.comboBox->currentIndex()!=1)
			PathConfig.setValue("/system/LightSourceType", 1);
		else
			PathConfig.setValue("/system/LightSourceType", 0);
	}
	if (ui.checkBox->isChecked())
	{
		int nTemp = 0;
		QList<QLabel*> labelList = ui.listWidget->findChildren<QLabel*>();
		foreach(QLabel *label, labelList)
		{
			nTemp = label->text().toInt();
			PathConfig.setValue(QString("/NoRejectIfROIFail/Device_%1").arg(nTemp),1);
		}
		if (nTemp == 0)
		{
			PathConfig.setValue("/system/NoKickIfNoFind", 1);
		}
		else {
			PathConfig.setValue("/system/NoKickIfNoFind", 0);
		}
	}
	else {
		PathConfig.setValue("/system/NoKickIfNoFind", 0);
		for (int i = 1; i <= nFictitiouCamCount; i++)
		{
			PathConfig.setValue(QString("/NoRejectIfROIFail/Device_%1").arg(i), 0);
		}
	}
	for (int i = 0; i < CameraNum; i++)
	{
		PathConfig.setValue(QString("/GarbCardParameter/Device%1RealLine").arg(i + 1), nCameraIOInfo[i].RealLineID);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1ID").arg(i+1), nCameraIOInfo[i].DeviceID-1);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1Name").arg(i + 1), nCameraIOInfo[i].DeviceName);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1Mark").arg(i + 1), nCameraIOInfo[i].DeviceMark);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1InitFile").arg(i + 1), nCameraIOInfo[i].DeviceInitFile);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1Station").arg(i + 1), nCameraIOInfo[i].DeviceStation);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1FristTrigger").arg(i + 1), nCameraIOInfo[i].DeviceFristTrigger);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1SecondTrigger").arg(i + 1), nCameraIOInfo[i].DeviceSecondTrigger);
		PathConfig.setValue(QString("/GarbCardParameter/Device%1ImageNumber").arg(i + 1), nCameraIOInfo[i].DeviceImageNumber);
		PathConfig.setValue(QString("/RoAngle/Device_%1").arg(i + 1), nCameraIOInfo[i].DeviceRoAngle);
		PathConfig.setValue(QString("/ImageType/Device_%1").arg(i), nCameraIOInfo[i].ImageType);
	}
	//GrabInfo
	QString ModeInfo = m_sConfigPathInfo.m_strModeInfoPath + "/" + ui.comboBox_5->currentText() + "/GrabInfo.ini";
	QSettings ModeInfoConfig(ModeInfo, QSettings::IniFormat);
	ModeInfoConfig.setIniCodec(QTextCodec::codecForName("GBK"));
	ClippingFrame(ModeInfoConfig);
	QFile file_2(ModeInfo);
	if(file_2.exists())
	{
		file_2.remove(ModeInfo);
	}
	/*
	Shuter
	tonormal
	convert
	*/
	for(int i=0;i<CameraNumTrue;i++)
		ModeInfoConfig.setValue(QString("/Shuter/Grab_%1").arg(i), nCameraIOInfo[i].DeviceShotTime);
	for(int i=0;i< nCameraIOInfo.size();i++)
	{
		
		ModeInfoConfig.setValue(QString("/tonormal/Grab_%1").arg(i), nCameraIOInfo[i].DeviceImageNumber-1);
		ModeInfoConfig.setValue(QString("/convert/Grab_%1").arg(i), nCameraIOInfo[i].RealLineID_-1);
	}
	//stress
	switch(nCameraCount)
	{
	case 4:
		{
			for(int i=0;i<nCameraCount;i++)
				ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i), 0);
		break;
		}
	case 12:
		{
			for(int i=0;i<nCameraIOInfo.size();i++)
			{
				if(i<6||i>11)
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i), 0);
				}
				else if(ui.locklocation->checkState())
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i),2);
				}
				else
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i),1);
				}
			}
			break;
		}
	case 15:
		{
			for(int i=0;i<nCameraIOInfo.size();i++)
			{
				if(i<9||i>14)
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i), 0);
				}
				else if(ui.locklocation->checkState())
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i),2);
				}
				else
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i),1);
				}
			}
			break;
		}
	case 18:
		{
			for(int i=0;i<nCameraIOInfo.size();i++)
			{
				if(i<9||i>17)
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i), 0);
				}
				else if(ui.locklocation->checkState())
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i),2);
				}
				else
				{
					ModeInfoConfig.setValue(QString("/Stress/Device_%1").arg(i),1);
				}
			}
			break;
		}
	}

	QMessageBox::information(this, tr("message"), tr("Export: succed!"));
}
