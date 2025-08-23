#include "List.h"
#include "Node.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

List* create_list() {
    List* new_list = malloc(sizeof(*new_list));

    if (new_list) {
        new_list->root = NULL;
        printf("liste creer a l'adresse : [%p]\n", new_list);
        return new_list;
    } else {
        printf("echec d'allocation pour la liste.\n");
        return NULL;
    }
}

bool is_empty(const List* MyList) {
    return MyList->root == NULL;
}
bool search_value(const List *MyList, const double value) {
    Node* new_node = create_new_node(value);
    return find_node(MyList, new_node);
}
void insert(List *MyList, const double value) {
    Node* new_node = create_new_node(value);

    if (is_empty(MyList)) {
        MyList->root = new_node;
    } else {
        Node* tmp_root = MyList->root;
        while (tmp_root->next != NULL) {
            tmp_root = tmp_root->next;
        }
        tmp_root->next = new_node;
    }
    MyList->size++;
}

void delete_node(List *MyList, const double value) {
    unsigned int taille = MyList->size;
    Node* tmp_root = MyList->root;

    if (!search_value(MyList, value) || is_empty(MyList)) {
        printf("l'element que vous voulez supprimer n'est pas dans la liste.\n");
    } else {
        size_t position = get_position(MyList, value);
        Node* previous_node = find_adjacent_node(MyList, position - 1);

        MyList->size--;
    }
}

size_t get_position(const List *MyList, const double value) {
    Node* new_node = create_new_node(value);

    if (is_empty(MyList)) {
        printf("la liste est vide.\n");
        return SIZE_MAX;

    } else if (!find_node(MyList, new_node)){
        printf("ce noeud n'est pas dans la liste.\n");
        return SIZE_MAX;
    } else {
        size_t npos = 0;
        Node* tmp_root = MyList->root;

        while (tmp_root != NULL) {
            if (tmp_root->value == new_node->value) break;
            tmp_root = tmp_root->next;
            npos++;
        }
        return npos;
    }
}

void display_list(const List *MyList) {
    Node* tmp_root = MyList->root;
    while (tmp_root != NULL) {
        printf("[%lf]->", tmp_root->value);
        tmp_root = tmp_root->next;
    }
    
    printf("0x000\ntaille de la liste : %zu", MyList->size);
    printf("\n");
}

void delete_list(List *MyList) {
    if (is_empty(MyList)) {
        printf("la liste est vide.\n");
    } else {
        Node* tmp_root = MyList->root;
        Node* tmp = NULL;

        while(tmp_root != NULL) {
            tmp = tmp_root->next;
            free(tmp_root);
            tmp_root = tmp;
        }
    }
    
    printf("l'arbre à l'adresse [%p] ete completement desallouer.\n", MyList);
}

static Node* find_adjacent_node(const List* MyList, const size_t position) {
    size_t i = 0;
    Node* tmp_root = MyList->root;
    while (i < position) {
        tmp_root = tmp_root->next;
        i++;
    }
    return tmp_root;
}

static bool find_node(const List* MyList, const Node* arg) {
    if (is_empty(MyList)) {
        return false;
    } else {
        Node* tmp_root = MyList->root;
        while (tmp_root != NULL) {
            if (tmp_root->value == arg->value) {
                return true;
            }
            tmp_root = tmp_root->next;
        }
        return false;
    }
}   
