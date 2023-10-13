#ifndef MAIN_H
#define MAIN_H

#define BUFFSIZE 1024

#include <stdio.h>
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
const char *_strchr(const char *s, int c);
int _strcmp(const char *s1, char *s2);
void *_realloc(void *ptr, size_t new_size);
int _f_ok(char *cmd, char **environ);
int __exit(char *input);
int __env(char *input);
int _strlen(const char *s);
int _fgetc(FILE *stream);
char *_fgets(char *s, int n, FILE *stream);
char *read_input(int *eof_status);
char **parse_input(char *input, int *token_status);




#endif

