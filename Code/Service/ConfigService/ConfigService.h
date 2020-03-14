#ifndef CONFIGSERVICE_H
#define CONFIGSERVICE_H

#include <QObject>
#include <QSettings>
#include <QString>

class ConfigService : public QObject
{
    Q_OBJECT
public:
    explicit ConfigService(const QString &filePath, QObject *parent = 0);
    ConfigService(QObject *parent = 0);
    ~ConfigService();

    int     getIntValue(QString group,    QString key, int defaultValue = 0);
    bool    getBoolValue(QString group,   QString key, bool defaultValue = false);
    QString getStringValue(QString group, QString key, QString defaultValue = "");

signals:

public slots:

private:
    QSettings *m_settings;
};

#endif // CONFIGSERVICE_H
