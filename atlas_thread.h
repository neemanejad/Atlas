#pragma once

#include <qthread.h>

class AtlasThread : public QThread
{
Q_OBJECT
public:
    explicit AtlasThread(QString executablePath, QObject* parent = nullptr);
private:
    QString executablePath;
    void run() override;
signals:
    void threadFinished(QString s);
};