#ifndef MAKRO
#define MAKRO

#include <stdio.h>
#include <stdlib.h>

#define NULL_PTR(ptr) \
{                      \
    if(NULL == ptr){    \
        fprintf(stderr, "greska je %s \n fajl: %s \n linija: %d", #ptr, __FILE__, __LINE__); \
        exit(-1);  \
    }  \
} \



#endif