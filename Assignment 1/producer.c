#include "producer_consumer.h"

int main() {

    //open shared memory object and make sure space is avaliable for our buffer
    int fd = shm_open("/producer-consumer", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);

    // create a pcbuf struct named pcbufs and map to the shared memory space
    struct shared *buffer = mmap(NULL, sizeof(*buffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    ftruncate(fd, sizeof(struct shared));
    
    sem_init(&buffer->empty, 1, 0);
    sem_init(&buffer->full, 1, 0);

    // loop and wait for the consumer to post to the semaphore before producing any data
    char item = 'a';
    int in = 0;
    for (int index = 0; index < MAX_BUF; index++) {
        sem_wait(&buffer->empty);
        pthread_mutex_lock(&buffer->mutex);
        buffer->buf[in] = item;
        printf("Producer sent item on %d: %c\n", in, item);
        in = (in + 1) % BUF_SIZE;
        item++;
        pthread_mutex_unlock(&buffer->mutex);
        sem_post(&buffer->full); 
    }

    shm_unlink("/producer-consumer"); // unlink
    exit(EXIT_SUCCESS); // exit with success

}