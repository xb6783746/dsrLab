#include <linked_list.h>
#include <stdlib.h>

Node* createNode(double val, Node* next);

List createEmptyList(){

    List list = {0, NULL};

    return list;
}

List createList(double val){

	Node* node = createNode(val, NULL);

	List list = {1, node};

	return list;
}

void push(List* list, double val){

	Node* node = createNode(val, list->head);

	list->head = node;
	list->size++;
}

double* toPlain(List* list){

	double* arr = (double*)malloc(list->size * sizeof(double));

	int i = 0;

	Node* node = list->head;

    while(node){

        arr[i] = node->val;
        i++;

        node = node->next;
    }

	return arr;
}

void delete(List* list){

	Node* node = list->head;
	
	while(node) {
		
		Node* curr = node;

		node = node->next;

		free(curr);
	}
}

Node* createNode(double val, Node* next){

	Node* node = (Node*)malloc(sizeof(Node));

	node->val = val;
	node->next = next;

	return node;
}


