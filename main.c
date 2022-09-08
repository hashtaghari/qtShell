#include "headers.h"

char *root_directory, *prev_directory, *cur_dir;
char old_commands[20][BUFFER_SIZE];
int old_commands_ptr=0;

int main()
{
    load_history();
    
    root_directory = (char *)malloc(100 * sizeof(char));
    prev_directory = (char *)malloc(100 * sizeof(char));
    cur_dir = (char *)malloc(100 * sizeof(char));
    root_directory = getcwd(NULL, 0);
    cur_dir = getcwd(NULL, 0);
    prev_directory = getcwd(NULL, 0);
    for(int i=0;i<20;i++){
        strcpy(old_commands[i],"NULL");
    }

    while (1)
    {
        prompt();
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);
        // check if input is null
        if (strcmp(input, "") == 0)
            continue;
        update_history(input);
        char **commands_sep;
        commands_sep = commands_extract(input, ";&\n");

        // print commands_se

        int i = 0;
        while (strcmp(commands_sep[i], "NULL") != 0)
        {

            int valid = execute_command(commands_sep[i]);
            if (valid == -1)
                printf("Invalid Command: %s\n", commands_sep[i]);
           
            i++;
        }
        
    }
    return 0;
}
