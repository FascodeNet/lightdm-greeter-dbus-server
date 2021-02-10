#include <QCoreApplication>
#include "lightdmobject.h"
#include "dbus_lightdm_server.h"
#include "greeter_subprocess_runner.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString pathBase = "net.fascode.lightdm.greeter_dbus.";
    QString objBase = "/net/fascode/lightdm/greeter_dbus/";
    QString	senderName = "sender";
    QString receiverName = "recevier";

    DBUS_Lightdm_Server serverkun(pathBase,objBase,receiverName,senderName);
    greeter_subprocess_runner runner(new QObject());
    QTimer::singleShot(0,&runner,&greeter_subprocess_runner::run);
    return a.exec();
}
