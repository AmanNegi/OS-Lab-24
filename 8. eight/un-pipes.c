#include <stdio.h>
#include <unistd.h>

/**
 * Create an un-named pipe using pipe() fn
 * pipe(arr[2]) -> arr[0]: read end, arr[1]: write end
*/
int main()
{
    int pipe_fd[2]; // 0 -> read end , 1-> write end
    if (pipe(pipe_fd) < 0)
    {
        printf("Unable to create pipe!");
        return 0;
    }

    int pid = fork();
    if(pid > 0){
        // parent
        char data[] = "Hello from parent\n";
        write(pipe_fd[1], data, sizeof(data));
        close(pipe_fd[1]);
    }else {
        // child
        char data[100];
        read(pipe_fd[0],data, sizeof(data));
        printf("The data is: %s", data);
        close(pipe_fd[0]);
    }

}
