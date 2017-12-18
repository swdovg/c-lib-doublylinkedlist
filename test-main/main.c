#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"


void printInt(void *value) {
    printf("%d ", *((int*) value));
}

int main() {
    DblLinkedList *list = createDblLinkedList();
    int a, b, c, d, e, f, g, h;

    a = 10;
    b = 20;
    c = 30;
    d = 40;
    e = 50;
    f = 60;
    g = 70;
    h = 80;
    pushHead(list, &a);
    pushHead(list, &b);
    pushHead(list, &c);
    pushTail(list, &d);
    pushTail(list, &e);
    pushTail(list, &f);
    printDblLinkedList(list, printInt);
    printf("length %d\n", list->size);
    printf("nth 2 %d\n", *((int*)(getNth(list, 2))->value));
    printf("nth 5 %d\n", *((int*)(getNth(list, 5))->value));
    printf("popHead %d\n", *((int*)popHead(list)));
    printf("popHead %d\n", *((int*)popHead(list)));
    printf("head %d\n", *((int*)(list->head->value)));
    printf("tail %d\n", *((int*)(list->tail->value)));
    printf("popTail %d\n", *((int*)popTail(list)));
    printf("popTail %d\n", *((int*)popTail(list)));
    printf("length %d\n", list->size);
    printDblLinkedList(list, printInt);
    pushNth(list, 1, &g);
    printDblLinkedList(list, printInt);
    popNth(list, 0);
    printDblLinkedList(list, printInt);
    deleteDblLinkedList(&list);

    return EXIT_SUCCESS;
}

