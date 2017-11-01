#include <set.h>


Set createEmptySet(size_t elemSize, FreeFunc freeFunc, Equals equals){

    List list = createEmptyList(elemSize, freeFunc);

    Set set = {list, equals};

    return set;
}

void add(Set* set, void* elem){

    push(&(set->list), elem);
}

int contains(Set* set, void* elem){

    Node* node = set->list.head;

    int res = 0;

    while(node && !res){

        res = set->equals(node->val, elem);

        node = node->next;
    }

    return res;
}

int isSubset(Set* set, Set* subset){

    Node* node = subset->list.head;

    int res = 1;

    while(node && res){

        res = contains(set, node->val);

        node = node->next;
    }

    return res;
}

void deleteSet(Set* set){

    delete(&(set->list));
}

