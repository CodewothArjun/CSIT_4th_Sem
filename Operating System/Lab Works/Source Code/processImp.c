#include <windows.h>
#include <stdio.h>

int main() {
    
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(
            NULL,                   
            "notepad.exe",         
            NULL,                  
            NULL,                 
            FALSE,                  
            0,                      
            NULL,                  
            NULL,                   
            &si,                    
            &pi)                   
    ) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printf("Child process has terminated.\n");

    return 0;
}
