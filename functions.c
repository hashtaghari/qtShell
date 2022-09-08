#include "headers.h"

// char *path_finder(char *path){
//     errno = 0;
//     if (getcwd(path, 100) == NULL) {
//         if (errno == ERANGE)
//             printf("[ERROR] pathname length exceeds the buffer size\n");
//         else
//             perror("getcwd");
//         exit(EXIT_FAILURE);
//     }
//     return path;
// }

char **commands_extract(char *input, const char *delim)
{
    char **command_list;
    command_list = (char **)malloc(10* sizeof(char *));
    int ctr = 0;
    char *commands = strtok(input, delim);
    while (commands != NULL)
    {
        command_list[ctr] = (char *)malloc(BUFFER_SIZE * sizeof(char));
        strcpy(command_list[ctr], commands);
        ctr++;
        commands = strtok(NULL, delim);
    }
    command_list[ctr] = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(command_list[ctr], "NULL");

    return command_list;
}

int execute_command(char *command)
{
    char **commands_broken;
    char commands_copy[BUFFER_SIZE];
    strcpy(commands_copy, command);
    commands_broken = commands_extract(commands_copy, " ");
    // printf("%s",commands_broken[1]);
    if (strcmp(commands_broken[0], "cd") == 0)
    {
        cd(commands_broken);
    }
    else if (strcmp(commands_broken[0], "pwd") == 0)
    {
        pwd();
    }
    else if (strcmp(commands_broken[0], "exit") == 0)
    {
        exit(0);
    }
    else if (strcmp(commands_broken[0], "echo") == 0)
    {
        echo(commands_broken);
    }
    else if (strcmp(commands_broken[0], "ls") == 0)
    {
        ls(commands_broken);
    }
    else if (strcmp(commands_broken[0], "history") == 0)
    {
        history(commands_broken);
    }
    else
    {
        return -1;
    }


    return 0;
}