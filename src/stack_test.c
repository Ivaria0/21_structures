#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push_test(struct stackNode *stack, int data);
void pop_test(struct stackNode *stack, int exp);

int main() {
    int data = 7;
    struct stackNode *stack;
    stack = init(data);
    data = 3;
    push_test(stack, data);
    data = 8;
    push_test(stack, data);
    pop_test(stack, data);
    data = 4;
    push_test(stack, data);
    pop_test(stack, data);
    destroy(stack);
    stack = NULL;
}

void push_test(struct stackNode *stack, int data) {
    struct stackNode *p;
    p = push(stack, data);
    printf("%d\n", p->elem);
    if (p->elem == data)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void pop_test(struct stackNode *stack, int exp) {
    struct stackNode *p;
    p = stack;
    int data = pop(p);
    printf("%d\n", data);
    if (data == exp)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
