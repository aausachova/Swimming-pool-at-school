#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

node* bstree_create_node(int value) {
    node* new = malloc(sizeof(node));
    new->value = value;
    new->right = NULL;
    new->left = NULL;
    return new;
};

void bstree_insert(node* root, int value) {
    if (root == NULL) {
        root = bstree_create_node(value);
    } else {
        if (value < root->value) {
            if (root->left == NULL) {
                root->left = bstree_create_node(value);
            } else {
                bstree_insert(root->left, value);
            }
        } else {
            if (root->right == NULL) {
                root->right = bstree_create_node(value);
            } else {
                bstree_insert(root->right, value);
            }
        }
    }
}
