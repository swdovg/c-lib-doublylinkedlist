#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"


void printInt(void *value) {
    printf("%d ", *((int*) value));
}

void printDouble(void *value) {
    printf("%1.1f ", *((double*) value));
}

void printChar(void *value) {
    printf("%c ", *((char*) value));
}

int main() {
    DblLinkedList *intlist = createDblLinkedList(INT);
    DblLinkedList *doublelist = createDblLinkedList(DOUBLE);
    DblLinkedList *charlist = createDblLinkedList(CHAR);

    int ia, ib, ic, id, ie, ik, ig, ih;
    double da, db, dc, dd, de, dk, dh;
    char ca, cb, cc, cd, ce, ck, cg, ch, cj, cs;

    ia = 10;
    ib = 20;
    ic = 30;
    id = 40;
    ie = 50;
    ik = 60;
    ig = 70;
    ih = 56;

    da = 3.2;
    db = 2.4;
    dc = 7.6;
    dd = -0.2;
    de = 0;
    dk = 0.2;
    dh = -1.4;

    ca = 's';
    cb = 'o';
    cc = 'm';
    cd = 'e';
    ce = 't';
    ck = 'h';
    cg = 'i';
    ch = 'n';
    cj = 'g';
    cs = 'r';

    //int list testing
    pushHead(intlist, &ia);
    pushHead(intlist, &ib);
    pushHead(intlist, &ic);
    pushTail(intlist, &id);
    pushTail(intlist, &ie);
    pushTail(intlist, &ik);
    printDblLinkedList(intlist, printInt);
    printf("length: %d\n", intlist->size);
    printf("2th element: %d\n", *((int*)(getNth(intlist, 2))->value));
    printf("5th element: %d\n", *((int*)(getNth(intlist, 5))->value));
    printf("find node with 50 value: %d\n", *((int*)(findNode(intlist, &ie))->value));
    if  (findNode(intlist, &ih)==NULL)
        printf("no node with value %d\n", ih);
    printf("popHead: %d\n", *((int*)popHead(intlist)));
    printf("popHead: %d\n", *((int*)popHead(intlist)));
    printDblLinkedList(intlist, printInt);
    printf("head: %d\n", *((int*)(intlist->head->value)));
    printf("tail: %d\n", *((int*)(intlist->tail->value)));
    printf("popTail: %d\n", *((int*)popTail(intlist)));
    printf("popTail: %d\n", *((int*)popTail(intlist)));
    printDblLinkedList(intlist, printInt);
    printf("length: %d\n", intlist->size);
    printf("push after 0th: 70\n");
    pushNth(intlist, 0, &ig);
    printDblLinkedList(intlist, printInt);
    printf("pop 1th element: %d\n", *(int*)popNth(intlist, 1));
    printDblLinkedList(intlist, printInt);
    printf("isListEmpty: %d\n", isListEmpty(intlist));
    printf("popTail: %d\n", *((int*)popTail(intlist)));
    printf("popTail: %d\n", *((int*)popTail(intlist)));
    printf("isListEmpty: %d\n", isListEmpty(intlist));
    deleteDblLinkedList(&intlist);
    printf("\n");

    //double list testing
    pushHead(doublelist, &da);
    pushHead(doublelist, &db);
    pushHead(doublelist, &dc);
    pushTail(doublelist, &dd);
    pushTail(doublelist, &de);
    pushTail(doublelist, &dk);
    printDblLinkedList(doublelist, printDouble);
    printf("find node with 2.4 value: %1.1f\n", *((double*)(findNode(doublelist, &db))->value));
    if  (findNode(doublelist, &dh)==NULL)
        printf("no node with value: %1.1f\n", dh);
    deleteDblLinkedList(&doublelist);
    printf("\n");

    //char list testing
    pushHead(charlist, &cd);
    pushHead(charlist, &cc);
    pushHead(charlist, &cb);
    pushHead(charlist, &ca);
    pushTail(charlist, &ce);
    pushTail(charlist, &ck);
    pushTail(charlist, &cg);
    pushTail(charlist, &ch);
    pushTail(charlist, &cj);
    printDblLinkedList(charlist, printChar);
    printf("find node with value: %c\n", *((char*)(findNode(charlist, &ce))->value));
    if  (findNode(charlist, &cs)==NULL)
        printf("no node with value: %c\n", cs);
    deleteDblLinkedList(&charlist);
    printf("\n");
    return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

