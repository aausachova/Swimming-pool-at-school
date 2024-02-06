CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
BUILD = ../build/

all: print_module bst_create_test bst_insert_test

print_module: print_module.o
	$(CC) print_module.o -o $(BUILD)Quest_1

bst_create_test: bst_create_test.o bst.o
	$(CC) bst_create_test.o bst.o -o $(BUILD)Quest_3

bst_insert_test: bst_insert_test.o
	$(CC) bst_insert_test.o -o $(BUILD)Quest_4

print_module.o: print_module.c print_module.h
	$(CC) $(CFLAGS) print_module.c

bst_create_test.o: bst_create_test.c bst.c bst.h
	$(CC) $(CFLAGS) bst_create_test.c

bst_insert_test.o: bst_insert_test.c bst.c bst.h
	$(CC) $(CFLAGS) bst_insert_test.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) bst.c

clean:
	rm -rf *.o $(BUILD)Q*

rebuild:
	clean all
