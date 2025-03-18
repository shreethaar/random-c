#ifndef TAGGED_H
#define TAGGED_H

#include <stdio.h>

#ifdef __linux__
    #define PLATFORM "Linux"
#elif _WIN32
    #define PLATFORM "Windows"
#else
    #define PLATFORM "Unknown"
#endif

void tagged();

#endif // TAGGED_H
