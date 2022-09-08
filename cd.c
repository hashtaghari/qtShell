#include "headers.h"

void cd(char **command)
{
    cur_dir=getcwd(NULL,0);
    if(strcmp(command[1],"NULL")==0){
        strcpy(prev_directory,cur_dir);
        chdir(root_directory);
        cur_dir=getcwd(NULL,0);
    }
    else if(strcmp(command[2],"NULL")!=0){
        printf("Error: Too many arguments in cd\n");
        return;
    }
    else if ((strcmp(command[1], "..") == 0) && (strcmp(root_directory, cur_dir) == 0))
    {
        printf("%s\n", root_directory);
    }
    else if (strcmp(command[1], "~") == 0)
    {
        
        chdir(root_directory);
        strcpy(prev_directory,cur_dir);
        strcpy(cur_dir,root_directory);

    }
    else if(strcmp(command[1],"-")==0){

        chdir(prev_directory);
        strcpy(prev_directory,cur_dir);
        cur_dir=getcwd(NULL,0);
    }
    else
        {
            prev_directory=getcwd(NULL,0);   
            int success=chdir(command[1]);
            if(success!=0){
                printf("No such directory\n");
            }
            }
            cur_dir=getcwd(NULL,0);
}
