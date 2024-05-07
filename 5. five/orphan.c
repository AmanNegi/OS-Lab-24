// When is a process Orphan?
// Ans: When it has no parent

#include <stdio.h>
#include <unistd.h>

int main(){

    int child_id = fork();

    if(child_id==0){
        // child
        sleep(3);
        printf("I'm child took some time");
        printf("\n");
    }else if(child_id > 0){
        // parent
        printf("I'm done!");
        printf("\n");
        return 0;
    }else{
        printf("Error while creating child process");
        printf("\n");
    }

    return 0;
}