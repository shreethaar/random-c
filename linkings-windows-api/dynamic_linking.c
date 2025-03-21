// dynamic_linking.c
// Demonstrates dynamic linking with a custom DLL
// Compile with: gcc dynamic_linking.c -o dynamic_linking.exe

#include <windows.h>
#include <stdio.h>

// First, we need to create a DLL. Here's the code for the DLL file:
// Save this as "windows_utils.c" and compile with:
// gcc -shared -o windows_utils.dll windows_utils.c

/*
// windows_utils.c - DLL source code
#include <windows.h>

// Export these functions from the DLL
__declspec(dllexport) DWORD GetWindowsUptime() {
    return GetTickCount() / 1000; // Convert milliseconds to seconds
}

__declspec(dllexport) BOOL GetWindowsDirectory(LPSTR buffer, DWORD size) {
    return GetWindowsDirectoryA(buffer, size);
}

__declspec(dllexport) UINT GetSystemDriveType() {
    CHAR rootPath[4] = "C:\\";
    return GetDriveTypeA(rootPath);
}
*/

// Define the function pointers for the functions we'll import from the DLL
typedef DWORD (*GetWindowsUptimeFunc)();
typedef BOOL (*GetWindowsDirectoryFunc)(LPSTR, DWORD);
typedef UINT (*GetSystemDriveTypeFunc)();

// Function to print the drive type
void PrintDriveType(UINT type) {
    switch (type) {
        case DRIVE_UNKNOWN:
            printf("Unknown drive type\n");
            break;
        case DRIVE_NO_ROOT_DIR:
            printf("Invalid root path\n");
            break;
        case DRIVE_REMOVABLE:
            printf("Removable drive\n");
            break;
        case DRIVE_FIXED:
            printf("Fixed drive\n");
            break;
        case DRIVE_REMOTE:
            printf("Network drive\n");
            break;
        case DRIVE_CDROM:
            printf("CD-ROM drive\n");
            break;
        case DRIVE_RAMDISK:
            printf("RAM disk\n");
            break;
        default:
            printf("Unrecognized drive type\n");
    }
}

int main() {
    HMODULE dll;
    GetWindowsUptimeFunc pGetWindowsUptime;
    GetWindowsDirectoryFunc pGetWindowsDirectory;
    GetSystemDriveTypeFunc pGetSystemDriveType;
    DWORD uptime;
    CHAR winDir[MAX_PATH];
    UINT driveType;
    
    printf("===== Dynamic Linking Example =====\n\n");
    
    // Load the DLL
    dll = LoadLibrary("windows_utils.dll");
    
    if (dll == NULL) {
        printf("Failed to load windows_utils.dll! Error code: %lu\n", GetLastError());
        printf("\nNote: You need to compile the DLL first with:\n");
        printf("gcc -shared -o windows_utils.dll windows_utils.c\n");
        return 1;
    }
    
    printf("Successfully loaded windows_utils.dll\n");
    
    // Get the function addresses
    pGetWindowsUptime = (GetWindowsUptimeFunc)GetProcAddress(dll, "GetWindowsUptime");
    pGetWindowsDirectory = (GetWindowsDirectoryFunc)GetProcAddress(dll, "GetWindowsDirectory");
    pGetSystemDriveType = (GetSystemDriveTypeFunc)GetProcAddress(dll, "GetSystemDriveType");
    
    if (pGetWindowsUptime == NULL || pGetWindowsDirectory == NULL || pGetSystemDriveType == NULL) {
        printf("Failed to get one or more function addresses! Error code: %lu\n", GetLastError());
        FreeLibrary(dll);
        return 1;
    }
    
    printf("Successfully retrieved function addresses\n\n");
    
    // Call the functions
    uptime = pGetWindowsUptime();
    printf("Windows Uptime: %lu seconds (%.2f hours)\n", uptime, (float)uptime / 3600);
    
    if (pGetWindowsDirectory(winDir, MAX_PATH)) {
        printf("Windows Directory: %s\n", winDir);
    } else {
        printf("Failed to get Windows directory\n");
    }
    
    driveType = pGetSystemDriveType();
    printf("System Drive Type: ");
    PrintDriveType(driveType);
    
    // Free the DLL when done
    FreeLibrary(dll);
    
    printf("\nThis example demonstrates dynamic linking where functions from a custom DLL\n");
    printf("are loaded at runtime. The DLL itself must be compiled separately.\n");
    
    return 0;
}
