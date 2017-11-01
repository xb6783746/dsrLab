#include <monotonic_checker.h>
#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

typedef struct {

    double lastVal;
    int monotonicType;
    int deleteCount;
} SequenceInfo;

typedef struct {

    SequenceInfo* arr;
    int count;
} Array;

SequenceInfo createSequenceInfo(double lastVal, int monType, int delCount);
void update(Array* arr, double val);
int check(SequenceInfo* info, double val);

void add(Array* arr, SequenceInfo val);

int findMinDelCount(Array* arr);

int getMinDeleteCount(const double* arr, size_t count){

    Array seqArr = {0, 0};

    seqArr.arr = (SequenceInfo*)malloc(2 * count * sizeof(SequenceInfo));

    for(int i = 0; i < count; i++){

      
        add(&seqArr, createSequenceInfo(arr[i], UP, i));
        add(&seqArr, createSequenceInfo(arr[i], DOWN, i));

        update(&seqArr, arr[i]);
    }

    return findMinDelCount(&seqArr);
}

SequenceInfo createSequenceInfo(double lastVal, int monType, int delCount){

    SequenceInfo info = {lastVal, monType, delCount};

    return info;
}

void update(Array* arr, double val){

    for(int i = 0; i < arr->count; i++){

        SequenceInfo* info = &(arr->arr[i]);

        if(!check(info, val)){
            
            info->deleteCount++;
        } else {

            info->lastVal = val;
        }
    }
}

int check(SequenceInfo* info, double val){

    return info->monotonicType == UP? 
          info->lastVal <= val : info->lastVal >= val;
}

void add(Array* arr, SequenceInfo val){

    int count = arr->count;

    arr->arr[count] = val;

    arr->count++;
}

int findMinDelCount(Array* arr){

    int minDelCount = arr->arr[0].deleteCount;

    for(int i = 0; i < arr->count; i++){

        minDelCount = MIN(minDelCount, arr->arr[i].deleteCount);
    }

    return minDelCount;
}
