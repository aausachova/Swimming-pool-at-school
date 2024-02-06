#ifndef SRC_SORT_H_
#define SRC_SORT_H_
#include "state_sort.h"

int sort_file(FILE* ptr);
int compare(const int* rec1, const int* rec2);
void swap(FILE* ptr, int* rec1, int* rec2, int id1, int id2);

#endif  // SRC_SORT_H_
