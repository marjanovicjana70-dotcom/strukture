#ifndef _DOUBLY_LINKED_H
#define _DOUBLY_LINKED_H


#include <stdlib.h>
#include <stdio.h>

typedef struct nodeD {

int val;
struct nodeD *prev;
struct nodeD *next;
    
} NodeD;


NodeD *create_nodeD(NodeD *prev, const int val);
NodeD *delete_node(NodeD *node);
NodeD *delete_node_at_end(NodeD *node);
NodeD *delete_node_at_beginning(NodeD *node);


#endif