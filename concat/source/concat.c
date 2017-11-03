#include <concat.h>
#include <stdlib.h>


int startsWith(const char* start, const char* word);

/* Записывает в массив buff все элементы массива arr, за исключением элемента с индексом except*/
void except(const char** arr, size_t size, size_t except, const char** buff);

/* Проверяет, можно ли составить слово word из слов массива dictionary*/
int check(const char** dictionary, size_t dictLength, const char* word){

    if(!*word){

        return 1;
    }

    const char** arr = (const char**)malloc((dictLength - 1) * sizeof(char*));
    int res = 0;

    /* Для всех слов из словаря, с которых начинается слово word, рекурсивно вызывается метод
     * для остатка слова word и нового словаря за исключением использованного слова */
    for(size_t i = 0; i < dictLength && !res; i++){

        if(startsWith(dictionary[i], word)){

            except(dictionary, dictLength, i, arr);

            res = check(arr, dictLength - 1, word + strlen(dictionary[i]));
        }
    }

    free(arr);

    return res;
}

int startsWith(const char* start, const char* word){

    if(strlen(start) > strlen(word)){
        
        return 0;
    }

    return strncmp(start, word, strlen(start)) == 0;
}

void except(const char** arr, size_t size, size_t except, const char** buf){

    for(size_t i = 0; i < size; i++){

        if(i != except){

            *buf = arr[i];

            buf++;
        }
    }
}
