#ifndef _HEAP_H
#define _HEAP_H

#define PARENT(x) ((x - 1) >> 1)
#define LEFT(x) (((x) << 1) + 1)
#define RIGHT(x) (((x) << 1) + 2)
#define MAX_SIZE 100

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef enum {

HEAP_MAX = 0,
HEAP_MIN = 1

} heap_property_t;


typedef struct heap {

int *arr;
int len;
int heap_size;


} Heap;

typedef struct priority_queue {

int size;
int capacity;
void **data;
int (*compare_func)(const void *d1, const void *d2);
/*
vraca 0 ako d1=d2
vraca -1 ako prioritet d1 < prioritet d2
vraca 1 ako prioritet d1 > prioritet d2
*/


}PQueue;

PQueue *pqueue_new(int (*compare_func)(const void *d1, const void *d2), size_t capacity);
void pqueue_enqueue(PQueue *p, const void *data);
void *pqueue_dequeue(PQueue *p);
void pqueue_delete(PQueue *p);



void heap_init(Heap *heap, int *storage_arr, const int len);
void max_heapify(int *arr, const int size, const int idx);
void min_heapify(int *arr, const int size, const int idx);


void heap_build(int *arr, int size, heap_property_t property);



void heapsort(int *arr, int size, heap_property_t property);

int heap_extract(Heap *heap, heap_property_t property, uint8_t *success);
int heap_peek(Heap *heap, uint8_t *success);

uint8_t max_heap_insert(Heap *heap, const int val);
uint8_t min_heap_insert(Heap *heap, const int val);

//uint8_t max_heap_remove(Heap *heap, int idx);
//uint8_t min_heap_remove(Heap *heap, int idx);


#endif