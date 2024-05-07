#include <stdio.h>
#include <pthread.h>

void* threadfn(){
    printf("Hello from thread");
    printf("\n");
}
int main(){
    pthread_t thread_id; // pthread_type
    pthread_create(&thread_id, NULL, threadfn, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}

