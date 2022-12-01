#ifndef AOCUTIL_H
#define AOCUTIL_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

unsigned int ato_ui(char* s)
{
    unsigned int ui = 0;
    while (*s != '\0') {
        ui = (ui*10) + (*s - '0');
        ++s;
    }
    return ui;
}

#endif
