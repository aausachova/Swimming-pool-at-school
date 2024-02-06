#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* log_init(char* filename);
int logcat(FILE* log_file, char* message, log_level level);
int log_close(FILE* log_file);

#endif  // LOGGER_H