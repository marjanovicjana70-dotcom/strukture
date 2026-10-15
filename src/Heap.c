#include "Heap.h"


void heap_init(Heap *heap, int *storage_arr, const int len){

heap->len = len;
heap->heap_size = 0;
heap->arr = storage_arr;



}


void max_heapify(int *arr, const int size, const int idx){

if(size < 2 || idx < 0) return;

int left = LEFT(idx);
int right = RIGHT(idx);

int largest = idx;



if(left < size && arr[left] > arr[idx]) largest = left;

if(right < size && arr[right] > arr[largest]) largest = right;


if(largest != idx){

int tmp = arr[largest];
arr[largest] =arr[idx];
arr[idx] = tmp;

max_heapify(arr, size, largest);


}


}

void min_heapify(int *arr,const int size, const int idx){


if(size < 2 || idx < 0) return;


int left = LEFT(idx);
int right = RIGHT(idx);

int smallest = idx;


if(left < size && arr[left] < arr[idx]) smallest = left;

if(right < size && arr[right] < arr[smallest]) smallest = right;


if(smallest != idx){

int tmp = arr[smallest];
arr[smallest] = arr[idx];
arr[idx] = tmp;

min_heapify(arr, size, smallest);


}



}



void heap_build(int *arr, int size, heap_property_t property){

void (*heapify)(int*, int, int);

if(property == HEAP_MAX) heapify = max_heapify;
else heapify = min_heapify;



int idx = ( size / 2 ) - 1;

for(int i = idx; i >= 0; i--){

heapify(arr, size, i);


}




}


int heap_peek(Heap *heap, uint8_t *success){

if (heap->heap_size <= 0){

*success = 0;
return 0;

}

*success = 1;
return heap->arr[0];


}


int heap_extract(Heap *heap, heap_property_t property, uint8_t *success){

if(heap->heap_size < 1){
    *success = 0;
    return 0;
}

void (*heapify)(int*, int, int);

if(property == HEAP_MAX) heapify = max_heapify;
else heapify = min_heapify;



int extracted = heap->arr[0];
*success = 1;


heap->arr[0] = heap->arr[heap->heap_size - 1];

heap->heap_size--;

heapify(heap->arr, heap->heap_size, 0);

return extracted;
}



void heapsort(int *arr, int size, heap_property_t property){

if(arr == NULL || size < 1) return;

void (*heapify)(int*, int, int);


if(property == HEAP_MAX) heapify = max_heapify;

else heapify = min_heapify;



heap_build(arr, size, property);

int ct = 0;

while(ct < size - 1){

int val = arr[0];
arr[0] = arr[size - ct - 1];
arr[size - ct - 1] = val;

size--;
heapify(arr, size, 0);

ct++;



}


}






uint8_t max_heap_insert(Heap *heap, const int val){

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

uint8_t min_heap_insert(Heap *heap, const int val){

if(heap->heap_size >= heap->len) return 0;

int idx = heap->heap_size;
heap->arr[idx] = val;
heap->heap_size++;

while(idx > 0){

int parent = PARENT(idx);

if(heap->arr[parent] <= heap->arr[idx]) break;

int tmp = heap->arr[idx];
heap->arr[idx] = heap->arr[parent];
heap->arr[parent] = tmp;

idx = parent;

}

return 1;

}

/*uint8_t heap_remove(Heap *heap, int idx, heap_property_t property){

if(heap->heap_size <= 0 || idx < 0) return 0;

heap->arr[idx] = heap->arr[heap->heap_size - 1];
heap->arr[heap->heap_size - 1] = 0;
heap->heap_size--;

if(property == HEAP_MAX) max_heapify(heap->arr, heap->heap_size, idx);
else min_heapify(heap->arr, heap->heap_size, idx);

}*/


void pqueue_heapify(PQueue *p, size_t idx){

if(!p || idx < 0 || idx > p->capacity) return;

int largest = idx;

int left = LEFT(idx);
int right = RIGHT(idx);

if(left < p->size && p->compare_func(p->data[left], p->data[idx]) > 0) largest = left;

if(right < p->size && p->compare_func(p->data[right], p->data[largest]) > 0) largest = right;

if(largest != idx){

void *tmp = p->data[idx];
p->data[idx] = p->data[largest];
p->data[largest] = tmp;

pqueue_heapify(p, largest);

}


}



void *pqueue_dequeue(PQueue *p){

if(!p) return NULL;

void *obj = p->data[0];
p->data[0] = p->data[p->size - 1];
p->size--;

//sort
pqueue_heapify(p, 0);

return obj;

}

void pqueue_enqueue(PQueue *p, const void *d2){

if(!p) return;

p->data[p->size] = d2;
p->size++;

int idx = p->size - 1;


while(idx > 0){

int parent = PARENT(idx);

int res =  p->compare_func(p->data[parent], p->data[idx]);
if(res > 0) break;

void *tmp = p->data[idx];
p->data[idx] = p->data[parent];
p->data[parent] = tmp;

idx = parent;

}


}

PQueue *pqueue_new(int (*compare_func)(const void *d1, const void *d2), size_t capacity){










}

void pqueue_delete(PQueue *p){

if(!p) return;

free(p->data);
free(p);



}