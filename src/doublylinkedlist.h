#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

enum type_t {
    INT,
    DOUBLE,
    CHAR
};

typedef struct _Node {
    void *value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
    enum type_t type;
} DblLinkedList;

DblLinkedList* createDblLinkedList(enum type_t listtype);

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

