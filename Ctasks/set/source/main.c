#include <set.h>
#include <line_reader.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Имеется два текстовых файла. 
 * Определить, может ли второй файл быть получен путём перестановки и дублирования некоторых строк первого файла.*/
int readFile(const char* filename, Set* set);

void freeString(void* elem){

    free(elem);
}

int equalsString(void* first, void* second){

    char* firstString = (char*)(first);
    char* secondString = (char*)(second);

    return strcmp(firstString, secondString) == 0;
}

/* Условия задачи выполняются, если множество строк второго файла содержится в множестве строк первого*/
int main(int argc, char** argv){
    
    Set sets[2];

    for(size_t i = 0; i < 2; i++){

        sets[i] = createEmptySet(sizeof(char*), &freeString, &equalsString);

        readFile(argv[i+1], &(sets[i]));
    }

    int res = isSubset(&(sets[0]), &(sets[1]));

    char* message = res? 
        "Можно" : "Нельзя";

    printf("%s\n", message);

    return 0;
}

int readFile(const char* filename, Set* set){

    FILE* fd = fopen(filename, "r");

    while(!feof(fd)){

        char* string;

        readLine(fd, &string);

        add(set, string);
    }

    fclose(fd);

    return 0;
}

