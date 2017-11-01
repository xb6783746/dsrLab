#include <linked_list.h>
#include <stdlib.h>

Node* createNode(size_t elemSize, void* val, Node* next);

List createEmptyList(size_t elemSize, FreeFunc freeFunc){

    List list = {elemSize, freeFunc, 0, NULL, NULL};

    return list;
}

List createList(size_t elemSize, void* val, FreeFunc freeFunc){

	Node* node = createNode(elemSize, val, NULL);

	List list = {elemSize, freeFunc, 1, node, node};

	return list;
}

void push(List* list, void* val){

	Node* node = createNode(list->elemSize, val, NULL);

    if(list->tail == NULL){

        list->head = node;
        list->tail = node;
    } else {
        
        list->tail->next = node;
        list->tail = node;
    }

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


