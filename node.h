#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node { 
	void *data;
	struct Node *next;
	struct Node *prev;
} Node; 

Node* create_node(void *data);
void write_node(Node* node, void *data); //sovrascrive il nodo inserendo un nuovo valore			     
void free_node(Node *node);

Node* next_node(Node *node); //restituisce il nodo succ
Node* prev_node(Node *node);
void set_next_node(Node *node, Node *next);
void set_prev_node(Node *node, Node *prev);

#endif
