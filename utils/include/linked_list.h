#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node {

	double val;
	struct Node *next;
} Node;

typedef struct {

	int size;
	Node *head;
} List;

List createEmptyList();
List createList(double val);
void push(List *list, double val);
double* toPlain(List* list);
void delete(List* list);
#endif
