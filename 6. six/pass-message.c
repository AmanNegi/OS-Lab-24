#include <stdio.h>
#include <pthread.h>

void *doSomething(void *message)
{
    printf("%s",(char*) message);
}
int main()
{
    pthread_t pid;
    pthread_create(&pid, NULL, doSomething, "Hello from pumpkin!\n"); // note here we pass reference &id
    pthread_join(pid, NULL); // note here we pass value
    return 0;
}