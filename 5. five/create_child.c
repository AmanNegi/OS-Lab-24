#include <stdio.h>
#include <unistd.h> // fork(), sleep()

int main(){
    int res = fork();
    if(res == 0){
        // child
        printf("Hello I am child, my id is %d", getpid());
        printf("\n");
        printf("Hello I am child, my parent id is %d", getppid());
        printf("\n");
    }else if(res>0){
        // parent
        printf("Hello I am parent, my id is: %d", getpid() );
        printf("\n");
        printf("Hello I am parent, my child id is: %d", res );
        printf("\n");
    }else{
        printf("Error occurred while creating a child");
    }
}