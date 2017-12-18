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

Node* getHead(DblLinkedList *list);

void pushTail(DblLinkedList *list, void *value);

void* popTail(DblLinkedList *list);

Node* getTail(DblLinkedList *list);

Node* getNth(DblLinkedList *list, size_t index);

void pushNth(DblLinkedList *list, size_t index, void *value);

void* popNth(DblLinkedList *list, size_t index);

#endif 

