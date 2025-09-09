#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Funzione di stampa per debug
void print_list(List* list) {
    if (!list || empty_list(list)) {
        printf("Lista vuota\n");
        return;
    }
    Position curr = list->head;
    while (curr) {
        printf("%d <-> ", (int)(intptr_t)curr->data); // cast a int per test
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    printf("=== Test Lista Doppiamente Concatenata ===\n");

    List* list = create_list();

    printf("\n1. Inserimento in lista vuota (10 in testa)\n");
    ins_list(list, (void*)(intptr_t)10, 0);
    print_list(list);

    printf("\n2. Inserimento in testa (20 in posizione 0)\n");
    ins_list(list, (void*)(intptr_t)20, 0);
    print_list(list);

    printf("\n3. Inserimento in coda (30 in posizione list_size)\n");
    ins_list(list, (void*)(intptr_t)30, list->list_size);
    print_list(list);

    printf("\n4. Inserimento in posizione intermedia (25 in posizione 2)\n");
    ins_list(list, (void*)(intptr_t)25, 2);
    print_list(list);

    printf("\n5. Rimozione dalla testa\n");
    remove_list(list, 0);
    print_list(list);

    printf("\n6. Rimozione dalla coda\n");
    remove_list(list, list->list_size - 1);
    print_list(list);

    printf("\n7. Rimozione da posizione intermedia\n");
    remove_list(list, 1);
    print_list(list);

    printf("\n8. Rimozione da lista vuota (dopo svuotamento completo)\n");
    remove_list(list, 0);
    remove_list(list, 0);
    print_list(list);

    printf("\n9. Inserimento in lista vuota (40 in testa)\n");
    ins_list(list, (void*)(intptr_t)40, 0);
    print_list(list);

    return 0;
}

