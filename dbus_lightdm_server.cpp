#include "dbus_lightdm_server.h"
#include <iostream>
DBUS_Lightdm_Server::DBUS_Lightdm_Server(const QString& pathName,const QString &objname,const QString &recievername,
                                         const QString &sendername
                                         ,QObject *parent): QObject(parent),
    m_pathNameBase(pathName),
    m_objNameBase(objname),
    m_receiverName(recievername),
    m_senderName(sendername),
    lightdm_obj(this)
{
    setupDbus();
    connectSyncMessage();
}
void DBUS_Lightdm_Server::setupDbus(){
    QDBusConnection session=QDBusConnection::connectToBus(QDBusConnection::SessionBus,m_receiverName);
    if(!session.isConnected()){
        std::cerr << "not connected" << std::endl;
        return;
    }
    if(!session.registerService(m_pathNameBase + m_receiverName)){

        std::cerr << "can't service reg" << std::endl;
    }
    if(!session.registerObject(m_objNameBase + m_receiverName,&lightdm_obj)){
        std::cerr << "can't obj reg" << std::endl;
    }
    new Greeter_dbusAdaptor(&lightdm_obj);
}
void DBUS_Lightdm_Server::connectSyncMessage(){
    QDBusConnection session=QDBusConnection::connectToBus(QDBusConnection::SessionBus,m_senderName);
    if(!session.isConnected()){
        return;
    }
    /*if(!session.connect(m_pathNameBase + m_senderName,m_objNameBase + m_senderName,
                        net::fascode::lightdm::krkr_dbus::staticInterfaceName(),
                        "set_session",
                        this,
                        SLOT(set_session(QString))));
                        */
}
