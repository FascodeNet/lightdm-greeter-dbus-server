#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class Settings_manager : public QObject
{
    Q_OBJECT
public:
    explicit Settings_manager(QObject *parent = nullptr);
    void load(QString);
    QString client_path="vlc";
signals:

};

#endif // SETTINGS_MANAGER_H
