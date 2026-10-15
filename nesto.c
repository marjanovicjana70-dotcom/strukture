#include <stdio.h>
#include <stdint.h>

#define PARENT(x) ((x - 1) >> 1)
#define LEFT(x) (((x) << 1) + 1)
#define RIGHT(x) (((x) << 1) + 2)

typedef enum {

HEAP_MAX = 0,
HEAP_MIN = 1

} heap_property_t;


typedef struct heap {

int *arr;
int len;
int heap_size;


} Heap;








uint8_t max_heap_insert(Heap *heap, const int val, heap_property_t property){

if(heap->heap_size >= heap->len) return 0;

int idx = heap->heap_size;
heap->arr[idx] = val;
heap->heap_size++;

while(idx > 0){

int parent = PARENT(idx);

if(heap->arr[parent] >= heap->arr[idx]) break;

int tmp = heap->arr[idx];
heap->arr[idx] = heap->arr[parent];
heap->arr[parent] = tmp;

idx = parent;

}


return 1;

}

void max_heapify(Heap *heap, const int idx){

int left = LEFT(idx);
int right = RIGHT(idx);

int largest = idx;



if(left < heap->heap_size && heap->arr[left] > heap->arr[idx]) largest = left;

if(right < heap->heap_size && heap->arr[right] > heap->arr[largest]) largest = right;


if(largest != idx){

int tmp = heap->arr[largest];
heap->arr[largest] = heap->arr[idx];
heap->arr[idx] = tmp;

max_heapify(heap, largest);


}


}

uint8_t max_heap_remove(Heap *heap, int idx){

if(idx >= heap->heap_size){

    return 0;

}


heap->arr[idx] = heap->arr[heap->heap_size - 1];


max_heapify(heap, idx);

heap->arr[heap->heap_size - 1] = 0;
heap->heap_size--;
return 1;
}


void max_heap_build(Heap *heap){

int idx = ( heap->heap_size / 2 ) - 1;

for(int i = idx; i >= 0; i--){


max_heapify(heap, i);


}




}


void heapsort(int *arr, int size){

if(arr == NULL) return;


Heap tmp;
tmp.arr = &arr[0];

tmp.heap_size = size;

tmp.len = size;

max_heap_build(&tmp);

int ct = 0;

while(ct < size){

int val = tmp.arr[0];
tmp.arr[0] = tmp.arr[size - ct - 1];
tmp.arr[size - ct - 1] = val;

tmp.heap_size--;
max_heapify(&tmp, 0);

ct++;



}


}

int main(){



int arr[100] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

heapsort(&arr[0], 10);


printf("Sortirani niz\n");
for(int i = 0; i < 10; i++){

printf("%d -> ", arr[i]);

}


}