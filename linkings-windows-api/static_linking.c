// static_linking.c
// compile: gcc static_linking.c -o static_linking.exe

#include <string.h>
#include <windows.h>
#include <stdio.h>

int main() {
    SYSTEM_INFO sysInfo;
    MEMORYSTATUSEX memStatus;
    DWORD procCount;

    memStatus.dwLength=sizeof(memStatus);
    GetSystemInfo(&sysInfo);
    GlobalMemoryStatusEx(&memStatus);

    printf("===== Static Linking Example =====\n\n");
    printf("Process Architecture:");
    switch(sysInfo.wProcessArchitecture) {
        case PROCESS_ARCHITECTURE_AMD64:
            printf("x64 (AMD or Intel)\n");
            break;
        case PROCESS_ARCHITECTURE_ARM:
            printf("ARM64\n");
            break;
        case PROCESS_ARCHITECTURE_INTEL:
            printf("x86\n");
            break;
        default:
            printf("Unknown\n");
    }

    procCount=sysInfo.dwNumberOfProcessors;
    printf("Number of Processors: %lu\n",procCount);
    printf("Page Size: %lu bytes\n",sysInfo.dwPageSize);
    printf("\nMemory Information:\n");
    printf("Memory Load: %lu%%\n", memStatus.dwMemoryLoad);
    printf("Total Physical Memory: %.2f GB\n", (double)memStatus.ullTotalPhys / (1024*1024*1024));
    printf("Available Physical Memory: %.2f GB\n", (double)memStatus.ullAvailPhys / (1024*1024*1024));
    
    printf("\nThis example demonstrates static linking where Windows API functions\n");
    printf("are resolved at compile time by the linker using the import libraries.\n");
    
    return 0;
}
