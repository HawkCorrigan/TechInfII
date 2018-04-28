#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Too few arguments!");
        return 1;
    }
    if (argc > 3) {
        printf("Too many arguments!");
        return 2;
    }

    printf("Result: %d", atoi(argv[1]) * atoi(argv[2]));
    return 0;

}
