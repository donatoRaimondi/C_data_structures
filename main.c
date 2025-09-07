#include <stdio.h>
#include "node.h"

int main(){
	int* x = malloc(sizeof(int));
	*x = 42;
	int* y= malloc(sizeof(int));
	*y = 17;

	Node *nodex = create_node(x);
	Node *nodey = create_node(y);
	nodex->next = nodey;	
	printf("%d\n", *(int*)nodex->data);
	printf("%d\n", *(int*)nodex->next->data);
	printf("%d\n", *(int*)nodey->data);	
	

	free(nodex->data);
	free(nodex);
	free(nodey->data);
        free(nodey);

	return 0;
}

