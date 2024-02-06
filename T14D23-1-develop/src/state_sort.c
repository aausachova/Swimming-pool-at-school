#include "state_sort.h"

#include "input.h"
#include "sort.h"

int main() {
    menu();
    return 0;
}

void menu() {
    int rc = 0;
    int choice;
    char* path = get_path();
    FILE* ptr = fopen(path, "r+b");
    free(path);
    if (ptr == NULL) rc = 1;
    choice = get_choice();
    if (rc == 0) {
        switch (choice) {
            case 0:
                rc = output_file(ptr);
                break;
            case 1:
                sort_file(ptr);
                rc = output_file(ptr);
                break;
            case 2:
                rc = add_record(ptr);
                if (!rc) {
                    sort_file(ptr);
                    rc = output_file(ptr);
                }
                break;
            default:
                rc = 1;
                break;
        }
    }
    if (rc) printf("n/a\n");
    if (ptr) fclose(ptr);
}

int output_file(FILE* ptr) {
    fseek(ptr, 0, SEEK_SET);
    int rc = 0;
    int num = 5;
    int size = len(ptr);
    if ((size % 8 != 0) || (size < 8)) {
        rc = 1;
    } else {
        fread(&num, sizeof(int), 1, ptr);
        printf("%d", num);
        for (int i = 1; i < size; i++) {
            if (i % 8 == 0)
                printf("\n");
            else
                printf(" ");
            fread(&num, sizeof(int), 1, ptr);
            printf("%d", num);
        }
    }
    return rc;
}

int add_record(FILE* ptr) {
    int rc = 0;
    int arr[8];
    for (int i = 0; i < 8; i++) {
        if (scanf("%d", &(arr[i])) != 1) {
            rc = 1;
            break;
        }
    }
    char c;
    if ((scanf("%c", &c) > 0) && ((c != '\n') && (c != ' '))) rc = 1;
    if (!rc) {
        fseek(ptr, 0, SEEK_END);
        fwrite(arr, sizeof(int), 8, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return rc;
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
    return i - 1;
}
