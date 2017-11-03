#include <gauss.h>
#include <matrix_operations.h>
#include <stdlib.h>

void forward(Matrix* coeffs);
void backward(Matrix* coeffs, Answer* ans);

/* Если переменная независимая, создает выражение-переменную с данным номером
 * Если переменная зависимая, создает выражение-константу с коэфф-м перед переменной */
Expression* createVarExpr(Matrix* matrix, size_t varNum);

int solve(Matrix* coeffs, Answer* ans){
    
    forward(coeffs);

    size_t rnk = rank(coeffs);

    if(rnk == coeffs->rows){
    
        return 0;
    }

    ans->elems = (Expression**)malloc(coeffs->rows * sizeof(Expression*));
    ans->count = coeffs->rows;

    backward(coeffs, ans);

    return 1;
}

void forward(Matrix* coeffs){

    makeTriangle(coeffs);
}

void backward(Matrix* coeffs, Answer* ans){

    size_t n = coeffs->rows;

    Expression** answer = ans->elems;

    //Инициализация выражений для переменных
    for(int i = 0; i < n; i++){
        
        answer[i] = createVarExpr(coeffs, i); 
    }

    //Цикл по всем уравнениям системы
    for(int i = n - 1; i >= 0; i--){

        Expression* valI = answer[i];

        //Уравнения для независимых переменных не рассматриваются
        if(valI->type == Variable){

            continue;
        }

        double* rowI = coeffs->elems[i];
        
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

        answer[i] = apply(Div, expr, valI);
    }
}

Expression* createVarExpr(Matrix* matrix, size_t varNum){

    double val = matrix->elems[varNum][varNum];

    //Если коэфф. перед переменной == 0, то переменная независимая
    return val == 0? fromVariable(varNum) : fromValue(val);
}

