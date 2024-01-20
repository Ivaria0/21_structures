#include "list.h"
#include "door_struct.h"

#include <stdio.h>
#include <stdlib.h>

void door_add_test(struct node *doors, struct door door_t, int exp_id, int exp_st);
struct node* door_remove_test(struct node *el, struct node *root, int exp_id, int exp_st);

int main() {
    find_door(0, NULL);
    struct door door_t;
    door_t.id = 5;
    door_t.status = 0;
    struct node *doors;
    doors = init(&door_t);
    door_t.id = 3;
    door_t.status = 1;
    struct node *el;
    el = doors;
    door_add_test(el, door_t, 3, 1);
    door_t.id = 2;
    door_t.status = 4;
    door_add_test(el, door_t, 2, 4);
    el = el->next;
    door_remove_test(el, doors, 2, 4);
    doors = door_remove_test(doors, doors, 3, 1);
    door_t.id = 4;
    door_t.status = 2;
    el = doors;
    door_add_test(el, door_t, 4, 2);
    destroy(doors);
    doors = NULL;
}

void door_add_test(struct node *doors, struct door door_t, int exp_id, int exp_st) {
    struct node *p;
    struct door door_1, door_res;
    door_1 = doors->elem;
    p = add_door(doors, &door_t);
    door_res = p->next->elem;
    printf("%d, %d\n", door_res.id, door_res.status);
    if ((door_res.id == exp_id) && (door_res.status == exp_st) &&
        (door_1.id == p->elem.id) && (door_1.status == p->elem.status))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

struct node* door_remove_test(struct node *el, struct node *root, int exp_id, int exp_st) {
    struct node *p;
    struct door door_res;
    int k = 0;
    if (root != el)
        k = 1;
    p = remove_door(el, root);
    if (k == 1)
        door_res = el->elem;
    else
        door_res = p->elem;
    printf("%d, %d\n", door_res.id, door_res.status);
    if ((door_res.id == exp_id) && (door_res.status == exp_st))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    return p;
}
