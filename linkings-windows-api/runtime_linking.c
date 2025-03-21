// runtime_linking.c
// Demonstrates runtime linking with Windows API functions using LoadLibrary and GetProcAddress
// Compile with: gcc runtime_linking.c -o runtime_linking.exe

#include <windows.h>
#include <stdio.h>

// Function pointer types for the functions we'll load at runtime
typedef BOOL (WINAPI *GetVersionExFunc)(LPOSVERSIONINFOW);
typedef BOOL (WINAPI *GetComputerNameFunc)(LPWSTR, LPDWORD);

int main() {
    HMODULE kernel32;
    GetVersionExFunc pGetVersionEx;
    GetComputerNameFunc pGetComputerName;
    
    OSVERSIONINFOW osInfo;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD computerNameSize = MAX_COMPUTERNAME_LENGTH + 1;
    
    // Initialize the OSVERSIONINFOW structure
    ZeroMemory(&osInfo, sizeof(OSVERSIONINFOW));
    osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOW);
    
    printf("===== Runtime Linking Example =====\n\n");
    
    // Load the library at runtime
    kernel32 = LoadLibrary(TEXT("kernel32.dll"));
    
    if (kernel32 == NULL) {
        printf("Failed to load kernel32.dll! Error code: %lu\n", GetLastError());
        return 1;
    }
    
    printf("Successfully loaded kernel32.dll\n");
    
    // Get the address of the GetVersionExW function
    pGetVersionEx = (GetVersionExFunc)GetProcAddress(kernel32, "GetVersionExW");
    
    if (pGetVersionEx == NULL) {
        printf("Failed to get address of GetVersionExW! Error code: %lu\n", GetLastError());
        FreeLibrary(kernel32);
        return 1;
    }
    
    // Get the address of the GetComputerNameW function
    pGetComputerName = (GetComputerNameFunc)GetProcAddress(kernel32, "GetComputerNameW");
    
    if (pGetComputerName == NULL) {
        printf("Failed to get address of GetComputerNameW! Error code: %lu\n", GetLastError());
        FreeLibrary(kernel32);
        return 1;
    }
    
    printf("Successfully retrieved function addresses\n\n");
    
    // Call the functions using the function pointers
    if (pGetVersionEx(&osInfo)) {
        printf("Windows Version Information:\n");
        printf("Major Version: %lu\n", osInfo.dwMajorVersion);
        printf("Minor Version: %lu\n", osInfo.dwMinorVersion);
        printf("Build Number: %lu\n", osInfo.dwBuildNumber);
    } else {
        printf("Failed to get OS version information\n");
    }
    
    if (pGetComputerName(computerName, &computerNameSize)) {
        wprintf(L"\nComputer Name: %s\n", computerName);
    } else {
        printf("\nFailed to get computer name\n");
    }
    
    // Free the library when done
    FreeLibrary(kernel32);
    printf("\nThis example demonstrates runtime linking where Windows API functions\n");
    printf("are loaded at runtime using LoadLibrary and GetProcAddress functions.\n");
    
    return 0;
}
