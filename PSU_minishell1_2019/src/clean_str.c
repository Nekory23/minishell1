/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** clean_str (retirer tous les espaces et les tabs)
*/

#include <stdio.h>
#include <string.h>

int first_space(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    for (int i = 0; str[i] == ' '; i++)
            space++;
    return (space);
}

char *clean_str(char *str)
{
    int space = first_space(str);
    int pos = 0;

    for (int i = 0; i != space; i++)
        for (int j = 0; str[j] != '\0'; j++)
            str[j] = str[j + 1];
    return (str);
}
