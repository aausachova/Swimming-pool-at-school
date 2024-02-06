CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 
BUILD = ../build/

all: cipher

cipher: cipher.o
	$(CC) cipher.o -o $(BUILD)cipcher

cipher.o: cipher.c cipher.h
	$(CC) $(CFLAGS) cipher.c 

clean:
	rm -rf *.o $(BUILD)cipcher

rebuild:
	clean all
