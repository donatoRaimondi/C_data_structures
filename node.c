#include "node.h"


Node* create_node(void *data){
	//dynamic allocation for the single Node 
	Node *node = malloc(sizeof(Node));

	if(!node) return NULL;

	node->data=data;
	node->next=NULL;
	node->prev=NULL;
	return node;
}

void write_node(Node *node, void *data){
	if (node) {
        	node->data = data;
   	}
}

void free_node(Node *node){
	if(node){
		//responsability of deallocation of the node->data is on the caller	
		free(node);
	}
}

Node* next_node(Node *node){
    return node ? node->next : NULL;    
}

Node* prev_node(Node *node){
    return node ? node->prev : null;
}

void set_next_node(Node *node, Node *next) {
    if (node) {
        node->next = next;
    }
}

void set_prev_node(Node *node, Node *prev) {i
    if (node) {
        node->prev = prev;
    }
}
