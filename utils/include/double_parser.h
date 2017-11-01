#ifndef DOUBLE_PARSER
#define DOUBLE_PARSER

#include <linked_list.h>

#define PARSE_ERROR 1

typedef struct{

	const char* string;

	const char* separators;
	const int sepsCount;
} ParseParams;

int parse(ParseParams params, double** arr, size_t* count);

#endif

