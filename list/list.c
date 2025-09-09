#include "list.h"

List* create_list() {
    List* list = malloc(sizeof(List));

    if (!list) return NULL;

    list->head = NULL;
    list->list_size = 0;

    return list;
}

bool empty_list(List* list) {
    return (list == NULL) || (list->head == NULL);
}

bool end_list(Position pos){
    return (succ_list(pos) == NULL);
}

Position first_list(List* list){
    return list->head;		
}

Position succ_list(Position pos){
    return next_node(pos);
}

Position prev_list(Position pos){
    return prev_node(pos);
}

void ins_list(List* list, void* data, int pos){
    if (!list || pos < 0 || pos > list->list_size) return;

    Position node = create_node(data);

    // insert in first position, but with empty list
    if(empty_list(list)){
	    list->head = node;
	    list->list_size++;
	    return;
    }

    // insert in first position
    if(pos == 0){
	set_next_node(node,list->head);
	if(list->head){
		set_prev_node(list->head, node);
	}
	list->head = node;
        list->list_size++;
	return;
    }

    // appending (tail insert)
    if(pos == list->list_size){
        Position curr = first_list(list);
	while(end_list(curr)){
     		curr = succ_list(curr);
	}
	set_next_node(curr, node);
	set_prev_node(node, curr);
	list->list_size++;
	return;
    }
    
    // insert in middle pos(i)
    Position curr = first_list(list);
    for(int i = 0; i < pos - 1; i++){
	    curr = succ_list(curr);
    }
    node->next = curr->next;
    node->prev = curr;
    curr->next->prev = node;
    curr->next = node;

    list->list_size++;
}

void remove_list(List* list, int pos){
    if (!list || pos < 0 || pos >= list->list_size) return;
    // delete the head - set the new head to head->next	
    if(pos == 0){
	Position node = list->head;    
	list->head = next_node(list->head);
	if(list->head) list->head->prev = NULL;
	free_node(node);
	list->list_size--;
	return;
    }	    

    // remove in the middle
    Position curr = first_list(list);
    for(int i = 0; i < pos; i++){
        curr = succ_list(curr);
    }
    
    if(curr->prev){
	curr->next->prev = curr->next;
    } 
    if(curr->next){
	curr->next->prev = curr->prev;
    }

    free_node(curr);
    list->list_size--;
}

void* read_list(List *list, int pos){
    if (!list || pos < 0 || pos >= list->list_size) return;
    Position curr = first_list(list);
    for(int i = 0; i < pos; i++){
        curr = succ_list(curr);
    }

    return curr->data;
}

void write_list(List *list, int pos, void* data){ //write inside the node, in the position written
    if (!list || pos < 0 || pos >= list->list_size) return;
    Position curr = first_list(list);
    for(int i = 0; i < pos; i++){
        curr = succ_list(curr);
    }
    write_node(curr, data);
}
