#include <stdio.h>
#include <pthread.h>

int sharedCounter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/**
 * Mutex is a type of binary semaphore, so the implementation is very similar
 * It is provided/implemented in the <pthread.h> itself, so we don't need any additional imports.
*/
void *performAdd()
{
    for (int i = 0; i < 10000; i++){
        pthread_mutex_lock(&mutex);
        sharedCounter++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t pids[10];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 10; i++)
        pthread_create(&pids[i], NULL, performAdd, NULL);
    for (int i = 0; i < 10; i++)
        pthread_join(pids[i], NULL);

    printf("Total value: %d\n", sharedCounter);

    return 0;
}