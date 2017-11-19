#ifndef DOUBLE_PARSER
#define DOUBLE_PARSER

#include <linked_list.h>

#define PARSE_ERROR 1

typedef struct{

	const char* string;

	const char* separators;
	const int sepsCount;
} ParseParams;

/* Парсит строку согласно заданным разделителям на вещественные числа, 
 * создает массив соответствующего размера и записывает его в arr,
 * а длину массива - в count
 */
int parse(ParseParams params, double** arr, size_t* count);

#endif

