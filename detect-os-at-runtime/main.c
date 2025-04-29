#include <stdio.h>

int main() {
#ifdef _WIN32
    printf("Windows");
#elif __linux__
    printf("Linux");
#elif __APPLE__
    printf("MacOS");
#else
    printf("unknown OS");
#endif
}
