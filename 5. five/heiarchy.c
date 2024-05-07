/*
    Create Heiarchy
            |P1|
       P2       P3
       P4
       P5 
*/

#include <stdio.h>  // STD I/O
#include <unistd.h> // universal STD functions

// including parent: 2^n processes
// discluding parent: 2^n - 1 processes

int main()
{
    int id1 = fork();
    if (id1 > 0)
    {
        // this is parent
        id1 = fork(); // create only one child
    }
    else if (id1 == 0)
    {
        int id2 = fork();
        if (id2 == 0)
        {
            int id3 = fork();
            
        }
    }

    printf("Hello");
    printf("\n");

    return 0;
}
