#include <sequence_reader.h>
#include <monotonic_checker.h>
#include <stdio.h>

/* В строках текстового файла записаны десятичные числа (не целые – т.е. может быть точка), 
 *разделённые пробелами и (или) символами перевода строки. Необходимо определить минимальное количество чисел, 
 * после удаления которых числовая последовательность станет монотонной. */
int main(int argc, char** argv){


    char* filename = argv[1];

    double* arr;
    size_t count;

    printf("%s\n", filename);
    readSequence(filename, &arr, &count);

    int minDelCount = getMinDeleteCount(arr, count);

    printf("Min del count: %d\n", minDelCount);

    return 0;
}
