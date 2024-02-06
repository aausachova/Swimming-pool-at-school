#ifndef BST_H
#define BST_H

typedef struct node {
    int value;
    struct node *right, *left;
} node;

node *bstree_create_node(int value);
void bstree_insert(node *root, int value);

#endif  // BST_H