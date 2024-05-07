#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 5

void * calcAverage(void * args){
    int* arr = (int*) args;

    int* avg = malloc(sizeof(int));

    for(int i =0;i<SIZE;i++){
        *avg+=arr[i];
    }

    *avg/=SIZE;
    pthread_exit(avg);
}


int main(){

    pthread_t pid;
    int arr[SIZE]= {1, 2, 3, 4, 5};
    int *avg;
    pthread_create(&pid, NULL, calcAverage, arr );
    pthread_join(pid, (void**) &avg); 
    // must cast to (void**) NOTE: It takes address of pointer not variable


    printf("Average is: %d\n", *avg);

    return 0;
}