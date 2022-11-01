
#include "producer_consumer.h"

int main() {
    int fd = shm_open("/producer-consumer", O_RDWR, 0);

    // create a pcbuf struct named pcbufs and map to the shared memory space
    struct shared *buffer = mmap(NULL, sizeof(*buffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    sem_post(&buffer->empty);
    
    int out = 0;
    for (int index = 0; index < MAX_BUF; index++) {
        sem_wait(&buffer->full);
        pthread_mutex_lock(&buffer->mutex);
        char item = buffer->buf[out];
        printf("Consumer recieved item on %d: %c\n", out, item);
        out = (out + 1) % BUF_SIZE;
        pthread_mutex_unlock(&buffer->mutex);
        sem_post(&buffer->empty);
    }

    shm_unlink("/producer-consumer"); // unlink
    exit(EXIT_SUCCESS); // exit with success

}