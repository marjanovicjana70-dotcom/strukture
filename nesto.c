#include "all.h"
#include "Heap.h"

int main(){
Heap new_heap;
int arr[6] = {19, 5, 3, 20, 17, 2};
heap_init(&new_heap, arr, 6);
heap_build(arr, 6, HEAP_MAX);

for(int i=0;i < 6; i++){
    printf("%d -> ", new_heap.arr[i]);
}

heap_build(arr, 6, HEAP_MIN);
for(int i=0;i < 6; i++){
    printf("%d -> ", new_heap.arr[i]);
}
    return 0;
}