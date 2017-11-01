#include <sequence_reader.h>
#include <linked_list.h>
#include <double_parser.h>
#include <stdlib.h>
#include <stdio.h>

int readFile(const char** string, const char* filename);

int readSequence(const char* filename, double** arr, int* count){

    const char* string;
    
    readFile(&string, filename); 

    List list = createEmptyList();

    char separators[] = {',', ' '};
    ParseParams params = {string, separators, 2};

    parse(params, &list);

    *arr = toPlain(&list);
    *count = list.size;
  
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
