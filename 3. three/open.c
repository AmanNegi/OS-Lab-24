#include <stdio.h>
#include <fcntl.h>  // exposes open(), O_CREAT, O_RDONLY
#include <unistd.h> // exposes close(fd)
#include <string.h>

int main()
{
    int fd;
    fd = open("file.txt", O_RDONLY| O_CREAT , 0644);
    close(fd);
    return 0;
}