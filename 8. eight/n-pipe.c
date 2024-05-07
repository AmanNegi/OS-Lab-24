#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char *path = "/tmp/myfifo";
    mkfifo(path, 0666);

    int fd;
    pid_t pid = fork();

    if (pid == 0)
    { // Child process
        fd = open(path, O_RDONLY);
        char readData[1024];
        read(fd, readData, sizeof(readData));
        printf("The data is: %s\n", readData);
        close(fd);
    }
    else if (pid > 0)
    { // Parent process
        fd = open(path, O_WRONLY);
        char data[] = "My OS Practical";
        write(fd, data, sizeof(data));
        close(fd);
        printf("Written data\n");
    }
    else
    { // fork failed
        printf("fork() failed!\n");
        return 1;
    }

    return 0;
}