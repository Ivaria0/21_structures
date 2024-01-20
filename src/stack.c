#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stackNode* init(int data) {
    struct stackNode *p;
    p = malloc(sizeof(struct stackNode));
    p->elem = data;
    p->next = NULL;
    return p;
}

struct stackNode* push(struct stackNode* st, const int data) {
    struct stackNode *p, *q;
    p = st;
    while (p->next != NULL)
        p = p->next;
    q = malloc(sizeof(struct stackNode));
    q->elem = data;
    p->next = q;
    q->next = NULL;
    return q;
}

int pop(struct stackNode* st) {
    struct stackNode *p, *q;
    p = st;
    while (p->next->next != NULL)
        p = p->next;
    q = p->next;
    int a = q->elem;
    q->next = NULL;
    free(q);
    q = NULL;
    return a;
}

void destroy(struct stackNode* st) {
    struct stackNode *p, *q;
    p = st;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
}
