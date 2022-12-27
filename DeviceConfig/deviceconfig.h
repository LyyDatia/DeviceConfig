#pragma once
#include <QMainWindow>
#include "ui_DeviceConfig.h"
#include <QList>
#include <qDebug>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include "configInfo.h"
class DeviceConfig : public QMainWindow
{
    Q_OBJECT

public:
    DeviceConfig(QWidget *parent = 0);
	~DeviceConfig();
public:
	void initUIParam();
	void initConfig();
	void initConnect();
	void initMarkAddress();	//初始化mark地址
	void initRead();		//初始化读取上次配置
	void initCameraParm();	//初始化读取配置文件
	void writeConfig(QString,QString);
	void insertDevList();
	void CameraClampSet(int);
	void CameraOtherSet(int);
	void FindModeInfo();

	void AddList();
	void ReadInit(QString path);
	void ClippingFrame(QSettings&);
public slots:
	void slots_SaveMode3Changed(int);
	void slots_addKicklist();
	void slots_defalut();//默认配置
	void slots_Export();//导出
	void slots_showCameraIOInfo(int);
	void slots_ChangeCamera(int);
	void slots_CameraSave();
	void slots_ReadConfig();
	void slots_GetIniPath();//读取配置文件
	void slots_SetAll();
	void slots_Lock(int);//应力自定位
private:
    Ui::UIDevicesConfig ui;
public:
	QVector<QString>MarkAddress;
	QVector<QLabel*>Labels;
	QVector<QWidget*>Widgets;
	int lastWidget;//用于指向上一个点击的widget

	s_ConfigPathInfo m_sConfigPathInfo;
	s_nSystemCfgInfo m_sSystemInfo;
	QList<s_CameraIOInfo> nCameraIOInfo;
	int nCurrentCamIO;
	int nFictitiouCamCount;

};
