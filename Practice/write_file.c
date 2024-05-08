#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("file1.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	char data[] = "Hello world!";
	write(fd, data, sizeof(data));
	close(fd);
	return 0;
}
