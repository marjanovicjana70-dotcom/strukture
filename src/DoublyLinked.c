#include "DoublyLinked.h"

NodeD *create_nodeD(NodeD *prev, const int val){

NodeD *new_node = (NodeD *)(malloc(sizeof(NodeD)));

if(new_node == NULL) return NULL;

new_node->val = val;
new_node->next = NULL;

if(prev){

    prev->next = new_node;
    new_node->prev = prev;

}
else {

    new_node->prev = NULL;
}
return new_node;
}

NodeD *delete_node(NodeD *node){

if(!node) return NULL;

if(!node->prev && node->next){
    return delete_node_at_beginning(node);
}
else if(!node->next && node->prev){
    return delete_node_at_end(node);
}
else if(!node->next && !node->prev) {
    free(node);
    return NULL;
}

node->prev->next = node->next;
node->next->prev = node->prev;

NodeD *tmp = node;
node = node->prev;

free(tmp);

return node;

}

NodeD *delete_node_at_beginning(NodeD *node){

node->next->prev = NULL;

NodeD *tmp = node;
node = node->next;

free(tmp);

return node;

}


NodeD *delete_node_at_end(NodeD *node){

node->prev->next = NULL;
NodeD *tmp = node;
node = node->prev;

free(tmp);

return node;





}