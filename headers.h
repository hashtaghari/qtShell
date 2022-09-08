#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>


#define BUFFER_SIZE 100

extern char *root_directory, *prev_directory, *cur_dir;

extern char old_commands[20][BUFFER_SIZE];

extern int old_commands_ptr;

// pwd.c
void pwd();

// cd.c
void cd(char **);

// prompt.c
void prompt();

// functions.c
char **commands_extract(char *input, const char *delim);
int execute_command(char *command);

// echo.c
void echo(char **command);

// ls.c

void ls(char **command);
char *check_perms(char *name);

// pinfo.c
void pinfo(char *command);

//history.c

void load_history();
void update_history(char *command);
void history(char **command);

#endif