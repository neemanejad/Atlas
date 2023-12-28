#pragma once

#include <qobject.h>
#include <unordered_map>
#include <string>
#include "atlas_thread.h"

class ProcessManager : public QObject
{
Q_OBJECT
public:
	static ProcessManager* GetManager();

signals:
	void threadStarted(QString& executablePath);
	void threadFinished(QString& executablePath);
public slots:
	void RunExecutable(QString& executablePath);
private slots:
	void AddRunningProcessEntry(QString& executablePath);
	void RemoveRunningProcessEntry(QString executablePath);

private:
	static ProcessManager* manager;
	explicit ProcessManager();
	~ProcessManager();

	std::unordered_map<std::string, AtlasThread*> runningProcesses;
};
