#ifndef MAIN_H
#define MAIN_H

#define BUFFSIZE 1024

#include <stdio.h>
#include <stderr>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

int _execvpe(const char *cmd, char *argv[], char *const envp[]);
char *_strtok(char *input, const char *delim);
ssize_t _getline(char **lineptr, size_t *alloc_size, FILE *input);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, size_t new_size);
int _f_ok(char *cmd, char **environ);
int __exit(char *input);
int __env(char *input);
int _strlen(char *s);





#endif

