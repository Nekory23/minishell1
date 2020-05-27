/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** unsetenv builtin
*/

#include "minishell.h"

char **remove_value(char **vars, char **args, char **envp)
{
    int i = 0;

    while (envp[i])
        i++;
    for (int j = 0; j != i; j++) {
        my_putstr("ok\n");
        if (compare_str(args[1], vars[j]) == KNOWN) {
            my_putstr("found\n");
            while (j != i) {
                envp[j] = envp[j + 1];
                j++;
            }
            envp[i] = NULL;
            return (envp);
        }
    }
    my_putstr("not found\n");
    return (envp);
}

char **my_unsetenv(char **envp, char *buff)
{
    int nbr = count_args(buff, ' ');
    char **args;
    char **vars;

    if (nbr != 2) {
        if (nbr > 2)
            my_putstr_error("unsetenv: Too many arguments.\n");
        if (nbr <= 2)
            my_putstr_error("unsetenv: Too few arguments.\n");
        return (envp);
    }
    vars = get_variables(envp);
    args = get_args(buff, nbr);
    envp = remove_value(vars, args, envp);
    return (envp);
}
