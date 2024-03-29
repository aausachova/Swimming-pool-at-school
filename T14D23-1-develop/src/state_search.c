#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int len(FILE* ptr);
int search(FILE* ptr, int* date, int* code);
int compare(const int* date, const int* rec);

int main() {
    int is_error = 0;
    int code;
    int date[3];
    char* path = get_path();
    FILE* ptr = fopen(path, "rb");
    free(path);
    if (ptr == NULL)
        is_error = 1;
    else
        is_error = get_date(date);
    if (!is_error) is_error = search(ptr, date, &code);
    if (!is_error) {
        printf("%d", code);
    } else {
        printf("n/a");
    }
    if (ptr) fclose(ptr);
    return 0;
}

int compare(const int* date, const int* rec) {
    int res = 0;
    if ((date[0] == rec[0]) && (date[1] == rec[1]) && (date[2] == rec[2])) res = 1;
    return res;
}

int len(FILE* ptr) {
    int i = 0;
    int num;
    fseek(ptr, 0, SEEK_SET);
    while (!feof(ptr)) {
        fread(&num, sizeof(int), 1, ptr);
        i++;
    }
    fseek(ptr, 0, SEEK_SET);
    return i;
}

int search(FILE* ptr, int* date, int* code) {
    int is_error = 1;
    int* rec = (int*)malloc(sizeof(int) * 8);
    int size = len(ptr) / 8;
    for (int i = 0; i < size; i++) {
        fread(rec, sizeof(int), 8, ptr);
        if (compare(date, rec)) {
            *code = rec[7];
            is_error = 0;
        }
    }
    free(rec);
    return is_error;
}
