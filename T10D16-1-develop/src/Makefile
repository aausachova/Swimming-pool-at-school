CC=gcc 
CFFLAGS=-Wall -Werror -Wextra
BUILD= ../build/

all : strcmp_tests strlen_tests strcpy_tests strcat_tests

strlen_tests: s21_string_strlen.o s21_string_test_strlen.o
	$(CC) $(CFFLAGS) -D STRLEN s21_string.c s21_string_test.c -o $(BUILD)Quest_1

strcmp_tests: s21_string_strcmp.o s21_string_test_strcmp.o
	$(CC) $(CFFLAGS) -D STRCMP s21_string.c s21_string_test.c -o $(BUILD)Quest_2

strcpy_tests: s21_string_strcpy.o s21_string_test_strcpy.o
	$(CC) $(CFFLAGS) -D STRCPY s21_string.c s21_string_test.c -o $(BUILD)Quest_3

strcat_tests: s21_string_strcat.o s21_string_test_strcat.o
	$(CC) $(CFFLAGS) -D STRCAT s21_string.c s21_string_test.c -o $(BUILD)Quest_4

s21_string_strlen.o: s21_string.o
	$(CC) $(CFFLAGS) -D STRLEN s21_string.c -c

s21_string_strcmp.o: s21_string.o
	$(CC) $(CFFLAGS) -D STRCMP s21_string.c -c

s21_string_strcpy.o: s21_string.o
	$(CC) $(CFFLAGS) -D STRCPY s21_string.c -c

s21_string_strcat.o: s21_string.o
	$(CC) $(CFFLAGS) -D STRCAT s21_string.c -c


s21_string_test_strlen.o: s21_string_test.o
	$(CC) $(CFFLAGS) -D STRLEN s21_string_test.c -c

s21_string_test_strcmp.o: s21_string_test.o
	$(CC) $(CFFLAGS) -D STRCMP s21_string_test.c -c

s21_string_test_strcpy.o: s21_string_test.o
	$(CC) $(CFFLAGS) -D STRCPY s21_string_test.c -c

s21_string_test_strcat.o: s21_string_test.o
	$(CC) $(CFFLAGS) -D STRCAT s21_string_test.c -c

clean : 
	rm -rf *.o $(BUILD)Quest_1 $(BUILD)Quest_2 $(BUILD)Quest_3 $(BUILD)Quest_4

rebuild : clean build