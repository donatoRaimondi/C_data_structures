#include "list.h"

List* create_list() {
    List* list = malloc(sizeof(List));

    if (!list) return NULL;

    list->head = NULL;
    list->list_size = 0;

    return list;
}

bool empty_list(List* list);
Position first_list(List* list);
Position succ_list(Position pos); //returns the next node in the list
Position prev_list(Position pos); //in this implementation it has to start from pos(0) to pos(curr-1)                                                                                     
void ins_list(List* list, void* node, Position pos); //add a node to the list, in the logical position passed (0 is the head)
void remove_list(List* list, Position pos);
void* read_list(Position pos);
void write_list(Position pos, void* data); //write inside the node, in the position written
