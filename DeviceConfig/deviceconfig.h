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
public:
	void initUIParam();
	void initConfig();
	void initConnect();
	void initMarkAddress();
	void writeConfig(QString,QString);
	void insertDevList();
	void CameraClampSet(int);
	void CameraOtherSet(int);
	void FindModeInfo();

	void AddList();
public slots:
	void slots_SaveMode3Changed(int);
	void slots_addKicklist();
	void slots_defalut();
	void slots_Export();
	void slots_showCameraIOInfo(int);
	void slots_ChangeCameraIOData(int);
	void slots_CameraioSave();

	void slots_ReadConfig();
	void slots_GetIniPath();
	void slots_SetAll();
	void slots_Lock(int);//应力自定位
private:
    Ui::UIDevicesConfig ui;
public:
	QVector<QLabel*>labels;
	QVector<QWidget*>widgets;
	QVector<QString>MarkAddress;

	s_ConfigPathInfo m_sConfigPathInfo;
	s_nSystemCfgInfo m_sSystemInfo;
	QList<s_CameraIOInfo> nCameraIOInfo;
	int nCurrentCamIO;
	int nFictitiouCamCount;

};
