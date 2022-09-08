#include "headers.h"

// get current working directory and return it
void pwd()
{
    char *current_path = getcwd(NULL, 0);
    printf("%s\n", current_path);
}