#include <matrix_reader.h>
#include <line_reader.h>
#include <linked_list.h>
#include <double_parser.h>
#include <stdlib.h>
#include <stdio.h>

int readRow(FILE* fd, Row* row);
int isEndOfFile(FILE* fd);

int read(const char* filename, Matrix* matrix){

	FILE* fd = fopen(filename, "r");

    Row row;

    double** storage = NULL;
    double** curr = NULL;

    while(!isEndOfFile(fd)){

        readRow(fd, &row);

        //проверить, что строки одной длины
        
        if(storage == NULL){

            storage = (double**)malloc(row.count * sizeof(double*));
            curr = storage;
        }

        *curr = row.coeff;
        curr++; 
    }

    fclose(fd);

    matrix->elems = storage;
    matrix->rows = row.count;
    matrix->columns = row.count;

    return 0;
}

int readRow(FILE* fd, Row* row){

	char* str;
    
    readLine(fd, &str);

    char separators[] = {','};
    ParseParams params = {str, separators, 1};
    
    parse(params, &(row->coeff), &(row->count));

    free(str);

    return 0;
}

int isEndOfFile(FILE* fd){

    size_t pos = ftell(fd);

    char curr = fgetc(fd);

    fseek(fd, pos, SEEK_SET);

    return curr == EOF;
}
