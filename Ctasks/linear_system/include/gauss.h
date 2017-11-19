#ifndef GAUSS
#define GAUSS

#include <structs.h>
#include <expression_tree.h>

typedef struct {

    Expression** elems;
    size_t count;
} Answer;

int solve(Matrix* coeffs, Answer* ans);

#endif
