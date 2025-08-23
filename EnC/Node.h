#ifndef __NODE_H__
#define __NODE_H__

typedef struct Node {
    double value;
    struct Node* next;
} Node;

Node* create_new_node(const double value);
#endif
