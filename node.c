#include "node.h"


Node* create_node(void *data){
	//dynamic allocation for the single Node 
	Node *node = (Node*)malloc(sizeof(Node));

	if(!node) return NULL;

	node->data=data;
	node->next=NULL;
	node->prev=NULL;
	return node;
}
