#ifndef SET
#define SET

#include <linked_list.h>

typedef int (*Equals)(void*, void*);

typedef struct{

    List list;
    Equals equals;
} Set;

Set createEmptySet(size_t elemSize, FreeFunc freeFunc, Equals equals);

void add(Set* set, void* elem);

int contains(Set* set, void* elem);
int isSubset(Set* set, Set* subset);

void deleteSet(Set* set);
#endif
