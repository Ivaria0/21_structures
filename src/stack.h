#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>


struct stackNode {
    int elem;
    struct stackNode* next;
};

struct stackNode* init(int data);
struct stackNode* push(struct stackNode* st, const int data);
int pop(struct stackNode* st);
void destroy(struct stackNode* st);


#endif  // SRC_STACK_H_
