#include <QCoreApplication>
#include "lightdmobject.h"
#include "dbus_lightdm_server.h"
#include "greeter_subprocess_runner.h"
#include "settings_manager.h"
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString pathBase = "net.fascode.lightdm.greeter_dbus.";
    QString objBase = "/net/fascode/lightdm/greeter_dbus/";
    QString	senderName = "sender";
    QString receiverName = "recevier";
    QCoreApplication::setApplicationName("Lightdm dbus server");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;
    parser.setApplicationDescription("LightDM Greeter DBUS Server");
    parser.addHelpOption();
    QCommandLineOption setting_option({"c","config"},"Greeter Config","json file","/etc/lightdm/lightdm-dbus-greeter-server.json");
    parser.addOption(setting_option);
    parser.process(a.arguments());
    Settings_manager settingm;
    if(QFile::exists(parser.value(setting_option))){
        settingm.load(parser.value(setting_option));
    }
    std::cout << settingm.client_path.toStdString() << std::endl;
    DBUS_Lightdm_Server serverkun(pathBase,objBase,receiverName,senderName);
    greeter_subprocess_runner runner(settingm.client_path,new QObject());
    QTimer::singleShot(0,&runner,&greeter_subprocess_runner::run);
    return a.exec();
}
