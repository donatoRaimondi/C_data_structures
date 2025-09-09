#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

// Funzione di stampa
void print_list(List* list) {
    if (!list || empty_list(list)) {
        printf("Lista vuota\n");
        return;
    }
    Position curr = list->head;
    while (curr) {
        printf("%d <-> ", *(int*)curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Funzione helper per creare interi dinamici
int* create_int(int value) {
    int* ptr = malloc(sizeof(int));
    if (!ptr) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    *ptr = value;
    return ptr;
}

int main() {
    printf("=== Test Lista Doppiamente Concatenata ===\n");

    List* list = create_list();

    // 1. Inserimento in lista vuota
    ins_list(list, create_int(10), 0);
    print_list(list);

    // 2. Inserimento in testa
    ins_list(list, create_int(20), 0);
    print_list(list);

    // 3. Inserimento in coda
    ins_list(list, create_int(30), list->list_size);
    print_list(list);

    // 4. Inserimento in posizione intermedia
    ins_list(list, create_int(25), 2);
    print_list(list);

    // 5. Rimozione dalla testa
    free(list->head->data); // libero il dato prima di rimuovere
    remove_list(list, 0);
    print_list(list);

    // 6. Rimozione dalla coda
    free(list->head->next->data); // libero dato coda
    remove_list(list, list->list_size - 1);
    print_list(list);

    // 7. Rimozione da posizione intermedia
    free(list->head->next->data); // libero dato
    remove_list(list, 1);
    print_list(list);

    // 8. Rimozione dalla lista fino a vuota
    free(list->head->data);
    remove_list(list, 0);
    print_list(list);

    // 9. Inserimento in lista vuota
    ins_list(list, create_int(40), 0);
    print_list(list);

    // Pulizia finale
    while (!empty_list(list)) {
        free(list->head->data); // libero il dato
        remove_list(list, 0);
    }
    free_list(list);

    printf("=== Fine Test ===\n");
    return 0;
}   