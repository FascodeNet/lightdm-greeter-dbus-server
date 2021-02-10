#include "lightdmobject.h"

lightdmobject::lightdmobject(QObject *parent) : QObject(parent),m_greeter(this),m_power(this),m_usermodel(this),m_SessionModel(this)
{
    if(!m_greeter.connectSync()){
        //none
    }
    for(int i=0;i<m_SessionModel.rowCount(QModelIndex());i++){
        sessions_str << m_SessionModel.data(m_SessionModel.index(i,0),QLightDM::SessionsModel::KeyRole).toString();
    }
    init_session = sessions_str.at(0);
    if(!m_greeter.hideUsersHint()){
        for(int i=0;i < m_usermodel.rowCount(QModelIndex());i++){
            users_str<< m_usermodel.data(m_usermodel.index(i,0),QLightDM::UsersModel::NameRole).toString();
        }
        init_user = users_str.at(0);
    }
    connect(&m_greeter,&QLightDM::Greeter::authenticationComplete,this,&lightdmobject::authenticationComplete);
}
QStringList lightdmobject::get_user_list(){
    return users_str;
}
QStringList lightdmobject::get_session_list(){
    return sessions_str;
}

QString lightdmobject::select_user(QString user){
    if(m_greeter.inAuthentication()){
        m_greeter.cancelAuthentication();
    }
    if(user != nullptr){
        m_greeter.authenticate(user);
    }
    return user;
}
QString lightdmobject::get_icon(QString user){

    for (int i = 0; i < m_usermodel.rowCount(QModelIndex()); i++) {
        if(m_usermodel.data(m_usermodel.index(i, 0), QLightDM::UsersModel::NameRole).toString() == user){
            QVariant image=m_usermodel.data(m_usermodel.index(i,0),QLightDM::UsersModel::ImagePathRole);
            return image.toString();
        }
    }
    return nullptr;
}
void lightdmobject::auth(QString password){
    m_greeter.respond(password);
}
QString lightdmobject::set_session(QString sess){
    current_session = sess;
    return sess;
}
void lightdmobject::authenticationComplete(){
    if(m_greeter.isAuthenticated()){
        m_greeter.startSessionSync(current_session);
    }else{
        error_login();
    }
}
void lightdmobject::shutdown(){
    m_power.shutdown();
}
void lightdmobject::reboot(){
    m_power.restart();
}
void lightdmobject::hibernate(){
    m_power.hibernate();

}
void lightdmobject::sleep(){
    m_power.suspend();
}
bool lightdmobject::authorize(QString pass){
    {
        QEventLoop loop;
        loop.connect(&m_greeter,SIGNAL(authenticationComplete()),SLOT(quit()));

        m_greeter.respond(pass);
        loop.exec();
    }
    if(m_greeter.isAuthenticated()){
        return m_greeter.startSessionSync(current_session);
    }else{
        return false;
    }
}
