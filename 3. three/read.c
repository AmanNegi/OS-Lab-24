#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // FileCoNTroL.h (fcntl)

int main(){

    int fd;
    char buffer[1024];

    fd = open("file.txt", O_RDONLY, 0644);
    read(fd, buffer, 1024);

    printf("Buffer Data: %s", buffer);
    printf("\n");
    
    return 0;
}