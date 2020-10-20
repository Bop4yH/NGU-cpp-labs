#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define SUCCESS 0
#define THREADS 4
#define BUF_SIZE 256

void pthread_error(const char *const msg, int error, int id) {
    fprintf(stderr, "%s: %d %s", msg, id, strerror(error));
    exit(1);
}

void *child_body(void* arg) {
    unsigned long int id = pthread_self();
    char** lines = (char**)arg;

    for (int i = 0; i < BUF_SIZE; i++){
        if(lines[i] != NULL) {
            printf("child %lu %s\n", id, lines[i]);
        }
    }
    return NULL;
}

int main() {
    char *child_p[THREADS][BUF_SIZE] = {{"line 1", "line 2", "line 3", NULL},
                                        {"line 4", "line 5", NULL},
                                        {"line 6", NULL},
                                        {"line 7", "line 8", "line 9", NULL}};

    pthread_t child[THREADS];
    int error;
    for (int i = 0; i < THREADS; i++) {

        error = pthread_create(&child[i], NULL, child_body, child_p[i]);
        if (error != 0) {
            pthread_error("pthread_create() failed on", error, i);
        }
    }

    for (int i = 0; i < THREADS; i++) {
        error = pthread_join(child[i], NULL);
        if (error != SUCCESS) {
            pthread_error("pthread_join() failed on", error, i);
        }
    }

    pthread_exit(NULL);
}
