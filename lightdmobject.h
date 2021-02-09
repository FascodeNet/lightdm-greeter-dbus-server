#ifndef LIGHTDMOBJECT_H
#define LIGHTDMOBJECT_H

#include <QObject>
#include <QLightDM/Greeter>
#include <QLightDM/UsersModel>
#include <QLightDM/Power>
#include <QLightDM/SessionsModel>

class lightdmobject : public QObject
{
    Q_OBJECT
public:
    explicit lightdmobject(QObject *parent = nullptr);
    QStringList get_user_list();
    QStringList get_session_list();
    void select_user(QString);
    QString get_icon(QString);
    void auth(QString);
    void set_session(QString);
    void sleep();
    void shutdown();
    void reboot();
    void hibernate();
private:
    QLightDM::Greeter m_greeter;
    QLightDM::PowerInterface m_power;
    QLightDM::UsersModel m_usermodel;
    QLightDM::SessionsModel m_SessionModel;
    QString init_session;
    QString init_user;
    QStringList sessions_str;
    QStringList users_str;
    QString current_session;
signals:
    void error_login();
public slots:

    void authenticationComplete();
};

#endif // LIGHTDMOBJECT_H
