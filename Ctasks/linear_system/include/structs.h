#ifndef STRUCTS
#define STRUCTS

#include <string.h>

typedef struct {

    double* coeff;
    size_t count;
} Row;

typedef struct {

    double** elems;
    size_t rows;
    size_t columns;
} Matrix;

#endif
