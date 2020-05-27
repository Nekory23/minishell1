/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** compare 2 strings
*/

#include "minishell.h"

int compare_str(char *str, char *str2)
{
    int i = 0;

    while (str2[i] != '\0') {
        if (str2[i] == str[i])
            i++;
        else
            return (UNKNOWN);
    }
    return (KNOWN);
}
