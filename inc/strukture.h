#ifndef J_MAKRO

#define J_MAKRO

#include <stdint.h>

//singly linked list



typedef struct {

int data;
struct Node* next;

} Node;

typedef struct {

size_t count;
Node* last;

} NodeMetaData;


Node* add(int val);
Node* removeLast(Node *ptr);










#endif