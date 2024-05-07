#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>  
#include <string.h> // for the strlen()

int main(){
    int fd = open("file.txt",O_CREAT | O_WRONLY , 0644);
    
    // first write into the file
    char data[] = "Hello my name is Kaddu Pakku";
    write(fd, data, strlen(data));
    close(fd);

    // now let's read
    fd = open("file.txt", O_RDONLY, 0644);
    char readBuffer[1024];
    read(fd, readBuffer, 1024);

    printf("Data: %s", readBuffer);
    printf("\n");

    return 0;
}
