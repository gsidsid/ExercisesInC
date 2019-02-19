#include <stdio.h>

void main(int argc, char* argv[]) {
    FILE *teefile;
    char inp_buf[92];
    while (1) {
        // Open filename specified by first argument in append mode
        teefile = fopen(argv[1], "a+");
        // Scan stdin to local variable
        scanf("%s", inp_buf);
        printf("%s\n", inp_buf);
        // Print contents of local variable to file
        fprintf(teefile, "%s\n", inp_buf);
        fclose(teefile);
    }
}

/*
    Using stackoverflow and reading the appropriate API for file reading/writing operations
    worked very well to speed up my development process. I was slowed down partly because I 
    expected this command to be much harder to implement (core functionality) than it 
    actually was. 
*/

/*
    The professional implementation has support for more options (using cases/switches), 
    interruptions (using SIGINT), has a help "?" option, and appears to have support for
    writing std in to multiple files using some sort of linked list.
*/