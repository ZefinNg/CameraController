#include "ConfigService.h"

ConfigService::ConfigService(const QString &filePath, QObject *parent) : QObject(parent)
{
    m_settings = new QSettings(filePath, QSettings::IniFormat, this);
}

ConfigService::ConfigService(QObject *parent)
{

}

ConfigService::~ConfigService()
{

}

int ConfigService::getIntValue(QString group, QString key, int defaultValue)
{
    m_settings->beginGroup(group);
    return m_settings->value(key, defaultValue).toInt();
}

bool ConfigService::getBoolValue(QString group, QString key, bool defaultValue)
{
    m_settings->beginGroup(group);
    return m_settings->value(key, defaultValue).toBool();
}

QString ConfigService::getStringValue(QString group, QString key, QString defaultValue)
{
    m_settings->beginGroup(group);
    return m_settings->value(key, defaultValue).toString();
}

