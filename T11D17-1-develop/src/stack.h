#ifndef SRC_STACK_H
#define SRC_STACK_H

typedef struct stack {
	int data;
	struct stack* next;
} stack;

stack *init(stack *stack_1, int id);
stack *push(stack *stack_1, int id);
stack *pop(stack *stack_1);
void destroy(stack *stack_1);
void output(stack *stack_1);


#endif //SRC_STACK_H