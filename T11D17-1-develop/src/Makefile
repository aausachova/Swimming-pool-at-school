CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
BUILD = ../build/

all: door_struct stack_test

door_struct: dmanager_module.o
	$(CC) dmanager_module.o -o $(BUILD)Quest_1

stack_test: stack_test.o stack.o
	$(CC) stack_test.o stack.o -o $(BUILD)Quest_3

dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) dmanager_module.c 

stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) stack_test.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c stack.h

clean:
	rm -rf *.o $(BUILD)Q*

rebuild:
	clean all

