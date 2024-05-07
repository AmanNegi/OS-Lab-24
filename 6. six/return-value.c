#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *threadFn(void *args)
{
    int *returnValue = malloc(sizeof(int));
    *returnValue = 10;
    pthread_exit(returnValue);
}

int main()
{

    int *response;
    pthread_t pid;
    pthread_create(&pid, NULL, threadFn, NULL);
    pthread_join(pid, (void **)&response); // must cast to (void **)

    printf("%d\n", *response);
    return 0;
}