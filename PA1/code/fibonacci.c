#include <stdlib.h>
#include <stdio.h>

int f(int x);

int main() {
    printf("%d", f(10));
}

int f(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    return (f(x - 1) + f(x - 2));
}