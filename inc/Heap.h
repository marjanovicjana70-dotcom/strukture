#ifndef _HEAP_H
#define _HEAP_H

#define PARENT(x) ((x - 1) >> 1)
#define LEFT(x) (((x) << 1) + 1)
#define RIGHT(x) (((x) << 1) + 2)
#define MAX_SIZE 100

#include <stdio.h>

typedef enum {

HEAP_MAX = 0,
HEAP_MIN = 1

} heap_property_t;


typedef struct heap {

int *arr;
int len;
int heap_size;


} Heap;


void heapify(Heap *heap, int idx, heap_property_t property);



#endif