#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("file1.txt", O_CREAT | O_RDONLY, 0644);
	char data[1024];
	read(fd, data, 1024);

	printf("%s\n", data);
	return 0;
}
