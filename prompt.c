#include "headers.h"

void prompt()
{

    char *username = (char *)malloc(30 * sizeof(char));
    char *hostname = (char *)malloc(30 * sizeof(char));
    getlogin_r(username, 30);
    gethostname(hostname, 30);
    printf("<%s@%s:", username, hostname);
    if (strcmp(root_directory, cur_dir) == 0)
        printf("~>");

    else
    {
        printf("%s>", cur_dir);
    }
}
