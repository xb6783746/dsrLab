#ifndef LINKED_LIST
#define LINKED_LIST

#include <string.h>


/* Обобщенный связный список*/

typedef void (*FreeFunc)(void*);

typedef struct Node {

	void* val;
	struct Node *next;
} Node;

typedef struct {

    size_t elemSize;
    FreeFunc freeFunc;

	size_t size;
	Node *head;
    Node *tail;
} List;

List createEmptyList(size_t elemSize, FreeFunc freeFunc);
List createList(size_t elemSize, void* elem, FreeFunc freeFunc);

void push(List *list, void* val);

void delete(List* list, int delElems);
#endif
