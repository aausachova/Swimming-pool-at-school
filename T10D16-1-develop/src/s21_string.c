#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *s) {
    int l = 0;
    while (s[l] != '\0') {
        l++;
    }
    return l;
}

char *s21_strcpy(char *s1, char *s2) {
    int l = s21_strlen(s1);
    for (int i = 0; i < l; i++) {
        s2[i] = s1[i];
    }
    return s2;
}

char *s21_strcat(char *str1, char *str2) {
    char *result = (char *)calloc(s21_strlen(str1) + s21_strlen(str2), sizeof(char));

    for (int i = 0; i < s21_strlen(str1); i++) {
        result[i] = str1[i];
    }
    for (int i = s21_strlen(str1); i < s21_strlen(str1) + s21_strlen(str2); i++) {
        result[i] = str2[i - s21_strlen(str1)];
    }

    return result;
}

int s21_strcmp(const char *s1, const char *s2) {
    int temp = 0;
    if (s21_strlen(s1) != s21_strlen(s2)) {
        temp = -1;
    } else {
        int l = s21_strlen(s1);
        for (int i = 0; i < l; i++) {
            if (s1[i] != s2[i]) {
                temp = -1;
            }
            if (temp == -1) {
                break;
            }
        }
    }
    return temp;
}
