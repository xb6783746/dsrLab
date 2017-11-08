#ifndef STRING_PARSER
#define STRING_PARSER

#include <string.h>

/* Разделяет строку string на отдельные слова по пробелам */
int parse(char* string, char*** arr, size_t* count);

#endif
