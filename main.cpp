#include <QCoreApplication>
#include "lightdmobject.h"
#include "dbus_lightdm_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString pathBase = "net.fascode.lightdm.krkr_dbus.";
    QString objBase = "/net/fascode/lightdm/krkr_dbus/";
    QString	senderName = "sender";
    QString receiverName = "recevier";

    DBUS_Lightdm_Server serverkun(pathBase,objBase,receiverName,senderName);
    return a.exec();
}
