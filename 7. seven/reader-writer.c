#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

/**
 * Syncronize `n` readers and 1 writer:
 *  - If `n` readers are active no writer is allowed
 *  - If 1 writer is writing no other writer should be allowed to write
 */
int sharedVar = 0;

pthread_mutex_t readLock = PTHREAD_MUTEX_INITIALIZER; // lock for reading
sem_t writeLock;                                      // lock for writing

void *readSection()
{
    for (int i = 0; i < 10; i++)
    {
        // don't allow reading while writing and  don't allow writing while reading
        pthread_mutex_lock(&readLock);
        sem_wait(&writeLock);
        printf("Reading: %d\n", sharedVar);
        sem_post(&writeLock);
        pthread_mutex_unlock(&readLock);
    }

    pthread_exit(NULL);
}

void *writeSection()
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&readLock);
        sem_wait(&writeLock);
        sharedVar++;
        printf("Updating value: %d\n", sharedVar);
        sem_post(&writeLock);
        pthread_mutex_unlock(&readLock);
    }

    pthread_exit(NULL);
}

int main()
{
    sem_init(&writeLock, 0, 1);
    pthread_mutex_init(&readLock, NULL);
    pthread_t readers[10];

    pthread_t writer;
    pthread_create(&writer, NULL, writeSection, NULL);

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&readers[i], NULL, readSection, NULL);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(readers[i], NULL);
    }

    pthread_join(writer, NULL);

    printf("Counter: %d", sharedVar);
    return 0;
}