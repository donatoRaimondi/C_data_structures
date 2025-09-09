#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include "../node.h"

typedef Node* Position;

typedef struct List {
	Position head;
	int list_size; //the size of the list	
} List;

List* create_list();
bool empty_list(List* list);
bool end_list(List* list,Posizione pos);
Position first_list(List* list);
Position succ_list(Position pos); //returns the next node in the list
Position prev_list(Position pos); //in this implementation it has to start from pos(0) to pos(curr-1)							     
void ins_list(List* list, void* node, Position pos); //add a node to the list, in the logical position passed (0 is the head)
void remove_list(List* list, int pos);
void* read_list(int pos);
void write_list(Position pos, void* data); //write inside the node, in the position written
						      

#endif
