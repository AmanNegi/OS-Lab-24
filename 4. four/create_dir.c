#include <stdio.h>
#include <sys/stat.h> // provides with mkdir(__name, __permissionLevel)

int main(){
    const char* dirName = "NewDirectory";
    mkdir(dirName, 0777); 
    // 0777 as all folders have `rwx` permissions 
    // x not to run the folder like we run .sh files but x to enter the folder
    return 0;

}