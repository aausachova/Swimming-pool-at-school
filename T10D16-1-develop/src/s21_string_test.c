#include "s21_string_test.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int main() {
#ifdef STRLEN
    s21_strlen_test("123", 3);
    s21_strlen_test("4567", 5);
    s21_strlen_test("", 0);
    return 0;
#endif

#ifdef STRCMP
    s21_strcmp_test("1234", "2345", -1);
    s21_strcmp_test("1234", "1234", 0);
    s21_strcmp_test("", "", 0);
    return 0;
#endif

#ifdef STRCPY
    s21_strcpy_test("1234", "5678");
    s21_strcpy_test("1234", "1234");
    s21_strcpy_test("", "");
    return 0;
#endif

#ifdef STRCAT
    s21_strcat_test("1234", "5678");
    s21_strcat_test("1234", "1234");
    return 0;
#endif
}

void s21_strlen_test(const char* str, int l1) {
    int l2 = s21_strlen(str);
    printf("\n");
    printf("\"%s\"\n", str);
    printf("%d\n", l1);
    printf("%d\n", l2);

    if (l2 == l1)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("\n");
}

void s21_strcmp_test(const char* str_1, const char* str_2, int num1) {
    int num2 = s21_strcmp(str_1, str_2);
    printf("\n");
    printf("\"%s %s\"\n", str_1, str_2);
    printf("%d\n", num1);
    printf("%d\n", num2);

    if (num2 == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("\n");
}

void s21_strcpy_test(const char* str_1, const char* str_2) {
    int num2 = s21_strcmp(str_1, str_2);
    printf("\n");
    printf("\"%s %s\"\n", str_1, str_2);
    printf("%s\n", str_1);
    printf("%s\n", str_2);

    if (num2 == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("\n");
}
void s21_strcat_test(char* str1, char* str2) {
    char* str3;
    printf("\n");
    if (str1 == NULL || str2 == NULL) {
        printf("%s %s (null) FAIL\n", str1, str2);
    } else {
        str3 = s21_strcat(str1, str2);
        printf("%s %s %s SUCCESS\n", str1, str2, str3);
        free(str3);
    }
}
