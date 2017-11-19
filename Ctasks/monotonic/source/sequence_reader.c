#include <sequence_reader.h>
#include <linked_list.h>
#include <double_parser.h>
#include <stdlib.h>
#include <stdio.h>

int readFile(const char** string, const char* filename);
double* toDoubleArray(List* list);

int readSequence(const char* filename, double** arr, size_t* count){

    const char* string;
    
    readFile(&string, filename); 

    char separators[] = {',', ' '};
    ParseParams params = {string, separators, 2};

    parse(params, arr, count);
  
    return 0;
}

int readFile(const char** string, const char* filename){

    FILE* fd = fopen(filename, "r");
   
    fseek(fd, 0, SEEK_END); 
    long size = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    char* arr = (char*)malloc(size);
    
    fread(arr, sizeof(char), size - 1, fd);

    arr[size] = '\0';

    fclose(fd);

    *string = arr;

    return 0;
}


