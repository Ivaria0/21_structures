#include "list.h"
#include "door_struct.h"

#include <stdio.h>
#include <stdlib.h>

struct node *init(const struct door *door) {
    if (door != NULL) {
        struct node *p;
        p = malloc(sizeof(struct node));
        p->elem = *door;
        p->next = NULL;
        return p;
    }
    return NULL;
}

struct node *add_door(struct node *elem, const struct door *door) {
    if (door != NULL) {
        struct node *p;
        p = malloc(sizeof(struct node));
        p->elem = *door;
        p->next = elem->next;
        elem->next = p;
    }
    return elem;
}

struct node *find_door(int door_id, struct node *root) {
    struct node *p;
    p = NULL;
    struct node *t = root;
    while ((t != NULL) && (p == NULL)) {
        if (t->elem.id == door_id)
            p = t;
        t = t->next;
    }
    return p;
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *p;
    p = root;
    if ((root != NULL) && (elem != NULL)) {
        if (p != elem) {
            while ((p->next != elem) && (p->next != NULL))
                p = p->next;
            struct node *q;
            if (p->next != NULL) {
                q = p->next;
                p->next = q->next;
                q->next = NULL;
                free(q);
            }
        } else {
            p = elem->next;
            elem->next = NULL;
            free(elem);
            root = p;
        }
    }
    return root;
}

void destroy(struct node *root) {
    struct node *p;
    while (root != NULL) {
        p = root->next;
        free(root);
        root = p;
    }
}
