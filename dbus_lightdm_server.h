#ifndef DBUS_LIGHTDM_SERVER_H
#define DBUS_LIGHTDM_SERVER_H

#include <QObject>
#include "lightdm_krkr_dbus_ifce.h"
#include "krkr_dbusadaptor.h"
class DBUS_Lightdm_Server : public QObject
{
    Q_OBJECT
    QString	m_pathNameBase;
    QString	m_objNameBase;
    QString m_receiverName;
    QString m_senderName;
    lightdmobject lightdm_obj;
public:
    explicit DBUS_Lightdm_Server(const QString& pathName,const QString &objname,const QString &recievername,const QString &sendername,QObject *parent = nullptr);
private:
    void setupDbus();
    void connectSyncMessage();
signals:
};

#endif // DBUS_LIGHTDM_SERVER_H
