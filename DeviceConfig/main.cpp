#include "DeviceConfig.h"
#include <QApplication>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QTranslator translator;
	
	translator.load("./deviceconfig_zh.qm");
	a.installTranslator(&translator);
	
    DeviceConfig w;
    w.show();
    return a.exec();
}
