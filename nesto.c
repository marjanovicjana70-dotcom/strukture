#include "nesto.h"
#include <stdio.h>


int main(){
int arr[6] = {14, 2, 5, 8, 10, 16};
Heap *hip;
heap_init(hip, arr, 6);
heap_build(arr, 6, HEAP_MAX);

for(int i = 0; i < 6; i++){


    printf("%d -> ", hip->arr[i]);
}

}