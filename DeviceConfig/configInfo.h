#pragma once
#include <qstring.h>
#include <QTextCodec>
#include <QDir>
typedef struct _ConfigInfo
{
	QString m_strAppPath;
	QString m_strConfigPath;
	QString m_strModeInfoPath;
	QString m_strDataPath;
	QString m_strGrabInfoPath;
	_ConfigInfo()
	{

	}
}s_ConfigPathInfo;

typedef struct _systemInfo
{
	//system
	int	systemType;
	int	isUseIOCard;
	int	iIOCardCount;
	int	CarveDeviceCount;
	int	NoKickIfROIFail;
	int MinKickNumber;
	int MaxKickNumber;
	//GarbCardParameter
	int DeviceNum;
	_systemInfo()
	{

	}
}s_nSystemCfgInfo;

typedef struct _CameraIOInfo
{
	//GarbCardParameter
	int	DeviceID;
	int RealLineID;//�û��Լ���д����ʵID�ţ�����CONFIG��realine����
	int RealLineID_;//�������������У�����GRABINFO��conver����
	QString DeviceName;
	QString DeviceMark;
	QString DeviceInitFile;
	int DeviceStation;
	int DeviceFristTrigger;
	int DeviceSecondTrigger;
	int DeviceShotTime;
	int DeviceRoAngle;
	int DeviceImageNumber;
	int ImageType;

	int DeviceType;//0:normal 1:stress 2:storial
	_CameraIOInfo()
	{
		DeviceID = 1;
		RealLineID = 1;
		DeviceName = "MER";
		DeviceMark = "FAIL";
		DeviceInitFile = "FAIL";
		DeviceStation = 1;
		DeviceFristTrigger = 1;
		DeviceSecondTrigger = 1;
		DeviceShotTime = 200;
		DeviceRoAngle = 0;
		DeviceImageNumber=0;
		DeviceType=false;
		ImageType=0;
	}
}s_CameraIOInfo;