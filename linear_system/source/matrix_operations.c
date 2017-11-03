#include <matrix_operations.h>
#include <stdio.h>

/* Ищет в столбце colNum, начиная со строки fromRow, ненулевой элемент и возвращает его строку
 * - нужно в методе приведения матрицы к ступенчатому виду
 */
size_t findNonzeroElement(Matrix* matrix, size_t fromRow, size_t colNum);
void swapRows(Matrix* matrix, size_t row1, size_t row2);

void add(double* vec1, double* vec2, size_t length){

    for(size_t i = 0; i < length; i++){

        vec1[i] += vec2[i];
    }
}

void sub(double* vec1, double* vec2, size_t length){

    for(size_t i = 0; i < length; i++){

        vec1[i] -= vec2[i];
    }
}

void mul(double* vec, size_t length, double coeff){

    for(size_t i = 0; i < length; i++){

        vec[i] *= coeff;
    }
}

int isZero(double* vec, size_t length){

    int res = 1;

    for(size_t i = 0; i < length && res; i++){

        res = vec[i] == 0;
    }

    return res;
}

void makeTriangle(Matrix* matrix){

    size_t currRow = 0;
    size_t currCol = 0;

    while(currRow < matrix->rows - 1 && currCol < matrix->columns){

        size_t elemIndex = findNonzeroElement(matrix, currRow, currCol);

        if(elemIndex >= 0){

            swapRows(matrix, currRow, elemIndex);

            double* currR = matrix->elems[currRow];
            double l = currR[currCol];

            for(size_t i = currRow + 1; i < matrix->rows; i++){

                double* rowI = matrix->elems[i];

                double elemI = rowI[currCol];

                if(elemI == 0){

                    continue;
                }

                double coeff = l / elemI;

                mul(rowI, matrix->columns, coeff);
                sub(rowI, currR, matrix->columns);

            }
            
            currRow++;
        } 

        currCol++;
    }

} 

int rank(Matrix* matrix){

    makeTriangle(matrix);

    size_t n = matrix->rows;
    
    int res = n;

    for(size_t i = 0; i < n; i++){

        if(isZero(matrix->elems[i], matrix->rows)){

            res--;
        }
    }

    return res;
}

size_t findNonzeroElement(Matrix* matrix, size_t fromRow, size_t colNum){

    size_t index = -1;

    for(size_t i = fromRow; i < matrix->rows; i++){

        double* rowI = matrix->elems[i];

        if(rowI[colNum] != 0){

            index = i;

            break;
        }
    }

    return index;
}

void swapRows(Matrix* matrix, size_t row1, size_t row2){

    if(row1 == row2){

        return;
    }

    double* r1 = matrix->elems[row1];

    matrix->elems[row1] = matrix->elems[row2];

    matrix->elems[row2] = r1;
}
