#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(){
	int* x = malloc(sizeof(int));
	*x = 42;

	Node *node = create_node(x);
	
	printf("%d\n", *(int*)node->data);	

	free(node->data);
	free(node);

	return 0;
}

