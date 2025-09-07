#import <stdio.h>
// #import <stdlib.h>

typedef struct Node (
    int value;
    struct Node* next;
) Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}