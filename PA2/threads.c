#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thredder(void *arg) {
    int *num = arg;
    int actualrealnumber = *num;
    while (1) {
        printf("Thread %d: Hello World!\n", actualrealnumber);
        sleep(5);
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Wrong number of arguments.");
        return 0;
    }

    int num = atoi(argv[1]);

    pthread_t *thrpnt = malloc(num * sizeof(pthread_t));

    for (int i = 0; i < num; ++i) {
        pthread_create((thrpnt + i), NULL, thredder, &i);
        sleep(0.001);
    }

    while (1);

}