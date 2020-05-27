/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** unix command interpreter
*/

#include "minishell.h"

void multi_free(char **c_envp)
{
    int i = 0;

    while (c_envp[i])
        i++;
    for (int j = 0; j != i; j++)
        free(c_envp[j]);
    free(c_envp);
}

char **copy_env(char **envp)
{
    char **c_envp;
    int i = 0;

    while (envp[i])
        i++;
    c_envp = malloc(sizeof(char *) * i);
    for (int j = 0; j != i; j++) {
        c_envp[j] = malloc(sizeof(char) * my_strlen(envp[j]));
        for (int z = 0; envp[j][z] != '\0'; z++)
            c_envp[j][z] = envp[j][z];
    }
    return (c_envp);
}

int main(int ac, char **av, char **envp)
{
    char **c_envp = copy_env(envp);

    if (ac != 1 && av[0] == NULL)
        return (FAIL);
    minishell(c_envp);
    multi_free(c_envp);
    return (SUCCESS);
}
