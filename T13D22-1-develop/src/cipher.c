
#include "cipher.h"

int main() {
    int menu;
    FILE *f = NULL;
    char str[40];
    char fileName[40];

    scanf("%d", &menu);
    if (menu_file(f, str, fileName, &menu) != 1) {
        printf("n/a\n");
    }
    return 0;
}

int menu_file(FILE *f, char *str, char *fileName, int *menu) {
    char str2[40];
    while (*menu != (-1)) {
        if (*menu == 1) {
            scanf("%98s", fileName);
            if ((f = fopen(fileName, "r")) != NULL) {
                print_file(f, str);
                fclose(f);
            } else {
                printf("n/a\n");
                *menu = 2;
            }
        } else if (*menu == 2) {
            if (fileName[0] != '\0') {
                if ((f = fopen(fileName, "a+")) != NULL) {
                    fgets(str2, 39, stdin);
                    str2[strcspn(str2, "\n")] = '\0';
                    add_file(f, str2, fileName);
                    fclose(f);
                } else {
                    printf("n/a\n");
                }
            } else {
                printf("n/a\n");
            }
        } else if (*menu == 3) {
            quest_3();
        } else if (*menu == 4) {
            quest_4();
        } else {
            printf("n/a\n");
        }

        scanf("%d", menu);
        stsdin_clear();
    }
    return 1;
}

void add_file(FILE *f, char *str2, char *fileName) {
    if (f != NULL) {
        fputs(str2, f);
        fclose(f);
        f = fopen(fileName, "r");
        print_file(f, str2);
    } else {
        printf("n/a\n");
    }
}

void print_file(FILE *f, char *str) {
    int test = 0;
    while (fgets(str, 40, f) != NULL) {
        printf("%s", str);
        test = 1;
    }
    if (test == 0) {
        printf("n/a\n");
    }
    printf("\n");
}

void encryption_cesar(char *fileName, int key) {
    FILE *in;
    in = fopen(fileName, "r");
    if (in) {
        FILE *out;
        out = fopen(fileName, "r+w");
        int c;
        while ((c = fgetc(in)) != EOF) {
            if (c >= 'A' && c <= 'Z') {
                c = (c - 'A' + key) % 26 + 'A';
            } else if (c >= 'a' && c <= 'z') {
                c = (c - 'a' + key) % 26 + 'a';
            }
            fputc(c, out);
        }
        fclose(in);
        fclose(out);
    }
}

void quest_3() {
    DIR *dir;
    char filename[99];
    scanf("%98s", filename);
    dir = opendir(filename);
    int key;
    if (scanf("%d", &key) == 1 && dir) {
        char put[100];
        struct dirent *data;
        while ((data = readdir(dir)) != 0) {
            strcpy(put, filename);
            strcat(put, "/");
            strcat(put, data->d_name);
            if (data->d_name[strlen(data->d_name) - 1] == 'h') {
                FILE *file = fopen(put, "w");
                fclose(file);
            } else if (data->d_name[strlen(data->d_name) - 1] == 'c') {
                encryption_cesar(put, key);
            }
        }
        closedir(dir);
    } else
        printf("n/a\n");
}

void des_caesar(char *fileName, int key) {
    FILE *f = fopen(fileName, "r+");
    if (f) {
        int c;
        while ((c = fgetc(f)) != EOF) {
            if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' - key + 26) % 26;
            } else if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' - key + 26) % 26;
            }
            fseek(f, -1, SEEK_CUR);
            fputc(c, f);
        }
        fclose(f);
    }
}

void quest_4() {
    DIR *dir;
    char filename[99];
    scanf("%98s", filename);
    dir = opendir(filename);
    int key;
    if (scanf("%d", &key) == 1 && dir) {
        char put[100];
        struct dirent *data;
        while ((data = readdir(dir)) != 0) {
            strcpy(put, filename);
            strcat(put, "/");
            strcat(put, data->d_name);
            if (data->d_name[strlen(data->d_name) - 1] == 'h') {
                FILE *file = fopen(put, "w");
                fclose(file);
            } else if (data->d_name[strlen(data->d_name) - 1] == 'c') {
                des_caesar(put, key);
            }
        }
        closedir(dir);
    } else
        printf("n/a\n");
}

void stsdin_clear() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}