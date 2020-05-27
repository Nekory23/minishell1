/*
** EPITECH PROJECT, 2020
** minshell1
** File description:
** reallocate space
*/

#include "minishell.h"

char **my_realloc_env(char **envp)
{
    char **new_envp;
    int i = 0;

    while (envp[i])
        i++;
    new_envp = malloc(sizeof(char *) * (i + 2));
    for (int j = 0; envp[j]; j++)
        new_envp[j] = envp[j];
    new_envp[i + 1] = NULL;
    return (new_envp);
}
