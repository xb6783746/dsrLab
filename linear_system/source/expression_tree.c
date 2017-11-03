#include <expression_tree.h>
#include <stdlib.h>

double calculateValue(OperatorType op, double left, double right);

Expression* createExpression(){

    Expression* expr = (Expression*)malloc(sizeof(Expression));

    memset(expr, 0, sizeof(Expression));

    return expr;
}

Expression* fromValue(double val){

    Expression* expr = createExpression();

    expr->type = Value;
    expr->val = val;

    return expr;
}

Expression* fromVariable(int varNum){

    Expression* expr = createExpression();

    expr->type = Variable;
    expr->varNum = varNum;

    return expr;
}

Expression* apply(OperatorType op, Expression* left, Expression* right){

    Expression* expr = createExpression();

    expr->type = Operator;
    expr->op = op;

    expr->left = left;
    expr->right = right;

    return expr;
}

int evaluate(Expression* expr){

    int res = 0;

    if(expr->type == Operator){

        Expression* left = expr->left;
        Expression* right = expr->right;

        int leftRes = evaluate(left);
        int rightRes = evaluate(right);

        if(leftRes && rightRes) {

            expr->val = calculateValue(expr->op, left->val, right->val);
            expr->type = Value;

            expr->left = NULL;
            expr->right = NULL;

            free(left);
            free(right);

            res = 1;
        }

    } else {

        res = expr->type == Value;
    }

    return res;
}

double calculateValue(OperatorType op, double left, double right){

    double res;

    switch(op){

        case Plus:
            res = left + right;
            break;
        case Minus:
            res = left - right;
            break;
        case Mul:
            res = left * right;
            break;
        case Div:
            res = left / right;
            break;
    }

    return res;
}
