#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

#include <structs.h>
#include <string.h>

void add(double* vec1, double* vec2, size_t length);
void sub(double* vec1, double* vec2, size_t length);

void mul(double* vec, size_t length, double coeff);

void makeTriangle(Matrix* matrix);
int rank(Matrix* matrix);

#endif
