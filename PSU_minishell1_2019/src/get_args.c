/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** get the arguments
*/

#include "minishell.h"

char **get_args_bin(char *buff)
{
    int nbr = count_args(buff, ' ');
    char **args = malloc(sizeof(char *) * nbr);

    for (int i = 0; i != nbr; i++)
        args[i] = malloc(sizeof(char) * my_strlen(buff));
    for (int i = 0, j = 0, z = 0; buff[i] != '\n'; i++, z++) {
        if (buff[i] == ' ') {
            i++;
            j++;
            z = 0;
        }
        args[j][z] = buff[i];
    }
    return (args);
}
