//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//
//#include "input.h"
//
// int compare(const int* rec1, const int* rec2);
// int len(FILE* ptr);
// int check_gap(int* date1, int* date2, int* rec);
// int check_date(const int* date1, const int* date2);
// int output_file(FILE* ptr);
// int clear(FILE* ptr, int* date1, int* date2);
// void shift(FILE* ptr, int id);
//
// int main() {
//    int rc = 0;
//    int date1[3];
//    int date2[3];
//    int newsize;
//    char* path = get_path();
//    FILE* ptr = fopen(path, "r+b");
//    if (ptr == NULL) {
//        rc = 1;
//    } else {
//        get_date(date1);
//        rc = get_date(date2);
//    }
//    if (check_date(date1, date2) != 1) newsize = clear(ptr, date1, date2);
//    if (!rc) {
//        // path[len] = '\0';
//        if (ptr != NULL) fclose(ptr);
//        truncate(path, newsize * sizeof(int));
//        ptr = fopen(path, "r+b");
//        output_file(ptr);
//    } else {
//        printf("n/a");
//    }
//    free(path);
//    if (ptr != NULL) fclose(ptr);
//    return 0;
//}
//
// int compare(const int* rec1, const int* rec2) {
//    int res = 0;
//    int i = 0;
//    while ((!res) && (i < 3)) {
//        if (rec1[i] > rec2[i]) res = 1;
//        if (rec1[i] < rec2[i]) res = -1;
//        i++;
//    }
//    return res;
//}
//
// int check_date(const int* date1, const int* date2) {
//    int res;
//    for (int i = 0; i < 3; i++) {
//        if (*(date1 + i) < *(date2 + i)) res = 0;
//        if (*(date1 + i) > *(date2 + i)) res = 1;
//    }
//    return res;
//}
//
// int check_gap(int* date1, int* date2, int* rec) {
//    int res = 0;
//    int res1 = compare(date1, rec);
//    int res2 = compare(rec, date2);
//    if ((res1 == -1) && (res2 == -1)) res = 1;
//    return res;
//}
//
// int len(FILE* ptr) {
//    int i = 0;
//    int num;
//    fseek(ptr, 0, SEEK_SET);
//    while (!feof(ptr)) {
//        fread(&num, sizeof(int), 1, ptr);
//        i++;
//    }
//    fseek(ptr, 0, SEEK_SET);
//    return i - 1;
//}
//
// void shift(FILE* ptr, int id) {
//    int num[8];
//    int i = id;
//    while (!feof(ptr)) {
//        fseek(ptr, (i + 1) * 8 * sizeof(int), SEEK_SET);
//        if (fread(num, sizeof(int), 8, ptr) != 8) break;
//        fseek(ptr, i * 8 * sizeof(int), SEEK_SET);
//        fwrite(num, sizeof(int), 8, ptr);
//        i++;
//    }
//}
//
// int clear(FILE* ptr, int* date1, int* date2) {
//    int size = len(ptr) / 8;
//    int* rec = (int*)malloc(sizeof(int) * 8);
//    for (int i = 0; i < size; i++) {
//        fread(rec, sizeof(int), 8, ptr);
//        if (check_gap(date1, date2, rec)) {
//            shift(ptr, i);
//            fseek(ptr, i * 8 * sizeof(int), SEEK_SET);
//            i--;
//            size--;
//        }
//    }
//    free(rec);
//    return (size * 8);
//}
//
// int output_file(FILE* ptr) {
//    fseek(ptr, 0, SEEK_SET);
//    int rc = 0;
//    int num = 5;
//    int size = len(ptr);
//    if ((size % 8 != 0) || (size < 8)) {
//        rc = 1;
//    } else {
//        fread(&num, sizeof(int), 1, ptr);
//        printf("%d", num);
//        for (int i = 1; i < size; i++) {
//            if (i % 8 == 0)
//                printf("\n");
//            else
//                printf(" ");
//            fread(&num, sizeof(int), 1, ptr);
//            printf("%d", num);
//        }
//    }
//    return rc;
//}
