#include <stdio.h>
#include <dirent.h> // directory entry

int main(){
    DIR *dir;
    struct dirent *entry ;

    dir = opendir(".");
    if(dir){
        printf("Contents of the directory: ");
        while((entry = readdir(dir)) != NULL){
                printf("%s\n", entry->d_name);
        }
    }

    return 0;
}


