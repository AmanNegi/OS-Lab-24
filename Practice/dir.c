#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>


int main(){
// 	mkdir("NewFolder", 0777); -> sys/stat.h
	DIR *dir;
	struct dirent *entry;
	dir = opendir("."); 

	if(dir){
		while((entry = readdir(dir))!=NULL){ // dirent.h
			printf("%s\n", entry->d_name);
		}
	}

}

