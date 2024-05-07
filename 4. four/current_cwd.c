#include <stdio.h>
#include <unistd.h> //provides:  getcwd, rmdir, chdir
//NOTE: But for mkdir we need #include <sys/stat.h>
// For readDir we need #include <dirent.h>

int main()
{
    char c[1024];
    getcwd(c, 1024);
    printf("%s", c);
    printf("\n");

    return 0;
}