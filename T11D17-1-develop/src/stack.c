#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack *init(stack *stack_1, int id) {
    stack_1 = (stack *)malloc(sizeof(stack));
    if (stack_1 == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    stack_1->data = id;
    stack_1->next = NULL;
    return stack_1;
}

stack *push(stack *stack_1, int id) {
    stack *new = (stack *)malloc(sizeof(stack));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return stack_1;
    }
    new->data = id;
    new->next = stack_1;
    return new;
}

stack *pop(stack *stack_1) {
    if (stack_1 == NULL) {
        return NULL;
    }
    // stack_1 = stack_1->next;
    return stack_1;
}

void destroy(stack *stack_1) {
    stack *desrt = stack_1;

    while (desrt != NULL) {
        stack_1 = stack_1->next;
        free(desrt);
        desrt = stack_1;
    }
};

void output(stack *stack_1) {
    stack *cnt = stack_1;
    while (cnt != NULL) {
        printf("%d ", cnt->data);
        cnt = cnt->next;
    }
    printf("\n");
}