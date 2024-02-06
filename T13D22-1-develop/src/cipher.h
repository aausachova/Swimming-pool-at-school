#ifndef CIPHER_H
#define CIPHER_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stsdin_clear();
void print_file(FILE *f, char *str);
int menu_file(FILE *f, char *str, char *fileName, int *menu);
void add_file(FILE *f, char *str2, char *fileName);
void encryption_caesar(char *fileName, int key);
void quest_3();
void des_caesar(char *fileName, int key);
void quest_4();

#endif  // CIPHER_H