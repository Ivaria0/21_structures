#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include "door_struct.h"

#include <stdio.h>
#include <stdlib.h>


struct node {
    struct door elem;
    struct node* next;
};

struct node* init(const struct door* door);
struct node* add_door(struct node* elem, const struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);


#endif  // SRC_LIST_H_
