#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

#define BUF_SIZE 2
#define MAX_BUF 10

struct shared {
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
    char buf[BUF_SIZE];
};