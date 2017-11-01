
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string_parser.h>
#include <concat.h>
#include <line_reader.h>

typedef struct {

    char** arr;
    size_t length;
} StringArray;

int load(const char* filename, StringArray arr[2]);
int process(StringArray* dict, StringArray* words);

int main(int argc, char** argv){

    char* filename = argv[1];

    StringArray arr[2];

    load(filename, arr);

    int res = process(&arr[0], &arr[1]);

    char* message = res?
        "Нет слов, которые нельзя получить конкатенацией слов из первой строки" 
        : "Есть слова, которые нельзя получить конкатенацией слов из первой строки";

    printf("%s\n", message);

    return 0;
}

int load(const char* filename, StringArray arr[2]){

    FILE* fd = fopen(filename, "r");

    for(int i = 0; i < 2; i++){

        char* str;

        readLine(fd, &str);

        parse(str, &(arr[i].arr), &(arr[i].length));

        free(str);  
    }

    fclose(fd);
}

int process(StringArray* dict, StringArray* words){

    int res = 1;

    for(size_t i = 0; i < words->length && res; i++){

        res = check(dict->arr, dict->length, words->arr[i]);
    }

    return res;
}
