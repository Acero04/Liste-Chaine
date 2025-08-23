#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_new_node(const double value) {
    Node* new_node = malloc(sizeof(*new_node));

    if (new_node) {
        new_node->value = value;
        new_node->next = NULL;
        return new_node;
    } else {
        printf("l'allocation pour un nouveau noeud a echouer.\n");
        return NULL;
    }
}
