#include "strukture.h"



Node *create_node(const int val){

Node *const node = (Node *)malloc(sizeof(Node));

if(node == NULL) return NULL;

node->val = val;
node->next = NULL;

return node;

}


Node *remove_last(Node *head){

if(head == NULL) return NULL;

if(head->next == NULL) {
    free(head);
    return NULL;
}

Node *traverse = head;
while(traverse && traverse->next){

if(traverse->next->next == NULL){

free(traverse->next);
traverse->next = NULL;
break;
}


traverse = traverse->next;


}
return head;

}







Node *find_node(Node *head, const int val){

while(head){

if(head->val == val){
return head;

}
head = head->next;

}

return NULL;


}



Node *remove_node(Node *head, const int val){

if(head == NULL) return NULL;

Node *dummy = (Node *)(malloc(sizeof(Node)));
if(dummy==NULL) return head;

dummy->val = 0;
dummy->next = head;


Node *prev = dummy;
Node *curr = head;


while(curr){

if(curr->val == val){

prev->next = curr->next;
free(curr);

break;

}
else {
prev = curr;
curr = curr->next;

}


}

Node *newHead = dummy->next;

free(dummy);

return newHead;



}


Node *merge_sorted_lists(Node *head1, Node *head2){

if(!head1 && !head2){
    return NULL;
}

if(!head1){
    return head2;
}
else if(!head2){
    return head1;
}
Node *new_head;


if(head1->val <= head2->val){

    new_head = head1;
    head1 = head1->next;
}
else {

    new_head = head2;
    head2 = head2->next;
}


Node *start = new_head;


while(head1 && head2){

if(head1->val <= head2.val){

start->next = head1;
head1 = head1->next;

}
else {

start->next = head2;
head2 = head2->next;


}

start = start->next;

}


while(head1){

start->next = head1;
head1 = head1->next;
start = start->next;

}
while(head2){

start->next = head2;
head2 = head2->next;
start = start->next;


}


return new_head;


}

t_bool is_cycle(Node *head){

if(!head) return FALSE;
Node *slow = head;
Node *fast = head;

while(fast && fast->next){

slow = slow->next;
fast = fast->next->next;


if(slow == fast){


    return TRUE;
}




}


return FALSE;

}


Node *reverse_list(Node *head){

if(head == NULL) return head;


Node *prev = NULL;
Node *curr = NULL;

while(head){


curr = head;
head = head->next;
curr->next = prev;
prev = curr;


}

return curr;



}



Node *get_intersection_node(Node *head1, Node *head2){

if(!head1 || !head2) {
    return NULL;
}

Node *a = head1;
Node *b = head2;

while(a != b){

if(a == NULL){
    a = head2;
}
else {

a = a -> next;    
}

if(b == NULL){
    b = head1;
}
else {
    b = b -> next;
}

}

return a;


}



Node *nodeSwap(Node *head, int k){

Node *first = NULL;
Node *second = NULL;

Node *ptr = head;
int indeks = 1;

while(ptr){

if(indeks == k){

first = ptr;
second = head;


}

if(ptr->next == NULL){
int val = first->val;
first->val = second->val;
second->val = val;

}
ptr = ptr->next;

if(second){
    second = second->next;
}
indeks++;
}

return head;

}


Node  *partition_list(Node *head, int x){

if(head == NULL) return NULL;

Node less;
Node more;
less.next = NULL;
more.next = NULL;

Node *lessPtr = &less;
Node *morePtr = &more;

Node *start = head;

while(start){

if(start->val >= x){

morePtr->next = start;
morePtr = morePtr->next;


}
else {

lessPtr->next = start;
lessPtr = lessPtr->next;

}
start = start->next;
}

morePtr->next = NULL;

lessPtr->next = more.next;


return less.next;
}