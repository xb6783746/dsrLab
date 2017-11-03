#include <expression_printer.h>
#include <stdio.h>

void printExpr(Expression* expr, int inBr);
char toChar(OperatorType op);

void printExpression(Expression* expr){

    printExpr(expr, 0);
}

void printExpr(Expression* expr, int inBr){
   
    switch(expr->type){

        case Operator:

            if(inBr){ 
                printf("(");
            }

            printExpr(expr->left, 1);

            printf("%c ", toChar(expr->op));

            printExpr(expr->right, 1);

            if(inBr){
             
                printf(")");
            }

            break;
        case Variable:

            printf("x%d ", expr->varNum);

            break;
        case Value:
            
            printf("%.2f ", expr->val);

            break;
    }
}

char toChar(OperatorType op){

    char res;

    switch(op){
        
        case Plus:
            res = '+';
            break;
        case Minus:
            res = '-';
            break;
        case Mul:
            res = '*';
            break;
        case Div:
            res = '/';
            break;
    }

    return res;
}
