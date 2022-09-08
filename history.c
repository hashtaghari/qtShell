#include "headers.h"

FILE *fp;


void load_history()
{
    fp = fopen("history.txt", "r");
    if (fp == NULL)
    {
        // create file with 20 NULL commands
        fp = fopen("history.txt", "w");
        for (int i = 0; i < 20; i++)
        {
            fprintf(fp, "NULL\n");
        }

        fclose(fp);

        fp = fopen("history.txt", "r");
    }
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp))
    {
        strcpy(old_commands[i], line);
        i++;
    }
    fclose(fp);
}

void update_history(char *command)
{
    // CHECK FOR LAST COMMAND
    command[strlen(command) - 1] = '\0';
    printf("%s %s a\n",old_commands[19],command);
    if (strcmp(old_commands[19], command) == 0)
        return;

    // UPDATE OLD COMMANDS
    for(int i=0;i<19;i++){
        strcpy(old_commands[i],old_commands[i+1]);
    }
    strcpy(old_commands[19],command);
    old_commands[19][strlen(old_commands[19])-1]='\0';

    // UPDATE HISTORY FILE
    fp = fopen("history.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    int i = 0;
    while (strcmp(old_commands[i], "\0") != 0)
    {
        fprintf(fp, "%s\n", old_commands[i]);
        i++;
    }
    fclose(fp);
}


void history(char **command)
{   
    
    for(int i=0;i<20;i++){
        if((old_commands[i],"NULL")!=0){
            continue;
        }
        printf("%s\n",old_commands[i]);
    }
}
