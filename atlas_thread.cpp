#include "atlas_thread.h"
#ifdef _WINDOWS
#include "windows.h"
#endif

AtlasThread::AtlasThread(QString executablePath, QObject* parent) : executablePath(executablePath), QThread(parent) {}

void AtlasThread::run() {
    // Run executable and wait till the process finishes
#ifdef _WINDOWS
    // additional information
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // start the program up
    CreateProcessA
    (
        executablePath.toStdString().c_str(),   // the path
        NULL,                // Command line
        NULL,                   // Process handle not inheritable
        NULL,                   // Thread handle not inheritable
        FALSE,                  // Set handle inheritance to FALSE
        CREATE_NEW_CONSOLE,     // Opens file in a separate console
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi           // Pointer to PROCESS_INFORMATION structure
    );

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
#endif
    
    emit threadFinished(executablePath);
}