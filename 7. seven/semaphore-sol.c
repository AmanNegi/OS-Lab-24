#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sharedCounter =0;
sem_t semaphore;  // sem_t stands for semaphore type (similar to pthread_t)

/**
 * The sem_wait and sem_post, help the thread to sleep and get back to work once no one is using the 
 * critical section.
 * 
 * 1. sem_wait: Decrements the semaphore, potraying it's unavailable. If it's already 0 then the function
 * blocks and waits for it to be greater than `0` i.e puts thread to wait.
 * 
 * 2. sem_post: Increments the semaphore, potraying it's available. It may wake up a thread that has
 * been waiting at (sem_wait).
*/
void* performAddition(){
    for(int i =0;i<1000;i++){
        sem_wait(&semaphore); // sem-- (decrement):  0 -> unavailable
        sharedCounter++;
        sem_post(&semaphore); // sem++ (increment): 1 -> available
    }
}


int main(){
    pthread_t pid[10];

    sem_init(&semaphore, 0, 1 );

    for(int i=0;i<10;i++){
        pthread_create(&pid[i], NULL, performAddition, NULL);
    }

    for(int i=0;i<10;i++){
        pthread_join(pid[i], NULL);
    }

/**
 * In this case no matter how many times you try the value will be exact 10,0000 which is as expected
*/
    printf("Counter: %d\n", sharedCounter);

    sem_destroy(&semaphore);
    return 0;
}