#include <string_parser.h>
#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

/* Превращает элементы обобщенного списка в массив строк */
char** toStringArray(List* list);

void stringFreeFunc(void* elem){

    free(elem);
}

/* Разделяет строку string на отдельные слова по пробелам */
int parse(char* string, char*** arr, size_t* count){

    List list = createEmptyList(sizeof(char*), &stringFreeFunc);

    char* curr;
    
    curr = strtok(string, " ");
    
    while (curr) {

        push(&list, curr);

        curr = strtok(NULL, " ");
    }

    *arr = toStringArray(&list);
    *count = list.size;

    delete(&list, 0);

    return 0;
}

char** toStringArray(List* list){

    char** arr = (char**)malloc(list->size * sizeof(char*));

    Node* node = list->head;

    int i = 0;

    while(node){

        arr[i] = (char*)(node->val);
        i++;

        node = node->next;
    }

    return arr;
}
