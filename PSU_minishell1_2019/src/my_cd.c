/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** cd command
*/

#include "minishell.h"

void go_home(char *arg, char **envp)
{
    char *pwd = get_env(envp, "PWD");
}

char *get_arg_cd(char *buffer)
{
    char *arg = malloc(sizeof(char) * my_strlen(buffer));
    int i = 2;
    int j = 0;

    while (buffer[i] == ' ' || buffer[i] == '\n') {
        if (buffer[i] == '\n') {
            arg[0] = '~';
            return (arg);
        }
        i++;
    }
    for (; buffer[i] != '\n'; j++, i++) {
        if (buffer[i] == ' ') {
            my_putstr_error("cd: Too many arguments.\n");
            return (NULL);
        }
        arg[j] = buffer[i];
    }
    arg[j] = '\0';
    return (arg);
}

int my_cd(char *buff, char **envp)
{
    char *arg = get_arg_cd(buff);

    if (arg == NULL)
        return (0);
    if (my_strlen(arg) == 1 && arg[0] == '~') {
        go_home(arg, envp);
        return (0);
    }
    if (chdir(arg) == -1) {
        perror(arg);
    }
    free(arg);
    return (0);
}
