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
	void initMarkAddress();	//��ʼ��mark��ַ
	void initRead();		//��ʼ����ȡ�ϴ�����
	void initCameraParm();	//��ʼ����ȡ�����ļ�
	void writeConfig(QString,QString);
	void insertDevList();
	void CameraClampSet(int);
	void CameraOtherSet(int);
	void FindModeInfo();

	void AddList();
	void ReadInit(QString path);
public slots:
	void slots_SaveMode3Changed(int);
	void slots_addKicklist();
	void slots_defalut();//Ĭ������
	void slots_Export();//����
	void slots_showCameraIOInfo(int);
	void slots_ChangeCamera(int);
	void slots_CameraSave();
	void slots_ReadConfig();
	void slots_GetIniPath();//��ȡ�����ļ�
	void slots_SetAll();
	void slots_Lock(int);//Ӧ���Զ�λ
private:
    Ui::UIDevicesConfig ui;
public:
	QVector<QString>MarkAddress;
	QVector<QLabel*>Labels;
	QVector<QWidget*>Widgets;
	int lastWidget;//����ָ����һ�������widget

	s_ConfigPathInfo m_sConfigPathInfo;
	s_nSystemCfgInfo m_sSystemInfo;
	QList<s_CameraIOInfo> nCameraIOInfo;
	int nCurrentCamIO;
	int nFictitiouCamCount;

};
