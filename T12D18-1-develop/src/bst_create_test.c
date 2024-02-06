#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    struct node* new_1 = bstree_create_node(10);
    struct node* new_2 = bstree_create_node(20);
    printf("%d\n", new_1->value);
    printf("%d\n", new_2->value);
    free(new_1);
    free(new_2);
    return 0;
}
