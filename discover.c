#include "headers.h"

void discover(char **command, char *sp, char *str)
{
    struct dirent **namelist;
    int n, i = 1, flagd = 0, flagf = 0;
    char *path = getcwd(NULL, 0);
    while (strcmp(command[i], "NULL") != 0)
    {
        if (strcmp(command[i], "-d") == 0)
        {
            flagd = 1;
        }
        else if (strcmp(command[i], "-f") == 0)
        {
            flagf = 1;
        }
        else if (strcmp(command[i], "-df") == 0)
        {
            flagd = flagf = 1;
        }
        else if (strcmp(command[i], "-fd") == 0)
        {
            flagd = flagf = 1;
        }
        else
        {
            strcpy(path, command[i]);
            if (strcmp(path, "~") == 0)
            {
                strcpy(path, root_directory);
            }
            // printf("%s\n",path);
        }
        i++;
    }
    n = scandir(path, &namelist, NULL, alphasort);
    char temp[100];
    strcpy(temp, str);
    if (n < 0)
        perror("scandir");
    else
    {
        int i = 0;
        while (i < n)
        {
            strcat(temp, namelist[i]->d_name);
            printf("%s%s\n", sp, temp);
            struct stat fs;
            int r;
            r = stat(namelist[i]->d_name, &fs);
            if (S_ISDIR(fs.st_mode))
            {
                char **path2;
                path2 = (char **)malloc(2 * sizeof(char *));
                path2[0] = (char *)malloc(100 * sizeof(char));
                path2[1] = (char *)malloc(100 * sizeof(char));
                strcpy(path2[1], "NULL");
                strcpy(path2[0], path);
                strcat(path2[0], "/");
                strcat(path2[0], namelist[i]->d_name);
                
                if(strcmp(namelist[i]->d_name,"..")!=0 && strcmp(namelist[i]->d_name,".")!=0)
                    explore(path2[0],"\t",temp);
            }
            strcpy(temp, str);
            i++;
        }
        free(namelist);
    }
}

void explore(char *path, char *space, char *address)
{
    struct dirent **namelist;
    int n = scandir(path, &namelist, NULL, alphasort);
    char temp[100];
    strcpy(temp, address);
    printf("%s\n", temp);
    // if (n < 0)
    //     perror("scandir");
    // else
    // {
    //     int i = 0;
    //     while (i < n)
    //     {
    //         // strcat(temp,namelist[i]->d_name);
    //         strcat(temp, namelist[i]->d_name);
    //         printf("%s%s\n", sp, temp);
    //         struct stat fs;
    //         int r;
    //         r = stat(namelist[i]->d_name, &fs);
    //         if (S_ISDIR(fs.st_mode))
    //         {
    //             char **path2;
    //             path2 = (char **)malloc(2 * sizeof(char *));
    //             path2[0] = (char *)malloc(100 * sizeof(char));
    //             path2[1] = (char *)malloc(100 * sizeof(char));
    //             strcpy(path2[1], "NULL");

    //             chdir("..");
    //             // printf("directory %s %s \n",path2[0],path2[1]);
    //         }
    //         strcpy(temp, str);
    //         i++;
    //     }
    //     free(namelist);
    // }
}