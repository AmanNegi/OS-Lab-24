// What is zombie process?
// Ans: A parent awaiting completion not doing any processing.... cause of sleep()
// In the below example child finishes almost instantly, however the proecess awaits 10 seconds
// doing nothing and then finishes.

#include <stdio.h>
#include <unistd.h>

int main(){
    int child_id = fork();
    if(child_id==0){
        printf("Child: Running...");
        printf("\n");
        printf("Child: I'm done exiting...");
        printf("\n");
        return 0;
    }else if(child_id >0){
        printf("Parent: Running... (sleep: 3 seconds)");
        printf("\n");
        sleep(10); // ~ hanging in there doing nothing
        printf("Parent: I'm also done now!!");
        printf("\n");
    }else {
        printf("An error occured while creating the process!");
        printf("\n");
    }


    return 0;
}