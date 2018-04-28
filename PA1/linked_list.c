#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node *next;
} Node;

void append(Node **a_head, int value) {
    if ((*a_head) == NULL) {
        (*a_head) = malloc(sizeof(a_head));
        (*a_head)->value = value;
        (*a_head)->next = NULL;
    } else {
        Node *tail = *a_head;
        while (tail != NULL && tail->next != NULL) {
            tail = tail->next;
        }

        Node *new_node = malloc(sizeof(*new_node));
        new_node->value = value;
        new_node->next = (*a_head);

        tail->next = new_node;
    }
}


int main(int argc, char *argv[]) {
    Node *head = NULL;
    append(&head, 3);
    append(&head, 5);
    return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */




/* gcc -Wall -O2 linked_list.c */
/* valgrind ./a.out */

#include <stdio.h>
#include <stdlib.h>

struct elem {
    int pos;
    struct elem *next;
};

static void panic(const char *serror) {
    printf("%s", serror);
    exit(1);
}

static void *xmalloc(size_t size) {
    void *ptr;
    if (size == 0)
        panic("Size is 0!\n");
    ptr = malloc(size);
    if (!ptr)
        panic("No mem left!\n");
    return ptr;
}

static void xfree(void *ptr) {
    if (ptr == NULL)
        panic("Got Null-Pointer!\n");
    free(ptr);
}

static struct elem *init_list(size_t len) {
    struct elem *head = xmalloc(sizeof(struct elem));
    struct elem *trav = head;
    for (int i = 1; i <= len; i++) {
        trav->pos = i;
        trav->next = xmalloc(sizeof(struct elem));
        trav = trav->next;
    }
    xfree(trav->next);
    trav->next = head;
}

static void clean_list(struct elem *head, size_t len) {

}

static void traverse_list(struct elem *head, int times) {
    for (int i = 0; i < times; i++) {

        struct elem *tail = head;
        int last_pos = 0;
        while (tail != NULL && tail->pos > last_pos) {
            tail = tail->next;
            last_pos = tail->pos;
        }
        xfree(tail);
    }
}

int main(void) {
    struct elem *head = NULL;
    size_t len = 10;

    head = init_list(len);


    return 0;
}
