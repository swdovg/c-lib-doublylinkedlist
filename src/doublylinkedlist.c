#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "doublylinkedlist.h"

DblLinkedList* createDblLinkedList(enum type_t listtype) {
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    tmp->type=listtype;
    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushHead(DblLinkedList *list, void *data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(EXIT_FAILURE);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void* popHead(DblLinkedList *list) {
    Node *prev;
    void *tmp;
    if (list->head == NULL) {
        exit(EXIT_FAILURE);
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);

    list->size--;
    return tmp;
}

void pushTail(DblLinkedList *list, void *value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(EXIT_FAILURE);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

void* popTail(DblLinkedList *list) {
    Node *next;
    void *tmp;
    if (list->tail == NULL) {
        exit(EXIT_FAILURE);
    }

    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);

    list->size--;
    return tmp;
}

Node* getNth(DblLinkedList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;

    if (index > list->size) {
	exit(EXIT_FAILURE);
    }

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

void pushNth(DblLinkedList *list, size_t index, void *value) {
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(EXIT_FAILURE);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
}

void* popNth(DblLinkedList *list, size_t index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(EXIT_FAILURE);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}

int isListEmpty(DblLinkedList *list) {
    if ( (!list->head) && (!list->tail) )
        return 1;
    else
        return 0;
}

Node* findNode(DblLinkedList *list, void *data) {
    if (list->head == NULL) {
        exit(EXIT_FAILURE);
    }

    Node *tmp = list->head;

    switch (list->type) {

        case INT:
            while (tmp) {
                if (*((int*)tmp->value)==*((int*)data)) {
                    return tmp;
                }
                tmp=tmp->next;
            }
            break;

        case DOUBLE:

            while (tmp) {
                if ( fabs( *((double*)tmp->value) - *((double*)data) ) < 0.00001  ) {
                    return tmp;
                }
                tmp=tmp->next;
            }
            break;

        case CHAR:
            while (tmp) {
                if (*((char*)tmp->value)==*((char*)data)) {
                    return tmp;
                }
                tmp=tmp->next;
            }
            break;

        default:
            return NULL;
    }
    return NULL;
}

DblLinkedList* filter(DblLinkedList *list, int (*func)(Node *elm)) {
    if (list->head == NULL) {
        exit(EXIT_FAILURE);
    }

    DblLinkedList *newList=createDblLinkedList(list->type);
    Node *tmp=list->head;

    while (tmp) {
        if (func(tmp)>0)
            pushTail(newList, tmp->value);
        tmp=tmp->next;
    }

    return newList;
}

DblLinkedList* reverse(DblLinkedList *list) {
    if (list->head == NULL) {
        exit(EXIT_FAILURE);
    }

    DblLinkedList *newList=createDblLinkedList(list->type);
    Node *tmp=list->head;

    while (tmp) {
        pushHead(newList, tmp->value);
        tmp=tmp->next;
    }
    return newList;
}


void printDblLinkedList(DblLinkedList *list, void (*fun)(void*)) {
    Node *tmp = list->head;
    while (tmp) {
        fun(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}
