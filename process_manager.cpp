#include "process_manager.h"

ProcessManager* ProcessManager::manager;

ProcessManager::ProcessManager() {}

ProcessManager::~ProcessManager() {};

ProcessManager* ProcessManager::GetManager() {
	if (manager == nullptr) {
		manager = new ProcessManager();
	}

	return manager;
}

void ProcessManager::RunExecutable(QString& executablePath) {
	AddRunningProcessEntry(executablePath);
}

void ProcessManager::AddRunningProcessEntry(QString& executablePath) {
	AtlasThread* thread = new AtlasThread(executablePath);
	connect(thread, SIGNAL(threadFinished(QString)), this, SLOT(RemoveRunningProcessEntry(QString)));
	runningProcesses[executablePath.toStdString()] = thread;
	thread->start();
	emit threadStarted(executablePath);
}


void ProcessManager::RemoveRunningProcessEntry(QString executablePath) {
	runningProcesses.erase(executablePath.toStdString());
	emit threadFinished(executablePath);
}