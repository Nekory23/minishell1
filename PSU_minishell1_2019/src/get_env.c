/*
** EPITECH PROJECT, 2020
** minshell1
** File description:
** get variables from the env
*/

#include "minishell.h"

int count_args(char *get_path, char sep)
{
    int nbr = 1;

    for (int i = 0; get_path[i] != '\0'; i++)
        if (get_path[i] == sep)
            nbr++;
    return (nbr);
}

char **get_path_command(char **paths, char *command, int nbr)
{
    int len = 0;

    for (int i = 0, j = 0; i != nbr; i++) {
        len = my_strlen(paths[i]);
        paths[i][len] = '/';
        len++;
        while (command[j] != '\0') {
            paths[i][len] = command[j];
            len++;
            j++;
        }
        j = 0;
    }
    return (paths);
}

char **get_path(char *get_path, char *command)
{
    char **paths;
    int nbr = count_args(get_path, ':');

    paths = malloc(sizeof(char *) * nbr);
    for (int i = 0; i != nbr; i++)
        paths[i] = malloc(sizeof(char) * my_strlen(get_path));
    for (int i = 0, j = 0, z = 0; get_path[i] != '\0'; i++, z++) {
        if (get_path[i] == ':') {
            i++;
            j++;
            z = 0;
        }
        paths[j][z] = get_path[i];
    }
    paths = get_path_command(paths, command, nbr);
    return (paths);
}

char *get_env(char **env, char *var)
{
    char *path;
    char *temp;
    int i = 0;
    int z = 0;

    while (env[i]) {
        if (compare_str(env[i], var) == KNOWN) {
            temp = env[i];
            break;
        }
        i++;
    }
    path = malloc(sizeof(char) * my_strlen(temp));
    for (; temp[z] != '='; z++);
    z++;
    for (int j = 0; temp[z] != '\0'; j++, z++)
        path[j] = temp[z];
    path[z] = '\0';
    return (path);
}
