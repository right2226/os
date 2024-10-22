#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0; // Next empty spot in the buffer
int out = 0; // Next full spot in the buffer

sem_t empty; // Semaphore to count empty spots
sem_t full;  // Semaphore to count full spots
pthread_mutex_t mutex; // Mutex for critical section

// Producer function
void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        // Produce an item
        int item = rand() % 100;

        // Wait for an empty spot
        sem_wait(&empty);
        pthread_mutex_lock(&mutex); // Enter critical section

        // Add item to buffer
        buffer[in] = item;
        printf("Produced: %d at %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&full); // Signal that a new item has been produced

        sleep(rand() % 2); // Simulate time taken to produce
    }
    return NULL;
}

// Consumer function
void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        // Wait for a full spot
        sem_wait(&full);
        pthread_mutex_lock(&mutex); // Enter critical section

        // Remove item from buffer
        int item = buffer[out];
        printf("Consumed: %d from %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&empty); // Signal that an item has been consumed

        sleep(rand() % 2); // Simulate time taken to consume
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE); // All spots are empty
    sem_init(&full, 0, 0); // No spots are full
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

