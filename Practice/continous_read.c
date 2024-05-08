#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("file1.txt", O_CREAT | O_RDONLY, 0644);
	char buffer[1024];
	
	int totalBytes = 0;
	int bytesRead;
	while((bytesRead = read(fd, buffer, 1024)) > 0){
		printf("%d\n", (int) bytesRead);
		totalBytes+=bytesRead;
	} 	
	printf("Total Bytes: %d\n", totalBytes);
	return 0;
}
