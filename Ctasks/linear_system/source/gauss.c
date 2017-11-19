#include <gauss.h>
#include <matrix_operations.h>
#include <stdlib.h>

void forward(Matrix* matrix);
void backward(Matrix* matrix, Answer* ans);

int solve(Matrix* matrix, Answer* ans){
    
    forward(matrix);

    size_t rnk = rank(matrix);

    if(rnk == matrix->rows){
    
        return 0;
    }

    ans->elems = (Expression**)malloc(matrix->rows * sizeof(Expression*));
    ans->count = matrix->rows;

    backward(matrix, ans);

    return 1;
}

void forward(Matrix* matrix){

    makeTriangle(matrix);
}

void backward(Matrix* matrix, Answer* ans){

    size_t n = matrix->rows;

    Expression** answer = ans->elems;

    //Цикл по всем уравнениям системы
    for(int i = n - 1; i >= 0; i--){

        double* rowI = matrix->elems[i];
        double coeff = rowI[i];

        //Если коэфф. перед переменной == 0, то она независимая
        if(coeff == 0){
            
            answer[i] = fromVariable(i);
            continue;
	}

        Expression* expr = NULL;
        
        // x(i) = (C(i+1)*x(i+1) - C(i+2)*x(i+2) ... ) / C(i)
        for(size_t j = n - 1; j > i; j--){

            Expression* mul = apply(Mul, answer[j], fromValue(-rowI[j]));

            if(expr == NULL){

                expr = mul;
            } else{
                
                expr = apply(Plus, expr, mul);
            }
        }

        answer[i] = apply(Div, expr, fromValue(coeff));
    }
}

