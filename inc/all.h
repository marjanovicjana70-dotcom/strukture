#ifndef __ALL__HEADER
#define __ALL__HEADER
#include <stdio.h>
#include <stdlib.h>
#define CHECK_PTR(ptr) { \
    if(NULL == ptr){     \
        fprintf(stderr, "Error: %s, file: %s, line %d\n", #ptr, __FILE__, __LINE__); \
        exit(-1); \
    } \
}




#endif