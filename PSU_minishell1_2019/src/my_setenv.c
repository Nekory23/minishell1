/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** setenv builtin
*/

#include "minishell.h"

char **mallocs_var(char **envp, char **var, int i)
{
    var = malloc(sizeof(char *) * i - 1);
    for (int j = 0, z = 0; envp[j][z] != '='; z++)
        if (envp[j][z + 1] == '=') {
            var[j] = malloc(sizeof(char) * z + 1);
            j++;
            z = 0;
        }
    return (var);
}

char **get_variables(char **envp)
{
    char **var;
    int i = 0;

    while (envp[i])
        i++;
    var = mallocs_var(envp, var, i);
    for (int j = 0, z = 0; envp[j][z] != '='; z++) {
        if (envp[j][z + 1] == '=') {
            var[j][z] = envp[j][z];
            j++;
            z = 0;
            if (j == i - 1)
                break;
        }
        var[j][z] = envp[j][z];
    }
    return (var);
}

char **get_args(char *buff, int nbr)
{
    char **args = malloc(sizeof(char *) * nbr);
    int j = 0;

    for (int i = 0; i != nbr; i++)
        args[i] = malloc(sizeof(char) * my_strlen(buff));
    for (int i = 0, z = 0; buff[i] != '\n'; i++, z++) {
        if (buff[i] == ' ') {
            i++;
            j++;
            z = 0;
        }
        args[j][z] = buff[i];
    }
    if (j != 4) {
        j++;
        while (j != 5) {
            args[j] = NULL;
            j++;
        }
    }
    return (args);
}

char **change_value(char **vars, char **args, char **envp)
{
    int i = 0;
    char **n_envp;

    while (envp[i])
        i++;
    for (int j = 0; j != i - 1; j++)
        if (compare_str(args[1], vars[j]) == KNOWN) {
            envp[j] = my_strcat(vars[j], "=");
            if (args[2] != NULL)
                envp[j] = my_strcat(envp[j], args[2]);
            return (envp);
        }
    n_envp = my_realloc_env(envp);
    n_envp[i] = my_strcat(args[1], "=");
    if (args[2] != NULL)
        n_envp[i] = my_strcat(n_envp[i], args[2]);
    return (n_envp);
}

char **my_setenv(char **envp, char *buff)
{
    int nbr = count_args(buff, ' ');
    char **args;
    char **vars = get_variables(envp);

    if (nbr >= 4) {
        my_putstr_error("setenv: Too many arguments.\n");
        return (envp);
    }
    args = get_args(buff, nbr);
    if (args[1] == NULL) {
        my_env(envp);
        return (envp);
    }
    envp = change_value(vars, args, envp);
    return (envp);
}
