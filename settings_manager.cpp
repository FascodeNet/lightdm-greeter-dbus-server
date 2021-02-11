#include "settings_manager.h"

Settings_manager::Settings_manager(QObject *parent) : QObject(parent)
{

}
void Settings_manager::load(QString file){

    QFile openFile(file);
    openFile.open(QIODevice::ReadOnly);
    QByteArray data = openFile.readAll();
    openFile.close();
    QJsonDocument jsondoc(QJsonDocument::fromJson(data));
    QJsonObject jsonObj(jsondoc.object());
    client_path=jsonObj["client_path"].toString();
}
