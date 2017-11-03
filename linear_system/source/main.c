#include <matrix_reader.h>
#include <gauss.h>
#include <expression_printer.h>
#include <stdlib.h>
#include <stdio.h>

/* Текстовый файл состоит из N строк, в каждой из которых записано N десятичных чисел A1,…,AN. 
 * Решить систему линейных уравнений AX=0*/
void printAnswer(Answer ans);

int main(int argc, char** argv){

    char* filename = argv[1];

    Matrix matrix;
    Answer ans;

    read(filename, &matrix);

    int res = solve(&matrix, &ans);

    if(!res){

        printf("Система имеет только тривиальное решение\n");

    } else {

        printAnswer(ans);
    }

    return 0;
}

void printAnswer(Answer ans){

    for(size_t i = 0; i < ans.count; i++){

        printf("x%d = ", i);

        printExpression(ans.elems[i]);
        
        printf("\n");
    }
}

