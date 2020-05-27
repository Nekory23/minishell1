/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** display the environment
*/

#include "minishell.h"

void my_env(char **envp)
{
    for (int j = 0; envp[j] != NULL; j++) {
        my_putstr(envp[j]);
        my_putchar('\n');
    }
}
