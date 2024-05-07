#include <stdio.h>
#include <pthread.h>

int sharedCounter = 0;
/*
    When a thread comes to this function, the value of sharedcounter may be incremented, causing
    inconsistency in data.

    The result should normally be 10,000 however it never will be.... 
*/
void *incrementCount(void *args)
{
    for(int i =0;i<1000;i++)
        sharedCounter++;
}

int main()
{
    pthread_t pid[10];

    for(int i =0;i<10;i++){
        pthread_create(&pid[0], NULL, incrementCount, NULL);
    }

    for(int i =0;i<10;i++){
        pthread_join(pid[0], NULL);
    }

    printf("Value of counter: %d\n", sharedCounter); 
    //  Try to run this couple of times the value will always be different
    return 0;
}