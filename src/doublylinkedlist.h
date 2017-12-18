#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct _Node {
    void *value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

DblLinkedList* createDblLinkedList(); 

void deleteDblLinkedList(DblLinkedList **list);

void pushHead(DblLinkedList *list, void *data);

void* popHead(DblLinkedList *list);

void pushTail(DblLinkedList *list, void *value);

void* popTail(DblLinkedList *list);

Node* getNth(DblLinkedList *list, size_t index);

void pushNth(DblLinkedList *list, size_t index, void *value);

void* popNth(DblLinkedList *list, size_t index);

int isListEmpty(DblLinkedList *list);

Node* findNode(DblLinkedList *list, void *data);

DblLinkedList* filter(DblLinkedList *list, int func(Node* elm));

void printDblLinkedList(DblLinkedList *list, void (*fun)(void*));

#endif 

