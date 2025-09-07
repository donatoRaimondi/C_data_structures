#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node { 
	void *data;
	struct Node *next;
	struct Node *prev;
} Node; 

Node* create_node(void *data);
void free_node(Node *node);

Node* next_node(Node *node);
Node* prev_node(Node *node);


#endif
