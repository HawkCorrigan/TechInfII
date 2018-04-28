#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char *substring(const char *, off_t off, size_t len);

static void *xmalloc(size_t size);

/*C substring function: It returns a pointer to the substring */

char *substring(const char *string, off_t off, size_t len) {
    static char *temp;
    temp = xmalloc(len);
    memcpy(temp, string + off, len);

    return temp;
}

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

int main() {
    char *foo = "Nicht\n";
    char *bar = substring(foo, 2, 3);
    printf("%s", bar);
    free(bar);
    return 0;
}