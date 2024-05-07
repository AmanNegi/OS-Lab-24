#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char buffer[1024];
    int fd = open("file.txt", O_CREAT| O_RDONLY, 0644);
    lseek(fd, 5, SEEK_SET); // move the pointer 5 characters ahead
    read(fd, buffer, 1024);

    printf("Data(from 5th index): %s", buffer);
    printf("\n");

    return 0;
}