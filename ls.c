#include "headers.h"

void ls(char **command)
{
    struct dirent **namelist;
    int n, i = 1, flagl = 0, flaga = 0;
    char *path = getcwd(NULL, 0);
    while (strcmp(command[i], "NULL") != 0)
    {
        if (strcmp(command[i], "-a") == 0)
        {
            flaga = 1;
        }
        else if (strcmp(command[i], "-l") == 0)
        {
            flagl = 1;
        }
        else if (strcmp(command[i], "-la") == 0)
        {
            flaga = flagl = 1;
        }
        else if (strcmp(command[i], "-al") == 0)
        {
            flaga = flagl = 1;
        }
        else
        {
            strcpy(path, command[i]);
            if(strcmp(path,"~")==0){
                strcpy(path,root_directory);
            }
            // printf("%s\n",path);
        }
        i++;
    }
    // printf("%d %d\n",flaga,flagl);

    if (flagl == 0)
    {
        n = scandir(path, &namelist, NULL, alphasort);
        if (n < 0)
            perror("scandir");
        else
        {
            int i = 0;
            while (i < n)
            {
                if(flaga==0 && namelist[i]->d_name[0]!='.'){
                    if(strcmp(namelist[i]->d_name,"..")!=0 && strcmp(namelist[i]->d_name,".")!=0)
                        printf("%s\n", namelist[i]->d_name);
                }
                else if(flaga==1){
                    if(strcmp(namelist[i]->d_name,"..")!=0 && strcmp(namelist[i]->d_name,".")!=0)
                    printf("%s\n", namelist[i]->d_name);
                }
                free(namelist[i]);
                i++;
            }
            free(namelist);
        }
    }
    else if (flagl == 1)
    {
        
        n = scandir(path, &namelist, NULL, alphasort);
        if (n < 0)
            perror("scandir");
        else
        {
            int i = 0;
            while (i < n)
            {
                char *permissions;
                permissions=check_perms(namelist[i]->d_name);
                if(flaga==0 && namelist[i]->d_name[0]!='.'){
                    if(strcmp(namelist[i]->d_name,"..")!=0 && strcmp(namelist[i]->d_name,".")!=0){
                        printf("%s\t", permissions);
                        printf("%s\t", namelist[i]->d_name);
                        printf("\n");
                    }
                }
                else if(flaga==1){
                    if(strcmp(namelist[i]->d_name,"..")!=0 && strcmp(namelist[i]->d_name,".")!=0){
                    printf("%s\t", namelist[i]->d_name);
                    printf("\n");
                    }
                }
                free(namelist[i]);
                i++;
            }
            free(namelist);
        }
    }
}


char *check_perms(char *name) //function to obtain permissions of a file/directory, given its address
{

    char *str = (char *)malloc(11 * sizeof(char));
    //char *occ=extract_name(name);
    str[0]='-';
    struct stat fs;
    int r;
    //check if given argument is a directory or file
    r = stat(name, &fs);
    if (r == -1)
    {
        perror("stat");
        exit(1);
    }
    if (S_ISDIR(fs.st_mode))
    {
        str[0] = 'd';
    }
    else if (S_ISREG(fs.st_mode))
    {
        str[0] = '-';
    }
    else if (S_ISLNK(fs.st_mode))
    {
        str[0] = 'l';
    }
    else if (S_ISCHR(fs.st_mode))
    {
        str[0] = 'c';
    }
    else if (S_ISBLK(fs.st_mode))
    {
        str[0] = 'b';
    }
    else if (S_ISFIFO(fs.st_mode))
    {
        str[0] = 'p';
    }
    else if (S_ISSOCK(fs.st_mode))
    {
        str[0] = 's';
    }

    //USER PERMISSIONS 
    if( fs.st_mode & S_IRUSR )
        str[1]='r';
    else
        str[1]='-';


    if( fs.st_mode & S_IWUSR )
        str[2]='w';
    else
        str[2]='-';
    if( fs.st_mode & S_IXUSR )
        str[3]='x';
    else
        str[3]='-';

    //GROUP PERMISSIONS

    if( fs.st_mode & S_IRGRP )
        str[4]='r';
    else
        str[4]='-';

    if( fs.st_mode & S_IWGRP )
        str[5]='w';
    else
        str[5]='-';
    
    if( fs.st_mode & S_IXGRP )
        str[6]='x';
    else
        str[6]='-';

    ///OTHERS' PERMISSIONS

    if( fs.st_mode & S_IROTH )
        str[7]='r';
    else
        str[7]='-';

    if( fs.st_mode & S_IWOTH )
        str[8]='w';
    else
        str[8]='-';
    
    if( fs.st_mode & S_IXOTH )
        str[9]='x';
    else
        str[9]='-';

    str[10]='\0';
    
    return str;
}

