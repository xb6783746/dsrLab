#include <line_reader.h>
#include <linked_list.h>
#include <stdlib.h>

#define BLOCK_SIZE 50

char* toString(List* list, char* buf, size_t buflen);

void freeBlockFunc(void* elem){

    free(elem);
}

int readLine(FILE* fd, char** line){

    char block[BLOCK_SIZE];
    size_t i = 0;

    List list = createEmptyList(sizeof(block), &freeBlockFunc);

    char curr = fgetc(fd);

    while(curr != EOF && curr != '\n'){

        block[i] = curr;
        i++;

        if(i == BLOCK_SIZE){

            push(&list, block);
            
            i = 0;
        }

        curr = fgetc(fd);
    }

    *line = toString(&list, block, i);

    delete(&list);

    return 0;
}

char* toString(List* list, char* buf, size_t buflen){

    size_t strlength = BLOCK_SIZE * list->size + buflen + 1;
    char* str = (char*)malloc(strlength);
    char* pointer = str;

    Node* node = list->head;

    while(node){

        char* arr = (char*)(node->val);

        memcpy(pointer, arr, BLOCK_SIZE);

        pointer += BLOCK_SIZE;
    }

    memcpy(pointer, buf, buflen);

    pointer+=buflen;

    *pointer = '\0';

    return str;
}

