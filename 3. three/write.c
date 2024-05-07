#include <stdio.h>
#include <fcntl.h>  // exposes open(), O_CREAT, O_APPEND, O_WRONLY
#include <unistd.h> // exposes close(fd)
#include <string.h>

int main()
{
    int fd;
    fd = open("file.txt", O_WRONLY | O_CREAT | O_APPEND , 0644);
    char data[] = "hello beta";
    write(fd, data, strlen(data));
    // close(fd);

    return 0;
}