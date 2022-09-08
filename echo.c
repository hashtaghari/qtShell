#include "headers.h"

void echo(char **command)
{
    int i = 1;
    while (strcmp(command[i], "NULL") != 0)
    {
        printf("%s ", command[i]);
        i++;
    }
    printf("\n");
}