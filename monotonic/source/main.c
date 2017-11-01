#include <sequence_reader.h>
#include <monotonic_checker.h>
#include <stdio.h>

int main(int argc, char** argv){


    char* filename = argv[1];

    double* arr;
    int count;

    printf("%s\n", filename);
    readSequence(filename, &arr, &count);

    int minDelCount = getMinDeleteCount(arr, count);

    printf("Min del count: %d\n", minDelCount);

    return 0;
}
