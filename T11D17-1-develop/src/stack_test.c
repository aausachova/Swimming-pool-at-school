#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "stack_test.h"

int main() {
    stack *stack_1 = malloc(sizeof(stack));
    stack_1 = init(stack_1, 20);
    stack_1 = push_test(stack_1);
    stack_1 = pop_test(stack_1);

    destroy(stack_1);
    return 0;
}

stack *pop_test(stack *stack_1) {
    stack_1 = pop(stack_1);
    output(stack_1);
    if (stack_1->data == 5)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n");

    return stack_1;
};

stack *push_test(stack *stack_1) {
    stack_1 = push(stack_1, 10);

    output(stack_1);
    if (stack_1->data == 10)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n");

    return stack_1;
};