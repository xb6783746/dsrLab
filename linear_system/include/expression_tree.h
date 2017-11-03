#ifndef SYMBOL
#define SYMBOL

#include <string.h>

typedef enum ExpressionType {

    Operator, Value, Variable
} ExpressionType;

typedef enum OperatorType {

    Plus, Minus, Mul, Div
} OperatorType;

typedef struct Expression {

    double val;
    int varNum;
    enum OperatorType op;
    enum ExpressionType type;

    struct Expression* left;
    struct Expression* right;
} Expression;

Expression* fromValue(double val);
Expression* fromVariable(int varNum);

Expression* apply(OperatorType op, Expression* left, Expression* right);
int evaluate(Expression* expr);

#endif
