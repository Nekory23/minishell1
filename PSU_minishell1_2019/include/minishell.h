/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** minishell1.h
*/

#ifndef __MINISHELL_H__
#define __MINISHELL_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void my_putchar(char c);
void my_putchar_error(char c);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
void my_put_nbr(int nbr);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *clean_str(char *str);

int compare_str(char *str, char *str2);
char **my_realloc_env(char **envp);
void segfault_handling(int status);

int minishell(char **envp);

int check_command(char *command, char *buff, char **envp);
char **commands(int nbr, char *buff, char **envp);
char *get_command(char *buff);

char *get_env(char **envp, char *var);
char **get_path(char *get_path, char *command);
char **get_path_command(char **paths, char *command, int nbr);
char **get_args_bin(char *buff);
int count_args(char *get_path, char sep);
char **get_variables(char **envp);
char **get_args(char *buff, int nbr);

void my_exit(void);
int my_cd(char *buff, char **envp);
void my_env(char **envp);

char **my_setenv(char **envp, char *buff);

char **my_unsetenv(char **envp, char *buff);

#define BL "\e[1;36m"
#define RE "\e[1;31m"
#define WHITE "\e[0;00m"
#define PROMPT RE"[~"BL" ₪ minishell ₪ "RE"~]"BL" (~‾▿‾)~⤅ "WHITE

#define SUCCESS 0
#define FAIL 84
#define ERROR -2

#define UNKNOWN -1
#define KNOWN 1

#endif
