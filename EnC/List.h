#include "Node.h"
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>


typedef struct List {
    Node* root;
    size_t size;
} List;

List* create_list();
bool is_empty(const List* MyList);
bool search_value(const List* MyList, const double value);
void insert(List* MyList, double const value);
void delete_node(List* MyList, const double value);
size_t get_position(const List* MyList, const Node* target);
void display_list(const List* MyList);
void delete_list(List* MyList);


static Node* find_adjacent_node(const List* MyList, const size_t position);
static bool find_node(const List* MyList, const Node* arg);
