#include "Heap.h"

void heapify(Heap *heap, int idx, heap_property_t property_type){

int left = LEFT(idx);
int right = RIGHT(idx);

int largest = idx;

if(property_type == HEAP_MAX){

if(left < heap->heap_size && heap->arr[left] > heap->arr[idx]) largest = left;

if(right < heap->heap_size && heap->arr[right] > heap->arr[largest]) largest = right;

}
else if(property_type == HEAP_MIN){


if(left < heap->heap_size && heap->arr[left] < heap->arr[idx]) largest = left;

if(right < heap->heap_size && heap->arr[right] < heap->arr[largest]) largest = right;


}




if(largest != idx){

int tmp = heap->arr[largest];
heap->arr[largest] = heap->arr[idx];
heap->arr[idx] = tmp;

heapify(heap, largest);

}


}






