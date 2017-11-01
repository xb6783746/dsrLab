#include <linked_list.h>
#include <stdlib.h>

Node* createNode(size_t elemSize, void* val, Node* next);

List createEmptyList(size_t elemSize, FreeFunc freeFunc){

    List list = {elemSize, freeFunc, 0, NULL};

    return list;
}

List createList(size_t elemSize, void* val, FreeFunc freeFunc){

	Node* node = createNode(elemSize, val, NULL);

	List list = {elemSize, freeFunc, 1, node};

	return list;
}

void push(List* list, void* val){

	Node* node = createNode(list->elemSize, val, list->head);

	list->head = node;
	list->size++;
}

void delete(List* list){

	Node* node = list->head;
	
	while(node) {
		
		Node* curr = node;

		node = node->next;

		list->freeFunc(curr);
	}
}

Node* createNode(size_t elemSize, void* val, Node* next){

	Node* node = (Node*)malloc(sizeof(Node));

	node->val = (void*)malloc(elemSize);
    memcpy(node->val, val, elemSize);

	node->next = next;

	return node;
}


