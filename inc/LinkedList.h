#ifndef _LINKED_LIST_H

#define _LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

//singly linked list

typedef struct node {

int val;
struct node* next;

} Node;



typedef enum e_bool {

FALSE,
TRUE


} t_bool;



Node *create_node(const int val);
Node *find_node(Node *head, const int val);
Node *remove_last(Node *head);
Node *merge_sorted_lists(Node *head1, Node *head2);
t_bool is_cycle(Node *head);
Node *reverse_list(Node *head);
Node *get_intersection_node(Node *head1, Node *head2);
Node *nodeSwap(Node *head, int k);
Node *partition_list(Node *head, int x);



#endif